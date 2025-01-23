/*
Usage:
jcc path/to/foo.c
Creates foo.s in current directory and assembles/links to get foo.exe

TODO:
Not needed to compile this compiler (and not done):
More initialise arrays: 
    char foo[]={'f','o','o'}="foo". int foo[]={1,2,3}. 
    char *foo[]={"hello","world"} (currently only done for globals)
Function protoypes (currently ignored but return value considered). Coercion. (WON'T DO)
comma operator (WON'T DO)
function pointers (WON'T DO)
double (WON'T DO)
const, long, register, short, volatile (parsed but ignored: WON'T DO)
short int (2 bytes on AX) (WON'T DO)
bit fields (WON'T DO)
struct, typedef and prototype in function body
inline for GNU C (don't compile inline functions)

static int s=0; need to change name to s+s_label since might have multiple functions with static int s
(in GLOBAL and VAR sections of writeasm)

Other calling conventions. 
Stack alignment (always push multiple of 4 bytes). (Application Binary Interface)
padding within structs?
64 bit
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/*
Taken from the above header files. We want to avoid headers as they have non-standard stuff
Below is the minimum set of declarations


#define NULL ((void*)0)
#define errno (*_errno())
#define SEEK_END 2

typedef unsigned int size_t;

typedef struct _iobuf
{
  char *_ptr;
  int _cnt;
  char *_base;
  int _flag;
  int _file;
  int _charbuf;
  int _bufsiz;
  char *_tmpfname;
} FILE;


__attribute__((__cdecl__)) __attribute__((__nothrow__)) FILE * fopen (const char *, const char *);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int fclose (FILE *);
 
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int fprintf (FILE *, const char *, ...);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int printf (const char *, ...);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int sprintf (char *, const char *, ...);

__attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t fread (void *, size_t, size_t, FILE *);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t fwrite (const void *, size_t, size_t, FILE *);

__attribute__((__cdecl__)) __attribute__((__nothrow__)) int fseek (FILE *, long, int);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) long ftell (FILE *);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) void rewind (FILE *);

__attribute__((__cdecl__)) __attribute__((__nothrow__)) int *_errno(void);

__attribute__((__cdecl__)) __attribute__((__nothrow__)) void *memcpy (void *, const void *, size_t);

__attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strcat (char *, const char *);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int strcmp (const char *, const char *) __attribute__((__pure__));
__attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strcpy (char *, const char *);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t strlen (const char *) __attribute__((__pure__));
__attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strstr (const char *, const char *) __attribute__((__pure__));
__attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strtok (char *, const char *);

__attribute__((__cdecl__)) __attribute__((__nothrow__)) void *malloc (size_t) __attribute__((__malloc__));
__attribute__((__cdecl__)) __attribute__((__nothrow__)) void free (void *);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) void exit (int) __attribute__((__noreturn__));

__attribute__((__cdecl__)) __attribute__((__nothrow__)) int isalnum(int);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int isalpha(int);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int isdigit(int);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int isspace(int);
 
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int system (const char *);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) long strtol (const char *, char **, int);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int fscanf (FILE *, const char *, ...);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int scanf (const char *, ...);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int sscanf (const char *, const char *, ...);

End of std headers stuff
*/

char *tokNames[]={"<<=", ">>=",

		  "&&", "||", "==", "!=", "<=", ">=", "<<", ">>", 
		  "++", "--", "->",
		  "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=",

		  "<", ">", "!", "=", ",", ";", "...", ".", "(",  ")", "{", "}", "[", "]",
		  "+", "-", "*", "/", "%", "&", "|", "^", "~", ":", "?",

		  "return", "int", "char", "if", "else", "for", "while", "do", "break", "continue", 
          "struct", "sizeof", "void", "enum", "typedef", "float", "const", "extern", "long", "register",
          "short", "static", "unsigned", "volatile", "inline", "goto", "switch", "case", "default", "union", 
          "double"};


// NB tokNames, the next enum and names must all correspond. Punctuation tokens
// must come first with 3 char punctuation, then 2 char, then 1 char. (eg && before &)
// Also, += ... ^= must be continuous sequence (+, -, *, /, &, |, ^), search "ops" to see why.
// qualifiers EXTERN to INLINE must remain in sequence

int numToks=77;  // ie number of entries in tokNames above

enum
{
 LESSTHAN2_EQUAL,
 GREATERTHAN2_EQUAL,
 AMP2,
 PIPE2,
 EQUALS2,
 EXCLAM_EQUAL,
 LESSTHAN_EQUAL,
 GREATERTHAN_EQUAL,
 LESSTHAN2,
 GREATERTHAN2,
 PLUS2,
 MINUS2,
 MINUS_GREATERTHAN,
 PLUS_EQUALS,          // += ... ^= must be continuous numbers
 MINUS_EQUALS,
 ASTERISK_EQUALS,
 SLASH_EQUALS,
 PERCENT_EQUALS,
 AMP_EQUALS,
 PIPE_EQUALS,
 HAT_EQUALS,
 LESSTHAN,
 GREATERTHAN,
 EXCLAM,
 EQUALS,
 COMMA,
 SEMICOLON,
 DOT3,
 DOT,
 OPEN_BRACKET,
 CLOSE_BRACKET,
 OPEN_BRACE,
 CLOSE_BRACE, 
 OPEN_SQUARE,
 CLOSE_SQUARE, 
 PLUS,
 MINUS,
 ASTERISK,
 SLASH,
 PERCENT,
 AMP,
 PIPE,
 HAT,
 TILDE,
 COLON,
 QUESTION,
 RETURN,           // "return" NB all puntuation chars must come before RETURN
 INT_DECLARATION , // "int"
 CHAR_DECLARATION, // "char"
 IF,               // "if"
 ELSE,             // "else"
 FOR,               // "for"
 WHILE,             // "while"
 DO,                // "do"
 BREAK,             // "break"
 CONTINUE,          // "continue"
 STRUCT,            // "struct"
 SIZEOF,
 VOID_DECLARATION,
 ENUM,
 TYPEDEF,
 FLOAT_DECLARATION,
 CONST,            // qualifiers must remain in sequence
 EXTERN,
 LONG,
 REGISTER,
 SHORT,
 STATIC,
 UNSIGNED,
 VOLATILE,
 INLINE,
 GOTO,
 SWITCH,
 CASE,
 DEFAULT,
 UNION,
 DOUBLE_DECLARATION,
 
 INT_LITERAL,      // eg,3
 IDENTIFIER,       // eg main
 STRING_LITERAL,   // "hello, world!\n"
 CHAR_LITERAL,     // '\n'
 FLOAT_LITERAL,    // 123.456

 FUNCTION,         // AST only from here...
 UNARY_MINUS,
 UNARY_COMPLEMENT,
 UNARY_NOT,
 BINARY_PLUS,
 BINARY_MINUS,
 BINARY_TIMES,
 BINARY_DIVIDE,
 BINARY_AND,
 BINARY_OR,
 BINARY_EQUAL,
 BINARY_NOT_EQUAL,
 BINARY_LESS_THAN_OR_EQUAL,
 BINARY_LESS_THAN,
 BINARY_GREATER_THAN_OR_EQUAL,
 BINARY_GREATER_THAN,
 ASSIGNMENT,
 VAR,
 EXPR,
 DECL,
 BLOCK,
 CALL,
 ARG,
 GLOBAL,
 PROGRAM,
 PROTOTYPE,
 DEREF,
 ADDRESS,
 INDEX,
 UNARY_PLUS,
 BINARY_LEFT_SHIFT,
 BINARY_RIGHT_SHIFT,
 BINARY_BITWISE_AND,
 BINARY_BITWISE_XOR,
 BINARY_BITWISE_OR ,
 BINARY_MODULO,
 INC,
 ARROW,
 DEC,
 INC_AFTER,
 DEC_AFTER,
 CAST,
 DECLGROUP,
 GLOBALGROUP,
 TYPEDEFGROUP,
 LABEL,
 TERNARY
};

char *names[]={
  "LESSTHAN2_EQUAL",
  "GREATERTHAN2_EQUAL",
  "AMP2",
  "PIPE2",
  "EQUALS2",
  "EXCLAM_EQUAL",
  "LESSTHAN_EQUAL",
  "GREATERTHAN_EQUAL",
  "LESSTHAN2",
  "GREATERTHAN2",
  "PLUS2",
  "MINUS2",
  "MINUS_GREATERTHAN",
  "PLUS_EQUALS",
  "MINUS_EQUALS",
  "ASTERISK_EQUALS",
  "SLASH_EQUALS",
  "PERCENT_EQUALS",
  "AMP_EQUALS",
  "PIPE_EQUALS",
  "HAT_EQUALS",
  "LESSTHAN",
  "GREATERTHAN",
  "EXCLAM",
  "EQUALS",
  "COMMA",
  "SEMICOLON",
  "DOT3",
  "DOT",
  "OPEN_BRACKET",
  "CLOSE_BRACKET",
  "OPEN_BRACE",
  "CLOSE_BRACE", 
  "OPEN_SQUARE",
  "CLOSE_SQUARE", 
  "PLUS",
  "MINUS",
  "ASTERISK",
  "SLASH",
  "PERCENT",
  "AMP",
  "PIPE",
  "HAT",
  "TILDE",
  "COLON",
  "QUESTION",
  "RETURN",           // "return"
  "INT_DECLARATION",  // "int"
  "CHAR_DECLARATION", // "char"
  "IF",
  "ELSE",
  "FOR",
  "WHILE",
  "DO",
  "BREAK",
  "CONTINUE",
  "STRUCT",
  "SIZEOF",
  "VOID_DECLARATION",
  "ENUM",
  "TYPEDEF",
  "FLOAT_DECLARATION",
  "CONST",
  "EXTERN",
  "LONG",
  "REGISTER",
  "SHORT",
  "STATIC",
  "UNSIGNED",
  "VOLATILE",
  "INLINE",
  "GOTO",
  "SWITCH",
  "CASE",
  "DEFAULT",
  "UNION",
  "DOUBLE_DECLARATION",

  "INT_LITERAL",      // eg 123
  "IDENTIFIER",       // eg main
  "STRING_LITERAL",           // "hello, world!"
  "CHAR_LITERAL",             // 'a'
  "FLOAT_LITERAL",

  "FUNCTION",         // AST only from here...
  "UNARY_MINUS",
  "UNARY_COMPLEMENT",
  "UNARY_NOT",
  "BINARY_PLUS",
  "BINARY_MINUS",
  "BINARY_TIMES",
  "BINARY_DIVIDE",
  "BINARY_AND",
  "BINARY_OR",
  "BINARY_EQUAL",
  "BINARY_NOT_EQUAL",
  "BINARY_LESS_THAN_OR_EQUAL",
  "BINARY_LESS_THAN",
  "BINARY_GREATER_THAN_OR_EQUAL",
  "BINARY_GREATER_THAN",
  "ASSIGNMENT",
  "VAR",
  "EXPR",
  "DECL",
  "BLOCK",
  "CALL",
  "ARG",
  "GLOBAL",
  "PROGRAM",
  "PROTOTYPE",
  "DEREF",
  "ADDRESS",
  "INDEX",
  "UNARY_PLUS",
  "BINARY_LEFT_SHIFT",
  "BINARY_RIGHT_SHIFT",
  "BINARY_BITWISE_AND",
  "BINARY_BITWISE_XOR",
  "BINARY_BITWISE_OR",
  "BINARY_MODULO",
  "INC",
  "ARROW",
  "DEC",
  "INC_AFTER",
  "DEC_AFTER",
  "CAST",
  "DECLGROUP",
  "GLOBALGROUP",
  "TYPEDEFGROUP",
  "LABEL",
  "TERNARY"
};

union F2U 
{
    float f;
    unsigned int u;
};

union F2U f2u;  // to convert eg 123.456 to IEEE-754 (4 byte float) format

struct Token
{
  int type;
  char *id;
  int lineno;
  struct Token *next;
};

// A fixed length string. Consider renaming this String and using it in place of char* id etc
struct Type
{
    char data[32];  // eg int*[3]
    int isConst;
    int isExtern;
    int isLong;
    int isRegister;
    int isShort;
    int isStatic;
    int isUnsigned;
    int isVolatile;
    int isInline;
};

struct Node
{
  int type;
  char *id;
  struct Type varType;
  int lineno;
  struct Node *child;
  struct Node *child2;
  struct Node *child3;
  struct Node *child4;
  struct Node **line;   // lines of code in functions
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

// typedef int Number;
// typedef Number* PNumber;
struct TypeDef
{
    char *name; // "Number" or "PNumber"
    struct Type type; // "int" or "Number*"
    struct TypeDef *prev;
};

//enum Color
//{
//   RED=3, BLACK
//};
struct EnumConst
{
    char *name; // "RED"
    int value;  // 3
    struct EnumConst *prev;
};

int g_offset;             // offset relative to ebp for local vars and args
struct Var *varEnd;       // top of the stack where we store variable declarations
struct Token *tokenHead;  // global for parsing
int lineno;

struct TypeDef *typeDefEnd = NULL;
struct EnumConst *enumConstEnd = NULL;

FILE* fps;

// forward declarations
struct Node *parse_decl(int type);
struct Node *parse_exp(); 

// ######################################################################

void advance()
{
  if (tokenHead==NULL) 
  {
      printf("Unexpected end of file");
      exit(1);
  }
  tokenHead=tokenHead->next;
}

int getType()
{
  if (tokenHead==NULL)
  {
      printf("Unexpected end of file");
      exit(1);
  }
  return tokenHead->type;
}

// ######################################################################

void fail(char *err)
{
    if (tokenHead->id==NULL)
        printf("Parse Error: %s got %s [lineno: %d]\n",err, names[getType()], tokenHead->lineno);
    else       
        printf("Parse Error: %s got %s (%s) [lineno: %d]\n",err, names[getType()], tokenHead->id, tokenHead->lineno);
    
    exit(1);
}

void asmFail(char *err, struct Node* node)
{
    printf("ASM Write Error: %s [line: %d], node type:%s\n", err, node->lineno, names[node->type]);
    exit(2);
}

// ######################################################################

char* newStr(char *from)
{
  int len=strlen(from);
  char* to=(char*)malloc(len+1);
  strcpy(to,from);
  return to;
}

char* newStrStruct(char *from)
{
  int len=strlen(from+7);
  char* to=(char*)malloc(len+1);
  strcpy(to,"struct ");
  strcat(to,from);
  return to;
}

char* newStrUnion(char *from)
{
  int len=strlen(from+6);
  char* to=(char*)malloc(len+1);
  strcpy(to,"union ");
  strcat(to,from);
  return to;
}


int isProtoOrFunc()
{
    struct Token* p = tokenHead;
    int isproto = 0;
    while (p->type != SEMICOLON)
    {
        if (p->type == EQUALS)       // Eg: int foo=1; Eg: int foo=static_cast<int>(1.0); ==> it's a DECL
        {
            isproto = 0;
            break;
        }
        else if (p->type == OPEN_SQUARE)  // Eg unsigned char m_val[sizeof(T)]; ==> DECL
        {
            isproto = 0;
            break;
        }
        else if (p->type == OPEN_BRACKET)   // Eg: int foo(int x=1); Eg int foo(int x){} ==> It's a PROTO
        {
            isproto = 1;                             
            break;
        }

        p = p->next;
    }  
    // Eg: int foo; struct vector** p;  ==> it's a DECL
    return isproto;
}

// ######################################################################

void addEnumConst(char *name, int value)
{
    struct EnumConst* p=enumConstEnd; // might be NULL
    enumConstEnd = (struct EnumConst*)malloc(sizeof(struct EnumConst));
    enumConstEnd->name=newStr(name);
    enumConstEnd->value=value;
    enumConstEnd->prev=p;
}

int isEnumConst(char *name)
{
    struct EnumConst* p=enumConstEnd;
    while (p!=NULL)
    {
        if (strcmp(p->name, name)==0)
            return 1;
        p=p->prev;
    }
    return 0;
}

char* getEnumConst(char *name)
{
    char *svalue = (char*)malloc(10*sizeof(char));
    
    struct EnumConst* p=enumConstEnd;
    while (p!=NULL)
    {
        if (strcmp(p->name, name)==0)
        {
            sprintf(svalue,"%d",p->value);
            return svalue;
        }
        p=p->prev;
    }
    fail("cannot find enum constant (shouldn't happen)");
}

void addTypedef(char *name, struct Type type)
{
    struct TypeDef* p=typeDefEnd; // might be NULL
    typeDefEnd = (struct TypeDef*)malloc(sizeof(struct TypeDef));
    typeDefEnd->name=newStr(name);
    typeDefEnd->type=type;
    typeDefEnd->prev=p;
}

int isTypedef(char *name)
{
    struct TypeDef* p=typeDefEnd;
    while (p!=NULL)
    {
        if (strcmp(p->name, name)==0)
            return 1;
        p=p->prev;
    }
    return 0;
}

struct Type getTypedef(char *name)
{
    struct TypeDef* p=typeDefEnd;
    while (p!=NULL)
    {
        if (strcmp(p->name, name)==0)
            return p->type;
        p=p->prev;
    }
    fail("undefined typedef");
}

// ######################################################################
// *  *   *
//() (1) (g(x,y),(1+2)/3) start after first bracket (*)
int countArgs()
{
  struct Token *p=tokenHead;

  if (p->type==CLOSE_BRACKET)
    return 0;

  int nargs=1;
  int nlevel=0;
  while(1){
    if (p->type==OPEN_BRACKET){
      nlevel++;
    }

    if (p->type==CLOSE_BRACKET){
      nlevel--;
      if (nlevel<0) break;
    }

    if (p->type==COMMA && nlevel==0)
      nargs++;

    p=p->next;
  }
  return nargs;
}

// ######################################################################
// count number of items in an init block eg x={1,2,3,4};
// *  *   *
//{} {1} {g(x,y),(1+2)/3} start after first bracket (*)
int countInit()
{
  struct Token *p=tokenHead;

  if (p->type==CLOSE_BRACE)
    return 0;

  int nInit=1;
  while(p->type!=CLOSE_BRACE)
  {
    if (p->type==COMMA)
      nInit++;

    p=p->next;
  }
  return nInit;
}

// ######################################################################

// count lines in a block, eg function body or for loop body
int countLines(struct Token *p)
{
  if (p==NULL) p=tokenHead;   // start on tokenHead unless specified otherwise

  int nlines=0;
  int nlevel=0;
  while(1){
    if (p->type==OPEN_BRACE){
      if (nlevel==0) nlines++;
      nlevel++;
    }

    if (p->type==CLOSE_BRACE){
      nlevel--;
      if (nlevel<0) break;
    }

    if ((p->type==SEMICOLON || p->type==COLON) && nlevel==0)
      nlines++;

    if (p->type==ELSE && nlevel==0) nlines--;
    if (p->type==DO && nlevel==0) nlines--;
    if (p->type==FOR && nlevel==0) nlines-=2;
    if (p->type==QUESTION && nlevel==0) nlines--;
    p=p->next;
  }
  return nlines;
}

// ######################################################################

int countArgsAndLines()
{
  //         *
  // int foo(int bar){..}
  int nargs=countArgs();

  struct Token *p=tokenHead;
  while(p->type!=OPEN_BRACE)
    p=p->next;

  p=p->next;
  int nlines=countLines(p);
  return nargs+nlines;
}

// ######################################################################

struct Node *parse_identifier()
{
    struct Node *exp = (struct Node*)malloc(sizeof(struct Node));
    exp->type=VAR;
    exp->lineno=tokenHead->lineno;
    exp->id=newStr(tokenHead->id);
    exp->child=NULL;
    exp->varType.data[0]='\0';
    advance();
    
