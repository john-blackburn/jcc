#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

char *ops[]={"and","or","xor"};

// t="foo", s="fo", return true
int startsWith(char *t, char *s)
{
    if (strlen(s) > strlen(t)) return 0;
    
    int i;
    for (i=0; i< strlen(s); i++)
    {
        if (t[i] != s[i])
            return 0;
    }
    return 1;
}

// t="foo", c='o', returns true
int endsWith(char* t, char c)
{
    int l=strlen(t);
    return t[l-1]==c;
}

// set "out" to substring of s from index st to ed inclusive
// if ed = -1, return rest of string
// don't return trailing comment starting with #
void getSubstr(char *out, char *s, int st, int ed)
{
    int i;
    if (ed==-1) ed=strlen(s);
    
    for (i=st; i<=ed; i++)
    {
        if (s[i]=='#') break;
        *out=s[i];
        ++out;
    }
    *out='\0';
}

// determine if sub is part of s starting at index ind
// inStr(line,4,"esp"), if so return true
int inStr(char *s, int ind, char* sub)
{
    int i;
    for (i=0;i<strlen(sub);i++)
    {
        if (s[ind+i]!=sub[i])
            return 0;
    }
    return 1;
}

// find index of first occurence of c in s. If not found return -1
// i=getInd(line,']');
int getInd(char *s, char c)
{
    int i;
    for (i=0;i<strlen(s);i++)
        if (s[i]==c)
            return i;
        
    return -1;
}

