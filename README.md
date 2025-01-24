# jcc
A simple C compiler written in C which outputs x86 assembly (32-bit). So far it supports only a subset of the C89 language. This project is just an experiment and should not be used for anything serious!

I wrote this compiler based on the excellent tutorial by Nora Sandler: https://norasandler.com/2017/11/29/Write-a-Compiler.html

The compiler source consists of a single file, `main.c`.

Compile the compiler using `compile.bat` (which uses gcc/mingw on Windows, see below). You also need to compile the supplied floating point library `floatlib.s` by running `compile_lib.bat`

Run the compiler using,

```
jcc [options] path/to/source.c
```
eg

```
jcc examples\fibonacci.c
jcc examples\expr.c
```

options are:
```
-c: compile only
-dumpLex: dump lex tokens to stdout
-dumpParse: dump Abstract Syntax Tree to stdout
-lexOnly: lex input file but do not parse or create assembly (no output file)
-parseOnly: lex and parse but don't create assembly (no output file)
```

This creates assembly language `source.s` in the current directory. Having written this file, the compiler calls the assembler to assemble into an object file and then link into an executable (`source.exe`). It also links against the supplied floating point library `floatlib.o`. You will see the calls to gcc which accomplish this. The assembly file (`source.s`) has some comments in it (beginning with `#`) which show the state of the compiler's internal variables list at various times. You can suppress the link stage by using `-c`.

In addition to compiling, the compiler optionally writes debug info to stdout. If `-dumpLex` is specified it writes the output from the lexer (tokens). If `-dumpParse` is specified it dumps the output from the parser (an Abstract Syntax Tree of Nodes)

I have used the 32-bit gcc/mingw compiler for Windows to compile the compiler and also to act as assembler (ie I'm using Gnu's AS assembler). Thus, the assembler directives in the `.s` file are in AS format, including the use of `#` as comments. You will see various directives in the `.s` file beginning with dots eg `.intel_syntax noprefix` specifies to use the more readable Intel syntax for the x86 assembly language (not AT&T).

The code should work equally well on Linux using gcc and tools, you would only need to change the convenience `.bat` scripts.

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

This source file is provided as `fibonacci.c` in `examples`.

The compiler implements the following language features:

* int (4 bytes), char (1 byte) and float (4 byte) base types. Also literal strings and void.
* arrays, pointers, structs and unions are fully supported.
* All C operators are supported except for the comma operator (,).
* for, if, do, while fully supported
* variables scope fully supported including local and global variables. New variables can be declared anywhere inside a block.
* function calls supported using the cdecl calling convention only. Can call the C std library no problem!

Limitations include:

* No doubles yet.
* Qualifiers const, long, register, short, volatile are currently ignored.
* No bitfields
* Single initialisations like `int i=j+k;` are supported but more complex block initialisation is not
 fully implemented. However `int i[]={1,2,3}` and `char* names[]={"foo","bar","zap"}` are allowed *for global variables only*.
* Function pointers are not supported. Types may not include parentheses eg `struct Foo **F[3][6]` is allowed but `int (*fp)()` is not.
* Function prototypes are parsed but only the return value is considered. No coercion is done when calling functions or on return values.

There's a long way to go but...

**The compiler is now advanced enough to compile itself!**

Before compiling, jcc first preprocesses the C code by calling gcc with `gcc -E`.

This code does not include a preprocessor, assembler or linker: the compiler's only function is to take a `.c` file (preprocessed) and create an assembly language file (`.s`) which must be assembled into an object file (`.o`) then linked into an executable or library.

# Example code

Example source files are supplied in `examples` and corresponding compiled assembly language files in `correct_asm`. The script `test.bat` can test a particular source file. Eg `test fibonacci` uses `jcc` to compile and run `examples\fibonacci.c`. It then compiles and runs the same code with gcc and compares output. It also compares the assembly language `.s` file written by `jcc` to the "correct" version in `correct_asm` (note there may be cosmetic differences due to updates)

# How it works

