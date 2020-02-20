int foo(int bar)
{
  return bar*bar;
}

int globalMass;

int putchar(int);
int strlen(char *p);

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

  for (i=0;i<26;i=i+1)
    putchar(65+i);
  
  putchar(foo(10));
  putchar('\n');
  
  int a=10;
  int b=1;
  int c=2;

  globalMass=4;
  printf("globalMass=%d\n",globalMass);

  int cmd="dir *.c";
  printf("cmd=%s %p %d\n",cmd,cmd,strlen(cmd));
  
  int disc=b*b-4*a*c;
  if (disc>0) {
    printf("+ve disc=%d %d\n",disc,bar());
    return disc;
  }
  else {
    int ret=disc*2;
    printf("-ve disc=%d\n",ret);
    return ret;
  }
}
