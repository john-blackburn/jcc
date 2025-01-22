#define FACTOR 3

int printf(char *format, ...);

int transpose(int b[][2])
{
    int temp=b[0][1];
    b[0][1]=b[1][0];
    b[1][0]=temp;
    
    return 0;
}

int main()
{
    int a[2][2];
    
    a[0][0]=1;
    a[0][1]=2;
    a[1][0]=FACTOR*a[0][1];
    a[1][1]=4*a[1][0];

    printf("%d %d\n",a[0][0],a[0][1]);
    printf("%d %d\n\n",a[1][0],a[1][1]);

    transpose(a);

    printf("%d %d\n",a[0][0],a[0][1]);
    printf("%d %d\n",a[1][0],a[1][1]);

    return 0;
}
