int isspace(int);
int isalnum(int);
int isalpha(int);
int isdigit(int);
int isspace(int);

int printf (const char *, ...);

int main()
{
    char c='A';
    printf("%d %d %d %d\n", isspace(c), isdigit(c), isalpha(c), isalnum(c));
    return 0;
}
