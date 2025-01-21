int main()
{

    int test=3;
    
    printf("You have %d item%s\n",test, test==1 ? "" : "s");

    if (test==1)
    {    
       int a = 1 ? 3 % 2 : 4;
       return a;
    }

    if (test==2)
    {    
        int a = 1;
        a != 2 ? a = 2 : 0;
        return a;
    }   

    if (test==3)
    {    
        int a = 10;
        // test that || is higher precedence than ?
        return a || 0 ? 20 : 0;
    }

    if (test==4)
        return 0 ? 1 : 0 || 2;

    if (test==5)
    {
        int a = 1;
        int b = 0;
        a ? (b = 1) : (b = 2);
        return b;
    }
}
