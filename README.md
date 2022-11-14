# jcc
A simple C compiler written in C which outputs x86 assembly. So far it supports only a subset of the C89 language. This project is just an experiment and should not be used for anything serious!

I wrote this compiler based on the excellent tutorial by Nora Sandler: https://norasandler.com/2017/11/29/Write-a-Compiler.html

The compiler source consists of a single file, `main.c`.

Compile the compiler using `compile.bat` (which uses gcc/mingw on Windows, see below)

Run it using,

```
jcc path/to/source.c
```
eg

```
jcc fibonacci.c
jcc expr.c
```

This creates assembly language `source.s` in the same directory. Having written this file, the compiler calls the assembler to assemble into an object file and then link into an executable (`source.exe`). You will see the call to gcc which accomplishes this. The assembly file (`source.s`) has some comments in it (beginning with `#`) which show the state of the variables list at various times. The assembler will ignore these.

In addition to compiling, the compiler writes lots of debug info to stdout. First it writes the output from the lexer (tokens), then the output from the parser (an Abstract Syntax Tree of Nodes)

I have used the 32-bit gcc/mingw compiler for Windows to compile the compiler and also to act as assembler (ie I'm using Gnu's AS assembler). Thus, the assembler directives in the `.s` file are in AS format, including the use of `#` as comments. You will see various directives in the `.s` file beginning with dots eg `.intel_syntax noprefix` specifies to use the more readable Intel syntax for the x86 assembly language (not AT&T).

The compiler supports only a subset of the ANSI C89 language (maybe 90%). Here is an example of code it can compile

```
int fib(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    } 
    else 
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int n = 10;
    printf("The %d-th Fibonacci number is %d\n", n, fib(n));
    return 0;
}
```

This source file is provided as `fibonacci.c`.

The compiler implements the following language features:

* int (4 bytes) and char (1 byte) base types. Also literal strings and void.
* arrays, pointers and structs are fully supported.
* All C operators are supported except for the comma operator (,) and the ternary operator (?:)
* for, if, do, while fully supported
* variable scope fully supported including local and global variables. New variables can be declaraed anywhere inside a block.
* function calls supported using the cdecl calling convention only. Can call the std library no problem!

Limitations include:

* No floats or doubles yet.
* Only int and char base types supported. Qualifiers short/long and signed/unsigned are not supported.
* No support for `switch, case, default, union, enum, typedef, goto`
* No support for qualifiers `auto, const, extern, register, static, volatile`
* Single initialisations like `int i=j+k;` are supported but more complex block initialisation is not
 fully implemented. However `int i[]={1,2,3}` and `char* names[]={"foo","bar","zap"}` are allowed for global variables only.
* Function pointers are not supported. Types may not include parentheses eg `struct Foo**[3][6]` is allowed but `int (*fp)()` is not.
(note there is no limit to the number of array dimensions or pointer dereferences)
* Function prototypes are parsed but only the return value is considered. No coercion is done when calling functions or on return values.

There's a long way to go but...

**The compiler is now advanced enough to compile itself!**

Note also that the compiler does not include a preprocessor so directives like `#include` are not supported. However, such includes would not be meaningful to the compiler anyway: the compiler ignores function prototypes (except for return values)
and would not understand a lot of code in standard library headers. The above code will compile and 
run fine even though `printf` is not declared (you could also write the prototype by hand). When calling a function, the compiler simply passes the 
arguments through not checking or coercing types (or even the number of arguments).

This code does not include a linker: the compiler's only function is to create an assembly language file (`.s`) which must be assembled into an object file (`.o`) then linked into an executable or library.

# How it works

