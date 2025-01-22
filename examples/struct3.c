struct Foo
{
    int a,b;
    struct Bar
    {
        float p,q;
    } a1,a2;
} x,y;

int main()
{
    x.a=1;
    y.b=x.a;
    y.a1.p=x.a;
    return y.b+sizeof (struct Foo);
}
