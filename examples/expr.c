int foo(int bar)
{
  return bar*bar;
}

static int globalMass, charge=10;  // global statics

int putchar(int c);
int strlen(const char*);

char* newStr(char* p);
void* malloc(int size);
int printf (const char *, ...);

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
  
  putchar(foo(10));  // d
  putchar('\n');
  
  static int a=10, b=1, c=2;  // local static

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
    printf("-ve disc=%d %d\n",ret,bar());
    return ret;
  }
}
