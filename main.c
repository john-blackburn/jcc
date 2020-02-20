/*
Usage:
jcc path/to/foo.c
Creates foo.s in current directory and assembles/links to get foo.exe
TODO:
Additional operators: unary+, binary-&, |, <<, >>, ^, %, ternary ?:, sizeof
+= -= /= *= %= <<= >>= &= |= ^= ++ -- comma operator
break
struct, pointer, array (unary-&, unary-*, ., ->, [])
char, 'a', "string literal"

Not needed to compile this compiler:
switch, case, default, union, enum, typedef, goto, continue
auto, const, double, extern, float, long, register, short, (un)signed, static, void, volatile
Function protoypes (currently ignored)
Initialise arrays. char foo[]={'f','o','o'}="foo". int foo[]={1,2,3}. char *foo[]={"hello","world"}
Multi-dim arrays

Other calling conventions. Stack alignment.
Pre-processor
Linker
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char *tokNames[]={"<<=", ">>=",

		  "&&", "||", "==", "!=", "<=", ">=", "<<", ">>", 
		  "++", "--", "->",
		  "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=",

		  "<", ">", "!", "=", ",", ";", ".", "(",  ")", "{", "}", "[", "]",
		  "+", "-", "*", "/", "%", "&", "|", "^", "~",

		  "return", "int", "if", "else", "for", "while", "do", "break", "continue"};

/*
char *tokNames[]={";",  "(",  ")",  "{",  "}",  "-", "~", "+", "*", "/", 
		  "&&", "||", "==", "!=", "<=", "<", ">=", ">", "!", "=", ",",
		  "return", "int", "if", "else", "for", "while", "do", "break", "continue"};
*/
int numToks=52;

#define LESSTHAN2_EQUAL 0
#define GREATERTHAN2_EQUAL 1
#define AMP2 2
#define PIPE2 3
#define EQUALS2 4
#define EXCLAM_EQUAL 5
#define LESSTHAN_EQUAL 6
#define GREATERTHAN_EQUAL 7
#define LESSTHAN2 8
#define GREATERTHAN2 9
#define PLUS2 10
#define MINUS2 11
#define MINUS_GREATERTHAN 12
#define PLUS_EQUALS 13
#define MINUS_EQUALS 14
#define ASTERISK_EQUALS 15
#define SLASH_EQUALS 16
#define PERCENT_EQUALS 17
#define AMP_EQUALS 18
#define PIPE_EQUALS 19
#define HAT_EQUALS 20
#define LESSTHAN 21
#define GREATERTHAN 22
#define EXCLAM 23
#define EQUALS 24
#define COMMA 25
#define SEMICOLON 26
#define DOT 27
#define OPEN_BRACKET 28
#define CLOSE_BRACKET 29
#define OPEN_BRACE 30
#define CLOSE_BRACE 31 
#define OPEN_SQUARE 32
#define CLOSE_SQUARE 33 
#define PLUS 34
#define MINUS 35
#define ASTERISK 36
#define SLASH 37
#define PERCENT 38
#define AMP 39
#define PIPE 40
#define HAT 41
#define TILDE 42
#define RETURN 43           // "return"
#define INT_DECLARATION 44  // "int"
#define IF 45
#define ELSE 46
#define FOR 47
#define WHILE 48
#define DO 49
#define BREAK 50
#define CONTINUE 51

#define INT_LITERAL 52      // eg 123
#define IDENTIFIER 53       // eg main
#define STRING 54           // "hello, world!\n"
#define CHAR 55             // '\n'

#define FUNCTION 56         // AST only
#define UNARY_MINUS 57
#define UNARY_COMPLEMENT 58
#define UNARY_NOT 59
#define BINARY_PLUS 60
#define BINARY_MINUS 61
#define BINARY_TIMES 62
#define BINARY_DIVIDE 63
#define BINARY_AND 64
#define BINARY_OR 65
#define BINARY_EQUAL 66
#define BINARY_NOT_EQUAL 67
#define BINARY_LESS_THAN_OR_EQUAL 68
#define BINARY_LESS_THAN 69
#define BINARY_GREATER_THAN_OR_EQUAL 70
#define BINARY_GREATER_THAN 71
#define ASSIGNMENT 72
#define VAR 73
#define EXPR 74
#define DECL 75
#define BLOCK 76
#define CALL 77
#define ARG 78
#define GLOBAL 79
#define PROGRAM 80
#define PROTOTYPE 81

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
  "RETURN",           // "return"
  "INT_DECLARATION",  // "int"
  "IF",
  "ELSE",
  "FOR",
  "WHILE",
  "DO",
  "BREAK",
  "CONTINUE",

  "INT_LITERAL",      // eg 123
  "IDENTIFIER",       // eg main
  "STRING",           // "hello, world!"
  "CHAR",             // 'a'

  "FUNCTION",         // AST only
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
  "PROTOTYPE"
};

