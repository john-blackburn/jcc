int main()
{
    printf("Start\n");
    char *p="Hello, world\n";
    printf(p);
    
    char array[6];
    array[0]='H';
    array[1]='e';
    array[2]='\0';
    
    printf("%s\n", array);
        
    strcpy(array, "Hello");
    array[0]='J';
    
    printf("%s: %s\n", array, p);
    printf("%c\n",108);

    return array[2];    
}