    return exp;
}

// a, 1, "foo", (expression)
struct Node* parse_primary_exp()
{
    struct Node *exp;
    int type=getType();
	
    if (type==OPEN_BRACKET)
    {
        advance();
        exp=parse_exp();
        if (getType() != CLOSE_BRACKET) fail("Expected ) at end of expression");
        advance();
    }

    // if enum constant, set up INT_LITERAL with correct value
	else if (type==IDENTIFIER && isEnumConst(tokenHead->id))
	{
        exp=(struct Node*)malloc(sizeof(struct Node));
		exp->type=INT_LITERAL;
        exp->lineno=tokenHead->lineno;
        exp->id=getEnumConst(tokenHead->id);
        exp->child=NULL;
        advance();
	}

	else if (type==INT_LITERAL)
    {
        exp=(struct Node*)malloc(sizeof(struct Node));
        exp->type=INT_LITERAL;
        exp->lineno=tokenHead->lineno;
        exp->id=newStr(tokenHead->id);
        exp->child=NULL;    
        advance();
  }
  else if (type==STRING_LITERAL){              // "foo"
    exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=STRING_LITERAL;
    exp->lineno=tokenHead->lineno;
    exp->id=newStr(tokenHead->id);
    exp->child=NULL;
    advance();
  }
  else if (type==CHAR_LITERAL){                // 'c'
    exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=CHAR_LITERAL;
    exp->lineno=tokenHead->lineno;
    exp->id=newStr(tokenHead->id);
    exp->child=NULL;
    advance();
  }
  else if (type==FLOAT_LITERAL){                // 123.456
    exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=FLOAT_LITERAL;
    exp->lineno=tokenHead->lineno;
    exp->id=newStr(tokenHead->id);
    exp->child=NULL;
    advance();
  }
  else if (type==IDENTIFIER)
  {
      exp=parse_identifier();
  }
  else
      fail("unknown type in parse_primary_exp");

  return exp;
}

// ######################################################################

// postfix-exp := <primary-exp> {"[" <exp> "]"}
// postfix-exp := <primary-exp> {"(" <exp> ")"}  // currently in parse_unary_exp
//             := <primary-exp> {("."|"->") <identifier> }
//             := <primary-exp> {("++"|"--")}  // a++
// left associative
// a[2][3], a[i+1], a[b[3]][4], a.x, a->y, a++
struct Node* parse_postfix_exp()
{
  struct Node *factor=parse_primary_exp();
  int nextType=getType();
  while (nextType==OPEN_SQUARE || nextType==DOT || nextType==MINUS_GREATERTHAN 
      || nextType==PLUS2 || nextType==MINUS2)
  {
    advance();
    struct Node *next_factor;
    
    if (nextType==OPEN_SQUARE)
    {
        next_factor=parse_exp();
        if (getType()!=CLOSE_SQUARE)
            fail("expected ]");
        advance();
    }
    else if (nextType==DOT || nextType==MINUS_GREATERTHAN)
    {        
        next_factor=parse_identifier();
    }
    else
        next_factor=NULL;

    struct Node *new_factor=(struct Node*)malloc(sizeof(struct Node));

    if (nextType==OPEN_SQUARE)
        new_factor->type=INDEX;
    else if (nextType==DOT)
        new_factor->type=DOT;
    else if (nextType==MINUS_GREATERTHAN)
        new_factor->type=ARROW;
    else if (nextType==PLUS2)
        new_factor->type=INC_AFTER;
    else
        new_factor->type=DEC_AFTER;
            

    new_factor->lineno=tokenHead->lineno;
    new_factor->child=factor;
    new_factor->child2=next_factor;
    factor=new_factor;
    nextType=getType();
  }

  return factor;
}

// is this start of a type declaration?
// (could still be a function or proto)
// NB if testing for DECL, need to rule out possible definition struct {}; union{}; enum{};
int isTypeDec(struct Token *tok)
{
    int type = tok->type;
    
    return type == FLOAT_DECLARATION || type==DOUBLE_DECLARATION || type==INT_DECLARATION || type==CHAR_DECLARATION 
        || type==STRUCT || type==UNION || type==ENUM || type==VOID_DECLARATION
           || (type>=CONST && type<=INLINE) // qualifiers like const, etc
           || (type==IDENTIFIER && isTypedef(tok->id)); // typedef
}

// ######################################################################

// <unary-exp> := (&,*,+,-,~,!,++,--)<unary-exp> | sizeof <decl> | (<decl>)<exp> | <postfix-exp>
// -2, *a, &a, a[1][2], a(2,3), !a, ~a, sizeof int, (int)5.0, ++a
// right associative
struct Node* parse_unary_exp()
{
  struct Node *exp;
  int type=getType();

  if (type==OPEN_BRACKET && isTypeDec(tokenHead->next))
  {
      // (int*)(p+1)
      advance();
      exp=parse_decl(CAST);

      if (getType()!=CLOSE_BRACKET) fail("Expected ) in cast");
      advance();

      exp->child=parse_exp();
  }
  
  // TODO should move this to parse_postfix_exp
  else if (type==IDENTIFIER && tokenHead->next->type==OPEN_BRACKET){
    exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=CALL;
    exp->lineno=tokenHead->lineno;
    exp->id=newStr(tokenHead->id);
    advance();
    advance();
    int nlines=countArgs();
    exp->nlines=nlines;
    exp->line=(struct Node**)malloc(nlines*sizeof(struct Node*));
    int i;
    for (i=0;i<nlines;i++){
      exp->line[i]=parse_exp();
      if (i<nlines-1 && getType()!=COMMA) fail("expected ,");
      if (i<nlines-1) advance();
    }
    if (getType()!=CLOSE_BRACKET) fail("expected ) in CALL");
    advance();
  }

  else if (type==AMP)        // &a
  {
      exp=(struct Node*)malloc(sizeof(struct Node));
      exp->type=ADDRESS;
      exp->lineno=tokenHead->lineno;
      advance();
      exp->child=parse_unary_exp();
  }  
  else if (type==ASTERISK)   // *p, **p etc
  {
      exp=(struct Node*)malloc(sizeof(struct Node));
      exp->type=DEREF;
      exp->lineno=tokenHead->lineno;
      advance();
      exp->child=parse_unary_exp();
  }
  else if (type==MINUS){
      exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=UNARY_MINUS;
    exp->lineno=tokenHead->lineno;
    advance();
    exp->child=parse_unary_exp();
  }
  else if (type==PLUS){
      exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=UNARY_PLUS;
    exp->lineno=tokenHead->lineno;
    advance();
    exp->child=parse_unary_exp();
  }
  else if (type==PLUS2){
    exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=INC;
    exp->lineno=tokenHead->lineno;
    advance();
    exp->child=parse_unary_exp();
  }
  else if (type==MINUS2){
    exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=DEC;
    exp->lineno=tokenHead->lineno;
    advance();
    exp->child=parse_unary_exp();
  }
  else if (type==TILDE){
    exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=UNARY_COMPLEMENT;
    exp->lineno=tokenHead->lineno;
    advance();
    exp->child=parse_unary_exp();
  }
  else if (type==EXCLAM){
    exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=UNARY_NOT;
    exp->lineno=tokenHead->lineno;
    advance();
    exp->child=parse_unary_exp();
  }
  else if (type==SIZEOF)
  {
      advance();
      int brk=0;
      if (getType()==OPEN_BRACKET)
      {
          brk=1;
          advance();
      }
      
//      if (0) // getType()==IDENTIFIER)
//          exp=parse_identifier();  // TODO fix this!
//      else
      exp=parse_decl(SIZEOF);

      if (brk)
      {
        if (getType()!=CLOSE_BRACKET)
            fail("expected ) in sizeof");
        advance();
      }
  }
  else
      exp=parse_postfix_exp();

  return exp;
}

// ######################################################################
// <multiplicative-exp> ::= <unary-exp> { ("*" | "/" | "%") <unary-exp> }
// (left associative)
// a * 5 / 7
struct Node* parse_multiplicative_exp()
{
  struct Node *factor=parse_unary_exp();
  int nextType=getType();
  while (nextType==ASTERISK || nextType==SLASH || nextType==PERCENT){
    advance();
    struct Node *next_factor=parse_unary_exp();
    struct Node *new_factor=(struct Node*)malloc(sizeof(struct Node));

    if (nextType==ASTERISK)
      new_factor->type=BINARY_TIMES;
    else if (nextType==SLASH)
      new_factor->type=BINARY_DIVIDE;
    else
      new_factor->type=BINARY_MODULO;

    new_factor->lineno=tokenHead->lineno;
    new_factor->child=factor;
    new_factor->child2=next_factor;
    factor=new_factor;
    nextType=getType();
  }

  return factor;
}

// ######################################################################

//<additive-exp> ::= <term> { ("+" | "-") <term> }
//1 + 2 - 3
struct Node* parse_additive_exp()
{
  struct Node *term=parse_multiplicative_exp();
  int nextType=getType();
  while (nextType==PLUS || nextType==MINUS){
    advance();
    struct Node *next_term=parse_multiplicative_exp();
    struct Node *new_term=(struct Node*)malloc(sizeof(struct Node));

    if (nextType==PLUS)
      new_term->type=BINARY_PLUS;
    else
      new_term->type=BINARY_MINUS;

    new_term->lineno=tokenHead->lineno;
    new_term->child=term;
    new_term->child2=next_term;
    term=new_term;
    nextType=getType();
  }

  return term;
}

// ######################################################################

//1<<2
struct Node* parse_shift_exp()
{
    struct Node* term = parse_additive_exp();
    int nextType = getType();
    while (nextType == LESSTHAN2 || nextType == GREATERTHAN2) {
        advance();
        struct Node* next_term = parse_additive_exp();
        struct Node* new_term = (struct Node*)malloc(sizeof(struct Node));

        if (nextType == LESSTHAN2)
            new_term->type = BINARY_LEFT_SHIFT;
        else
            new_term->type = BINARY_RIGHT_SHIFT;

        new_term->lineno=tokenHead->lineno;
        new_term->child = term;
        new_term->child2 = next_term;
        term = new_term;
        nextType = getType();
    }

    return term;
}

// ######################################################################

//<relational-exp> ::= <additive-exp> { ("<" | ">" | "<=" | ">=") <additive-exp> }
// (left associative)
//1<2<=3
struct Node* parse_relational_exp()
{
  struct Node *term=parse_shift_exp();
  int nextType=getType();
  while (nextType==GREATERTHAN || nextType==LESSTHAN ||
	 nextType==GREATERTHAN_EQUAL || nextType==LESSTHAN_EQUAL){
    advance();
    struct Node *next_term=parse_shift_exp();
    struct Node *new_term=(struct Node*)malloc(sizeof(struct Node));

    if (nextType==GREATERTHAN){
      new_term->type=BINARY_GREATER_THAN;
    }
    else if (nextType==LESSTHAN){
      new_term->type=BINARY_LESS_THAN;
    }
    else if (nextType==GREATERTHAN_EQUAL){
      new_term->type=BINARY_GREATER_THAN_OR_EQUAL;
    }
    else{
      new_term->type=BINARY_LESS_THAN_OR_EQUAL;
    }

    new_term->lineno=tokenHead->lineno;
    new_term->child=term;
    new_term->child2=next_term;
    term=new_term;
    nextType=getType();
  }

  return term;
}

// ######################################################################

// <equality-exp> ::= <relational-exp> { ("!=" | "==") <relational-exp> }
// (left associative)
//1 != 2 == 3
struct Node* parse_equality_exp()
{
  struct Node *term=parse_relational_exp();
  int nextType=getType();
  while (nextType==EQUALS2 || nextType==EXCLAM_EQUAL){
    advance();
    struct Node *next_term=parse_relational_exp();
    struct Node *new_term=(struct Node*)malloc(sizeof(struct Node));

    if (nextType==EQUALS2)
      new_term->type=BINARY_EQUAL;
    else
      new_term->type=BINARY_NOT_EQUAL;

    new_term->lineno=tokenHead->lineno;
    new_term->child=term;
    new_term->child2=next_term;
    term=new_term;
    nextType=getType();
  }

  return term;
}

// ######################################################################

//1 | 2 
struct Node* parse_bitwise_and_exp()
{
    struct Node* term = parse_equality_exp();
    int nextType = getType();
    while (nextType == AMP) {
        advance();
        struct Node* next_term = parse_equality_exp();
        struct Node* new_term = (struct Node*)malloc(sizeof(struct Node));

        new_term->type = BINARY_BITWISE_AND;
        new_term->lineno=tokenHead->lineno;

        new_term->child = term;
        new_term->child2 = next_term;
        term = new_term;
        nextType = getType();
    }

    return term;
}

// ######################################################################

//1 ^ 2 
struct Node* parse_bitwise_xor_exp()
{
    struct Node* term = parse_bitwise_and_exp();
    int nextType = getType();
    while (nextType == HAT) {
        advance();
        struct Node* next_term = parse_bitwise_and_exp();
        struct Node* new_term = (struct Node*)malloc(sizeof(struct Node));

        new_term->type = BINARY_BITWISE_XOR;
        new_term->lineno=tokenHead->lineno;

        new_term->child = term;
        new_term->child2 = next_term;
        term = new_term;
        nextType = getType();
    }

    return term;
}

// ######################################################################

//1 | 2 
struct Node* parse_bitwise_or_exp()
{
    struct Node* term = parse_bitwise_xor_exp();
    int nextType = getType();
    while (nextType == PIPE) {
        advance();
        struct Node* next_term = parse_bitwise_xor_exp();
        struct Node* new_term = (struct Node*)malloc(sizeof(struct Node));

        new_term->type = BINARY_BITWISE_OR;
        new_term->lineno=tokenHead->lineno;

        new_term->child = term;
        new_term->child2 = next_term;
        term = new_term;
        nextType = getType();
    }

    return term;
}

// ######################################################################

// <logical-and-exp> ::= <equality-exp> { "&&" <equality-exp> }
// (left associative)
//1 && 2 && 3
struct Node* parse_and_exp()
{
  struct Node *term=parse_bitwise_or_exp();
  int nextType=getType();
  while (nextType==AMP2){
    advance();
    struct Node *next_term=parse_bitwise_or_exp();
    struct Node *new_term=(struct Node*)malloc(sizeof(struct Node));

    new_term->type=BINARY_AND;
    new_term->lineno=tokenHead->lineno;

    new_term->child=term;
    new_term->child2=next_term;
    term=new_term;
    nextType=getType();
  }

