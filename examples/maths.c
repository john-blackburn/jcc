int main()
{
    int i=2;
    int j=2;
    ++i;
    
    j = i & j;

    int k;    
    for (k=0; k<10; ++k)
    {
       int z;
       j += 3*k;       
       if (j>100)
       {
           int q;
           break;
       }
    }
        
    return j;
}
