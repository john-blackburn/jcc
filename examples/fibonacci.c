// example showing function call, variable declaration (initialisation), var reference
// if block, return, int literal, string literal, use of stdlib
// we call printf despite no function prototype (no #include<stdio.h>)
// jcc only reads return value of function prototype and even that is optional
// Note we rely on the preprocessor to remove comments (like this) so jcc doesn't see them

typedef unsigned int size_t;
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int printf (const char *, ...);

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

int main(void) 
{
    const char n = 10;
    printf("The %d-th Fibonacci number is %d\n",(int)n,fib(n));
    return 0;
}
