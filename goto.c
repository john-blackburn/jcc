int main()
{
    int i=0;
    
//    i ? j : k;
        
st :    
    if (i==10) goto ed;
    printf("iteration %d\n",i);
    i++;
    goto st;
  
ed: printf("Don't use goto!\n");  

    return i;    
}
