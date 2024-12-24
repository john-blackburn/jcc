int main()
{
    char c='A';
    int i;
    
    if (c=='A') 
        goto a1;
    else
        goto agn;
    
a1: i=1;
    
agn:if (c=='A') goto skp;
    c='B';
    
    skp:
    switch(c)
    {
    case 'A':
        i=5;
        break;
    case 'B':
        i=6;
        break;
    default:
        i=7;
        break;
    }
    
    return i;
}