  return term;
}

// ######################################################################

//<logical-or-exp> ::= <logical-and-exp> { "||" <logical-and-exp> } 
// (left associative)
//1 || 2 || 3
struct Node* parse_or_exp()
{
  struct Node *term=parse_and_exp();
  int nextType=getType();
  while (nextType==PIPE2){
    advance();
    struct Node *next_term=parse_and_exp();
    struct Node *new_term=(struct Node*)malloc(sizeof(struct Node));

    new_term->type=BINARY_OR;
    new_term->lineno=tokenHead->lineno;

    new_term->child=term;
    new_term->child2=next_term;
    term=new_term;
    nextType=getType();
  }

  return term;
}

// ######################################################################

// <conditional-exp> ::= <logical-or-exp> [ "?" <exp> ":" <conditional-exp> ]
// x>y ? 1 : 0

struct Node* parse_conditional_exp()
{
    struct Node *term = parse_or_exp();
    
    if (getType() == QUESTION)
    {
        advance();
        
        struct Node *left_term=parse_exp();
        
        if (getType()!=COLON)
            fail("Expected : in ternary expression");

        advance();        

        struct Node *right_term=parse_conditional_exp();
        
        struct Node *new_term=(struct Node*)malloc(sizeof(struct Node));

        new_term->type=TERNARY;
        new_term->lineno=tokenHead->lineno;
        
        new_term->child=term;
        new_term->child2=left_term;
        new_term->child3=right_term;
        
        term=new_term;
    }

    return term;
}
    
// ######################################################################
// <exp> ::= <logical-or-exp> [ "=" <exp> ]
// (right associative)
// note: I simplified this, Nora grammar was 
// <exp> ::= <id> "=" <exp> | <logical-or-exp>
// x = y = 0

struct Node* parse_exp()
{
    struct Node *temp=parse_conditional_exp();
    struct Node *exp;

    int nextType=getType();
    if (nextType==EQUALS || (nextType >= PLUS_EQUALS && nextType <= HAT_EQUALS) 
        || nextType == LESSTHAN2_EQUAL || nextType == GREATERTHAN2_EQUAL)
    {
        advance();
        exp=(struct Node*)malloc(sizeof(struct Node));
        
        if (nextType==EQUALS)
            exp->type=ASSIGNMENT;
        else
            exp->type=nextType;

        exp->lineno=tokenHead->lineno;        
        exp->child=temp;
        exp->child2=parse_exp();
    }
    else
    {
        exp=temp;
    }
    return exp;
}

// ######################################################################

// new variable type with no qualifiers
struct Type newVartype()
{
    struct Type vt;
    vt.isConst=0;
    vt.isExtern=0;
    vt.isLong=0;
    vt.isRegister=0;
    vt.isShort=0;
    vt.isStatic=0;
    vt.isUnsigned=0;
    vt.isVolatile=0;
    vt.isInline=0;
    
    return vt;
}

/*
given a set of qualifiers, quals, find as many of these as
possible in the Token sequence until we come to some other Token.
Insert them into varType
Advance tokenHead
*/

struct Type getBaseType()
{
    struct Type vt=newVartype();
        
    while (1)
    {
        int type = getType();
        printf("type=%s\n",names[type]);
        
        if (type==CONST)
            vt.isConst=1;
        else if (type==EXTERN)
            vt.isExtern=1;
        else if (type==LONG)
            vt.isLong=1;
        else if (type==REGISTER)
            vt.isRegister=1;
        else if (type==SHORT)
            vt.isShort=1;
        else if (type==STATIC)
            vt.isStatic=1;
        else if (type==UNSIGNED)
            vt.isUnsigned=1;
        else if (type==VOLATILE)
            vt.isVolatile=1;
        else if (type==INLINE)
            vt.isInline=1;
        else
            break;  // no more
        
        advance();
    }

    // case where int is possibly ommited: short, short int, long, unsigned, long double etc
    if (vt.isUnsigned || vt.isLong || vt.isShort)
    {
        if (getType()==INT_DECLARATION)
        {
            strcpy(vt.data, "int");
            advance();
        }
        else if (getType()==CHAR_DECLARATION)
        {
            strcpy(vt.data, "char");
            advance();
        }
        else if (getType()==FLOAT_DECLARATION)
        {
            strcpy(vt.data, "float");
            advance();
        }
        else if (getType()==DOUBLE_DECLARATION)
        {
            strcpy(vt.data, "double");
            advance();
        }
        else // must be int but "int" ommitted, don't advance
            strcpy(vt.data, "int");
    }
    else // general case, no relevant qualifiers. "int" must be specified if variable is an int
    {
        if (getType()==INT_DECLARATION)
            strcpy(vt.data, "int");
        else if (getType()==CHAR_DECLARATION)
            strcpy(vt.data, "char");
        else if (getType()==VOID_DECLARATION)
            strcpy(vt.data, "void");
        else if (getType()==FLOAT_DECLARATION)
            strcpy(vt.data, "float");
        else if (getType()==DOUBLE_DECLARATION)
            strcpy(vt.data, "double");
        else if (getType()==STRUCT)
        {
             strcpy(vt.data, "struct ");
             advance();
             strcat(vt.data, tokenHead->id);
        }
        else if (getType()==UNION)
        {
             strcpy(vt.data, "union ");
             advance();
             strcat(vt.data, tokenHead->id);
        }
        else if (getType()==ENUM)  // enum is just int
        {
            strcpy(vt.data, "int");
            advance();  // ignore enum type it's just an int
        }
        else
        {
            // must be typedef
            vt = getTypedef(tokenHead->id); // will fail if not found
        }

        advance();
    }
    
    return vt;
}

void addPointerDecn(char *data)
{
    while (getType()==ASTERISK)
    {
        strcat(data,"*");
        advance();
    }        
}

void addArrayDecn(char *data)
{
    while (getType()==OPEN_SQUARE)
    {
        strcat(data,"[");
        advance();
        while(getType()!=CLOSE_SQUARE)
        {            
            strcat(data,tokenHead->id);
            advance();
        }
        strcat(data,"]");
        advance();
    }
}
void addInit(struct Node *decl)
{
    if (getType()==EQUALS){
      advance();
      if (getType()==OPEN_BRACE)
      {
          advance();
          int n=countInit();
          struct Node* block=(struct Node*)malloc(sizeof(struct Node));
          block->type=BLOCK;
          block->lineno=tokenHead->lineno;

          block->nlines=n;
          block->line=(struct Node**)malloc(n*sizeof(struct Node*));
          
          int i;
          for (i=0; i<n; i++)
          {
            block->line[i]=parse_exp();
            if (getType()==COMMA) advance();
          }
        
          decl->child=block;
          
          if (getType()!=CLOSE_BRACE) fail("Expected }");
          advance();
      }
      else
        decl->child=parse_exp();
    }
    else
      decl->child=NULL;
}

// const int **foo[3][4];
// struct Foo foo;
// enum Colour c;
// PNumber p;  << typedef
// int foo(int a) << FUNCTION: get "int foo", ARG get "int a"
// (unsigned int)x << CAST
// sizeof (int)
// type can be DECL, GLOBAL, 
// ARG, FUNCTION, PROTOTYPE (in which case don't advance past ;)
// SIZEOF, CAST (don't read id or advance past ;)

struct Node* parse_decl(int type)
{
  struct Node *decl=(struct Node*)malloc(sizeof(struct Node));

    decl->type=type;
    decl->lineno=tokenHead->lineno;

    decl->varType = getBaseType(); // unsigned int
    
    addPointerDecn(decl->varType.data); // unsigned int **

    decl->id=NULL;
    if (type != SIZEOF && type != CAST)
    {
        if (getType()==IDENTIFIER)  // identifier optional for prototype args
        {
            decl->id=newStr(tokenHead->id);  // foo
            advance();
        }
        else
            decl->id=NULL;
    }

    addArrayDecn(decl->varType.data);    // unsigned int **[3][4]
    
    addInit(decl);

    if (type == DECL || type == GLOBAL)
    {
        if (getType()!=SEMICOLON) fail("Expected ; in DECL");
        advance();
    }

    return decl;
}

// ######################################################################
// count number of items in an init group eg int i=1, *j[3], k[]={1,2,3};
int countDeclGroup()
{
  struct Token *p=tokenHead;

  int nInit=1;
  int level=0;
  while(!(p->type==SEMICOLON && level==0))
  {
      if (p->type==OPEN_BRACE)
          level++;
      
      if (p->type==CLOSE_BRACE)
          level--;
            
    if (p->type==COMMA && level==0)
      nInit++;

    p=p->next;
  }
  return nInit;
}

// ######################################################################
// unsigned int i=1, *j[3];
// struct Foo f;
// struct Foo {} f;
// type can be DECLGROUP or GLOBALGROUP

int isStructOrUnion(struct Type t);
struct Node* parse_struct();

struct Node* parse_decl_group(int type, int n)
{
    struct Node *group=(struct Node*)malloc(sizeof(struct Node));
    group->type=type;
    group->lineno=tokenHead->lineno;

    struct Token* tok = tokenHead;
    struct Type baseType=getBaseType(); // unsigned int; struct Foo

    int subtype, st;
    if (type==DECLGROUP)
        subtype=DECL;
    else if (type==GLOBALGROUP)
        subtype=GLOBAL;
    else
        fail("unexpected DECLGROUP type");
        
    if (tok->type==STRUCT && tokenHead->type==OPEN_BRACE)
    {
        tokenHead=tok; // rewind
        st=1;
        n++;
        printf("basetype is struct %d %d\n", st, n);
    }
    else
        st=0;
        
    printf("found declgroup with %d entries\n", n);    
        
    group->nlines = n;
    group->line=(struct Node**)malloc(n*sizeof(struct Node*));

    if (st==1)
        group->line[0]=parse_struct();
   
    int i;
    for (i=st;i<n;i++)
    {
        struct Node *decl=(struct Node*)malloc(sizeof(struct Node));
        decl->type=subtype;
        decl->lineno=tokenHead->lineno;
        decl->varType = baseType;

        addPointerDecn(decl->varType.data);  // unsigned int*
                
        decl->id=newStr(tokenHead->id);  // j
        advance();

        addArrayDecn(decl->varType.data);  // unsigned int*[3]

        addInit(decl);
      
        group->line[i]=decl;
        
        if (getType()==COMMA)
            advance();                
    }

    if (getType()!=SEMICOLON) fail("Expected ; in DECLGROUP");
    advance();    
    
    return group;
}

// ######################################################################
// typedef Number* PNumber;
struct Node* parse_typedef()
{
    advance();

    struct Node* declNode;
    int n=countDeclGroup();
    int i;

    if (1)
    {
       declNode = parse_decl_group(DECLGROUP,n);
       declNode->type = TYPEDEFGROUP;
       for (i=0;i<declNode->nlines;i++)
           // ignore struct in typedef struct Foo {int x,y;} z;
           if (declNode->line[i]->type != STRUCT)
             addTypedef(declNode->line[i]->id, declNode->line[i]->varType);
    }
    else
    {
        declNode = parse_decl(DECL);
        declNode->type=TYPEDEF;
        addTypedef(declNode->id, declNode->varType);
    }
        
    return declNode;
}

// ######################################################################
// enum Colour {RED=0,BLACK};

struct Node* parse_enum()
{
    struct Node *en=(struct Node*)malloc(sizeof(struct Node));
    en->type=ENUM;
    en->lineno=tokenHead->lineno;
    
    advance();
    
    if (getType()==IDENTIFIER) advance();
    
    if (getType()!=OPEN_BRACE)
    {
        fail("Expected { at beginning of enum");
        exit(1);
    }

    advance();
    
    struct Token *p=tokenHead;
    int n=1;
    while(p->type!=CLOSE_BRACE)
    {
        if (p->type==COMMA) n++;
        p=p->next;
    }

    printf("Found enum with %d entries\n", n);
    
    en->nlines=n;
    en->line=(struct Node**)malloc(n*sizeof(struct Node*));

    int i;
    int ind=0;
    for (i=0; i<n; i++)
    {        
        en->line[i]=parse_exp();

        if (en->line[i]->type==ASSIGNMENT)  // RED=0
        {
            char *endptr = NULL;
            ind = strtol(en->line[i]->child2->id, &endptr, 0); // 0
            addEnumConst(en->line[i]->child->id, ind); // RED, 0
        }
        else  // BLACK
            addEnumConst(en->line[i]->id, ind);

        if (getType()==COMMA) advance();
        ind++;
    }
    
    if (getType()!=CLOSE_BRACE)
        fail("Expeced } at end of enum");
    
    advance();

    if (getType()!=SEMICOLON)
        fail("Expeced ; at end of enum");
    
    advance();
    
    return en;    
}

// ######################################################################
// struct/union Foo {int x; int y;};
// doesn't advance past final ;

int countStructLines()
{
  struct Token *p=tokenHead;

  int n=0;
  int level=0;
  while(1)
  {
      if (p->type==OPEN_BRACE)
          level++;
      
      if (p->type==CLOSE_BRACE)
      {
          level--;
          if (level<0) break;
      }
            
    if (p->type==SEMICOLON && level==0)
      n++;

    p=p->next;
  }
  return n;
}

struct Node* parse_struct()
{
    struct Node *str=(struct Node*)malloc(sizeof(struct Node));
    str->type=tokenHead->type;
    str->lineno=tokenHead->lineno;

    advance();

    if (getType()!=IDENTIFIER)
        fail("Expected struct tag");
    
    str->id=newStr(tokenHead->id);
    advance();

    if (getType()!=OPEN_BRACE)
    {
        fail("Expected { at beginning of struct");
    }

    advance();

    int n=countStructLines();
    printf("Found struct with %d lines\n", n);

    str->nlines=n;
    str->line=(struct Node**)malloc(n*sizeof(struct Node*));
    
    int i;
    for (i=0; i<n; i++)
    {   
        int m=countDeclGroup();
        if (1)
            str->line[i]=parse_decl_group(DECLGROUP,m);
        else
            str->line[i]=parse_decl(DECL);
    }

    if (getType()!=CLOSE_BRACE)
    {
        fail("Expected } at end of struct");
        exit(1);
    }
    advance();
    
    // don't advance over semi-colon as parse_decl_group may call this function
    
    return str;
}
    
// ######################################################################

// struct Foo {}; -> true
// struct Foo f; -> false
// struct Foo {} f; -> false
int isStructDef(struct Token* tok)
{
    if (tok->type==STRUCT)
    {
        tok=tok->next;
        if (tok->type == IDENTIFIER) tok=tok->next;
        if (tok->type == OPEN_BRACE)
        {
            tok=tok->next; // after the {

            int nlevel=0;
            while(1)
            {
                if (tok->type==OPEN_BRACE){
                  nlevel++;
                }

                if (tok->type==CLOSE_BRACE){
                  nlevel--;
                  if (nlevel<0) break;
                }

                tok=tok->next;
            }
            if (tok->next->type==SEMICOLON) return 1;
        }
    }
    return 0;
}
    
// return 2;
struct Node* parse_statement()
{
  struct Node *statement=(struct Node*)malloc(sizeof(struct Node));
  statement->lineno=tokenHead->lineno;

  if (getType()==IF){
    statement->type=IF;
    advance();
    
    if (getType()!=OPEN_BRACKET) fail("Expected ( in IF");
    advance();

    statement->child=parse_exp();

    if (getType()!=CLOSE_BRACKET) fail("Expected ) in IF");
    advance();

    statement->child2=parse_statement();

    if (getType()==ELSE){
      advance();
      statement->child3=parse_statement();
    }
    else
      statement->child3=NULL;
  }
  else if (getType()==WHILE){
    statement->type=WHILE;
    advance();
    
    if (getType()!=OPEN_BRACKET) fail("Expected ( in WHILE");
    advance();

    statement->child=parse_exp();

    if (getType()!=CLOSE_BRACKET) fail("Expected ) in WHILE");
    advance();

    statement->child2=parse_statement();
  }
  else if (getType()==SWITCH)
  {
    statement->type=SWITCH;
    advance();
    
    if (getType()!=OPEN_BRACKET) fail("Expected ( in SWITCH");
    advance();

    statement->child=parse_exp();

    if (getType()!=CLOSE_BRACKET) fail("Expected ) in SWITCH");
    advance();

    statement->child2=parse_statement();
  }
  else if (getType()==FOR){
    statement->type=FOR;
    advance();
    
    if (getType()!=OPEN_BRACKET) fail("Expected ( in FOR");
    advance();

    statement->child=parse_exp();

    if (getType()!=SEMICOLON) fail("Expected ; in FOR");
    advance();

    statement->child2=parse_exp();

    if (getType()!=SEMICOLON) fail("Expected ; in FOR");
    advance();

    statement->child3=parse_exp();

    if (getType()!=CLOSE_BRACKET) fail("Expected ) in FOR");
    advance();

    statement->child4=parse_statement();
  }
  else if (getType()==DO){
    statement->type=DO;
    advance();

    statement->child=parse_statement();
    
    if (getType()!=WHILE) fail("Expected WHILE");
    advance();

    if (getType()!=OPEN_BRACKET) fail("Expected ( in WHILE");
    advance();

    statement->child2=parse_exp();

    if (getType()!=CLOSE_BRACKET) fail("Expected ) in WHILE");
    advance();

    if (getType()!=SEMICOLON) fail("Expected ;");
    advance();
  }
  else if (getType()==OPEN_BRACE){
    statement->type=BLOCK;
    advance();
    statement->nlines=countLines(NULL);

    statement->line=(struct Node**)malloc((statement->nlines)*sizeof(struct Node*));
    int i;
    for (i=0; i<statement->nlines; i++)
      statement->line[i]=parse_statement();  // removes return 2;
    
    if (getType()!=CLOSE_BRACE) fail("Expected }");
    advance();
  }
  else if (getType()==RETURN){
    statement->type=RETURN;
    advance();
    
    statement->child=parse_exp();  // removes 2
    
    if (getType()!=SEMICOLON) fail("Expected ;");
    advance();
  }
  else if(isStructDef(tokenHead))  // struct/union Foo{int x; int y;};
  {
      statement = parse_struct();
      advance();
  }

