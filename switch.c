int main()
{
    char c='A'; // also try 'B'
    int i=0;
    
    if (c=='A') 
        goto a1;
    else
        goto agn;
    
a1: i=1;
    
agn:if (c=='A') goto skp;
    c='C';
    
    skp:
    switch(c)
    {
    case 'A':
        i+=7;
        break;
    case 'B':
        i+=6;
        break;
    default:
        i+=5;
        break;
    }
    
    return i;  // 8
}
