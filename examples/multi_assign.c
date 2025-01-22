int main()
{
  int x;
  int y;

  x=y=0;

  int *px=&x;
  int *py;

  py=&y;

  *py=*px+3;
  y=*(px+3);
  
  int a[6];
  
  y=3*a[2]+20;
    
  a[4]=1;
  
  int foo[3][6];
  int bar[6];
  
  foo[2][4]=1;

  x = 1+bar[bar[y]];
  
  y=foo[2][5];

  return *py;
}