  else if (getType()==GOTO)
  {
      printf("goto\n");
      statement->type=GOTO;
      advance();
      statement->id=tokenHead->id;
      statement->child=NULL;
      advance();
      if (getType()!=SEMICOLON) fail("Expected ;");
      advance();      
  }
  
  else if (getType()==IDENTIFIER && tokenHead->next->type==COLON)  // LABEL foo:
  {
      statement->type=LABEL;
      statement->id = tokenHead->id;
      statement->child=NULL;
      advance();
      advance();
  }
  else if (getType()==CASE)
  {
      statement->type=CASE;
      advance();
      statement->id=tokenHead->id;

      if (tokenHead->type==CHAR_LITERAL) 
          strcpy(statement->varType.data,"char");
      else if (tokenHead->type==INT_LITERAL)
          strcpy(statement->varType.data,"int");
      else
          fail("CASE constant must be char or int");
      
      statement->child=NULL;
      advance();
      if (getType()!=COLON) fail("Expected : in CASE");
      advance();
  }
  else if (getType()==DEFAULT)
  {
      statement->type=DEFAULT;
      statement->child=NULL;
      advance();
      if (getType()!=COLON) fail("Expected : after DEFAULT");
      advance();
  }
  else if (isTypeDec(tokenHead))  // int x; struct Foo f; (already ruled out struct Foo {};)
  {
      int n=countDeclGroup();
      if (1)
          return parse_decl_group(DECLGROUP,n);
      else
          return parse_decl(DECL);
  }
  else if(getType()==BREAK)
  {
      advance();
      statement->type=BREAK;
      statement->child=NULL;
      
      if (getType()!=SEMICOLON) fail("Expected ; after BREAK");
      advance();      
  }
  else if(getType()==CONTINUE)
  {
      advance();
      statement->type=CONTINUE;
      statement->child=NULL;
      
      if (getType()!=SEMICOLON) fail("Expected ; after CONTINUE");
      advance();      
  }
  else
  {
    statement->type=EXPR;    
    statement->child=parse_exp();  // removes 2
    
    if (getType()!=SEMICOLON) fail("Expected ; after EXPR");
    advance();
  }
  return statement;
}

// ######################################################################

struct Node* parse_arg()
{
    if (getType()==DOT3)
    {
        advance();
        struct Node *arg=(struct Node*)malloc(sizeof(struct Node));
        arg->type=ARG;
        arg->lineno=tokenHead->lineno;
        arg->id=newStr("...");
        strcpy(arg->varType.data, "...");
        arg->child=NULL;
        return arg;
    }
    return parse_decl(ARG);
}

// ######################################################################

struct Node* parse_function()
{
  struct Node* function=parse_decl(FUNCTION);

  if (getType()!=OPEN_BRACKET) fail("Expected (");
  advance();

  int ntot=countArgsAndLines();
  int nargs=countArgs();
  function->nlines=ntot;

  printf("found %d args and %d statements in function\n", nargs, ntot-nargs);

  function->line=(struct Node**)malloc(ntot*sizeof(struct Node*));

  int i;
  for (i=0;i<nargs;i++){
    function->line[i]=parse_arg();
    if (i<nargs-1){
      if (getType()!=COMMA) fail("expected ,");
      advance();
    }
  }

  if (getType()!=CLOSE_BRACKET) fail("Expected ) after function args");
  advance();

  if (getType()!=OPEN_BRACE) fail("Expected {");
  advance();

  for (i=nargs; i < ntot; i++)
    function->line[i]=parse_statement();  // removes return 2;

  if (getType()!=CLOSE_BRACE) fail("Expected }");
  advance();

  return function;
}

// ######################################################################

struct Node* parse_prototype()
{
  /*
  if (getType()!=INT_DECLARATION) fail("Expected return type");
  advance();

  if (getType()!=IDENTIFIER) fail("Expected function name");
  struct Node *node=(struct Node*)malloc(sizeof(struct Node));
  node->type=PROTOTYPE;
  node->id=newStr(tokenHead->id);
  advance();
  */
  
  struct Node *node=parse_decl(PROTOTYPE);
  
  if (getType()!=OPEN_BRACKET) fail("Expected (");
  advance();

  int nargs=countArgs();
  node->nlines=nargs;

  printf("found %d args in prototype\n", nargs);

  node->line=(struct Node**)malloc(nargs*sizeof(struct Node*));

  int i;
  for (i=0;i<nargs;i++){
    node->line[i]=parse_arg();
    if (i<nargs-1){
      if (getType()!=COMMA) fail("expected ,");
      advance();
    }
  }

  if (getType()!=CLOSE_BRACKET) fail("Expected ) at end of prototype");
  advance();

  if (getType()!=SEMICOLON) fail("Expected ;");
  advance();

  return node;
}

// ######################################################################

struct Node* parse_global()
{
    int n=countDeclGroup();
    printf("parse_global found %d\n",n);
    if (1)
      return parse_decl_group(GLOBALGROUP,n);
    else
      return parse_decl(GLOBAL);
}

// ######################################################################

/*
int foo;
int foo();
int foo(){}
struct Foo{};
struct Foo f;
struct Foo {} f;
enum Foo {};
typedef int Number;
*/

int countGlobals()
{
    int count=0;
    int level=0;
    struct Token *p=tokenHead;
    struct Token *prev=p;

    while (p!=NULL)
    {
        if (p->type==OPEN_BRACE)
        {
            if (level==0 && prev->type==CLOSE_BRACKET) count++;
            level++;
        }

        if (p->type==CLOSE_BRACE)
            level--;

        if (level==0 && p->type==SEMICOLON)
            count++;

        prev=p;
        p=p->next;
    }
    if (level!=0) fail("Mismatched braces");
    return count;
}

// ######################################################################
// The whole program

struct Node* parse_program()
{
  struct Node *program=(struct Node*)malloc(sizeof(struct Node));
  program->type=PROGRAM;
  program->lineno=tokenHead->lineno;

  int n=countGlobals();
  
  printf("Found %d global objects in program\n",n);
  
  program->nlines=n;
  program->line=(struct Node**)malloc(n*sizeof(struct Node*));

  // int foo();
  // int foo(){}
  // int foo;
  // int foo=2;
  // struct Foo {int x; int y;};
  // struct Foo {int x; int y;} f;
  // struct Foo f;
  // enum Colour {RED, BLACK};
  // enum Colour c;
  // typedef int Number;

  int i;
  for (i=0; i<n; i++)
  {
    if (isStructDef(tokenHead)) // struct/union Foo {int x; int y;};
    {
        program->line[i]=parse_struct();
        advance();
    }
    else if (getType()==ENUM && (tokenHead->next->next->type==OPEN_BRACE || tokenHead->next->type==OPEN_BRACE)) // enum Colour {RED, BLACK};
    {
        program->line[i]=parse_enum();
    }
    else if (getType()==TYPEDEF)
    {
        program->line[i]=parse_typedef();
    }
    else if (!isProtoOrFunc())   // int foo=2; struct Foo f; struct Foo {} f;
    {
      program->line[i]=parse_global();
    }
    else
    {
      struct Token *p=tokenHead;
      while(p->type!=CLOSE_BRACKET)
      {
          if (p==NULL) fail("unexpected end of file");
             p=p->next;
      }
      p=p->next;
      if (p->type==SEMICOLON)
	     program->line[i]=parse_prototype();    // int foo();
      else
	     program->line[i]=parse_function();     // int foo(){}
    }
  }

  return program;
}

// ######################################################################
// Starting at st, read past white space and get next token.
// Allocate and return a token struct. Return ed, pointer to where we got to
// Return NULL if nothing left
// Maintain lineno (global). If line begins with #, skip past it and pay attention to lineno (from preprocessor)
// each token returned has a lineno

struct Token* getTok(char *st, char **ed)
{
  int i,j;
  char linestr[64];
  char *endptr = NULL;
  char *line1;

  int lenleft=strlen(st);
  if (*st=='\0' || lenleft==0) return NULL;

  while (isspace(*st) || *st=='#')
  {
      if (*st=='\0') 
          return NULL;
      else if (*st=='#')
      {
          st += 2;
          line1=st;
          while(*st!='\n')
          {
              st++;
          }

          int len=st-line1;          
          memcpy(linestr, line1, len);
          linestr[len]='\0';
          if (linestr[len-1]=='\r') linestr[len-1]='\0';
//          printf("linestr=[%s]", linestr);
          
          lineno = strtol(strtok(linestr, " "), &endptr, 0);          
//          printf(" %d\n", lineno);
      }
      else if (*st == '\n') 
      {
          lineno++;
//          printf("lineno=%d\n",lineno);
      }

      st++;
  }

  struct Token *tok=(struct Token*) malloc(sizeof (struct Token));
  tok->next=NULL;
  tok->id=NULL;

  for (j=0;j<numToks;j++)
  {
    int lentok=strlen(tokNames[j]);
    if (lentok>=lenleft) continue;
    int puncTok=j<RETURN;
    int good=1;
    for (i=0;i<lentok;i++)
    {
      if (*(st+i)!=tokNames[j][i])
      {
        good=0;
        break;
      }
    }
    if (good && (puncTok || !(isalnum(*(st+lentok)) || *(st + lentok) == '_')))
    {
      *ed=st+lentok;
      tok->type=j;
      tok->lineno = lineno;
      return tok;
    }
  }

  if (*st=='"')
  {
    st++;
    char *p=st;
    while(*p!='\0')
    {
      if (*p == '"' && !(*(p - 1) == '\\' && *(p - 2) != '\\'))
      {
        int sz=p-st;
        tok->id=(char*) malloc(sz+1);
        tok->type=STRING_LITERAL;
        memcpy(tok->id,st,sz);
        tok->id[sz]='\0';
        tok->lineno = lineno;
        *ed=p+1;
        return tok;
      }
      p++;
    }
    printf("Unexpected EOF while scanning string const\n");
    exit(1);
  }
  else if (*st=='\'')
  {
    st++;
    char *p=st;
    while(*p!='\0')
    {
      if (*p == '\'' && !(*(p - 1) == '\\' && *(p - 2) != '\\'))
      {
        int sz=p-st;
        tok->id=(char*) malloc(sz+1);
        tok->type=CHAR_LITERAL;
        memcpy(tok->id,st,sz);
        tok->id[sz]='\0';
        tok->lineno = lineno;
        *ed=p+1;
        return tok;
      }
      p++;
    }
    printf("Unexpected EOF while scanning char const\n");
    exit(1);
  }
  else
  {
    int idOK=isalpha(*st) || *st=='_';
    int literalOK=isdigit(*st);
    int floatOK=isdigit(*st);
    char *p=st;

    while(*p!='\0')
    {
      if (!isalnum(*p) && *p != '_' && !(floatOK && *p=='.')) // end of literal or identifier
      {   // found punctuation, space, \0 or . which is not in a float
	
        if (idOK)
        {
          *ed=p;
          tok->type=IDENTIFIER;
          int sz=*ed-st;
          tok->id=(char*) malloc(sz+1);
          memcpy(tok->id,st,sz);
          tok->id[sz]='\0';
          tok->lineno = lineno;
          return tok;
        }
	
        if (literalOK)
        {
          *ed=p;
          tok->type=INT_LITERAL;
          int sz=*ed-st;
          tok->id=(char*) malloc(sz+1);
          memcpy(tok->id,st,sz);
          tok->id[sz]='\0';
          tok->lineno = lineno;
          return tok;
        }

        if (floatOK)
        {
          *ed=p;
          tok->type=FLOAT_LITERAL;
          int sz=*ed-st;
          tok->id=(char*) malloc(sz+1);
          memcpy(tok->id,st,sz);
          tok->id[sz]='\0';
          tok->lineno = lineno;
          return tok;
        }

	
        printf("Lexer: Unknown token: ");
        char *q;
        for (q=st; q<=p; q++) printf("%c", *q);
        printf("\n");
        exit(1);
      }

      if (!isalnum(*p) && *p != '_')
        idOK=0;
      
      if (!isdigit(*p))
        literalOK=0;
    
      if (!isdigit(*p) && *p!='.' && *p!='e')
          floatOK=0;

      p++;
    }
  }