struct Token
{
  int type;
  char *id;
  struct Token *next;
};

struct Node
{
  int type;
  char *id;
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
  int level;
  int offset;
  struct Var *prev;
};

int g_offset;
struct Var *varEnd;
struct Token *tokenHead;  // global for parsing

FILE* fps;

struct Node *parse_exp(); // forward declaration

void advance()
{
  if (tokenHead==NULL) perror("Unexpected end of file");
  tokenHead=tokenHead->next;
}

int getType()
{
  if (tokenHead==NULL) perror("Unexpected end of file");
  return tokenHead->type;
}

// ######################################################################

void fail(char *err)
{
  printf("Error: %s got %s\n",err,names[getType()]);
  exit(1);
}

// ######################################################################

char* newStr(char *from)
{
  int len=strlen(from);
  char* to=(char*)malloc(len+1);
  strcpy(to,from);
  return to;
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

    if (p->type==SEMICOLON && nlevel==0)
      nlines++;

    if (p->type==ELSE && nlevel==0) nlines--;
    if (p->type==DO && nlevel==0) nlines--;
    if (p->type==FOR && nlevel==0) nlines-=2;
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

// 2 or -2
struct Node* parse_factor()
{
  struct Node *exp=(struct Node*)malloc(sizeof(struct Node));
  int type=getType();

  if (type==OPEN_BRACKET){
    advance();
    exp=parse_exp();
    if (type != CLOSE_BRACKET) fail("Expected )");
    advance();
  }
  else if (type==INT_LITERAL){
    exp->type=INT_LITERAL;
    exp->id=newStr(tokenHead->id);
    exp->child=NULL;    
    advance();
  }
  else if (type==STRING){
    exp->type=STRING;
    exp->id=newStr(tokenHead->id);
    exp->child=NULL;
    advance();
  }
  else if (type==CHAR){
    exp->type=CHAR;
    exp->id=newStr(tokenHead->id);
    exp->child=NULL;
    advance();
  }
  else if (type==IDENTIFIER && tokenHead->next->type==OPEN_BRACKET){
    exp->type=CALL;
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
    if (getType()!=CLOSE_BRACKET) fail("expected )");
    advance();
  }
  else if (type==IDENTIFIER){
    exp->type=VAR;
    exp->id=newStr(tokenHead->id);
    exp->child=NULL;

    advance();
  }
  else if (type==MINUS){
    exp->type=UNARY_MINUS;
    advance();
    exp->child=parse_factor();
  }
  else if (type==TILDE){
    exp->type=UNARY_COMPLEMENT;
    advance();
    exp->child=parse_factor();
  }
  else if (type==EXCLAM){
    exp->type=UNARY_NOT;
    advance();
    exp->child=parse_factor();
  }
  else
    fail("Expected literal or unary operator");

  return exp;
}

// ######################################################################

//3*5*7
struct Node* parse_term()
{
  struct Node *factor=parse_factor();
  int nextType=getType();
  while (nextType==ASTERISK || nextType==SLASH){
    advance();
    struct Node *next_factor=parse_factor();
    struct Node *new_factor=(struct Node*)malloc(sizeof(struct Node));

    if (nextType==ASTERISK)
      new_factor->type=BINARY_TIMES;
    else
      new_factor->type=BINARY_DIVIDE;

    new_factor->child=factor;
    new_factor->child2=next_factor;
    factor=new_factor;
    nextType=getType();
  }

  return factor;
}

// ######################################################################

//1+2+3
struct Node* parse_additive_exp()
{
  struct Node *term=parse_term();
  int nextType=getType();
  while (nextType==PLUS || nextType==MINUS){
    advance();
    struct Node *next_term=parse_term();
    struct Node *new_term=(struct Node*)malloc(sizeof(struct Node));

    if (nextType==PLUS)
      new_term->type=BINARY_PLUS;
    else
      new_term->type=BINARY_MINUS;

    new_term->child=term;
    new_term->child2=next_term;
    term=new_term;
    nextType=getType();
  }

  return term;
}

// ######################################################################

//1<2<=3
struct Node* parse_relational_exp()
{
  struct Node *term=parse_additive_exp();
  int nextType=getType();
  while (nextType==GREATERTHAN || nextType==LESSTHAN ||
	 nextType==GREATERTHAN_EQUAL || nextType==LESSTHAN_EQUAL){
    advance();
    struct Node *next_term=parse_additive_exp();
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

    new_term->child=term;
    new_term->child2=next_term;
    term=new_term;
    nextType=getType();
  }

  return term;
}

// ######################################################################

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

    new_term->child=term;
    new_term->child2=next_term;
    term=new_term;
    nextType=getType();
  }

  return term;
}

