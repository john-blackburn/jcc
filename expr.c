int foo(int bar)
{
  return bar*bar;
}

int globalMass, charge=10;

int putchar(int c);
int strlen(int s);

char* newStr(char* p);
void* malloc(int size);

int bar()
{
  int ret=2*globalMass+3;
  return ret;
}

int main()
{
  int i;
  putchar('H');
  putchar('\n');

  for (i=0; i<26; ++i)
    putchar(65+i);
  
  putchar(foo(10));
  putchar('\n');
  
  int a=10, b=1, c=2;

  globalMass=4;
  printf("globalMass=%d\n",globalMass);

  char *cmd="dir *.c";
  printf("cmd=%s %p %d\n",cmd,cmd,strlen(cmd));
  
  int disc=b*b-4*a*c;
  if (disc>0) 
  {
    printf("+ve disc=%d %d\n",disc,bar());
    return disc;
  }
  else 
  {
    int ret=disc*2;
    printf("-ve disc=%d\n",ret);
    return ret;
  }
}
