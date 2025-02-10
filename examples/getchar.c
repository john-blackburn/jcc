// taken from GNU GCC standard library

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

// extern global var means we don't need to allocate space in data segment so OK for array to have no dimension
extern __attribute__((__dllimport__)) FILE _iob[];

__attribute__((__cdecl__)) __attribute__((__nothrow__)) int _filbuf (FILE *);

// jcc currently ignores inline. Always ignores extern when applied to a function or prototype.
// gnu attributes always ignored so this would just be "int mygetchar(void)"
// removed next line to avoid gcc confusion for testing.
// extern inline __attribute__((__gnu_inline__)) __attribute__((__cdecl__)) __attribute__((__nothrow__)) 
int mygetchar (void)
{
  return (--(&_iob[0])->_cnt >= 0)
    ? (int) (unsigned char) *(&_iob[0])->_ptr++
    : _filbuf ((&_iob[0]));
}

int main()
{
    int tot=0;
    while(1)
    {
        int c=mygetchar();
        printf("_cnt=%d\n", _iob[0]._cnt);
        if (c=='\n') break;
        tot+=c;
    }
    
    return tot;
}