// ######################################################################

//1 && 2 && 3
struct Node* parse_and_exp()
{
  struct Node *term=parse_equality_exp();
  int nextType=getType();
  while (nextType==AMP2){
    advance();
    struct Node *next_term=parse_equality_exp();
    struct Node *new_term=(struct Node*)malloc(sizeof(struct Node));

    new_term->type=BINARY_AND;

    new_term->child=term;
    new_term->child2=next_term;
    term=new_term;
    nextType=getType();
  }

  return term;
}

// ######################################################################

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

    new_term->child=term;
    new_term->child2=next_term;
    term=new_term;
    nextType=getType();
  }

  return term;
}

// ######################################################################

struct Node* parse_exp()
{
  struct Node *exp;
  if (getType()==IDENTIFIER && tokenHead->next->type==EQUALS){
    exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=ASSIGNMENT;
    exp->id=newStr(tokenHead->id);
    advance();
    advance();

    exp->child=parse_exp();
  }
  else{
    exp=parse_or_exp();
  }
  return exp;
}

// ######################################################################

// return 2;
struct Node* parse_statement()
{
  struct Node *statement=(struct Node*)malloc(sizeof(struct Node));

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
  else if (getType()==INT_DECLARATION){
    advance();
    statement->type=DECL;
    statement->id=newStr(tokenHead->id);
    advance();

    if (getType()==EQUALS){
      advance();
      statement->child=parse_exp();
    }
    else
      statement->child=NULL;

    if (getType()!=SEMICOLON) fail("Expected ;");
    advance();
  }
  else{
    statement->type=EXPR;    
    statement->child=parse_exp();  // removes 2
    
    if (getType()!=SEMICOLON) fail("Expected ;");
    advance();
  }
  return statement;
}

// ######################################################################

struct Node* parse_arg()
{
  if (getType()!=INT_DECLARATION) fail("Expected int in arg declaration");
  advance();
  if (getType()!=IDENTIFIER) fail("Expected identifier in arg declaration");
  
  struct Node* arg=(struct Node*)malloc(sizeof(struct Node));
  arg->type=ARG;
  arg->id=newStr(tokenHead->id);

  advance();
  return arg;
}

// ######################################################################

struct Node* parse_function()
{
  if (getType()!=INT_DECLARATION) fail("Expected return type");
  advance();

  if (getType()!=IDENTIFIER) fail("Expected function name");
  struct Node *function=(struct Node*)malloc(sizeof(struct Node));
  function->type=FUNCTION;
  function->id=newStr(tokenHead->id);
  advance();

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

  if (getType()!=CLOSE_BRACKET) fail("Expected )");
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
  if (getType()!=INT_DECLARATION) fail("expected int");
  advance();

  if (getType()!=IDENTIFIER) fail("Expected function name");
  advance();

  if (getType()!=OPEN_BRACKET) fail("proto expected (");
  advance();

  while(getType()!=CLOSE_BRACKET)
    advance();

  advance();

  if (getType()!=SEMICOLON) fail("expected ;");
  advance();

  struct Node *node=(struct Node*)malloc(sizeof(struct Node));
  node->type=PROTOTYPE;
  return node;
}

// ######################################################################

struct Node* parse_global()
{
  if (getType()!=INT_DECLARATION) fail("expected int");
  advance();

  struct Node *global=(struct Node*)malloc(sizeof(struct Node));
  global->type=GLOBAL;
  global->id=newStr(tokenHead->id);
  advance();

  if (getType()!=SEMICOLON) fail("expected ;");
  advance();

  return global;
}

// ######################################################################

int countGlobals()
{
  int count=0;
  int level=0;
  struct Token *p=tokenHead;
  while (p!=NULL){
    if (p->type==OPEN_BRACE){
      if (level==0) count++;
      level++;
    }
    if (p->type==CLOSE_BRACE)
      level--;
    if (level==0 && p->type==SEMICOLON)
      count++;

    p=p->next;
  }
  if (level!=0) fail("Mismatched braces");
  return count;
}

