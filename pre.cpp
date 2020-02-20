#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <vector>

using namespace std;

const char* tokNames[] = { ";",  "(",  ")",  "{",  "}",  "-", "~", "+", "*", "/",
          "&&", "||", "==", "!=", "<=", "<", ">=", ">", "!", "=", ",",
          "#define", "#undef", "#include", "#if", "#ifdef", "#ifndef", "#elif", "#else", "#endif" };
int numToks = 30;

#define SEMICOLON 0
#define OPEN_BRACKET 1
#define CLOSE_BRACKET 2
#define OPEN_BRACE 3
#define CLOSE_BRACE 4 
#define MINUS 5
#define TILDE 6
#define PLUS 7
#define ASTERISK 8
#define SLASH 9
#define AND 10
#define OR 11
#define EQUAL 12
#define NOT_EQUAL 13
#define LESS_THAN_OR_EQUAL 14
#define LESS_THAN 15
#define GREATER_THAN_OR_EQUAL 16
#define GREATER_THAN 17
#define EXCLAMATION 18
#define ASSIGNMENT 19
#define COMMA 20
#define DEFINE 21           
#define UNDEF 22
#define INCLUDE 23
#define IF 24
#define IFDEF 25
#define IFNDEF 26
#define ELSE 27
#define ELIF 28
#define ENDIF 29

#define INT_LITERAL 30      // eg 123
#define IDENTIFIER 31       // eg main

#define FUNCTION 32         // AST only
#define UNARY_MINUS 33
#define UNARY_COMPLEMENT 34
#define UNARY_NOT 35
#define BINARY_PLUS 36
#define BINARY_MINUS 37
#define BINARY_TIMES 38
#define BINARY_DIVIDE 39
#define BINARY_AND 40
#define BINARY_OR 41
#define BINARY_EQUAL 42
#define BINARY_NOT_EQUAL 43
#define BINARY_LESS_THAN_OR_EQUAL 44
#define BINARY_LESS_THAN 45
#define BINARY_GREATER_THAN_OR_EQUAL 46
#define BINARY_GREATER_THAN 47
#define VAR 48
#define EXPR 49
#define DECL 50
#define BLOCK 51
#define CALL 52
#define ARG 53
#define GLOBAL 54
#define PROGRAM 55

const char* names[] = {
  "SEMICOLON",
  "OPEN_BRACKET",
  "CLOSE_BRACKET",
  "OPEN_BRACE",
  "CLOSE_BRACE",
  "MINUS",
  "TILDE",
  "PLUS",
  "ASTERISK",
  "SLASH",
  "AND",
  "OR",
  "EQUAL",
  "NOT_EQUAL",
  "LESS_THAN_OR_EQUAL",
  "LESS_THAN",
  "GREATER_THAN_OR_EQUAL",
  "GREATER_THAN",
  "EXCLAMATION",
  "ASSIGNMENT",
  "COMMA",
  "DEFINE",
  "UNDEF",
  "INCLUDE",
  "IF",
  "IFDEF",
  "IFNDEF",
  "ELIF",
  "ELSE",
  "ENDIF",

  "INT_LITERAL",
  "IDENTIFIER",

  "FUNCTION",            // AST only
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
  "VAR",
  "EXPR",
  "DECL",
  "BLOCK",
  "CALL",
  "ARG",
  "GLOBAL",
  "PROGRAM"
};

struct Token
{
    int type;
    char* id;
};

struct Node
{
    int type;
    char* id;
    Node* child;
    Node* child2;
    Node* child3;
    Node* child4;
    Node** line;   // lines of code in functions
    int nlines;
};

struct Var
{
  char *name;
  vector<Token> val;
};

int g_offset;
struct Var* varEnd;
struct Token* tokenHead;  // global for parsing

FILE* fps;

struct Node* parse_exp(); // forward declaration

char* newStr(char* from)
{
    int len = strlen(from);
    char* to = (char*)malloc(len + 1);
    strcpy(to, from);
    return to;
}

// ######################################################################
// Starting at st, read past white space and get next token.
// Allocate and return a token struct. Return ed, pointer to where we got to
// Return token with type=-1 if nothing left
// If dryrun, don't alloc or fill id. Caller needs to free returned token

