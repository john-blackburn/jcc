int fib(int n) {
    if (n == 0 || n == 1) {
        return n;
    } else {
        return fib(n - 1) + fib(n - 2);
    }
}

int main() {
    int n = 10;
    printf("The %d-th Fibonacci number is %d\n",n,fib(n));
    return 0;
}
