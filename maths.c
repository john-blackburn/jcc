int main()
{
    int i=2;
    int j=2;
    ++i;
    
    j = i & j;

    int k;    
    for (k=0; k<10; ++k)
    {
       j += 3*k;       
       if (j>100) break;
    }
        
    return j;
}