int process(FILE* fp, FILE* fpz)
{
    
    char line[100];
    int i,inc,add,op,n;
    char *p;
    char reg[100], num[100], label[100];
    char *endptr = NULL;

    while(fgets(line,100,fp)!=NULL)
    {
        
        // remove newline from end of line
        p=strchr(line,'\n');
        if (p!=NULL) *p='\0';

        // ignore some assembler directives
        if (startsWith(line,".intel") 
            || startsWith(line,".globl")
            || startsWith(line,".text")
            || startsWith(line,".data")) continue;
        
        // copy full line comments
        if (line[0]=='#')
        {
            line[0]=';';
            fprintf(fpz,"%s\n",line);
            continue;
        }

        // labels
        if (endsWith(line,':'))
        {
            fprintf(fpz,"%s\n",line);
            continue;
        }
                        
// ----------------------------------------------------------
// .SET .SKIP .LONG .BYTE .ASCIZ
// ----------------------------------------------------------
        
        // .set -> equ
        if (startsWith(line,".set"))
        {
            i=getInd(line,',');
            getSubstr(label,line,5,i-1);
            getSubstr(num,line,i+1,-1);
            fprintf(fpz,"%s equ %s",label,num);
        }        
        else if (startsWith(line,".skip"))
        {
            getSubstr(num,line,6,-1);
            fprintf(fpz,"    ds %s",num);
        }
        else if (startsWith(line,".long"))
        {
            getSubstr(num,line,6,-1);
            fprintf(fpz,"    dw %s",num);
        }
        else if (startsWith(line,".byte"))
        {
            getSubstr(num,line,6,-1);
            fprintf(fpz,"    db %s",num);
        }
        else if (startsWith(line,".asciz"))
        {
            getSubstr(num,line,7,-1);
            printf("%s",num);
            fprintf(fpz,"    db %s,0",num);
        }
        
// ----------------------------------------------------------
// SETcc
// ----------------------------------------------------------
        
        else if (startsWith(line,"set"))
        {
            getSubstr(label,line,3,4);
            if (label[1]==' ') label[1]='\0';
            fprintf(fpz,"    call _set%s",label);
        }

// ----------------------------------------------------------
// MOVZX
// ----------------------------------------------------------
        
        else if (startsWith(line,"movzx eax,al"))
            fprintf(fpz,"    ld h,0");

// ----------------------------------------------------------
// CALL, JE, JNE, JMP, RET
// ----------------------------------------------------------
        
        else if (startsWith(line,"call"))
        {
            getSubstr(label,line,5,-1);
            fprintf(fpz,"    call %s",label);
        }

        else if (startsWith(line,"je"))
        {
            getSubstr(label,line,3,-1);
            fprintf(fpz,"    jp z,%s",label);
        }

        else if (startsWith(line,"jne"))
        {
            getSubstr(label,line,4,-1);
            fprintf(fpz,"    jp nz,%s",label);
        }

        else if (startsWith(line,"jmp"))
        {
            getSubstr(label,line,4,-1);
            fprintf(fpz,"    jp %s",label);
        }

        else if (startsWith(line,"ret"))
            fprintf(fpz,"    ret");

// ----------------------------------------------------------
// LEA
// ----------------------------------------------------------

        else if (startsWith(line,"lea eax"))
        {
            if (inStr(line,7,",[ebp"))
            {
                i=getInd(line,']');
                getSubstr(num,line,12,i-1);
                fprintf(fpz,
                        "    push iy\n"
                        "    pop hl\n"
                        "    ld bc,%s\n"
                        "    add hl,bc",num);
            }            
        }

// ----------------------------------------------------------
// INC, DEC
// ----------------------------------------------------------

        else if (startsWith(line,"inc") || startsWith(line,"dec"))
        {
            if (startsWith(line,"inc"))
                inc=1;
            else 
                inc=0;
            
            if (inStr(line,4,"byte ptr [eax]"))
                fprintf(fpz,"    %s (hl)", inc ? "inc":"dec");
            else if (inStr(line,4,"dword ptr [eax]"))
                fprintf(fpz,
                       "    ld c,(hl)\n"
                       "    inc hl\n"
                       "    ld b,(hl)\n"
                       "    %s bc\n"
                       "    ld (hl),b\n"
                       "    dec hl\n"
                       "    ld (hl),c", inc ? "inc":"dec");
        }

// ----------------------------------------------------------
// ADD, SUB
// ----------------------------------------------------------

        else if (startsWith(line,"add") || startsWith(line,"sub"))
        {
            if (startsWith(line,"add")) 
                add=1;
            else
                add=0;
            
            if (inStr(line,4,"dword ptr [eax]"))
            {
                i=getInd(line,',');
                getSubstr(num,line,i+1,-1);
                fprintf(fpz,
                        "    push hl\n"
                        "    push hl\n"
                        "    pop ix\n"
                        "    ld c,(ix+0)\n"
                        "    ld b,(ix+1)\n"
                        "    push bc\n"
                        "    pop hl\n"
                        "    ld bc,%s\n"
                        "    %s"
                        "    ld (ix+0),l\n"
                        "    ld (ix+1),h\n"
                        "    pop hl", num, add ? "add hl,bc":"or a\n    sbc hl,bc");
            }
            else if (inStr(line,4,"esp,offset"))
            {
                getSubstr(label,line,15,-1);
                fprintf(fpz,
                        "    ld hl,0\n"
                        "    add hl,sp\n"
                        "    ld bc,%s\n"
                        "    %s\n"
                        "    ld sp,hl", label, add ? "add hl,bc":"or a\n    sbc hl,bc");
            }        
            else if (inStr(line,4,"esp"))
            {
                getSubstr(num,line,8,-1);
                n=strtol(num, &endptr, 0);
                if (n<=20)
                    for (i=0;i<n/2;i++)
                        fprintf(fpz,"    pop bc%s",(i==n/2-1) ? "":"\n");
                else
                {
                    fprintf(fpz,
                            "    push hl\n",
                            "    ld hl,0\n"
                            "    add hl,sp\n"
                            "    ld bc,%s\n"
                            "    %s\n"
                            "    ld sp,hl",
                            "    pop hl\n", num, add ? "add hl,bc":"or a\n    sbc hl,bc");
                }
            }
            else if (inStr(line,4,"eax,ecx"))
                fprintf(fpz,"%s",add ? "    add hl,de":"    or a\n    sbc hl,de");
        }

// ----------------------------------------------------------
// NOT
// ----------------------------------------------------------

        else if (startsWith(line,"not"))
        {
            if (inStr(line,4,"al"))
                fprintf(fpz,
                        "    ld a,l\n"
                        "    cpl\n"
                        "    ld l,a");
            else if (inStr(line,4,"eax"))
                fprintf(fpz,
                        "    ld a,h\n"
                        "    cpl\n"
                        "    ld h,a\n"
                        "    ld a,l\n"
                        "    cpl\n"
                        "    ld l,a");
        }

// ----------------------------------------------------------
// NEG
// ----------------------------------------------------------

        else if (startsWith(line,"neg"))
        {
            if (inStr(line,4,"al"))
                fprintf(fpz,
                        "    ld a,l\n"
                        "    neg\n"
                        "    ld l,a");
            else if (inStr(line,4,"eax"))
                fprintf(fpz,
                        "    push hl\n"
                        "    pop bc\n"
                        "    ld hl,0\n"
                        "    or a\n"
                        "    sbc hl,bc\n");
        }

// ----------------------------------------------------------
// AND OR XOR
// ----------------------------------------------------------

        else if (startsWith(line,"and") || startsWith(line,"or") || startsWith(line,"xor"))
        {
            if (startsWith(line,"and"))
                op=0;
            else if (startsWith(line,"or"))
                op=1;
            else
                op=2;
            
            if (inStr(line,4,"eax,ecx"))
            fprintf(fpz,
                    "    ld a,h\n"
                    "    %s d\n"
                    "    ld h,a\n"
                    "    ld a,l\n"
                    "    %s e\n"
                    "    ld l,a", ops[op], ops[op]);
            else if (inStr(line,4,"al,cl"))
                fprintf(fpz,
                        "    ld a,l\n"
                        "    %s e\n"
                        "    ld l,a", ops[op]);
        }

// ----------------------------------------------------------
// [I]MUL, [I]DIV
// ----------------------------------------------------------

        else if (startsWith(line,"imul eax") || startsWith(line,"mul eax"))
            fprintf(fpz,"    call _mul_hlde");

        else if (startsWith(line,"imul al") || startsWith(line,"mul al"))
            fprintf(fpz,"    call _mul_le");

        else if (startsWith(line,"idiv eax"))
            fprintf(fpz,"    call _idiv_hlde");

        else if (startsWith(line,"idiv al"))
            fprintf(fpz,"    call _idiv_le");

        else if (startsWith(line,"div eax"))
            fprintf(fpz,"    call _div_hlde");

        else if (startsWith(line,"div al"))
            fprintf(fpz,"    call _div_le");

// ----------------------------------------------------------
// PUSH
// ----------------------------------------------------------

        else if (startsWith(line, "push"))
        {
            getSubstr(reg,line,5,7);  // reg=line[5:7]
            if (strcmp(reg,"ebp")==0)
                fprintf(fpz,"    push iy");
            else if (strcmp(reg,"eax")==0)
                fprintf(fpz,"    push hl");
            else
                fprintf(fpz,"unknown push");
        }

// ----------------------------------------------------------
// POP
// ----------------------------------------------------------

        else if (startsWith(line, "pop"))
        {
            getSubstr(reg,line,4,6);
            if (strcmp(reg,"ebp")==0)
                fprintf(fpz,"    pop iy");
            else if (strcmp(reg,"eax")==0)
                fprintf(fpz,"    pop hl");
            else if (strcmp(reg,"ecx")==0)
                fprintf(fpz,"    pop de");
            else
                fprintf(fpz,"unknown pop");
        }

// ----------------------------------------------------------
// cmp
// ----------------------------------------------------------
        
        else if (startsWith(line,"cmp"))
        {
            if (startsWith(line,"cmp eax,0"))
                fprintf(fpz,
                        "    ld a,h\n"
                        "    or l");
            else if (startsWith(line,"cmp eax,ecx"))
                fprintf(fpz,
                        "    push hl\n"
                        "    or a\n"
                        "    sbc hl,de\n"
                        "    pop hl");
            else if (startsWith(line,"cmp al,0"))
                fprintf(fpz,
                        "    ld a,l\n"
                        "    cp 0");
            else if (startsWith(line,"cmp al,cl"))
                fprintf(fpz,
                        "    ld a,l\n"
                        "    cp e");
            else if (startsWith(line,"cmp eax,"))
            {
                getSubstr(num,line,8,-1);
                fprintf(fpz,
                        "    push hl\n"
                        "    or a\n"
                        "    ld bc,%s\n"
                        "    sbc hl,bc\n"
                        "    pop hl",num);
            }
            else if (startsWith(line,"cmp al,"))
            {
                getSubstr(num,line,7,-1);
                fprintf(fpz,
                        "    ld a,l\n"
                        "    cp %s",num);
            }
            
        }

// ----------------------------------------------------------
// MOV
// ----------------------------------------------------------

        else if (startsWith(line, "mov"))
        {
            if (inStr(line,4,"esp"))
                fprintf(fpz,"    ld sp,iy");
            else if (inStr(line,4,"ebp"))
            {
                fprintf(fpz,"    ld iy,0\n");
                fprintf(fpz,"    add iy,sp");
            }
            // mov [ebp+number],eax
            else if (inStr(line,4,"[ebp"))
            {
                i=getInd(line,']');
                getSubstr(num,line,8,i-1);
                n=strtol(num, &endptr, 0);
                fprintf(fpz,"    ld (iy%+d),l\n",n);
                fprintf(fpz,"    ld (iy%+d),h",n+1);
            }
            else if (inStr(line,4,"eax"))
            {
                // mov eax,[ebp+NN]
                if (inStr(line,7,",[ebp"))
                {
                    i=getInd(line,']');
                    getSubstr(num,line,12,i-1);
                    n=strtol(num, &endptr, 0);
                    fprintf(fpz,"    ld l,(iy%+d)\n",n);
                    fprintf(fpz,"    ld h,(iy%+d)",n+1);
                }
                // mov eax,[eax]
                else if (inStr(line,7,",[eax]"))
                {
                    fprintf(fpz,"    ld c,(hl)\n");
                    fprintf(fpz,"    inc hl\n");
                    fprintf(fpz,"    ld b,(hl)\n");
                    fprintf(fpz,"    push bc\n");
                    fprintf(fpz,"    pop hl");
                }
                // mov eax,ecx
                else if (inStr(line,7,",ecx"))
                {
                    fprintf(fpz,
                            "    push de\n"
                            "    pop hl");
                }
                // mov eax,offset label
                else if (inStr(line,7,",offset"))
                {
                    getSubstr(label,line,15,-1);
                    fprintf(fpz,"    ld hl,%s",label);
                }
                // mov eax,label
                // mov eax,number
                else
                {
                    if (isdigit(line[8]))
                    {
                        getSubstr(num,line,8,-1);
                        fprintf(fpz,"    ld hl,%s",num);
                    }
                    else
                    {
                        getSubstr(label,line,8,-1);
                        fprintf(fpz,"    ld hl,(%s)",label);                        
                    }
                }
                
            }  // end begin with eax
            else if (inStr(line,4,"[eax]"))
            {
                // mov [eax],cl
                if (inStr(line,10,"cl"))
                    fprintf(fpz,"    ld (hl),e");
                // mov [eax],ecx
                else  if (inStr(line,10,"ecx"))
                {
                    fprintf(fpz,"    ld (hl),e\n");
                    fprintf(fpz,"    inc hl\n");
                    fprintf(fpz,"    ld (hl),d\n");
                    fprintf(fpz,"    dec hl");
                }
            }
            else if (inStr(line,4,"ecx"))
            {
                // mov ecx,eax
                if (inStr(line,8,"eax"))
                {
                    fprintf(fpz,"    push hl\n");
                    fprintf(fpz,"    pop de");
                }
                else if (inStr(line,8,"[eax]"))
                {
                    fprintf(fpz,
                            "    ld e,(hl)\n"
                            "    inc hl\n"
                            "    ld d,(hl)\n"
                            "    dec hl");
                }
                // mov ecx,edx
                else if (inStr(line,8,"edx"))
                {
                    fprintf(fpz,
                            "    push bc\n"
                            "    pop de");
                }
                // mov ecx,number
                else
                {
                    getSubstr(num,line,8,-1);
                    fprintf(fpz,"    ld de,%s",num);
                }
            } // begin with [ecx]
            else if (inStr(line,4,"[ecx]"))
            {
                if (inStr(line,10,"al"))
                    fprintf(fpz,"    ld (de),a");
                else if (inStr(line,10,"eax"))
                {
                    fprintf(fpz,
                            "    push de\n"
                            "    pop ix\n"
                            "    ld (ix+0),l\n"
                            "    ld (ix+1),h");
                }
            }
            else if (inStr(line,4,"al"))
            {
                if (inStr(line,7,"[ebp"))
                {
                    i=getInd(line,']');
                    getSubstr(num,line,11,i-1);
                    fprintf(fpz,"    ld l,(iy%s)",num);
                }
                else if (inStr(line,7,"[eax]"))
                    fprintf(fpz,"    ld l,(hl)");
                else if (inStr(line,7,"cl"))
                    fprintf(fpz,"    ld l,e");
                else
                {
                    getSubstr(num,line,7,-1);
                    if (isdigit(line[7]))
                        fprintf(fpz,"    ld l,%s",num);
                    else if (inStr(line,7,"'\\n'"))
                        fprintf(fpz,"    ld l,10 ; newline");
                    else if (line[7]=='\'')
                        fprintf(fpz,"    ld l,%s",num);
                    else
                        fprintf(fpz,"    ld l,(%s)",num);                    
                }
            }
            else if (inStr(line,4,"cl"))
                fprintf(fpz,"    ld e,(hl)");
        }  // end mov


        // trailing comment
        p=strchr(line,'#');
        if (p!=NULL)
            fprintf(fpz," ;%s\n",p+1);
        else
            fprintf(fpz,"\n");
    }
    
    if (feof(fp))
       puts("End of file reached");

    return 0;
}

int main(int argc, char **argv)
{    
    const char *usage="toZ80 name\n";

    if (argc != 2)
    {
        printf("Usage:\n%s\n",usage);
        return 0;
    }

    char zname[64];
    strcpy(zname,argv[1]);
    strcat(zname,".z80");
    
    char dname[64];
    strcpy(dname,argv[1]);
    strcat(dname,".d");

    char sname[64];
    strcpy(sname,argv[1]);
    strcat(sname,".s");
    

    FILE* fpz=fopen(zname,"w");
    fprintf(fpz,"org 40000\n"
                "jp _main\n");
    
    FILE* fpd=fopen(dname,"r");
    process(fpd, fpz);
    fclose(fpd);

    FILE* fps=fopen(sname,"r");
    process(fps, fpz);
    fclose(fps);

    fprintf(fpz,"include \"z80lib.z80\"\n");
    fprintf(fpz,"include \"stdio.z80\"\n");
    fprintf(fpz,"include \"string.z80\"\n");

    fclose(fpz);
    
    return 0;
}