The program first lexes the source file then parses it. The output from both stages is optionally dumped to stdout. For the above example code, the lexer gives:
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
  int lineno;
  struct Token *next;
};
```
The type could be an identifier (variable), an int literal, a C keyword such as `return` or one of many punctuation symbols such as `OPEN_BRACKET`. The `id` is defined only
for identifiers and literals. The tokens are assembled into a linked list pointed to by global variable `tokenHead`. Function `getTok` is called repeatedly to generate these Tokens.
Lineno is the used for error output and is the line number from which the token was generated. (this is reset by preprocessor `#` directives so refers to the line number in the original file)

The parser then takes these tokens and creates an Abstract Syntax Tree (AST). The output from the parser, for `fibonacci.c`, is
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
  int lineno;
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
    char data[32];   // eg int*
    int isConst;
    :
};
```

Each Node has a certain number of children with different meaning depending on the type (the other children are not used):

* unary operators have 1 child (`child`)
* binary operators have 2 children (`child` and `child2`), 
* `IF` statements have 3 children (`child` is the condition, `child2` is the positive branch, `child3` is the else branch (if present else NULL))
* `FOR` statements have 4 children (`child` is the initialiser, `child2` is the condition, `child3` is the increment, `child4` is the body)
* `WHILE` has 2 children (`child` is the condition and `child2` is the body)
* `DO` has 2 children (`child` is the body and `child2` is the condition)
* ternary operator has 3 children (`child` is the conditional, `child2` is left expression (before the :), `child3` is right expression)

The "bodies" mentioned above can be a single statement or block.
Some nodes have an arbitrary number of children, stored in `line` with `nlines` being the number of children:

* `FUNCTION` the first n children are the arguments then each child is a statement in the function (where "statement" can be a block)
* `BLOCK` each child is a statement in the block
* `CALL` each child is function parameter
* `DECLGROUP` each child is a variable defined in one line. eg `int x,y,z` produces a DECLGROUP with 3 entries (each a DECL). Note that when a struct is created on the fly to define variables the 0-th entry is the STRUCT. Eg `struct Foo {int x,y;} a,b;` would have 3 entries: the Struct itself, then a, then b.
* `STRUCT` each child is a DECLGROUP
* `ENUM` each child is an Enum constant
* `PROGRAM` each child is a function, function prototype, global variable, struct, enum or typedef

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

`varType` is the variable type stored as a fixed length string eg `int*[3][6]`. `isArg` specifies if the variable is a function argument. `isConst` etc define qualifiers.
`structNode` is a pointer to the AST which is used when defining structs. Note that when a struct is declared its name is pushed onto the variable stack with 
`structNode` pointing to the AST location of the struct.

The compiler uses the machine stack to evaluate expressions pushing and poping values onto it to do calculations. Values from this "calculator stack" are popped off onto the `eax` and `ecx` registers to do calculations and these are the only registers used. When calling functions `jcc` uses only the `cdecl` calling convention (arguments pushed onto the stack right to left and `eax`, `ecx`, `edx` volatile. Return value put on eax). A stack frame is set up using `esp` and `ebp`. Note that local variables within inner scopes (eg in an if-block) are created on demand by pushing them onto the stack. This is different from commercial compilers which will create all local variables within a function right at the beginning of the function.
So the compiler doesn't need to worry about registers getting corrupted when it calls a function: everything is pushed onto the stack.

Once the AST has been prepared, the assembly language is written out using a single call to `writeAsm`. This function is recursive and has the prototype

```
struct Type writeAsm(struct Node *node, int level, int lvalue, int loop)
```

Each node has a type which is returned to the parent node. Eg if we add `'1'+2` then the addition node will call its two children which will create `mov al,'1'` (and pass back `char`) and `mov eax,2` (and pass back `int`) respectively. The addition node will then promote the char to int before adding the two and returning `int` to *its* superior node.

The `lvalue` argument tells a node whether to return an lvalue (if lvalue=1) or an rvalue. The addition node above will always ask for rvalues, while an assignment node would ask for an lvalue from its left child and an rvalue from its right child.

The `level` argument is the nesting level: 0 for global scope, 1 for function scope and higher for blocks. `loop` is the index of the current loop which is used by break and continue.