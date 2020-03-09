# jcc
A simple C compiler written in C

The compiler source consists of a single file, main.c. The other source files are examples of code which can be compiled. 

Compile the compiler using compile.bat. 

Run it using

```
jcc path/to/source.c
```
eg

```
jcc fibonacci.c
```

This create source.exe in the current directory. It also creates assembly language source.s in the same directory. Having written this file, the compiler calls the assembler to assemble into an object file and then link into an executable (source.exe). You will see the call to gcc which accomplishes this. The assembly file (source.s) has some comments in it (beginning with #) which show the state of the variables list at various times. The assembler will ignore these.

In addition to compiling, the compiler writes lots of debug info to stdout. First it writes the output from the lexer (tokens), then the output from the parser (an Abstract Syntax Tree of Nodes)

I have used the 32-bit gcc/mingw compiler for Windows to compile the compiler and also to act as assembler (ie I'm using Gnu's AS assembler). Thus, the assembler directives are in AS format, including the use of # as comments.

The compiler is currently very limited supporting only a subset of the C language (maybe about 50%). Here is an example of code it can compile

```
int fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int n = 10;
    return fib(n);
}
```

This source file is provided as `fibonacci.c`.

Limitations include:
* Only ints supported
* No pointers, arrays, structs
