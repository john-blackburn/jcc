typedef int size_t;

typedef int Number, *QNumber;
typedef Number* PNumber;

struct _iobuf
{
  char *_ptr;
  int _cnt;
  char *_base;
  int _flag;
  int _file;
  int _charbuf;
  int _bufsiz;
  char *_tmpfname;
};

typedef struct _iobuf FILE;

int main()
{
    Number n;
    PNumber p;
    PNumber *q;
    FILE *fp;
    size_t index=2;
    return index;
}
