typedef int size_t;

typedef int Number, *QNumber;
typedef Number* PNumber;

typedef struct _iobuf
{
  char *_ptr;
  int _cnt;
  char *_base;
  int _flag;
  int _file;
  int _charbuf;
  int _bufsiz;
  char *_tmpfname;
} FILE;

//typedef struct _iobuf FILE;

void *malloc(size_t);

int main()
{
    printf("sizeof FILE=%d\n", sizeof (FILE));
    Number n,m;
    PNumber p, *z;
    PNumber *q;
    QNumber *k;
    FILE *fp = (FILE*)malloc(sizeof (FILE));
    fp->_flag=9;
    size_t index=2;
    return index + fp->_flag;
}