The program first lexes the source file then parses it. The output from both stages is dumped to stdout. For the above example code, the lexer gives:
```
INT_DECLARATION
IDENTIFIER: 'fib'
OPEN_BRACKET
INT_DECLARATION
IDENTIFIER: 'n'
CLOSE_BRACKET
OPEN_BRACE
IF
OPEN_BRACKET
IDENTIFIER: 'n'
EQUALS2
INT_LITERAL: '0'
PIPE2
IDENTIFIER: 'n'
EQUALS2
INT_LITERAL: '1'
CLOSE_BRACKET
OPEN_BRACE
RETURN
IDENTIFIER: 'n'
SEMICOLON
CLOSE_BRACE
ELSE
OPEN_BRACE
RETURN
IDENTIFIER: 'fib'
OPEN_BRACKET
IDENTIFIER: 'n'
MINUS
INT_LITERAL: '1'
CLOSE_BRACKET
PLUS
IDENTIFIER: 'fib'
OPEN_BRACKET
IDENTIFIER: 'n'
MINUS
INT_LITERAL: '2'
CLOSE_BRACKET
SEMICOLON
CLOSE_BRACE
CLOSE_BRACE
INT_DECLARATION
IDENTIFIER: 'main'
OPEN_BRACKET
CLOSE_BRACKET
OPEN_BRACE
INT_DECLARATION
IDENTIFIER: 'n'
EQUALS
INT_LITERAL: '10'
SEMICOLON
IDENTIFIER: 'printf'
OPEN_BRACKET
STRING: 'The %d-th Fibonacci number is %d\n'
COMMA
IDENTIFIER: 'n'
COMMA
IDENTIFIER: 'fib'
OPEN_BRACKET
IDENTIFIER: 'n'
CLOSE_BRACKET
CLOSE_BRACKET
SEMICOLON
RETURN
INT_LITERAL: '0'
SEMICOLON
CLOSE_BRACE
```
These tokens are placed in a one dimensional list of structs of the type
```
struct Token
{
  int type;
  char *id;
  struct Token *next;
};
```
The type could be an identifier (variable), an int literal, a C keyword such as `return` or one of many punctuation symbols such as `OPEN_BRACKET`. The `id` is defined only
for identifiers and literals. The tokens are assembled into a linked list pointed to by global variable `tokenHead`. Function `getTok` is called repeatedly to generate these Tokens.
The parser then takes these tokens and creates an Abstract Syntax Tree. The output from the parser, for the same example, is
```
PROGRAM
   FUNCTION: 'fib' [int]
      ARG: 'n' [int]
      IF
         BINARY_OR
            BINARY_EQUAL
               VAR: 'n'
               INT_LITERAL: '0'
            BINARY_EQUAL
               VAR: 'n'
               INT_LITERAL: '1'
         BLOCK
            RETURN
               VAR: 'n'
         BLOCK
            RETURN
               BINARY_PLUS
                  CALL: 'fib'
                     BINARY_MINUS
                        VAR: 'n'
                        INT_LITERAL: '1'
                  CALL: 'fib'
                     BINARY_MINUS
                        VAR: 'n'
                        INT_LITERAL: '2'
   FUNCTION: 'main'
      DECL: 'n' [int]
         INT_LITERAL: '10'
      EXPR
         CALL: 'printf'
            STRING: 'The %d-th Fibonacci number is %d\n'
            VAR: 'n'
            CALL: 'fib'
               VAR: 'n'
      RETURN
         INT_LITERAL: '0'
```
The AST is made of Nodes of the type
```
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
```
Each Node has a type such as `BINARY_PLUS`, `VAR` (a reference to a variable), `DECL` (a variable declaration) etc. `id` is the name of the node if needed
(function, variable reference, declaration, call, literals etc) otherwise ignored. `varType` is the variable type if appropriate stored as a string with

```
struct Type
{
    char data[32];
};
```

Each Node has a certain number of children with different meaning depending on the type (the other children are not used):

* unary operators have 1 child (`child`)
* binary operators have 2 children (`child` and `child2`), 
* `IF` statements have 3 children (`child` is the condition, `child2` is the positive branch, `child3` is the else branch (if present else NULL))
* `FOR` statements have 4 children (`child` is the initialiser, `child2` is the condition, `child3` is the increment, `child4` is the body)
* `WHILE` has 2 children (`child` is the condition and `child2` is the body)
* `DO` has 2 children (`child` is the body and `child2` is the condition)

The "bodies" mentioned above can be a single statement, a block (see next) or another if, for etc...
Some nodes have an arbitrary number of children, stored in `line` with `nlines` being the number of children:

* `FUNCTION` the first n children are the arguments then each child is a statement in the function (where "statement" can be a block, if etc)
* `BLOCK` each child is a statement in the block ("statement" can be another block, an if, for etc)
* `CALL` each child is function parameter
* `PROGRAM` each child is a function, function prototype or global variable

The AST is generated by calling `parse_program` which recursively calls a series of other functions `parse_xxx`. These functions advance pointer `tokenHead` (a global variable)
until no more tokens are available.

Finally `writeAsm` creates the assembly language from the AST. It is a recursive function. As it generates code, this function maintains a linked list (a stack) of local variables of the form:
```
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
```
where `id` is the variable name, `level` is the scoping level with 0 being global scope, 1 function level scope and higher numbers being within (nested) blocks.
`offset` is the offset of each variable on the stack (negative for local variables, positive for function arguments).

`varType` is the variable type stored as a fixed length string eg `int*[3][6]`. `isArg` specifies if the variable is a function argument.
`structNode` is a pointer to the AST which is used when defining structs. Note that when a struct is declared its name is pushed onto the variable stack with 
`structNode` pointing to the AST location of the struct.

The compiler uses the machine stack to evaluate expressions pushing and poping values onto it to do calculations. Values from this "calculator stack" are popped off onto the `eax` and `ecx` registers to do calculations and these are the only registers used. When calling functions `jcc` uses only the `cdecl` calling convention (arguments pushed onto the stack right to left and `eax`, `ecx`, `edx` corrupted during the call: caller must preserve these. Return value put on eax [in fact the compiler doesn't use `edx`]). A stack frame is set up using `esp` and `ebp`. Note that local variables within inner scopes (eg in an if-block) are created on demand by pushing them onto the stack. This is different from commercial compilers which will create all local variables within a function right at the beginning of the function.
So the compiler doesn't need to worry about registers getting corrupted when it calls a function: everything is pushed onto the stack.
