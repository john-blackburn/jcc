#define NULL (void*)0
#define errno (*_errno())

int strlen(char *s);
int strcmp(char *s1, char *s2);
int printf(char *format, ...);
void* memcpy(void* s1, void* s2, int n);
void exit(int status);
char* strcpy(char* s1, char* s2);
int strtol(char* nptr, char **endptr, int base);

int *_errno();

struct Type
{
    char data[32];
};

struct Node
{
  int type;
  char *id;
  struct Type varType;
  struct Node *child;
  struct Node *child2;
  struct Node *child3;
  struct Node *child4;
  struct Node **line;
  int nlines;
};

struct Var
{
  char *id;
  struct Type varType;
  int level;
  int offset;
  int isArg;
  struct Node *structNode;
  struct Var *prev;
};

struct Var *varEnd;

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

int endsWith(char* t, char c)
{
    int l=strlen(t);
    return t[l-1] == c;
}

int getArray(char* t, int open[], int close[])
{
    int l=strlen(t);

    int i;
    int ind=0;

    for (i=0;i<l;i++)
    {
        if (t[i]=='[')
        {
            open[ind]=i;
        }
        if (t[i]==']')
        {
            close[ind]=i;
            ind++;
        }        
    }
    return ind;
}

int sizeOf(struct Type t)
{
    if (strcmp(t.data,"void")==0)
    {
        printf("Cannot take sizeof void\n");
        exit(1);
    }
    
    if (strlen(t.data)==0) return 0;
    
    int i;
    int n;
    int open[10];
    int close[10];
    
    n = getArray(t.data, open, close);
 
    int nElem=1;
    int st;
    int len;
    char index[16];    
    char* endptr = NULL;
    for (i=0; i<n; i++)
    {        
        st=open[i]+1; len=close[i]-1-st+1;
        memcpy(index, &t.data[st], len);
        index[len]='\0';
        
        errno = 0;

        nElem *= strtol(index, &endptr, 0);

        if (!(errno == 0 && *endptr == '\0'))
        {
            printf("Failed to parse index number\n");
            exit(1);
        }
    }
            
    struct Type s = t;
    
    if (n>0)
    {
        s.data[open[0]]='\0';
    }
    
    if (endsWith(s.data, '*'))
        return 4*nElem;
    else if (strcmp(s.data, "int") == 0)
        return 4*nElem;
    else if (strcmp(s.data, "char") == 0)
        return nElem;
    else if (startsWith(s.data, "struct"))
    {
        struct Var *p=varEnd;
        struct Node* structNode;
        int found=0;
        while(p!=NULL)
        {
            if (strcmp(s.data, p->id) == 0)
            {
                structNode=p->structNode;
                found=1;
                break;
            }
            p=p->prev;
        }
        if (found==0) 
        {
            printf("Unknown struct %s\n",s.data);
            exit(1);
        }

        int tot=0;
        for (i=0; i < structNode->nlines; i++)
        {
            tot += sizeOf(structNode->line[i]->varType);
        }    
        return nElem*tot;
    }
    else
    {
        printf("Cannot find sizeof %s\n", s.data);
        exit(1);
    }
}

int isPointer(struct Type t)
{
    return endsWith(t.data, '*');
}

int main(int argc, char **argv)
{
    struct Type t;
    
    printf("startsWith %d %d\n", startsWith("John","Jo"), startsWith("John","jo"));
    printf("endsWith %d %d\n", endsWith("John",'n'), endsWith("John",'N'));

    strcpy(t.data, "int*");
    printf("sizeOf int* =%d, isPointer=%d\n", sizeOf(t), isPointer(t));

    strcpy(t.data, "int");
    printf("sizeOf int =%d, isPointer=%d\n", sizeOf(t), isPointer(t));
    
    strcpy(t.data, "char");
    printf("sizeOf char =%d isPointer=%d\n", sizeOf(t), isPointer(t));

    strcpy(t.data, "char*");
    printf("sizeOf char* =%d isPointer=%d\n", sizeOf(t), isPointer(t));

    strcpy(t.data, "char*[2][3]");
    printf("sizeOf char*[2][3] =%d isPointer=%d\n", sizeOf(t), isPointer(t));
    
    return 0;
}