// ######################################################################

struct Node* parse_program()
{
  struct Node *program=(struct Node*)malloc(sizeof(struct Node));
  program->type=PROGRAM;

  int n=countGlobals();
  program->nlines=n;
  program->line=(struct Node**)malloc(n*sizeof(struct Node*));

  // int foo();
  // int foo(){}
  // int foo;
  // int foo=2;

  int i;
  for (i=0; i<n; i++){
    if (tokenHead->next->next->type==SEMICOLON){
      program->line[i]=parse_global();      
    }
    else{
      struct Token *p=tokenHead;
      while(p->type!=CLOSE_BRACKET){
	if (p==NULL) fail("unexpected end of file");
	p=p->next;
      }
      p=p->next;
      if (p->type==SEMICOLON)
	program->line[i]=parse_prototype();
      else
	program->line[i]=parse_function();
    }
  }

  return program;
}

// ######################################################################
// Starting at st, read past white space and get next token.
// Allocate and return a token struct. Return ed, pointer to where we got to
// Return NULL if nothing left
struct Token* getTok(char *st, char **ed)
{
  int i,j;

  int lenleft=strlen(st);
  if (*st=='\0' || lenleft==0) return NULL;

  while (isspace(*st)){
    if (*st=='\0') return NULL;
    st++;
  }

  struct Token *tok=(struct Token*) malloc(sizeof (struct Token));
  tok->next=NULL;

  for (j=0;j<numToks;j++){
    int lentok=strlen(tokNames[j]);
    if (lentok>=lenleft) continue;
    int puncTok=j<RETURN;
    int good=1;
    for (i=0;i<lentok;i++){
      if (*(st+i)!=tokNames[j][i]){
	good=0;
	break;
      }
    }
    if (good && (puncTok || !isalnum(*(st+lentok)))){
      *ed=st+lentok;
      tok->type=j;
      return tok;
    }
  }

  if (*st=='"'){
    st++;
    char *p=st;
    while(*p!='\0'){
      if (*p=='"'){
	int sz=p-st;
	tok->id=(char*) malloc(sz+1);
	tok->type=STRING;
	memcpy(tok->id,st,sz);
	tok->id[sz]='\0';
	*ed=p+1;
	return tok;
      }
      p++;
    }
    perror("Unexpected EOF while scanning string const");
  }
  else if (*st=='\''){
    st++;
    char *p=st;
    while(*p!='\0'){
      if (*p=='\''){
	int sz=p-st;
	tok->id=(char*) malloc(sz+1);
	tok->type=CHAR;
	memcpy(tok->id,st,sz);
	tok->id[sz]='\0';
	*ed=p+1;
	return tok;
      }
      p++;
    }
    perror("Unexpected EOF while scanning char const");
  }
  else{
    int idOK=isalpha(*st);
    int literalOK=isdigit(*st);
    char *p=st;

    while(*p!='\0'){
      if (!isalnum(*p)){   // punctuation, space, 0
	
	if (idOK){
	  *ed=p;
	  tok->type=IDENTIFIER;
	  int sz=*ed-st;
	  tok->id=(char*) malloc(sz+1);
	  memcpy(tok->id,st,sz);
	  tok->id[sz]='\0';
	  return tok;
	}
	
	if (literalOK){
	  *ed=p;
	  tok->type=INT_LITERAL;
	  int sz=*ed-st;
	  tok->id=(char*) malloc(sz+1);
	  memcpy(tok->id,st,sz);
	  tok->id[sz]='\0';
	  return tok;
	}
	
	printf("Lexer: Unknown token: ");
	char *q;
	for (q=st; q<=p; q++) putchar(*q);
	putchar('\n');
	exit(1);
      }

      if (!isalnum(*p))
	idOK=0;
      
      if (!isdigit(*p))
	literalOK=0;
      
      p++;
    }
  }

  printf("Nothing left\n");
  free(tok);
  return NULL;
}

// ######################################################################

