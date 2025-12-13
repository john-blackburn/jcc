/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
*/

#define MAXTOKEN 100
#define BUFSIZE 100
#define EOF (-1)

int isalnum(int);
int getchar (void);
char *strcat (char *, const char *);
int strcmp (const char *, const char *);
char *strcpy (char *, const char *);

enum {NAME, PARENS, BRACKETS};

int tokentype;           // type of last token
char token[MAXTOKEN];    // last token string
char name[MAXTOKEN];     // identifier name
char datatype[MAXTOKEN]; // data type = char, int etc
char out[1000];          // output string

char buf[BUFSIZE];
int bufp = 0;  // next free position in bufp

int getch(void)
{
//    printf("getch: bufp=%d\n",bufp);
    return (bufp>0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many character\n");
    else
        buf[bufp++] = (char)c;
//    printf("ungetch: bufp=%d\n",bufp);
}

// return next token
int gettoken(void)
{
    int c;
    char *p = token;
    
    while ((c=getch()) == ' ' || c =='\t') ;
    
    if (c == '(')
    {
        if ((c = getch()) == ')')
        {
            strcpy(token,"()");
            return tokentype = PARENS;
        }
        else
        {
            ungetch(c);
            return tokentype = '(';
        }
    }
    else if (c == '[')
    {
        for (*p++ = (char)c; (*p++ = (char)getch()) != ']'; ) ;
        *p = '\0';
        return tokentype = BRACKETS;
    }
    else if (isalpha(c))
    {
        for (*p++ = (char)c; isalnum(c = getch()); )
            *p++ = (char)c;
        *p='\0';
        ungetch(c);
        return tokentype=NAME;
    }
    else
        return tokentype = c;
}

void dirdcl(void);  // forward dec

void dcl(void)
{
    int ns;
    
    for (ns=0L; gettoken() == '*'; )   // count *'s
        ns++;
    
    dirdcl();
    while (ns-- > 0)
        strcat(out, " pointer to");
}

void dirdcl(void)
{
    int type;
    
    if (tokentype == '(')   // (dcl)
    {
        dcl();
        if (tokentype != ')')
            printf("error: missing )\n");
    }
    else if (tokentype == NAME)  // variable name
        strcpy(name, token);
    else
        printf("error: expected name of (dcl)\n");
        
    while ((type=gettoken()) == PARENS || type == BRACKETS)
    {
        if (type == PARENS)
            strcat(out, " function returning");
        else
        {
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
    }
} 

int main()
{
    while (gettoken() != EOF)
    {
        strcpy(datatype, token);   // 1st token on line is datatype
        out[0]='\0';
        dcl();
        if (tokentype != '\n')
            while (getchar()!='\n') ; // clear out stuff after decl before new one
        printf("%s: %s %s\n", name, out, datatype);
    }
    return 0;
}
