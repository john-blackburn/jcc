/*
Correct output
10 int**[3]
1+p[2]=2
names=foo, BAr
*/

void* malloc(int);
char *strcpy(char *s1, char *s2);

int numToks=56;

char *names[]={"foo","bar"};

struct Type
{
    char data[32];
};

struct Node
{
  int type;
  char *id;
  struct Type varType;
  struct Node *child;
  struct Node *child2;
  struct Node *child3;
  struct Node *child4;
  struct Node **line;
  int nlines;
};

int main()
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->type=10;
    strcpy(node->varType.data, "int**[3]");
    
    printf("%d %s\n", node->type, node->varType.data);

    int array[3];    
    int *p=&array[0];
    p[2]=1;
    printf("1+p[2]=%d\n",1+p[2]);
    
    *(names[1]+1)='A';
    names[1][0]='B';
    
    printf("names=%s, %s\n",names[0],names[1]);
    
    int i=20, j=30;
    
    j = j*i++;
    
    i = ++j;
    return i+j; // 1202
}