  printf("nothing left\n");
  free(tok);
  return NULL;
}

// ######################################################################

void writeQuals(struct Type varType, FILE *fp)
{
    if (varType.isConst) fprintf(fp," CONST");
    if (varType.isExtern) fprintf(fp," EXTERN");
    if (varType.isLong) fprintf(fp," LONG");
    if (varType.isRegister) fprintf(fp," REGISTER");
    if (varType.isShort) fprintf(fp," SHORT");
    if (varType.isStatic) fprintf(fp," STATIC");
    if (varType.isUnsigned) fprintf(fp," UNSIGNED");
    if (varType.isVolatile) fprintf(fp," VOLATILE");
    if (varType.isInline) fprintf(fp," INLINE");
    fprintf(fp,"\n");
}

void writeTree(struct Node *node, int indent)
{
  int i;
  for (i=0;i<indent;i++)
    printf(" ");

  printf("%s",names[node->type]);

  int nodetype=node->type;

  if (nodetype==DECL || nodetype==FUNCTION || nodetype==PROTOTYPE || nodetype==ARG 
   || nodetype==GLOBAL || nodetype==TYPEDEF || nodetype==CASE)
  {
    if (node->id==NULL)
        printf(": [%s]", node->varType.data);
    else
        printf(": '%s' [%s]",node->id, node->varType.data);

    writeQuals(node->varType, stdout);    
  }
  else if (nodetype==INT_LITERAL || nodetype==FLOAT_LITERAL ||
      nodetype==VAR || nodetype==CALL || 
      nodetype==STRING_LITERAL || nodetype==CHAR_LITERAL || nodetype==STRUCT || nodetype==UNION || nodetype==LABEL || nodetype==GOTO)
    printf(": '%s'\n",node->id);
  else if (nodetype==SIZEOF || nodetype==CAST)
    printf(": [%s]\n",node->varType.data);
  else 
    printf("\n");

  // children if any...

  if (nodetype==ASSIGNMENT || (nodetype >= PLUS_EQUALS && nodetype <= HAT_EQUALS))
  {
      writeTree(node->child,indent+3);      
      writeTree(node->child2,indent+3);
  }
  else if (nodetype==INDEX || nodetype==DOT || nodetype==ARROW)
  {
      writeTree(node->child,indent+3);      
      writeTree(node->child2,indent+3);
  }
  else if (nodetype==WHILE){
    writeTree(node->child,indent+3);
    writeTree(node->child2,indent+3);    
  }
  else if (nodetype==SWITCH){
    writeTree(node->child,indent+3);
    writeTree(node->child2,indent+3);    
  }
  else if (nodetype==DO){
    writeTree(node->child,indent+3);
    writeTree(node->child2,indent+3);    
  }
  else if (nodetype==FOR){
    writeTree(node->child,indent+3);
    writeTree(node->child2,indent+3);    
    writeTree(node->child3,indent+3);    
    writeTree(node->child4,indent+3);    
  }
  else if (nodetype==IF){
    writeTree(node->child,indent+3);
    writeTree(node->child2,indent+3);    
    if (node->child3!=NULL) writeTree(node->child3,indent+3);
  }
  else if (nodetype==TERNARY){
    writeTree(node->child,indent+3);
    writeTree(node->child2,indent+3);    
    writeTree(node->child3,indent+3);
  }  
  else if (nodetype==EXPR ||
      nodetype==RETURN || 
      nodetype==UNARY_MINUS ||
      nodetype==UNARY_PLUS ||
      nodetype==UNARY_COMPLEMENT ||
      nodetype==UNARY_NOT ||
      nodetype==DEREF || nodetype==ADDRESS || nodetype==INC || nodetype==DEC ||
      nodetype==INC_AFTER || nodetype==DEC_AFTER || nodetype==CAST)
  {    
    writeTree(node->child,indent+3);
  }
  else if (nodetype==BINARY_PLUS ||
	   nodetype==BINARY_MINUS ||
	   nodetype==BINARY_TIMES ||
	   nodetype==BINARY_DIVIDE ||
	   nodetype==BINARY_MODULO ||
	   nodetype==BINARY_LESS_THAN ||
	   nodetype==BINARY_LESS_THAN_OR_EQUAL ||
	   nodetype==BINARY_GREATER_THAN ||
	   nodetype==BINARY_GREATER_THAN_OR_EQUAL ||
	   nodetype==BINARY_EQUAL ||
	   nodetype==BINARY_NOT_EQUAL ||
	   nodetype==BINARY_AND ||
	   nodetype==BINARY_OR ||
	   nodetype==BINARY_BITWISE_AND ||
	   nodetype==BINARY_BITWISE_OR ||
  	   nodetype==BINARY_BITWISE_XOR ||
       nodetype==BINARY_LEFT_SHIFT ||
       nodetype==BINARY_RIGHT_SHIFT)
  {
    writeTree(node->child,indent+3);
    writeTree(node->child2,indent+3);
  }
  else if (nodetype==FUNCTION || nodetype==PROTOTYPE || nodetype==BLOCK || nodetype==CALL ||
           nodetype==PROGRAM || nodetype==STRUCT || nodetype==UNION || nodetype==ENUM 
           || nodetype==DECLGROUP || nodetype==GLOBALGROUP || nodetype==TYPEDEFGROUP)
  {
    int i;
    for (i=0; i < node->nlines; i++)
    {
      writeTree(node->line[i],indent+3);
    }
  }
  else if (nodetype==INT_LITERAL || nodetype==FLOAT_LITERAL || nodetype==CASE)
  {
  }
  else if (nodetype==VAR)
  {
  }
  else if (nodetype==ARG)
  {
  }
  else if (nodetype==STRING_LITERAL)
  {
  }
  else if (nodetype==CHAR_LITERAL)
  {
  }
  else if (nodetype==PROTOTYPE)
  {
  }
  else if (nodetype==BREAK || nodetype==CONTINUE || nodetype==LABEL || nodetype==GOTO || nodetype==DEFAULT)
  {
  }
  else if (nodetype==SIZEOF)
  {
  }
  else if (nodetype==DECL || nodetype==GLOBAL || nodetype==TYPEDEF)
  {
    if (node->child!=NULL) writeTree(node->child,indent+3);
  }
  else
  {
    printf("Internal compiler error: illegal nodetype (writeTree). Got %d\n",nodetype);
    exit(1);
  }
}

// ######################################################################

void writeVars()
{
  struct Var *p=varEnd;

  fprintf(fps,"# =========================================\n");
  while(p!=NULL)
  {
    fprintf(fps,"# %s l=%d o=%d [%s] %s", p->id, p->level, p->offset, p->varType.data, 
        (p->isArg) ? "ARG" : "");
    writeQuals(p->varType,fps);
    p=p->prev;
  }  
  fprintf(fps,"# =========================================\n");
}

// ######################################################################
// helper routines for writeAsm

// t="foo", c='o', return true
int endsWith(char* t, char c)
{
    int l=strlen(t);
    return t[l-1]==c;
}

// t="foo", s="oo", return true
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

// 0123456789
// int*[3][6] -> open={4,7} close={6,9}, return 2 (dimension of array or 0)
int getArray(char* t, int open[], int close[])
{
    int l=strlen(t);

    int i, ind=0;

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

// int*[3][6] -> 3*6*4 bytes
// struct Point p[3][6]
int sizeOf(struct Type t, struct Node* node)
{
//    printf("sizeOf '%s' requested. Lineno %d\n",t.data, node->lineno);
    if (strcmp(t.data,"void")==0)
    {
        printf("Cannot take sizeof void\n");
        exit(1);
    }
    
    if (strlen(t.data)==0) return 0;  // For Structs put on the stack (no type)
    
    int i, j, n;
    int open[10], close[10];
    
    n = getArray(t.data, open, close);
 
    int nElem=1,st,len;
    char index[16];    
    char* endptr = NULL;
    for (i=0; i<n; i++)
    {        
        st=open[i]+1; len=close[i]-1-st+1;
        memcpy(index, t.data+st, len);
        index[len]='\0';

        if (strlen(index)==0)
        {
            printf("[%s]\n",index);
            asmFail("Empty array index", node);
        }
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
    else if (strcmp(s.data, "int") == 0 || strcmp(s.data, "float")==0)
        return 4*nElem;
    else if (strcmp(s.data, "char") == 0)
        return nElem;
    else if (startsWith(s.data, "struct") || startsWith(s.data, "union"))
    {
        struct Var *p=varEnd;
        struct Node* structNode;
        int found=0;
        int sz;
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

        // TODO make this double loop since line[i] is DECLGROUP
        int tot=0;
        for (i=0; i < structNode->nlines; i++)
        {
            if (structNode->line[i]->type==DECL)
            {
                sz = sizeOf(structNode->line[i]->varType, node);
                if (startsWith(s.data,"struct"))
                    tot += sz;
                else
                    tot = (sz > tot) ? sz : tot;
            }
            else if (structNode->line[i]->type==DECLGROUP) // DECLGROUP
            {
                for (j=0;j<structNode->line[i]->nlines;j++)
                {
                    sz = sizeOf(structNode->line[i]->line[j]->varType, node);
                    if (startsWith(s.data,"struct"))
                        tot += sz;
                    else
                        tot = (sz > tot) ? sz : tot;                    
                }
            }
                
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

int isArray(struct Type t)
{
    int n;
    int open[10], close[10];
    
    n = getArray(t.data, open, close);
    return n!=0;
}

int isStruct(struct Type t)
{
    return startsWith(t.data, "struct") && !isArray(t) && !isPointer(t);
}

int isUnion(struct Type t)
{
    return startsWith(t.data, "union") && !isArray(t) && !isPointer(t);
}

int isStructOrUnion(struct Type t)
{
    return isStruct(t) || isUnion(t);
}

// int** -> int*
struct Type removePointer(struct Type t)
{
    if (!isPointer(t))
    {
        printf("Can't removePointer if not pointer %s\n", t.data);
        exit(1);
    }
    
    // int*
    struct Type s;
    s=t;
    int l=strlen(s.data);
    s.data[l-1]='\0';
    return s;
}

// int* -> int**
struct Type addPointer(struct Type t)
{
    struct Type s;
    s = t;
    strcat(s.data, "*");
    return s;
}

// int[2][3] -> int[3]
struct Type removeArray(struct Type t)
{
    int open[10], close[10];
    int n = getArray(t.data, open, close);
    if (n==0) return t;
    
    struct Type s = t;
    s.data[open[0]]='\0';
    
    char ind[16];
    int i, st, len;
    for (i=1;i<n;i++)
    {
        st=open[i]; len=close[i]-st+1;
        memcpy(ind, t.data+st, len);
        ind[len]='\0';
        strcat(s.data, ind);
    }
    return s;
}

int isInt(struct Type t)
{
    return strcmp(t.data,"int")==0;
}

int isChar(struct Type t)
{
    return strcmp(t.data,"char")==0;
}

int isFloat(struct Type t)
{
    return strcmp(t.data,"float")==0;
}


// not void*. Should only occur for empty arg list int foo(void){}
int isVoid(struct Type t)
{
    return strcmp(t.data,"void")==0;
}


struct Type writeBinOp(char* op, struct Type type1, struct Type type2, struct Node* node)
{
    if (type1.isUnsigned+type2.isUnsigned == 1)
        asmFail("Binary operation between signed and unsigned",node);
    
    struct Type varType=newVartype();

    if (isFloat(type1) && isFloat(type2))
    {
        fprintf(fps,"push ecx\n");
        fprintf(fps,"push eax\n");
        fprintf(fps,"call _f%s\n",op);
        fprintf(fps,"pop ecx\n");  // don't use add esp as this messes up the flags
        fprintf(fps,"pop ecx\n");
        varType=type1;
//        strcpy(varType.data,"float");
    }
    else if (isFloat(type1) && isInt(type2))
    {
        fprintf(fps,"push eax\n"); // the float
        fprintf(fps,"push ecx\n");  // function arg, the int
        fprintf(fps,"call _int2float\n"); // result in eax now float
        fprintf(fps,"add esp,4\n");
        fprintf(fps,"mov ecx,eax\n");
        fprintf(fps,"pop eax\n");  // orig eax
        fprintf(fps,"push ecx\n");
        fprintf(fps,"push eax\n");
        fprintf(fps,"call _f%s\n",op);
        fprintf(fps,"pop ecx\n");
        fprintf(fps,"pop ecx\n");
        varType=type1;
//        strcpy(varType.data,"float");
    }
    else if (isInt(type1) && isFloat(type2))
    {
        fprintf(fps,"push eax\n");  // function arg, the int
        fprintf(fps,"call _int2float\n"); // result in eax now float
        fprintf(fps,"add esp,4\n");
        fprintf(fps,"push ecx\n");
        fprintf(fps,"push eax\n");
        fprintf(fps,"call _f%s\n",op);
        fprintf(fps,"pop ecx\n");
        fprintf(fps,"pop ecx\n");
        varType=type2;
//        strcpy(varType.data,"float");
    }
    else if (isChar(type1) && isInt(type2))
    {
        fprintf(fps,"movzx eax,al\n");
        fprintf(fps,"%s eax,ecx\n", op);
        varType=type2;
//        strcpy(varType.data,"int");
    }
    else if (isInt(type1) && isChar(type2))
    {
        fprintf(fps,"movzx ecx,cl\n");
        fprintf(fps,"%s eax,ecx\n", op);
        varType=type1;
//        strcpy(varType.data,"int");
    }
    else if (isChar(type1) && isChar(type2))
    {
        fprintf(fps,"%s al,cl\n", op);
//        strcpy(varType.data,"char");
        varType=type1;
    }
    else if (isInt(type1) && isInt(type2))
    {
        fprintf(fps,"%s eax,ecx\n", op);
        varType=type1;
//        strcpy(varType.data,"int");
    }
    else if (strstr("add,sub", op)!=0 && isPointer(type1) && isInt(type2))
    {
        fprintf(fps, "imul ecx,%d\n",sizeOf(removePointer(type1),node));
        fprintf(fps,"%s eax,ecx\n", op);
        varType=type1;
    }
    else if (strcmp(op,"add")==0 && isInt(type1) && isPointer(type2))
    {
        fprintf(fps, "imul eax,%d\n",sizeOf(removePointer(type2),node));
        fprintf(fps,"add eax,ecx\n");
        varType=type2;
    }
    else if (strcmp(op,"sub")==0 && isPointer(type1) && isPointer(type2))
    {
        if (strcmp(type1.data, type2.data)!=0)
        {
            printf("Pointers must be identical in subtraction\n");
            exit(1);
        }

        fprintf(fps,"sub eax,ecx\n");
        fprintf(fps,"cdq\n");
        fprintf(fps,"idiv eax,%d\n", sizeOf(removePointer(type1),node));
        strcpy(varType.data,"int");
    }
    else if (strcmp(op,"cmp")==0 && isPointer(type1) && isPointer(type2))
    {
        fprintf(fps,"%s eax,ecx\n", op);
        strcpy(varType.data,"int");
    }
    else
    {
        printf("Illegal combination of types during %s [%s, %s]\n", op, type1.data, type2.data);
        asmFail("", node);
    }    
    return varType;
}

struct Type writeAsm(struct Node *node, int level, int lvalue, int loop);

void findSubStructs(struct Node *node, int level, int loop)
{
    int i;
    for (i=0; i< node->nlines; i++)
    {
        if (node->line[i]->type==DECLGROUP)
            findSubStructs(node->line[i], level, loop);
        if (node->line[i]->type==STRUCT)
            writeAsm(node->line[i],level,0,loop);
    }
}

// ######################################################################

struct Type writeAsm(struct Node *node, int level, int lvalue, int loop)
{
  static int s_label=0;
  int nodetype=node->type;
  struct Type varType=newVartype(), type1=newVartype(), type2=newVartype();
  int i;
  
  /*
  PROGRAM
  */

  if (node->type==PROGRAM){
    varEnd=NULL;
    int i;
    for (i=0; i<node->nlines; i++){
      writeAsm(node->line[i], level, 0, loop);
    }
  }
  
  else if (node->type==ENUM || node->type==TYPEDEF)
  {
  }
  
  else if (node->type==TYPEDEFGROUP)
  {
    for (i=0; i < node->nlines; i++)
    {
        if (node->line[i]->type==STRUCT)   
            writeAsm(node->line[i],level,0, loop);
    }      
  }

  /*
  GLOBALGROUP
  */
  
  else if (node->type==GLOBALGROUP)
  {
    for (i=0; i < node->nlines; i++)
    {
      writeAsm(node->line[i],level,0, loop);
    }      
  }
  
  /*
  GLOBAL
  Create data section with new global variable (also for local static)
  Add it to the variable stack
  */
  
  else if (node->type==GLOBAL || (node->type==DECL && node->varType.isStatic))
  {
    if (!node->varType.isExtern)
    {
        fprintf(fps,".data\n");

        if (node->child==NULL)
        {
            if (!node->varType.isStatic) fprintf(fps,".globl _%s\n",node->id);
            fprintf(fps,"_%s:\n",node->id);
            fprintf(fps,".skip %d\n",sizeOf(node->varType, node));
        }
        else if (node->child->type==INT_LITERAL)
        {
            if (!node->varType.isStatic) fprintf(fps,".globl _%s\n",node->id);
            fprintf(fps,"_%s:\n",node->id);
            fprintf(fps,".long %s\n",node->child->id);
        }
        else if (node->child->type==FLOAT_LITERAL)
        {
            if (!node->varType.isStatic) fprintf(fps,".globl _%s\n",node->id);
            fprintf(fps,"_%s:\n",node->id);
            fprintf(fps,".float %s\n",node->child->id);
        }
        else if (node->child->type==STRING_LITERAL)
        {
            fprintf(fps,"%s_string:\n",node->id);
            fprintf(fps,".asciz \"%s\"\n", node->child->id);
            if (!node->varType.isStatic) fprintf(fps,".globl _%s\n",node->id);
            fprintf(fps,"_%s:\n",node->id);
            fprintf(fps,".long %s_string\n",node->id);
        }
        else if (node->child->type==BLOCK)
        {
            if (!isArray(node->varType))
            {
                asmFail("Block init must be to array", node);
            }
            
            type1=removeArray(node->varType);
            printf("type1=%s\n",type1.data);
            if (isInt(type1))
            {
                if (!node->varType.isStatic) fprintf(fps,".globl _%s\n",node->id);
                fprintf(fps,"_%s:\n",node->id);
                int i;
                for (i=0;i<node->child->nlines;i++)
                {
                    fprintf(fps,".long %s\n", node->child->line[i]->id);
                }
            }
            else if (isFloat(type1))
            {
                if (!node->varType.isStatic) fprintf(fps,".globl _%s\n",node->id);
                fprintf(fps,"_%s:\n",node->id);
                int i;
                for (i=0;i<node->child->nlines;i++)
                {
                    fprintf(fps,".float %s\n", node->child->line[i]->id);
                }
            }
            else if (strcmp(type1.data,"char*")==0) // char*
            {
                int i;
                for (i=0; i < node->child->nlines; i++)
                {
                    fprintf(fps,"%s_string%d:\n",node->id,i);
                    fprintf(fps,".asciz \"%s\"\n", node->child->line[i]->id);
                }            
                if (!node->varType.isStatic) fprintf(fps,".globl _%s\n",node->id);
                fprintf(fps,"_%s:\n",node->id);
                for (i=0;i<node->child->nlines;i++)
                {
                    fprintf(fps,".long %s_string%d\n",node->id,i);
                }
            }
            else
                asmFail("Only int[] and char*[] supported for block init", node);
        }
        
        fprintf(fps,".text\n");
    }

    struct Var *oldVarEnd=varEnd;  // might be NULL
    varEnd=malloc(sizeof(struct Var));
    varEnd->offset=0;
    varEnd->id=newStr(node->id);
    varEnd->varType=node->varType;
    varEnd->level=level;
    varEnd->isArg=0;
    varEnd->prev=oldVarEnd;
    writeVars();
  }
  
  /*
  FUNCTION
  Put function name and type on variable stack (global scope)
  Put args on var stack (varEnd) as local variables with offsets
  Setup stack frame
  Process lines within function
  Remove stack frame
  Remove locals from variable stack
  */
  
  else if (node->type==FUNCTION)
  {

    struct Var *oldVarEnd=varEnd;  // put name of function on vars stack
    varEnd=malloc(sizeof(struct Var));
    varEnd->offset=0;
    varEnd->id=newStr(node->id);
    varEnd->varType=node->varType;
    varEnd->level=0;
    varEnd->isArg=0;
    varEnd->prev=oldVarEnd;

    g_offset = 0;

    // create arguments as local variables (data is on stack but lets point to it)
    int i=0;
    int tot=8;
    while(node->line[i]->type==ARG)
    {
      if (isVoid(node->line[i]->varType)) {i++; break;}
      if (node->line[i]->id==NULL) asmFail("argument name must be defined for function",node);
      oldVarEnd=varEnd;  // might be NULL
      varEnd=malloc(sizeof(struct Var));
      varEnd->offset=tot;
      varEnd->id=newStr(node->line[i]->id);
      varEnd->varType=node->line[i]->varType;
      varEnd->level=1;
      varEnd->isArg=1;
      varEnd->prev=oldVarEnd;
      i++;
      if (isArray(varEnd->varType))
          tot += 4;
      else
      {
          tot += sizeOf(varEnd->varType, node);
      }
    }
    
    writeVars();

    // declare function name globally and setup stack frame
    fprintf(fps,".globl _%s\n",node->id);
    fprintf(fps,"_%s:\n",node->id);

    fprintf(fps,"push ebp\n");
    fprintf(fps,"mov ebp,esp\n");

    for ( ; i<node->nlines; i++)
    {
      writeAsm(node->line[i], level+1, 0, loop);
    }    

    // Clear local vars (level 1) from list
    // 0  1
    // a<-b
    while(varEnd!=NULL){
      if (varEnd->level>1) asmFail("Unexpected high level variable", node);
      if (varEnd->level!=1) break;
      struct Var *prev=varEnd->prev;
      free(varEnd);
      varEnd=prev;
    }

    fprintf(fps,"# ** End of function **\n");
    writeVars();
    
    // cdecl convention: if returning float, return it on st(0)
    
    if (isFloat(node->varType))
    {
        fprintf(fps,"mov [_float_temp],eax\n");
        fprintf(fps,"FLD dword ptr [_float_temp]\n");
    }

    fprintf(fps,"mov esp,ebp\n");
    fprintf(fps,"pop ebp\n");
    fprintf(fps,"ret\n");
  }
  
  /*
  PROTOTYPE
  */
  
  else if (node->type==PROTOTYPE)
  {
    struct Var *oldVarEnd=varEnd;  // put name of function on vars stack
    varEnd=malloc(sizeof(struct Var));
    varEnd->offset=0;
    varEnd->id=newStr(node->id);
    varEnd->varType=node->varType;
    varEnd->level=0;
    varEnd->isArg=0;
    varEnd->prev=oldVarEnd;
  }
  
  /*
  BLOCK
  Process lines
  Clear local variables from variable stack (and machine stack by adding to ESP)
  */
  
  else if (node->type==BLOCK){
      
    int i;
    for (i=0;i<node->nlines;i++){
      writeAsm(node->line[i], level+1, 0, loop);
    }

    // clear local variables in BLOCK from end of list. ADD to ESP, increase g_offset
    int tot=0;
    while(varEnd!=NULL){
      if (varEnd->level > level+1) asmFail("Error: Unexpected high level variable", node);
      if (varEnd->level != level+1) break;
      tot += sizeOf(varEnd->varType,node);
      struct Var *prev=varEnd->prev;
      free(varEnd);
      varEnd=prev;
    }
    fprintf(fps,"add esp,%d\n",tot);
    g_offset += tot;
    fprintf(fps,"# ** End of block **\n");
    writeVars();
  }
  
  /*
  IF
  */
  
  else if (node->type==IF){
    int label = ++s_label;
    writeAsm(node->child,level,0, loop);

    fprintf(fps,"cmp eax, 0\n");          // If cond is false, jump either to end or else
    if (node->child3==NULL)
      fprintf(fps,"je _end%d\n",label);
    else
      fprintf(fps,"je _else%d\n",label);

    writeAsm(node->child2,level,0, loop);

    if (node->child3!=NULL){
      fprintf(fps,"jmp _end%d\n",label);  // jump over else since if was true
      fprintf(fps,"_else%d:\n",label);

      writeAsm(node->child3,level,0, loop);
    }

    fprintf(fps,"_end%d:\n",label);
  }

  /*
  TERNARY
   <CODE FOR e1 GOES HERE>
    cmpl $0, %eax
    je   _e3                  ; if e1 == 0, e1 is false so execute e3
    <CODE FOR e2 GOES HERE>  ; we're still here so e1 must be true. execute e2.
    jmp  _post_conditional    ; jump over e3
_e3:
    <CODE FOR e3 GOES HERE>  ; we jumped here because e1 was false. execute e3.
_post_conditional:            ; we need this label to jump over e3
  */
  
  else if (node->type==TERNARY)
  {
    int label = ++s_label;

    writeAsm(node->child,level,0, loop);

    fprintf(fps,"cmp eax, 0\n");          // If cond is false, jump to else
    fprintf(fps,"je _else%d\n",label);

    type1 = writeAsm(node->child2,level,0, loop);
    fprintf(fps,"jmp _end%d\n",label);  // jump over else since conditional was true
    
    fprintf(fps,"_else%d:\n",label);

    type2 = writeAsm(node->child3,level,0, loop);
    
    fprintf(fps,"_end%d:\n",label);

    varType=type1;  // TODO make correct type (wider of type1 and type2)
  }
        
  /*
  WHILE
  */

  else if (node->type==WHILE){
    int label = ++s_label;

    fprintf(fps,"_cont%d:\n",label);
    fprintf(fps,"_start%d:\n",label);

    writeAsm(node->child,level,0, loop);

    fprintf(fps,"cmp eax, 0\n");
    fprintf(fps,"je _end%d\n",label);

    writeAsm(node->child2,level,0, label);  // body
    fprintf(fps,"jmp _start%d\n",label);
    fprintf(fps,"_end%d:\n",label);
  }

  /*
  SWITCH
  */

  else if (node->type==SWITCH)
  {
    int label = ++s_label;

    writeAsm(node->child,level,0, loop);

    int defaultFound=0;
    for (i=0; i<node->child2->nlines; i++)
    {
        if (node->child2->line[i]->type==CASE)
        {
            if (isInt(node->child2->line[i]->varType))
                fprintf(fps,"cmp eax,%s\n",node->child2->line[i]->id);
            else
                fprintf(fps,"cmp al,'%s'\n",node->child2->line[i]->id);
                
            fprintf(fps,"je _case%s%d\n",node->child2->line[i]->id, label);
        }
        if (node->child2->line[i]->type==DEFAULT)
            defaultFound=1;
    }
    
    if (defaultFound)
        fprintf(fps,"jmp _default%d\n", label);
    else
        fprintf(fps,"jmp _end%d\n", label);
        
    writeAsm(node->child2,level,0, label);  // body
    fprintf(fps,"_end%d:\n",label);
  }

  /*
  DO
  */

  else if (node->type==DO)
  {
    int label = ++s_label;

    fprintf(fps,"_cont%d:\n",label);
    fprintf(fps,"_start%d:\n",label);

    writeAsm(node->child,level,0, label);   // body

    writeAsm(node->child2,level,0, loop);
    fprintf(fps,"cmp eax, 1\n");

    fprintf(fps,"je _start%d\n",label);
    fprintf(fps,"_end%d:\n",label);
  }

  /*
  FOR
  */

  else if (node->type==FOR){
    int label = ++s_label;

    writeAsm(node->child,level,0, loop);  // init

    fprintf(fps,"_start%d:\n",label);

    writeAsm(node->child2,level,0, loop); // cond

    fprintf(fps,"cmp eax, 0\n");
    fprintf(fps,"je _end%d\n",label);

    writeAsm(node->child4,level,0, label);  // body
    
    fprintf(fps,"_cont%d:\n",label);
    writeAsm(node->child3,level,0, loop);  // increment

    fprintf(fps,"jmp _start%d\n",label);
    fprintf(fps,"_end%d:\n",label);
  }
  
  /*
  BREAK and CONTINUE
  */
  
  else if (node->type==BREAK)
  {
      fprintf(fps, "jmp _end%d\n", loop);
  }

  else if (node->type==CONTINUE)
  {
      fprintf(fps, "jmp _cont%d\n", loop);
  }
  
  /*
  LABEL and GOTO
  */
  
  else if (node->type==LABEL)
  {
      fprintf(fps,"_%s:\n",node->id);
  }

  else if (node->type==GOTO)
  {
      fprintf(fps,"jmp _%s\n",node->id);
  }
  
  else if (node->type==CASE)
  {
      fprintf(fps,"_case%s%d:\n",node->id, loop);
  }

  else if (node->type==DEFAULT)
  {
      fprintf(fps,"_default%d:\n", loop);
  }
  
  /*
  RETURN
  We don't know what the return type ought to be so can't do coercion
  if thing being returned is float, push it onto the st(0)
  */

  else if (node->type==RETURN){
    type1 = writeAsm(node->child,level,0, loop);
    
    // Coerce return to int for now...
//    if (sizeOf(type1, node)==1)
//        fprintf(fps,"movzx eax,al\n");

    if (isFloat(type1))
    {
        fprintf(fps,"mov [_float_temp],eax\n");
        fprintf(fps,"FLD dword ptr [_float_temp]\n");
    }

    fprintf(fps,"mov esp,ebp\n");
    fprintf(fps,"pop ebp\n");

    fprintf(fps,"ret\n");
  }
  
  /*
  EXPR: expression followed by semi-colon, eg i=2*f(n);
  */

  else if (node->type==EXPR){
    writeAsm(node->child,level,0, loop);
  }
  
  /*
  CALL
  Push args on the stack right to left. If 1 byte, push 4 bytes with char first
  On return clear arguments from stack
  Find the return type of the function and pass it up to caller node
  */

  else if (node->type==CALL){
    int i;
    int tot=0;
    int size;
    int paddedSize;

    for (i=node->nlines-1;i>=0;i--)
    {
      type1 = writeAsm(node->line[i],level,0, loop);
      if (isArray(type1)) 
          size=4;
      else
          size = sizeOf(type1, node);

      paddedSize= size%4 == 0 ? size : (1+size/4)*4;
      tot += paddedSize;
      
//      if (sizeOf(type1)==1)
//          fprintf(fps,"movzx eax,al\n");

      if (paddedSize==4)
        fprintf(fps,"push eax\n");
      else
      {
        fprintf(fps,"sub esp,%d\n",paddedSize);

        // memcpy(esp,eax,sizeOf(type1));
        
        fprintf(fps,"mov ecx,esp\n");       // store esp as we are about to change it
        fprintf(fps,"push %d\n",sizeOf(type1, node));
        fprintf(fps,"push eax\n");
        fprintf(fps,"push ecx\n");
        fprintf(fps,"call _memcpy\n");
        fprintf(fps,"add esp,12\n");

      }
    }

    fprintf(fps,"call _%s\n",node->id);
    fprintf(fps,"add esp,%d\n",tot);

    strcpy(varType.data,"int");  // default return is int
    struct Var *p=varEnd;
    while(p!=NULL)
    {
        if (strcmp(node->id,p->id)==0)
        {
            varType=p->varType;
            break;
        }
        p=p->prev;
    }

    // if function returns float get return value from st(0) into eax    
    if (strcmp(varType.data,"float")==0)    
    {
        fprintf(fps,"FSTP dword ptr [_float_temp]\n");
        fprintf(fps,"mov eax,[_float_temp]\n");
    }
    
  }
  
  /*
  STRUCT. shove it on varEnd with the variables and give a pointer to its position in the tree
  */

  else if (node->type==STRUCT  || node->type == UNION)
  {
    struct Var *oldVarEnd=varEnd;  // might be NULL
    varEnd=malloc(sizeof(struct Var));
    varEnd->offset=0;
    varEnd->id=(node->type==STRUCT) ? newStrStruct(node->id) : newStrUnion(node->id);  // eg "struct Point"
    varEnd->varType.data[0]='\0';       // no type. sizeOf this will be 0
    varEnd->level=level;
    varEnd->isArg=0;
    varEnd->structNode=node;            // Pointer to this STRUCT on the tree
    varEnd->prev=oldVarEnd;

    findSubStructs(node, level, loop); // add any sub structs to variable list also
    
    writeVars();
  }
  
  /*
  DECLGROUP
  */
  
  else if (node->type==DECLGROUP)
  {
    for (i=0; i < node->nlines; i++)
    {
      writeAsm(node->line[i],level,0, loop);
    }      
  }
  
  /*
  DECL
  Declare a local variable and push it onto the stack. If 1 byte, push 4 bytes with char first. For arrays pad to multiple of 4 bytes
  First calculate its initial value (if any).
  Add new variable to var stack
  */

  else if (node->type==DECL)
  {
    // printf("decl '%s' [%s] %p\n", node->id, node->varType.data, node->child);
    int size=sizeOf(node->varType, node);
    int paddedSize= size%4 == 0 ? size : (1+size/4)*4;

    if (node->child!=NULL) 
    {
        type1 = writeAsm(node->child,level,0, loop);
        if (sizeOf(type1, node)==1) fprintf(fps,"movzx eax,al\n");
    }
    
    if (paddedSize==4)
        fprintf(fps,"push eax # declare %s (level %d)\n",node->id,level);
    else
        fprintf(fps,"sub esp,%d # declare %s (level %d)\n",paddedSize,node->id,level);

    // struct init TODO: fix this, type1 might not be defined
    if (node->child!=NULL && isStructOrUnion(type1))
    {
        // memcpy(esp,eax,sizeOf(type1));
        fprintf(fps,"mov ecx,esp\n");
        fprintf(fps,"push %d\n",sizeOf(type1, node));
        fprintf(fps,"push eax\n");
        fprintf(fps,"push ecx\n");
        fprintf(fps,"call _memcpy\n");
        fprintf(fps,"add esp,12\n");

        varType = type1;
    }

    g_offset -= paddedSize;

    struct Var *oldVarEnd=varEnd;  // might be NULL
    varEnd=malloc(sizeof(struct Var));
    varEnd->offset=g_offset;
    varEnd->id=newStr(node->id);
    varEnd->varType=node->varType;
    varEnd->level=level;
    varEnd->isArg=0;
    varEnd->prev=oldVarEnd;

    writeVars();
  }
  
  /*
  INDEX. Calculate array index eg a[2]
  First child is variable or lvalue expression like *p or a[3] so call with lvalue=1
  So eax is set to a pointer. If WE have been asked for an rvalue, get memory at this pointer
  (if our type is char, get a single byte). Multiply so a[2][3] -> offset = 2*sizeof(int[3])+3*sizeof(int)
  */

  else if (node->type==INDEX)
  {
    type2 = writeAsm(node->child2,level,0, loop); // the index
    fprintf(fps,"push eax\n");

    type1 = writeAsm(node->child,level,1, loop);  // the variable address, lvalue requested
    if (isPointer(type1)) fprintf(fps,"mov eax,[eax]\n");  // eg int*p; reference p[2]
    fprintf(fps,"pop ecx\n");

    if (isArray(type1))
        varType=removeArray(type1);
    else if (isPointer(type1))
        varType=removePointer(type1);
    else
        asmFail("Indexing can only be used on array or pointer type", node);
    
    printf("index %s\n",varType.data);
    fprintf(fps,"imul ecx,%d\n",sizeOf(varType, node));
    fprintf(fps,"add eax,ecx\n");

    if (lvalue==0 && !isStructOrUnion(varType) && !isArray(varType))
    {
        if (lvalue==0)
        {
            if (sizeOf(varType,node)==1)
                fprintf(fps,"mov al,[eax]\n");
            else
                fprintf(fps,"mov eax,[eax]\n");
        }    
    }
  }    

  /*
  DOT and ARROW eg p.x; type1=struct Point
  */
  
  else if (node->type==DOT || node->type==ARROW)
  {
    char* field = node->child2->id; // eg x

    type1 = writeAsm(node->child,level,1,loop);  // p, lvalue requested (type1=struct Point)

    if (node->type==ARROW) 
    {
        type1 = removePointer(type1); 
        fprintf(fps,"mov eax,[eax]\n");
    }
    
    struct Var *p=varEnd;
    struct Node* structNode;
    int found=0;
    while(p!=NULL)
    {
        if (strcmp(type1.data, p->id) == 0)
        {
            structNode=p->structNode;
            found=1;
            break;
        }
        p=p->prev;
    }
    if (found==0) 
    {
        printf("Unknown struct/union %s\n",type1.data);
        exit(1);
    }

    int tot=0;
    found=0;
    int i, j;
    for (i=0; i < structNode->nlines; i++)
    {
        // TODO: double loop since lines[i] might be DECLGROUP
        if (structNode->line[i]->type==DECL)  // line[i] is DECL
        {
            if (strcmp(field, structNode->line[i]->id)==0)
            {
                varType = structNode->line[i]->varType;
                found=1;
                break;
            }
            tot += sizeOf(structNode->line[i]->varType, node);
        }
        else if (structNode->line[i]->type==DECLGROUP) // line[i] is a DECLGROUP
        {
            for (j=0; j<structNode->line[i]->nlines; j++)
            {
                if (strcmp(field, structNode->line[i]->line[j]->id)==0)
                {
                    varType = structNode->line[i]->line[j]->varType;
                    found=1;                
                    goto ed;
                }
                tot += sizeOf(structNode->line[i]->line[j]->varType, node);
            }            
        }
    }
    
ed: if (found==0)
    {
        printf("Struct/union %s has no field %s\n", type1.data, field);
        exit(1);
    }

    // add offset struct only
    if (isStruct(type1))
    {
        fprintf(fps,"mov ecx,%d\n",tot);
        fprintf(fps,"add eax,ecx\n");
    }

    if (lvalue==0 && !isStructOrUnion(varType) && !isArray(varType))
    {
        if (sizeOf(varType, node)==1)
            fprintf(fps,"mov al,[eax]\n");
        else
            fprintf(fps,"mov eax,[eax]\n");
    }          
  }
  
  /*
  ASSIGNMENT. First child is lvalue so call Node with lvalue=1, get back a pointer
  Widen or narrow before putting into memory. Second child is rvalue.
  */

  else if (node->type==ASSIGNMENT)
  {
    type1 = writeAsm(node->child,level,1,loop);    // lvalue requested for LHS -> ecx
    fprintf(fps,"push eax\n");
 
    type2 = writeAsm(node->child2,level,0, loop);  // value to be assigned -> eax
    fprintf(fps,"pop ecx\n");
    
    if (isStructOrUnion(type1) && isStructOrUnion(type2))
    {
        if (strcmp(type1.data, type2.data)!=0)
        {
            printf("Different struct types in assignment\n");
            exit(1);
        }
        // memcpy(ecx,eax,sizeOf(type1));
        fprintf(fps,"push %d\n",sizeOf(type1, node));
        fprintf(fps,"push eax\n");
        fprintf(fps,"push ecx\n");
        fprintf(fps,"call _memcpy\n");
        fprintf(fps,"add esp,12\n");

        return type1;
    }

    // OK if both are integer types or both are pointers. Else fail
    if (   (isInt(type1) || isChar(type1) || isFloat(type1)) 
        && (isInt(type2) || isChar(type2) || isFloat(type2)) )
    {
    }
    else if (isPointer(type1) && isPointer(type2))
    {
    }
    else
    {
        printf("Incompatible types for assignment: %s, %s\n", type1.data, type2.data);
        exit(1);
    }
    
    if (isChar(type1))   // LHS = char
    {
        if (isInt(type2))   // narrow int to char
        {
            printf("Cannot narrow int to char\n");
            exit(1);
        }
        fprintf(fps,"mov [ecx],al\n");
    }
    else if (isInt(type1)) // LHS=int
    {
        if (isFloat(type2))  // narrow float to int
        {
            fprintf(fps,"push eax\n");
            fprintf(fps,"call _float2int\n");
            fprintf(fps,"add esp,4\n");
        }
        else if (isChar(type2))  // RHS = char so widen
            fprintf(fps,"movzx eax,al\n");

        fprintf(fps,"mov [ecx],eax\n");
    }
    else if (isPointer(type1))
    {
        if (!isPointer(type2)) asmFail("Pointer must be assigned to another pointer", node);
        fprintf(fps,"mov [ecx],eax\n");        
    }    
    else if (isFloat(type1)) // LHS=float
    {
        if (isInt(type2))  // widen int to float
        {
            fprintf(fps,"push eax\n");
            fprintf(fps,"call _int2float\n");
            fprintf(fps,"add esp,4\n");
        }
        fprintf(fps,"mov [ecx],eax\n");
    }
    else
    {
        asmFail("unknown assignment type", node);
    }
    varType=type1;
  }
  
  /*
  PLUS_EQUALS (+=) etc: += -= *= /= %= &= |= ^=

#define PLUS_EQUALS 13
#define MINUS_EQUALS 14
#define ASTERISK_EQUALS 15
#define SLASH_EQUALS 16
#define PERCENT_EQUALS 17
#define AMP_EQUALS 18
#define PIPE_EQUALS 19
#define HAT_EQUALS 20
  */

  else if (node->type >= PLUS_EQUALS && node->type <= HAT_EQUALS)
  {
    type2 = writeAsm(node->child2,level,0, loop);  // value to be added -> ecx
    fprintf(fps,"push eax\n");
 
    type1 = writeAsm(node->child,level,1,loop);    // lvalue requested for LHS -> eax
    fprintf(fps,"pop ecx\n");
    
    fprintf(fps,"push eax\n"); // push the lvalue
    fprintf(fps,"mov eax,[eax]\n"); // get the actual value
    
    char* ops[]={"add","sub","imul","idiv","idiv","and","or","xor"};
    char* op;

    printf("types=%s %s\n", type1.data,type2.data);

    op = ops[node->type - PLUS_EQUALS];

    varType = writeBinOp(op, type1, type2, node);

    if (node->type == PERCENT_EQUALS)
        fprintf(fps,"mov ecx,edx\n");
    else
        fprintf(fps,"mov ecx,eax\n");  // result in ecx

    fprintf(fps,"pop eax\n");      // eax = lvalue
        
    if (isChar(type1))   // LHS = char
    {
        if (isInt(varType))   // narrow int to char
        {
            printf("Cannot narrow int to char\n");
            exit(1);
        }

        fprintf(fps,"mov [eax],cl\n");
        fprintf(fps,"mov al,cl\n");
    }
    else if (isInt(type1)) // LHS=int, pointer, float
    {
        if (isFloat(varType))  // narrow float to int
        {
            fprintf(fps,"push eax\n");
            fprintf(fps,"push ecx\n");
            fprintf(fps,"call _float2int\n");
            fprintf(fps,"add esp,4\n");
            fprintf(fps,"mov ecx, eax\n");
            fprintf(fps,"pop eax\n");
        }
        else if (isChar(varType))  // RHS = char so widen
            fprintf(fps,"movzx ecx,cl\n");

        fprintf(fps,"mov [eax],ecx\n");
        fprintf(fps,"mov eax,ecx\n");
    }
    else if (isPointer(type1))
    {
        if (!isPointer(varType)) asmFail("Pointer must be assigned to another pointer", node);
        fprintf(fps,"mov [eax],ecx\n");        
        fprintf(fps,"mov eax,ecx\n");        
    }    
    else if (isFloat(type1)) // LHS=float
    {
        if (isInt(varType))  // widen int to float
        {
            fprintf(fps,"push eax\n");
            fprintf(fps,"push ecx\n");
            fprintf(fps,"call _int2float\n");
            fprintf(fps,"add esp,4\n");
            fprintf(fps,"mov ecx, eax\n");
            fprintf(fps,"pop eax\n");
        }
        fprintf(fps,"mov [eax],ecx\n");
        fprintf(fps,"mov eax,ecx\n");
    }
    else
    {
        asmFail("unknown assignment arithmetic type", node);
    }
    varType=type1;
  }

  /* 
  <<= and >>=
  */

  else if (node->type == LESSTHAN2_EQUAL || node->type == GREATERTHAN2_EQUAL)
  {
  }

  /*
  DEREF eg *p
  eg child note type is int*, return int (remove one *)
  If rvalue requested, dereference
  */
  
  else if (node->type==DEREF)   // int* p; *p=1+*q. return varType = int (lvalue or rvalue) not int*
  {
    type1 = writeAsm(node->child,level,0, loop);
    varType=removePointer(type1);
    if (lvalue==0)
    {
        if (sizeOf(varType, node)==1)
            fprintf(fps,"mov al,[eax]\n");
        else
            fprintf(fps,"mov eax,[eax]\n");
    }
    
    varType=removePointer(type1);      
  }

  /*
  ADDRESS. eg &a
  eg child node is int, return int* (add one *)
  Request lvalue so we get a pointer to the object
  */  
  
  else if (node->type==ADDRESS)
  {
      type1 = writeAsm(node->child,level,1,loop); // request lvalue
      varType = addPointer(type1);
  }

  /* 
  SIZEOF  
  */
  
  else if (node->type==SIZEOF)
  {
      fprintf(fps,"mov eax,%d\n",sizeOf(node->varType, node));
      strcpy(varType.data,"int");
  }
  
  /*
  CAST eg (int)7.0
  */
  
  else if (node->type==CAST)
  {
      type1 = writeAsm(node->child,level,0, loop);
      varType = node->varType;

      if (strcmp(varType.data, type1.data)==0)
      {
          // identical
      }
      else if (isPointer(type1) && isPointer(varType))
      {
          // pointer to pointer
      }
      else if (isChar(type1) && isInt(varType))  // widen char -> int
      {
          fprintf(fps,"movzx eax,al\n");
      }
      else if (isInt(type1) && isFloat(varType))  // widen int -> float
      {
          fprintf(fps,"push eax\n");
          fprintf(fps,"call _int2float\n");
          fprintf(fps,"add esp,4\n");
      }
      else if (isFloat(type1) && isInt(varType))  // widen float -> int
      {
          fprintf(fps,"push eax\n");
          fprintf(fps,"call _float2int\n");
          fprintf(fps,"add esp,4\n");
      }
      else if (isInt(type1) && isChar(varType))  // narrow
      {
      }
      else if (isPointer(varType) && isInt(type1))
      {
      }
      else
      {
          asmFail("Illegal cast!", node);
      }
  }

  /*
  Unary operations, MINUS, PLUS, ++, --, COMPLEMENT(~), NOT(!)
  */
  
  else if (node->type==UNARY_MINUS){
    type1 = writeAsm(node->child,level,0, loop);
    if (isChar(type1))
        fprintf(fps,"neg al\n");
    else if (isFloat(type1))
    {
        fprintf(fps,"push eax\n");
        fprintf(fps,"call _fneg\n");
        fprintf(fps,"add esp,4\n");
    }
    else
        fprintf(fps,"neg eax\n");
        
    varType = type1;
  }
  else if (node->type==UNARY_PLUS)
  {
      // does nothing!
  }
  else if (node->type==INC)
  {
    varType = writeAsm(node->child,level,1,loop);
    if (isChar(varType))
    {
        fprintf(fps,"inc byte ptr [eax]\n");
        fprintf(fps,"mov al,[eax]\n");
    }
    else if (isInt(varType))
    {
        fprintf(fps,"inc dword ptr [eax]\n");
        fprintf(fps,"mov eax,[eax]\n");
    }
    else
        asmFail("INC only for int or char",node);
  }
  else if (node->type==DEC)
  {
    varType = writeAsm(node->child,level,1,loop);
    if (isChar(varType))
    {
        fprintf(fps,"dec byte ptr [eax]\n");
        fprintf(fps,"mov al,[eax]\n");
    }
    else if (isInt(varType))
    {
        fprintf(fps,"dec dword ptr [eax]\n");
        fprintf(fps,"mov eax,[eax]\n");
    }
    else
        asmFail("DEC only for int or char",node);
  }
  else if (node->type==INC_AFTER)
  {
    varType = writeAsm(node->child,level,1,loop);
    if (isChar(varType))
    {
        fprintf(fps,"mov cl,[eax]\n");
        fprintf(fps,"inc byte ptr [eax]\n");
        fprintf(fps,"mov al,cl\n");
    }
    else if (isInt(varType))
    {
        fprintf(fps,"mov ecx,[eax]\n");   // store old value
        fprintf(fps,"inc dword ptr [eax]\n");  // increase
        fprintf(fps,"mov eax,ecx\n");          // return old value
    }
    else
        asmFail("INC_AFTER only for int or char",node);
  }
  else if (node->type==DEC_AFTER)
  {
    varType = writeAsm(node->child,level,1,loop);
    if (isChar(varType))
    {
        fprintf(fps,"mov cl,[eax]\n");
        fprintf(fps,"dec byte ptr [eax]\n");
        fprintf(fps,"mov al,cl\n"); 
    }
    else if (isInt(varType))
    {
        fprintf(fps,"mov ecx,[eax]\n");
        fprintf(fps,"dec dword ptr [eax]\n");
        fprintf(fps,"mov eax,ecx\n");
    }
    else
        asmFail("DEC_AFTER only for int or char",node);
  }
  else if (node->type==UNARY_COMPLEMENT){
    type1 = writeAsm(node->child,level,0, loop);
    if (sizeOf(type1, node)==1)
        fprintf(fps,"not al\n");
    else
        fprintf(fps,"not eax\n");
        
    varType = type1;
  }
  else if (node->type==UNARY_NOT){
    type1 = writeAsm(node->child,level,0, loop);
    if (sizeOf(type1, node)==1)
    {
        fprintf(fps,"cmp al,0\n");
        fprintf(fps,"sete al\n");
    }
    else
    {
        fprintf(fps,"cmp eax,0\n");    // set ZF on if exp == 0, set it off otherwise
        fprintf(fps,"mov eax,0\n");    // zero out EAX (doesn't change FLAGS)
        fprintf(fps,"sete al\n");
    }
    varType = type1;
  }
  
  /*
  Literals
  GNU assembler (as) doesn't understand '\0' so do special case
  */
  
  else if (node->type==INT_LITERAL){
    fprintf(fps,"mov eax,%s\n",node->id);
    strcpy(varType.data,"int");    
  }
  else if (node->type==FLOAT_LITERAL)
  {
      float f;
      sscanf(node->id, "%f", &f);
      f2u.f=f;
      
    fprintf(fps,"mov eax,0x%0x # %f\n",f2u.u, f);
    strcpy(varType.data,"float");
  }
  else if (node->type==STRING_LITERAL){
    int label = ++s_label;

    fprintf(fps,".data\n");
    fprintf(fps,"_string%d:\n",label);
    fprintf(fps,".asciz \"%s\"\n",node->id);
    fprintf(fps,".text\n");
    fprintf(fps,"mov eax, offset _string%d\n",label);
    strcpy(varType.data,"char*");
  }
    
  else if (node->type==CHAR_LITERAL){
      if (strcmp(node->id,"\\0")==0)
          fprintf(fps,"mov al,0\n");
      else
          fprintf(fps,"mov al,'%s'\n",node->id);
      strcpy(varType.data,"char");
  }
  
  /*
  VAR
  Variable reference. Find variable in var stack and get its type and offset and whether is Arg
  If rvalue was requested, deref and put result in eax or al (char)
  If lvalue was requested, don't deref but get address in eax
  Either local or global might be requested
  */
  
  else if (node->type==VAR)           // variable reference
  {
    struct Var *p=varEnd;
    int offset=0;
    int found=0;
    int isArg;
    while(p!=NULL)
    {
        if (strcmp(node->id,p->id)==0)
        {
            offset=p->offset;
            varType=p->varType;
            isArg=p->isArg;
            found=1;
            break;
        }
        p=p->prev;
    }
    if (found==0) 
        
    {
        printf("Variable %s\n",node->id); 
        asmFail("Refer to undeclared variable", node);
    }

    // Special case for arrays. Normally return the address but if array is arg to our function dereference it
    if (isArray(varType))
    {
        if (isArg)
        {
            if (offset==0)
                fprintf(fps,"mov eax,_%s\n",node->id);
            else
                fprintf(fps,"mov eax,[ebp%+d] # %s\n",offset,node->id);
        }
        else
        {
            if (offset==0)
                fprintf(fps,"mov eax,offset _%s\n",node->id);
            else
                fprintf(fps,"lea eax,[ebp%+d] # %s\n",offset,node->id);
        }
        return varType;
    }

    // Special case for structs. Always give address
    if (isStructOrUnion(varType) && !isPointer(varType))
    {
        if (offset==0)
            fprintf(fps,"mov eax,offset _%s\n",node->id);
        else
            fprintf(fps,"lea eax,[ebp%+d] # %s\n",offset,node->id);

        return varType;
    }

//    printf("var %s\n",varType.data);
    char *reg;    
    if (sizeOf(varType, node)==1)
        reg="al";
    else
        reg="eax";

    // normal case        
    if (lvalue)
    {
        if (offset==0)
            fprintf(fps,"mov eax,offset _%s\n",node->id);
        else
            fprintf(fps,"lea eax,[ebp%+d] # %s\n",offset,node->id);
    }
    else
    {
        if (offset==0)
            fprintf(fps,"mov %s,_%s\n",reg,node->id);
        else
            fprintf(fps,"mov %s,[ebp%+d] # %s\n",reg,offset,node->id);
    }
  }
  
  /*
  Binary ops. + - * / % & | ^
  If both char, result is char
  If both int, result int
  If char, int, promote to int
  If pointer, int, do pointer arithmetic
  */
  
  else if (node->type==BINARY_PLUS){
    type2 = writeAsm(node->child2,level,0, loop);
    fprintf(fps,"push eax\n");

    type1 = writeAsm(node->child,level,0, loop);
    fprintf(fps,"pop ecx\n");  // child on eax, child2 on ecx
    
    varType = writeBinOp("add", type1, type2, node);
  }
  else if (node->type==BINARY_MINUS){
    type2 = writeAsm(node->child2,level,0, loop);
    fprintf(fps,"push eax\n");
    type1 = writeAsm(node->child,level,0, loop);
    fprintf(fps,"pop ecx\n");
    
    varType = writeBinOp("sub", type1, type2, node);
    
//    fprintf(fps,"sub eax,ecx\n");
  }
  else if (node->type==BINARY_TIMES){
    type2 = writeAsm(node->child2,level,0, loop);
    fprintf(fps,"push eax\n");
    type1 = writeAsm(node->child,level,0, loop);
    fprintf(fps,"pop ecx\n");
    
    varType = writeBinOp("imul", type1, type2, node);
        
//    fprintf(fps,"imul eax,ecx\n");
  }
  else if (node->type==BINARY_DIVIDE){
    type2 = writeAsm(node->child2,level,0, loop);
    fprintf(fps,"push eax\n");
    type1 = writeAsm(node->child,level,0, loop);
    fprintf(fps,"pop ecx\n");
    fprintf(fps,"cdq\n");

    varType = writeBinOp("idiv", type1, type2, node);

//    fprintf(fps,"idiv eax,ecx\n");
  }
  else if (node->type==BINARY_MODULO){
    type2 = writeAsm(node->child2,level,0, loop);
    fprintf(fps,"push eax\n");
    type1 = writeAsm(node->child,level,0, loop);
    fprintf(fps,"pop ecx\n");
    fprintf(fps,"cdq\n");

    varType = writeBinOp("idiv", type1, type2, node);
    
    fprintf(fps,"mov eax,edx\n");
  }
  else if (node->type==BINARY_BITWISE_AND)
  {
    type2 = writeAsm(node->child2,level,0, loop);
    fprintf(fps,"push eax\n");
    type1 = writeAsm(node->child,level,0, loop);
    fprintf(fps,"pop ecx\n");

    varType = writeBinOp("and", type1, type2, node);
  }
  else if (node->type==BINARY_BITWISE_OR)
  {
    type2 = writeAsm(node->child2,level,0, loop);
    fprintf(fps,"push eax\n");
    type1 = writeAsm(node->child,level,0, loop);
    fprintf(fps,"pop ecx\n");

    varType = writeBinOp("or", type1, type2, node);
  }
  else if (node->type==BINARY_BITWISE_XOR)
  {
    type2 = writeAsm(node->child2,level,0, loop);
    fprintf(fps,"push eax\n");
    type1 = writeAsm(node->child,level,0, loop);
    fprintf(fps,"pop ecx\n");

    varType = writeBinOp("xor", type1, type2, node);
  }
  else if (node->type==BINARY_LEFT_SHIFT)
  {
    type2 = writeAsm(node->child2,level,0, loop);
    fprintf(fps,"push eax\n");
    type1 = writeAsm(node->child,level,0, loop);
    fprintf(fps,"pop ecx\n");

    varType = writeBinOp("shl", type1, type2, node);
  }
  else if (node->type==BINARY_RIGHT_SHIFT)
  {
    type2 = writeAsm(node->child2,level,0, loop);
    fprintf(fps,"push eax\n");
    type1 = writeAsm(node->child,level,0, loop);
    fprintf(fps,"pop ecx\n");

    varType = writeBinOp("shr", type1, type2, node);
  }
  
  /*
  relational operators < > <= >= == !=
  */
  
  else if (
	   nodetype==BINARY_LESS_THAN ||
	   nodetype==BINARY_LESS_THAN_OR_EQUAL ||
	   nodetype==BINARY_GREATER_THAN ||
	   nodetype==BINARY_GREATER_THAN_OR_EQUAL ||
	   nodetype==BINARY_EQUAL ||
	   nodetype==BINARY_NOT_EQUAL){

    type2 = writeAsm(node->child2,level,0, loop);
    fprintf(fps,"push eax\n");       // save value of e1 on the stack
    type1 = writeAsm(node->child,level,0, loop);
    fprintf(fps,"pop ecx\n");         // pop e1 from the stack into ecx - e2 is already in eax
    
    if (type1.isUnsigned + type2.isUnsigned == 1)
    {
        asmFail("Comparison of signed and unsigned integer", node);
    }

    varType = writeBinOp("cmp", type1, type2, node);

//    fprintf(fps,"cmp eax, ecx\n");    // set ZF on if e1 == e2, set it off otherwise

    fprintf(fps,"mov eax, 0\n");      //zero out EAX (doesn't change FLAGS)

    if (nodetype==BINARY_LESS_THAN)
    {        
        if (isFloat(varType) || varType.isUnsigned)
            fprintf(fps,"setb al\n");
        else
            fprintf(fps,"setl al\n");
    }
    else if (nodetype==BINARY_LESS_THAN_OR_EQUAL)
    {
        if (isFloat(varType) || varType.isUnsigned)
            fprintf(fps,"setbe al\n");
        else
            fprintf(fps,"setle al\n");
    }
    else if (nodetype==BINARY_GREATER_THAN || varType.isUnsigned)
    {
        if (isFloat(varType))
            fprintf(fps,"seta al\n");
        else
            fprintf(fps,"setg al\n");
    }
    else if (nodetype==BINARY_GREATER_THAN_OR_EQUAL || varType.isUnsigned)
    {
        if (isFloat(varType))
            fprintf(fps,"setae al\n");
        else
            fprintf(fps,"setge al\n");
    }
    else if (nodetype==BINARY_EQUAL)
      fprintf(fps,"sete al\n");
    else
      fprintf(fps,"setne al\n");
  
    strcpy(varType.data,"int");
  }
  
  /*
  logical AND OR: && ||
  */
  
  else if (nodetype==BINARY_OR){
    // 0 || 0 = 0
    // 0 || 1 = 1
    // 1 || 0 = 1
    // 1 || 1 = 1
    int label = ++s_label;
    type1 = writeAsm(node->child,level,0, loop);

    if (sizeOf(type1, node)==1)
        fprintf(fps,"cmp al, 0\n");
    else
        fprintf(fps,"cmp eax, 0\n");          // check if e1 is 0
            
    fprintf(fps,"je _else%d\n",label);    // e1 is 0, so we need to evaluate _else

    if (sizeOf(type1, node)==1)
        fprintf(fps,"mov al, 1\n");
    else
        fprintf(fps,"mov eax, 1\n");          // we didn't jump, so e1 is 1 and therefore result is 1

    fprintf(fps,"jmp _end%d\n",label);
    fprintf(fps,"_else%d:\n",label);

    type2 = writeAsm(node->child2,level,0, loop);

    if (sizeOf(type2, node)==1)
    {
        fprintf(fps,"cmp al, 0\n");
        fprintf(fps,"mov al, 0\n");
    }
    else
    {
        fprintf(fps,"cmp eax, 0\n");          // check if e2 is true
        fprintf(fps,"mov eax, 0\n");          // zero out EAX without changing ZF
    }

    fprintf(fps,"setne al\n");           // set AL register (the low byte of EAX) to 1 iff e2 != 0
    fprintf(fps,"_end%d:\n",label);

    strcpy(varType.data,"int");
  }
  else if (nodetype==BINARY_AND){
    // 0 && 0 = 0
    // 0 && 1 = 0
    // 1 && 0 = 0
    // 1 && 1 = 1
    int label = ++s_label;
    type1 = writeAsm(node->child,level,0, loop);

    if (sizeOf(type1, node)==1)
        fprintf(fps,"cmp al, 0\n");
    else
        fprintf(fps,"cmp eax, 0\n");          // check if e1 is 0
        
    fprintf(fps,"jne _else%d\n",label);   // e1 isnt 0, so we need to evaluate _else

    if (sizeOf(type1, node)==1)
        fprintf(fps,"mov al, 0\n");
    else
        fprintf(fps,"mov eax, 0\n");          // we didn't jump, so e1 is 0 and therefore result is 0

    fprintf(fps,"jmp _end%d\n",label);
    fprintf(fps,"_else%d:\n",label);

    type2 = writeAsm(node->child2,level,0, loop);

    if (sizeOf(type2, node)==1)
    {
        fprintf(fps,"cmp al, 0\n");
        fprintf(fps,"mov al, 0\n");
    }
    else
    {
        fprintf(fps,"cmp eax, 0\n");          // check if e2 is 0
        fprintf(fps,"mov eax, 0\n");          // zero out EAX without changing ZF
    }
      
    fprintf(fps,"setne al\n");           // set AL register (the low byte of EAX) to 1 iff e2 != 0
    fprintf(fps,"_end%d:\n",label);

    strcpy(varType.data,"int");
  }
  else
  {
    printf("Internal compiler error: illegal nodetype (writeAsm). Got %d %s\n",nodetype, names[nodetype]);
    exit(1);
  }

  return varType;
}

// ######################################################################

int main(int argc, char **argv)
{
    int i;

    if (0)
    {
                // unit tests!

        printf("==== start of unit tests ===\n");

        struct Type t;
        strcpy(t.data, "int*");
        printf("sizeOf int* =%d, isPointer=%d Array=%d\n", sizeOf(t, NULL),isPointer(t), isArray(t));

        strcpy(t.data, "int");
        printf("sizeOf int =%d, isPointer=%d Array=%d\n", sizeOf(t, NULL),isPointer(t), isArray(t));
        
        strcpy(t.data, "char");
        printf("sizeOf char =%d isPointer=%d Array=%d\n", sizeOf(t, NULL), isPointer(t), isArray(t));

        strcpy(t.data, "char*");
        printf("sizeOf char* =%d isPointer=%d Array=%d\n", sizeOf(t, NULL), isPointer(t), isArray(t));

        strcpy(t.data, "char*[2][3]");
        printf("sizeOf char*[2][3] =%d isPointer=%d is Array=%d\n", sizeOf(t, NULL), isPointer(t), isArray(t));
        
        int open[10], close[10];
        int n = getArray(t.data, open, close);

        for (i=0;i<n;i++)
            printf("o=%d c=%d\n",open[i],close[i]);
        
        struct Type s = removeArray(t);
        printf("After remove %s\n", s.data); 
        
        addEnumConst("FOO",13);
        addEnumConst("BAR",96);
        printf("isEnumConst FOO=%d\n", isEnumConst("FOO"));
        printf("getEnumConst FOO=%s\n", getEnumConst("FOO"));  // returns a char*
        printf("isEnumConst BAR=%d\n", isEnumConst("BAR"));
        printf("getEnumConst BAR=%s\n", getEnumConst("BAR"));
        printf("isEnumConst foo=%d\n", isEnumConst("foo"));
        
        struct Type v;
        strcpy(v.data,"int*");
        
        addTypedef("foo",v);
        v=getTypedef("foo");
        printf("getTypedef foo=%s\n",v.data);
        
        printf("==== end of unit tests ===\n");
    }

  // ----------------------------------------------------------------------
  // Read command line args
  // ----------------------------------------------------------------------

    const char* usage =
        "jcc [options] foo.c\n"
        "-c: compile only\n"
        "-dumpLex: dump lex tokens to stdout\n"
        "-dumpParse: dump Abstract Syntax Tree to stdout\n"
        "-lexOnly: lex input file but do not parse or create function calls (no output file)\n"
        "-parseOnly: lex and parse but don't create function calls (no output file)\n";

  int dumpLex=0;
  int dumpParse=0;
  int lexOnly=0;
  int parseOnly=0;
  int compileOnly=0;
  
  char* fname = NULL;
  
  if (argc == 1)
  {
    printf("Usage:\n%s\n",usage);
    exit(0);
  }
  
  for (i=0;i<argc;i++)
  {
      if (strcmp(argv[i],"-dumpLex")==0)
          dumpLex=1;
      else if (strcmp(argv[i],"-dumpParse")==0)
          dumpParse=1;
      else if (strcmp(argv[i],"-lexOnly")==0)
          lexOnly=1;
      else if (strcmp(argv[i],"-parseOnly")==0)
          parseOnly=1;
      else if (strcmp(argv[i],"-c")==0)
          compileOnly=1;
      else
          fname=argv[i];
  }
  
  if (fname==NULL)
  {
      printf("A .c file must be specified\n");
      exit(1);
  }

  // ----------------------------------------------------------------------
  // Figure out various filenames
  // ----------------------------------------------------------------------
    
  char name[64];    // base name, eg foo.c
  char sname[64];   // name of s file eg foo.s
  char exename[64]; // name of exe eg foo.exe
  char iname[64]; // name of postprocessed source eg foo.i
  char oname[64]; // foo.o file

  // 012345678
  // dir/foo.c
  for (i=strlen(fname)-1; i>=0; i--)
  {
    char c = fname[i];
    if (c=='/' || c=='\\') 
    {
      strcpy(name, fname+i+1);
      break;
    }
  }

  if (i<0)
    strcpy(name,fname);

  for(i=strlen(name);i>=0;i--)
  {
    if (name[i]=='.')
      break;
  }

  if (i<0) 
  {
      printf("Expected file ending .c");
      exit(1);
  }

  strcpy(sname,name);
  sname[i]='\0';
  strcat(sname,".s");

  strcpy(exename,name);
  exename[i]='\0';
  strcat(exename,".exe");

  strcpy(iname,name);
  iname[i]='\0';
  strcat(iname,".i");

  strcpy(oname,name);
  oname[i]='\0';
  strcat(oname,".o");
  
  printf("name=%s\n",name);
  printf("sname=%s\n",sname);  
  printf("exename=%s\n",exename);
  printf("iname=%s\n",iname);
  printf("oname=%s\n",oname);
  
  // ----------------------------------------------------------------------
  // Preprocess
  // ----------------------------------------------------------------------

  char cmd[256];

  sprintf(cmd, "gcc -E %s > %s", fname, iname);

  printf("SYSTEM: %s\n",cmd);
  system(cmd);

  // ----------------------------------------------------------------------
  // Read entire source file into "source"
  // ----------------------------------------------------------------------

  FILE* fp;
  fp=fopen(iname, "rb");
  if (fp==NULL)
  {
    printf("file not found\n");
    exit(1);
  }

  fseek(fp, 0L, SEEK_END);
  int sz = ftell(fp);
  rewind(fp);

  char *source=(char*)malloc(sz+1);
  fread(source,1,sz,fp);
  fclose(fp);

  source[sz]='\0';

  // ----------------------------------------------------------------------
  // Get list of tokens starting at head
  // ----------------------------------------------------------------------

  printf("%s###\n",source);
  printf("source length=%d\n",strlen(source));

  lineno=1;

  char *st, *ed;
  struct Token *head, *prev, *tok, *stringStart, *p;
  
  head=getTok(source,&ed);
  prev=head;
  st=ed;

//  printf("head: %d %s %s\n", head->type, names[head->type], head->id);
  
  while(1)
  {
    tok=getTok(st,&ed);
    if (tok==NULL) break;
            
    if (tok->type==IDENTIFIER && strcmp(tok->id, "__attribute__") == 0)   // discard __attribute__((whatever))
    {        
        printf("found __attribute__\n");
        st=ed;
        for (i=1;i<=5;i++)
        {
            getTok(st, &ed);
            st=ed;
        }
        continue;
    }

    prev->next=tok;
    prev=tok;
    st=ed;
  }
  
  free(source);

  // ----------------------------------------------------------------------
  // concatenate multiple string literals
  // ----------------------------------------------------------------------

  int inString=0;
  tok=head;
  while(tok!=NULL)
  {

    if (tok->type==STRING_LITERAL && !inString)
    {
        stringStart=tok;
        inString=1;
    }

    if (inString && tok->type!=STRING_LITERAL)
    {
        inString=0;
        p=stringStart;
        int len=0, n=0;
        while(p!=tok)
        {
            printf("%s %s %d\n", names[p->type], p->id, strlen(p->id));
            n++;
            len+=strlen(p->id);
            p=p->next;
        }
        printf("multistring %d %d\n",n,len);
        if (n>1)
        {
            stringStart->id = realloc(stringStart->id, len+1);
            p=stringStart->next;
            while(p!=tok)
            {
                strcat(stringStart->id,p->id);
                // could free the Token here
                p=p->next;
            }
            stringStart->next=tok;
        }
    }            
    tok=tok->next;
  }

  // ----------------------------------------------------------------------
  // Write out tokens list
  // ----------------------------------------------------------------------

  if (dumpLex)
  {
      tok=head;
      while(tok!=NULL)
      {
        printf("%s [%d]",names[tok->type], tok->lineno);
        if (tok->type==IDENTIFIER || tok->type==INT_LITERAL || tok->type==FLOAT_LITERAL || tok->type==STRING_LITERAL || tok->type == CHAR_LITERAL)
          printf(": '%s'\n",tok->id);
        else 
          printf("\n");
        
        tok=tok->next;
      }
  }
  
  if (lexOnly) return 0;

  // ----------------------------------------------------------------------
  // Construct AST tree
  // ----------------------------------------------------------------------

  tokenHead=head;
  struct Node *tree=parse_program();

  // ----------------------------------------------------------------------
  // Write out the AST tree
  // ----------------------------------------------------------------------

  if (dumpParse)
  {
      writeTree(tree,0);

      printf("EnumConst list:\n");      
      struct EnumConst* p=enumConstEnd;      
      while (p!=NULL)
      {
          printf("%s %d\n",p->name, p->value);
          p=p->prev;
      }

      printf("TypeDef list:\n");      
      struct TypeDef* q=typeDefEnd;      
      while (q!=NULL)
      {
          printf("%s %s\n", q->name, q->type.data);
          q=q->prev;
      }

  }

  if (parseOnly)
      return 0;
  
  // ----------------------------------------------------------------------
  // Write out assembly
  // ----------------------------------------------------------------------

  fps=fopen(sname,"w");
  fprintf(fps,".intel_syntax noprefix\n");

  writeAsm(tree,0,0,0);

  fclose(fps);
  
//  exit(1);

  // ----------------------------------------------------------------------
  // Assemble generated ASM code into .o file
  // ----------------------------------------------------------------------

  sprintf(cmd,"gcc -c %s",sname);
  printf("SYSTEM: %s\n",cmd);
  system(cmd);
  
  if (compileOnly) return 0;

  // ----------------------------------------------------------------------
  // if not -c also link to .exe
  // ----------------------------------------------------------------------

  sprintf(cmd,"gcc -o %s %s floatlib.o",exename,oname);
  printf("SYSTEM: %s\n",cmd);
  system(cmd);

  return 0;
}