void writeTree(struct Node *node, int indent)
{
  int i;
  for (i=0;i<indent;i++)
    printf(" ");

  printf("%s",names[node->type]);

  int nodetype=node->type;

  if (nodetype==ASSIGNMENT || nodetype==INT_LITERAL || nodetype==FUNCTION || 
      nodetype==VAR || nodetype==DECL || nodetype==CALL || nodetype==ARG || 
      nodetype==GLOBAL || nodetype==STRING || nodetype==CHAR)
    printf(": '%s'\n",node->id);
  else 
    printf("\n");

  if (nodetype==WHILE){
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
  else if (nodetype==EXPR ||
      nodetype==RETURN || 
      nodetype==UNARY_MINUS ||
      nodetype==UNARY_COMPLEMENT ||
      nodetype==UNARY_NOT ||
      nodetype==ASSIGNMENT){    
    writeTree(node->child,indent+3);
  }
  else if (nodetype==BINARY_PLUS ||
	   nodetype==BINARY_MINUS ||
	   nodetype==BINARY_TIMES ||
	   nodetype==BINARY_DIVIDE ||
	   nodetype==BINARY_LESS_THAN ||
	   nodetype==BINARY_LESS_THAN_OR_EQUAL ||
	   nodetype==BINARY_GREATER_THAN ||
	   nodetype==BINARY_GREATER_THAN_OR_EQUAL ||
	   nodetype==BINARY_EQUAL ||
	   nodetype==BINARY_NOT_EQUAL ||
	   nodetype==BINARY_AND ||
	   nodetype==BINARY_OR){
    writeTree(node->child,indent+3);
    writeTree(node->child2,indent+3);
  }
  else if (nodetype==FUNCTION || nodetype==BLOCK || nodetype==CALL || nodetype==PROGRAM){
    int i;
    for (i=0;i<node->nlines;i++){
      writeTree(node->line[i],indent+3);
    }
  }
  else if (nodetype==INT_LITERAL){
    return;
  }
  else if (nodetype==VAR){
    return;
  }
  else if (nodetype==ARG){
    return;
  }
  else if (nodetype==GLOBAL){
    return;
  }
  else if (nodetype==STRING){
    return;
  }
  else if (nodetype==CHAR){
    return;
  }
  else if (nodetype==PROTOTYPE){
    return;
  }
  else if (nodetype==DECL){
    if (node->child!=NULL) writeTree(node->child,indent+3);
    return;
  }
  else{
    printf("Internal compiler error: illegal nodetype (writeTree). Got %d\n",nodetype);
    exit(1);
  }
}

// ######################################################################

void writeVars()
{
  fprintf(fps,"# ======================\n");
  struct Var *p=varEnd;
  while(p!=NULL){
    fprintf(fps,"# %s %d %d\n", p->id, p->level, p->offset);
    p=p->prev;
  }  
  fprintf(fps,"# ======================\n");
}

// ######################################################################

void writeAsm(struct Node *node, int level)
{
  static int s_label=0;
  int nodetype=node->type;

  if (node->type==PROGRAM){
    varEnd=NULL;
    int i;
    for (i=0;i<node->nlines;i++){
      writeAsm(node->line[i], level);
    }
  }
  else if (node->type==GLOBAL){
    fprintf(fps,".data\n");
    fprintf(fps,".globl _%s\n",node->id);
    fprintf(fps,"_%s:\n",node->id);
    fprintf(fps,".long 0\n");
    fprintf(fps,".text\n");

    struct Var *oldVarEnd=varEnd;  // might be NULL
    varEnd=malloc(sizeof(struct Var));
    varEnd->offset=0;
    varEnd->id=newStr(node->id);
    varEnd->level=0;
    varEnd->prev=oldVarEnd;
    writeVars();
  }
  else if (node->type==FUNCTION){

    g_offset=-4;

    int i=0;
    while(node->line[i]->type==ARG){
      struct Var *oldVarEnd=varEnd;  // might be NULL
      varEnd=malloc(sizeof(struct Var));
      varEnd->offset=i*4+8;
      varEnd->id=newStr(node->line[i]->id);
      varEnd->level=1;
      varEnd->prev=oldVarEnd;
      i++;
    }

    fprintf(fps,".globl _%s\n",node->id);
    fprintf(fps,"_%s:\n",node->id);

    fprintf(fps,"push ebp\n");
    fprintf(fps,"mov ebp,esp\n");

    for ( ; i<node->nlines; i++){
      writeAsm(node->line[i], level+1);
    }    

    // Clear local vars (level 1) from list
    // 0  1
    // a<-b
    while(varEnd!=NULL){
      if (varEnd->level>1) perror("Error: Unexpected high level variable\n");
      if (varEnd->level!=1) break;
      struct Var *prev=varEnd->prev;
      free(varEnd);
      varEnd=prev;
    }

    fprintf(fps,"# ** End of function **\n");
    writeVars();

    fprintf(fps,"mov esp,ebp\n");
    fprintf(fps,"pop ebp\n");
    fprintf(fps,"ret\n");
  }
  else if (node->type==PROTOTYPE){    
  }
  else if (node->type==BLOCK){
    int i;
    for (i=0;i<node->nlines;i++){
      writeAsm(node->line[i], level+1);
    }

    // clear local variables in BLOCK from end of list. ADD to ESP, increase g_offset
    int count=0;
    while(varEnd!=NULL){
      if (varEnd->level>level+1) perror("Error: Unexpected high level variable\n");
      if (varEnd->level!=level+1) break;
      struct Var *prev=varEnd->prev;
      free(varEnd);
      count++;
      varEnd=prev;
    }
    fprintf(fps,"add esp,%d\n",4*count);
    g_offset+=4*count;
    fprintf(fps,"# ** End of block **\n");
    writeVars();
  }
  else if (node->type==IF){
    int label=s_label++;
    writeAsm(node->child,level);

    fprintf(fps,"cmp eax, 0\n");          // If cond is false, jump either to end or else
    if (node->child3==NULL)
      fprintf(fps,"je _end%d\n",label);
    else
      fprintf(fps,"je _else%d\n",label);

    writeAsm(node->child2,level);

    if (node->child3!=NULL){
      fprintf(fps,"jmp _end%d\n",label);  // jump over else since if was true
      fprintf(fps,"_else%d:\n",label);

      writeAsm(node->child3,level);
    }

    fprintf(fps,"_end%d:\n",label);
  }
  else if (node->type==WHILE){
    int label=s_label++;

    fprintf(fps,"_start%d:\n",label);

    writeAsm(node->child,level);

    fprintf(fps,"cmp eax, 0\n");
    fprintf(fps,"je _end%d\n",label);

    writeAsm(node->child2,level);
    fprintf(fps,"jmp _start%d\n",label);
    fprintf(fps,"_end%d:\n",label);
  }
  else if (node->type==DO){
    int label=s_label++;

    fprintf(fps,"_start%d:\n",label);

    writeAsm(node->child,level);

    writeAsm(node->child2,level);
    fprintf(fps,"cmp eax, 1\n");

    fprintf(fps,"je _start%d\n",label);
    fprintf(fps,"_end%d:\n",label);
  }
  else if (node->type==FOR){
    int label=s_label++;

    writeAsm(node->child,level);  // init

    fprintf(fps,"_start%d:\n",label);

    writeAsm(node->child2,level); // cond

    fprintf(fps,"cmp eax, 0\n");
    fprintf(fps,"je _end%d\n",label);

    writeAsm(node->child4,level);  // body
    writeAsm(node->child3,level);  // increment
    fprintf(fps,"jmp _start%d\n",label);
    fprintf(fps,"_end%d:\n",label);
  }
  else if (node->type==RETURN){
    writeAsm(node->child,level);
    fprintf(fps,"mov esp,ebp\n");
    fprintf(fps,"pop ebp\n");

    fprintf(fps,"ret\n");
  }
  else if (node->type==EXPR){
    writeAsm(node->child,level);
  }
  else if (node->type==CALL){
    int i;
    for (i=node->nlines-1;i>=0;i--){
      writeAsm(node->line[i],level);
      fprintf(fps,"push eax\n");
    }
    fprintf(fps,"call _%s\n",node->id);
    fprintf(fps,"add esp,%d\n",4*node->nlines);
  }
  else if (node->type==DECL){
    if (node->child!=NULL) writeAsm(node->child,level);
    fprintf(fps,"push eax # declare %s (level %d)\n",node->id,level);

    struct Var *oldVarEnd=varEnd;  // might be NULL
    varEnd=malloc(sizeof(struct Var));
    varEnd->offset=g_offset;
    varEnd->id=newStr(node->id);
    varEnd->level=level;
    varEnd->prev=oldVarEnd;
    g_offset -= 4;

    writeVars();
  }
  else if (node->type==ASSIGNMENT){
    writeAsm(node->child,level);
    struct Var *p=varEnd;
    int offset=0;
    int found=0;
    while(p!=NULL){
      if (strcmp(node->id,p->id)==0){
	offset=p->offset;
	found=1;
	break;
      }
      p=p->prev;
    }
    if (found==0) {printf("Assign to undeclared variable %s\n",node->id); exit(1);}
    if (offset==0)
      fprintf(fps,"mov _%s,eax\n",node->id);
    else
      fprintf(fps,"mov [ebp%+d],eax # %s\n",offset,node->id);
  }
  else if (node->type==UNARY_MINUS){
    writeAsm(node->child,level);
    fprintf(fps,"neg eax\n");
  }
  else if (node->type==UNARY_COMPLEMENT){
    writeAsm(node->child,level);
    fprintf(fps,"not eax\n");
  }
  else if (node->type==UNARY_NOT){
    writeAsm(node->child,level);
    fprintf(fps,"cmp eax,0\n");    // set ZF on if exp == 0, set it off otherwise
    fprintf(fps,"mov eax,0\n");    // zero out EAX (doesn't change FLAGS)
    fprintf(fps,"sete al\n");
  }
  else if (node->type==INT_LITERAL){
    fprintf(fps,"mov eax,%s\n",node->id);
  }
  else if (node->type==STRING){
    int label=s_label++;

    fprintf(fps,".data\n");
    fprintf(fps,"_string%d:\n",label);
    fprintf(fps,".asciz \"%s\"\n",node->id);
    fprintf(fps,".text\n");
    fprintf(fps,"mov eax, offset _string%d\n",label);
  }
  else if (node->type==CHAR){
    fprintf(fps,"mov eax,'%s'\n",node->id);
  }
  else if (node->type==VAR){
    struct Var *p=varEnd;
    int offset=0;
    int found=0;
    while(p!=NULL){
      if (strcmp(node->id,p->id)==0){
	offset=p->offset;
	found=1;
	break;
      }
      p=p->prev;
    }
    if (found==0) {printf("Refer to undeclared variable %s\n",node->id); exit(1);}
    if (offset==0)
      fprintf(fps,"mov eax,_%s\n",node->id);
    else
      fprintf(fps,"mov eax,[ebp%+d] # %s\n",offset,node->id);
  }
  else if (node->type==BINARY_PLUS){
    writeAsm(node->child,level);
    fprintf(fps,"push eax\n");
    writeAsm(node->child2,level);
    fprintf(fps,"pop ecx\n");
    fprintf(fps,"add eax,ecx\n");
  }
  else if (node->type==BINARY_MINUS){
    writeAsm(node->child2,level);
    fprintf(fps,"push eax\n");
    writeAsm(node->child,level);
    fprintf(fps,"pop ecx\n");
    fprintf(fps,"sub eax,ecx\n");
  }
  else if (node->type==BINARY_TIMES){
    writeAsm(node->child2,level);
    fprintf(fps,"push eax\n");
    writeAsm(node->child,level);
    fprintf(fps,"pop ecx\n");
    fprintf(fps,"imul eax,ecx\n");
  }
  else if (node->type==BINARY_DIVIDE){
    writeAsm(node->child2,level);
    fprintf(fps,"push eax\n");
    writeAsm(node->child,level);
    fprintf(fps,"pop ecx\n");
    fprintf(fps,"cdq\n");
    fprintf(fps,"idiv eax,ecx\n");
  }
  else if (
	   nodetype==BINARY_LESS_THAN ||
	   nodetype==BINARY_LESS_THAN_OR_EQUAL ||
	   nodetype==BINARY_GREATER_THAN ||
	   nodetype==BINARY_GREATER_THAN_OR_EQUAL ||
	   nodetype==BINARY_EQUAL ||
	   nodetype==BINARY_NOT_EQUAL){
    writeAsm(node->child2,level);
    fprintf(fps,"push eax\n");       // save value of e1 on the stack
    writeAsm(node->child,level);
    fprintf(fps,"pop ecx\n");         // pop e1 from the stack into ecx - e2 is already in eax
    fprintf(fps,"cmp eax, ecx\n");    // set ZF on if e1 == e2, set it off otherwise
    fprintf(fps,"mov eax, 0\n");      //zero out EAX (doesn't change FLAGS)

    if (nodetype==BINARY_LESS_THAN)      
      fprintf(fps,"setl al\n");
    else if (nodetype==BINARY_LESS_THAN_OR_EQUAL)
      fprintf(fps,"setle al\n");
    else if (nodetype==BINARY_GREATER_THAN)
      fprintf(fps,"setg al\n");
    else if (nodetype==BINARY_GREATER_THAN_OR_EQUAL)
      fprintf(fps,"setge al\n");
    else if (nodetype==BINARY_EQUAL)
      fprintf(fps,"sete al\n");
    else
      fprintf(fps,"setne al\n");
  }
  else if (nodetype==BINARY_OR){
    // 0 || 0 = 0
    // 0 || 1 = 1
    // 1 || 0 = 1
    // 1 || 1 = 1
    int label=s_label++;
    writeAsm(node->child,level);

    fprintf(fps,"cmp eax, 0\n");          // check if e1 is 0
    fprintf(fps,"je _else%d\n",label);    // e1 is 0, so we need to evaluate _else
    fprintf(fps,"mov eax, 1\n");          // we didn't jump, so e1 is 1 and therefore result is 1
    fprintf(fps,"jmp _end%d\n",label);
    fprintf(fps,"_else%d:\n",label);

    writeAsm(node->child2,level);

    fprintf(fps,"cmp eax, 0\n");          // check if e2 is true
    fprintf(fps,"mov eax, 0\n");          // zero out EAX without changing ZF
    fprintf(fps,"setne al\n");           // set AL register (the low byte of EAX) to 1 iff e2 != 0
    fprintf(fps,"_end%d:\n",label);
  }
  else if (nodetype==BINARY_AND){
    // 0 && 0 = 0
    // 0 && 1 = 0
    // 1 && 0 = 0
    // 1 && 1 = 1
    int label=s_label++;
    writeAsm(node->child,level);

    fprintf(fps,"cmp eax, 0\n");          // check if e1 is 0
    fprintf(fps,"jne _else%d\n",label);   // e1 isnt 0, so we need to evaluate _else
    fprintf(fps,"mov eax, 0\n");          // we didn't jump, so e1 is 0 and therefore result is 0
    fprintf(fps,"jmp _end%d\n",label);
    fprintf(fps,"_else%d:\n",label);

    writeAsm(node->child2,level);

    fprintf(fps,"cmp eax, 0\n");          // check if e2 is 0
    fprintf(fps,"mov eax, 0\n");          // zero out EAX without changing ZF
    fprintf(fps,"setne al\n");           // set AL register (the low byte of EAX) to 1 iff e2 != 0
    fprintf(fps,"_end%d:\n",label);
  }
  else{
    printf("Internal compiler error: illegal nodetype (writeAsm). Got %d\n",nodetype);
    exit(1);
  }
}

// ######################################################################

int main(int argc, char **argv)
{

  // ----------------------------------------------------------------------
  // Read source file into source
  // ----------------------------------------------------------------------

  char name[64];
  char sname[64];
  char exename[64];

  if (argc!=2){
    printf("Usage: jcc foo.c\n");
    exit(1);
  }

  FILE* fp;
  fp=fopen(argv[1],"rb");
  if (fp==NULL){
    printf("file not found\n");
    exit(1);
  }

  // 012345678
  // dir/foo.c
  int i;
  for (i=strlen(argv[1])-1; i>=0; i--){
    char c=argv[1][i];
    if (c=='/' || c=='\\') {
      strcpy(name,argv[1]+i+1);
      break;
    }
  }

  if (i<0)
    strcpy(name,argv[1]);

  for(i=strlen(name);i>=0;i--){
    if (name[i]=='.')
      break;
  }

  if (i<0) perror("Expected file ending .c");

  strcpy(sname,name);
  sname[i]='\0';
  strcat(sname,".s");

  strcpy(exename,name);
  exename[i]='\0';
  strcat(exename,".exe");

  printf("name=%s\n",name);
  printf("sname=%s\n",sname);  
  printf("exename=%s\n",exename);

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

  char *st, *ed;
  struct Token *head, *prev, *tok;
  
  head=getTok(source,&ed);
  prev=head;
  st=ed;

  while(1){
    tok=getTok(st,&ed);
    if (tok==NULL) break;

    prev->next=tok;
    prev=tok;
    st=ed;
  }

  // ----------------------------------------------------------------------
  // Write out tokens list
  // ----------------------------------------------------------------------

  tok=head;
  while(tok!=NULL){
    printf("%s",names[tok->type]);
    if (tok->type==IDENTIFIER || tok->type==INT_LITERAL || tok->type==STRING)
      printf(": '%s'\n",tok->id);
    else 
      printf("\n");
    
    tok=tok->next;
  }

  // ----------------------------------------------------------------------
  // Construct AST tree
  // ----------------------------------------------------------------------

  tokenHead=head;
  struct Node *tree=parse_program();

  // ----------------------------------------------------------------------
  // Write out the AST tree
  // ----------------------------------------------------------------------

  writeTree(tree,0);

  // ----------------------------------------------------------------------
  // Write out assembly
  // ----------------------------------------------------------------------

  //  exit(1);

  fps=fopen(sname,"w");
  fprintf(fps,".intel_syntax noprefix\n");

  writeAsm(tree,0);

  fclose(fps);

  char cmd[256];
  sprintf(cmd,"gcc -o %s %s",exename,sname);
  printf("%s\n",cmd);
  system(cmd);

  return 0;
}