Token getTok(char* st, char** ed, bool dryrun)
{
    int i, j;
    Token tok;

    while (isspace(*st)) 
    {
        st++;
    }

    if (*st == '\0'){
      tok.type=-1;
      return tok;
    }

    int lenleft = strlen(st);

    for (j = 0; j < numToks; j++) {
        int lentok = strlen(tokNames[j]);
        if (lentok >= lenleft) continue;
        int puncTok = j < DEFINE;
        int good = 1;
        for (i = 0; i < lentok; i++) {
            if (*(st + i) != tokNames[j][i]) {
                good = 0;
                break;
            }
        }
        if (good && (puncTok || !isalnum(*(st + lentok)))) {
            *ed = st + lentok;
            tok.type = j;
            return tok;
        }
    }

    int idOK = isalpha(*st);
    int literalOK = isdigit(*st);
    char* p = st;

    while (*p != '\0') {
        if (!isalnum(*p)) {   // punctuation, space, 0

            if (idOK) {
                *ed = p;
                tok.type = IDENTIFIER;
                if (!dryrun)
                {
                    int sz = *ed - st;
                    tok.id = (char*)malloc(sz + 1);
                    memcpy(tok.id, st, sz);
                    tok.id[sz] = '\0';
                }
                return tok;
            }

            if (literalOK) {
                *ed = p;
                tok.type = INT_LITERAL;
                if (!dryrun)
                {
                    int sz = *ed - st;
                    tok.id = (char*)malloc(sz + 1);
                    memcpy(tok.id, st, sz);
                    tok.id[sz] = '\0';
                }
                return tok;
            }

            printf("Lexer: Unknown token: ");
            char* q;
            for (q = st; q <= p; q++) putchar(*q);
            putchar('\n');
            exit(1);
        }

        if (!isalnum(*p))
            idOK = 0;

        if (!isdigit(*p))
            literalOK = 0;

        p++;
    }
    printf("Error unexpected end of file\n");
    exit(1);
}

vector<Token> getTokLine(char *buff)
{
    char* st = buff;
    char* ed;

    vector<Token> tl;

    while(true){
      Token tok = getTok(st, &ed, false);
      if (tok.type == -1) break;
      tl.push_back(tok);
      st = ed;
    }

    return tl;
}

void writeTok(Token tok)
{
    if (tok.type == IDENTIFIER)
    {
        printf("%s", tok.id);
    }
    else if (tok.type == INT_LITERAL)
    {
        printf("%s", tok.id);
    }
    else
    {
        printf(tokNames[tok.type]);
    }
    printf(" ");
}

int main(int argc, char** argv)
{
    vector<vector<Token> > head;
    char buff[256];
    vector<Var> vars;

    FILE* fp = fopen("pretest.c", "r");

    while (fgets(buff, 256, fp) != NULL){
      head.push_back(getTokLine(buff));
    }
    
    fclose(fp);

    for (int line=0;line<head.size();line++){
      for (int i = 0; i < head[line].size(); i++) {
	Token tok = head[line][i];
	printf("%s", names[tok.type]);
	
	if (tok.type == IDENTIFIER || tok.type == INT_LITERAL)
	  printf(": '%s'\n", tok.id);
	else
	  printf("\n");
      }
      printf("--------------------\n");
    }
    
    for (int line=0;line<head.size();line++){      
      vector<Token> tl=head[line];

      if (tl.size()==0) {
	printf("\n");
	continue;
      }

      if (tl[0].type == DEFINE){
	Var var;	
	var.name = newStr(tl[1].id);
	var.val = tl;
	vars.push_back(var);
	
	continue;
      }

      bool replaced;
      do{
	replaced=false;
	for (int i = 0; i < tl.size(); i++){
	  Token tok = tl[i];
	  
	  if (tok.type == IDENTIFIER){
	    vector<Token> tlval;
	    bool found=false;
	    
	    for (int v = 0; v < vars.size(); v++){
	      if (strcmp(vars[v].name, tok.id) == 0){
		tlval = vars[v].val;
		found=true;
		break;
	      }
	    }
	    
	    if (found){
	      vector<Token>::iterator it=tl.begin()+i;
	      tl.erase(it,it+1);
	      for (int j = tlval.size() - 1; j>=2; j--) {
		it=tl.begin()+i;
		tl.insert(it,tlval[j]);
	      }
	      replaced=true;
	    }
	  }
	}
      } while(replaced);
	
      for (int i = 0; i < tl.size(); i++){
	writeTok(tl[i]);
      }
      printf("\n");
    }

    for (int i=0;i<vars.size();i++){
      printf("%s := ",vars[i].name);
      for (int j = 2; j < vars[i].val.size(); j++){
	writeTok(vars[i].val[j]);
      }
      printf("\n");
    }

    return 0;
}
