# 1 "main.c"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "main.c"
# 25 "main.c"
# 1 "c:\\mingw\\include\\stdio.h" 1 3
# 38 "c:\\mingw\\include\\stdio.h" 3
       
# 39 "c:\\mingw\\include\\stdio.h" 3
# 56 "c:\\mingw\\include\\stdio.h" 3
# 1 "c:\\mingw\\include\\_mingw.h" 1 3
# 55 "c:\\mingw\\include\\_mingw.h" 3
       
# 56 "c:\\mingw\\include\\_mingw.h" 3
# 66 "c:\\mingw\\include\\_mingw.h" 3
# 1 "c:\\mingw\\include\\msvcrtver.h" 1 3
# 35 "c:\\mingw\\include\\msvcrtver.h" 3
       
# 36 "c:\\mingw\\include\\msvcrtver.h" 3
# 67 "c:\\mingw\\include\\_mingw.h" 2 3






# 1 "c:\\mingw\\include\\w32api.h" 1 3
# 35 "c:\\mingw\\include\\w32api.h" 3
       
# 36 "c:\\mingw\\include\\w32api.h" 3
# 59 "c:\\mingw\\include\\w32api.h" 3
# 1 "c:\\mingw\\include\\sdkddkver.h" 1 3
# 35 "c:\\mingw\\include\\sdkddkver.h" 3
       
# 36 "c:\\mingw\\include\\sdkddkver.h" 3
# 60 "c:\\mingw\\include\\w32api.h" 2 3
# 74 "c:\\mingw\\include\\_mingw.h" 2 3
# 57 "c:\\mingw\\include\\stdio.h" 2 3
# 69 "c:\\mingw\\include\\stdio.h" 3
# 1 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 1 3 4
# 216 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 3 4

# 216 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 3 4
typedef unsigned int size_t;
# 328 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 3 4
typedef short unsigned int wchar_t;
# 357 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 3 4
typedef short unsigned int wint_t;
# 70 "c:\\mingw\\include\\stdio.h" 2 3
# 94 "c:\\mingw\\include\\stdio.h" 3
# 1 "c:\\mingw\\include\\sys/types.h" 1 3
# 34 "c:\\mingw\\include\\sys/types.h" 3
       
# 35 "c:\\mingw\\include\\sys/types.h" 3
# 62 "c:\\mingw\\include\\sys/types.h" 3
  typedef long __off32_t;




  typedef __off32_t _off_t;







  typedef _off_t off_t;
# 91 "c:\\mingw\\include\\sys/types.h" 3
  typedef long long __off64_t;






  typedef __off64_t off64_t;
# 115 "c:\\mingw\\include\\sys/types.h" 3
  typedef int _ssize_t;







  typedef _ssize_t ssize_t;
# 95 "c:\\mingw\\include\\stdio.h" 2 3







# 1 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stdarg.h" 1 3 4
# 40 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stdarg.h" 3 4
typedef __builtin_va_list __gnuc_va_list;
# 103 "c:\\mingw\\include\\stdio.h" 2 3
# 210 "c:\\mingw\\include\\stdio.h" 3
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
# 239 "c:\\mingw\\include\\stdio.h" 3
extern __attribute__((__dllimport__)) FILE _iob[];
# 252 "c:\\mingw\\include\\stdio.h" 3








 __attribute__((__cdecl__)) __attribute__((__nothrow__)) FILE * fopen (const char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) FILE * freopen (const char *, const char *, FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int fflush (FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int fclose (FILE *);






 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int remove (const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int rename (const char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) FILE * tmpfile (void);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char * tmpnam (char *);


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_tempnam (const char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _rmtmp (void);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _unlink (const char *);
# 289 "c:\\mingw\\include\\stdio.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char * tempnam (const char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int rmtmp (void);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int unlink (const char *);



 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int setvbuf (FILE *, char *, int, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void setbuf (FILE *, char *);
# 342 "c:\\mingw\\include\\stdio.h" 3
extern int __attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__format__(__mingw_printf__,2,3))) __mingw_fprintf(FILE*, const char*, ...);
extern int __attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__format__(__mingw_printf__,1,2))) __mingw_printf(const char*, ...);
extern int __attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__format__(__mingw_printf__,2,3))) __mingw_sprintf(char*, const char*, ...);
extern int __attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__format__(__mingw_printf__,3,4))) __mingw_snprintf(char*, size_t, const char*, ...);
extern int __attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__format__(__mingw_printf__,2,0))) __mingw_vfprintf(FILE*, const char*, __builtin_va_list);
extern int __attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__format__(__mingw_printf__,1,0))) __mingw_vprintf(const char*, __builtin_va_list);
extern int __attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__format__(__mingw_printf__,2,0))) __mingw_vsprintf(char*, const char*, __builtin_va_list);
extern int __attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__format__(__mingw_printf__,3,0))) __mingw_vsnprintf(char*, size_t, const char*, __builtin_va_list);
# 376 "c:\\mingw\\include\\stdio.h" 3
extern unsigned int _mingw_output_format_control( unsigned int, unsigned int );
# 453 "c:\\mingw\\include\\stdio.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int fprintf (FILE *, const char *, ...);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int printf (const char *, ...);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int sprintf (char *, const char *, ...);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int vfprintf (FILE *, const char *, __builtin_va_list);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int vprintf (const char *, __builtin_va_list);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int vsprintf (char *, const char *, __builtin_va_list);
# 478 "c:\\mingw\\include\\stdio.h" 3
 int __attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__format__(__ms_printf__,2,3))) __msvcrt_fprintf(FILE *, const char *, ...);
 int __attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__format__(__ms_printf__,1,2))) __msvcrt_printf(const char *, ...);
 int __attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__format__(__ms_printf__,2,3))) __msvcrt_sprintf(char *, const char *, ...);
 int __attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__format__(__ms_printf__,2,0))) __msvcrt_vfprintf(FILE *, const char *, __builtin_va_list);
 int __attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__format__(__ms_printf__,1,0))) __msvcrt_vprintf(const char *, __builtin_va_list);
 int __attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__format__(__ms_printf__,2,0))) __msvcrt_vsprintf(char *, const char *, __builtin_va_list);






 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _snprintf (char *, size_t, const char *, ...);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _vsnprintf (char *, size_t, const char *, __builtin_va_list);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _vscprintf (const char *, __builtin_va_list);
# 501 "c:\\mingw\\include\\stdio.h" 3
__attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__format__(__mingw_printf__,3,4)))
int snprintf (char *, size_t, const char *, ...);

__attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__format__(__mingw_printf__,3,0)))
int vsnprintf (char *, size_t, const char *, __builtin_va_list);

__attribute__((__cdecl__)) __attribute__((__nothrow__))
int vscanf (const char * __restrict__, __builtin_va_list);

__attribute__((__cdecl__)) __attribute__((__nothrow__))
int vfscanf (FILE * __restrict__, const char * __restrict__, __builtin_va_list);

__attribute__((__cdecl__)) __attribute__((__nothrow__))
int vsscanf (const char * __restrict__, const char * __restrict__, __builtin_va_list);
# 646 "c:\\mingw\\include\\stdio.h" 3
__attribute__((__cdecl__)) __attribute__((__nothrow__)) ssize_t
getdelim (char ** __restrict__, size_t * __restrict__, int, FILE * __restrict__);

__attribute__((__cdecl__)) __attribute__((__nothrow__)) ssize_t
getline (char ** __restrict__, size_t * __restrict__, FILE * __restrict__);
# 666 "c:\\mingw\\include\\stdio.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int fscanf (FILE *, const char *, ...);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int scanf (const char *, ...);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int sscanf (const char *, const char *, ...);



 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int fgetc (FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char * fgets (char *, int, FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int fputc (int, FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int fputs (const char *, FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char * gets (char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int puts (const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int ungetc (int, FILE *);
# 687 "c:\\mingw\\include\\stdio.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _filbuf (FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _flsbuf (int, FILE *);



extern inline __attribute__((__gnu_inline__)) __attribute__((__cdecl__)) __attribute__((__nothrow__)) int getc (FILE *);
extern inline __attribute__((__gnu_inline__)) __attribute__((__cdecl__)) __attribute__((__nothrow__)) int getc (FILE * __F)
{
  return (--__F->_cnt >= 0)
    ? (int) (unsigned char) *__F->_ptr++
    : _filbuf (__F);
}

extern inline __attribute__((__gnu_inline__)) __attribute__((__cdecl__)) __attribute__((__nothrow__)) int putc (int, FILE *);
extern inline __attribute__((__gnu_inline__)) __attribute__((__cdecl__)) __attribute__((__nothrow__)) int putc (int __c, FILE * __F)
{
  return (--__F->_cnt >= 0)
    ? (int) (unsigned char) (*__F->_ptr++ = (char)__c)
    : _flsbuf (__c, __F);
}

extern inline __attribute__((__gnu_inline__)) __attribute__((__cdecl__)) __attribute__((__nothrow__)) int getchar (void);
extern inline __attribute__((__gnu_inline__)) __attribute__((__cdecl__)) __attribute__((__nothrow__)) int getchar (void)
{
  return (--(&_iob[0])->_cnt >= 0)
    ? (int) (unsigned char) *(&_iob[0])->_ptr++
    : _filbuf ((&_iob[0]));
}

extern inline __attribute__((__gnu_inline__)) __attribute__((__cdecl__)) __attribute__((__nothrow__)) int putchar(int);
extern inline __attribute__((__gnu_inline__)) __attribute__((__cdecl__)) __attribute__((__nothrow__)) int putchar(int __c)
{
  return (--(&_iob[1])->_cnt >= 0)
    ? (int) (unsigned char) (*(&_iob[1])->_ptr++ = (char)__c)
    : _flsbuf (__c, (&_iob[1]));}
# 734 "c:\\mingw\\include\\stdio.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t fread (void *, size_t, size_t, FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t fwrite (const void *, size_t, size_t, FILE *);



 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int fseek (FILE *, long, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) long ftell (FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void rewind (FILE *);
# 787 "c:\\mingw\\include\\stdio.h" 3
typedef long long fpos_t;




 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int fgetpos (FILE *, fpos_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int fsetpos (FILE *, const fpos_t *);



 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int feof (FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int ferror (FILE *);
# 808 "c:\\mingw\\include\\stdio.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void clearerr (FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void perror (const char *);






 __attribute__((__cdecl__)) __attribute__((__nothrow__)) FILE * _popen (const char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _pclose (FILE *);


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) FILE * popen (const char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int pclose (FILE *);




 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _flushall (void);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _fgetchar (void);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _fputchar (int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) FILE * _fdopen (int, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _fileno (FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _fcloseall (void);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) FILE * _fsopen (const char *, const char *, int);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _getmaxstdio (void);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _setmaxstdio (int);
# 859 "c:\\mingw\\include\\stdio.h" 3
unsigned int __attribute__((__cdecl__)) __mingw_get_output_format (void);
unsigned int __attribute__((__cdecl__)) __mingw_set_output_format (unsigned int);







int __attribute__((__cdecl__)) __mingw_get_printf_count_output (void);
int __attribute__((__cdecl__)) __mingw_set_printf_count_output (int);
# 885 "c:\\mingw\\include\\stdio.h" 3
extern inline __attribute__((__gnu_inline__)) __attribute__((__always_inline__)) unsigned int __attribute__((__cdecl__)) _get_output_format (void)
{ return __mingw_get_output_format (); }

extern inline __attribute__((__gnu_inline__)) __attribute__((__always_inline__)) unsigned int __attribute__((__cdecl__)) _set_output_format (unsigned int __style)
{ return __mingw_set_output_format (__style); }
# 910 "c:\\mingw\\include\\stdio.h" 3
extern inline __attribute__((__gnu_inline__)) __attribute__((__always_inline__)) int __attribute__((__cdecl__)) _get_printf_count_output (void)
{ return 0 ? 1 : __mingw_get_printf_count_output (); }

extern inline __attribute__((__gnu_inline__)) __attribute__((__always_inline__)) int __attribute__((__cdecl__)) _set_printf_count_output (int __mode)
{ return 0 ? 1 : __mingw_set_printf_count_output (__mode); }



 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int fgetchar (void);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int fputchar (int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) FILE * fdopen (int, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int fileno (FILE *);
# 930 "c:\\mingw\\include\\stdio.h" 3
extern inline __attribute__((__gnu_inline__)) __attribute__((__always_inline__)) FILE * __attribute__((__cdecl__)) __attribute__((__nothrow__)) fopen64 (const char *, const char *);
extern inline __attribute__((__gnu_inline__)) __attribute__((__always_inline__))
FILE * __attribute__((__cdecl__)) __attribute__((__nothrow__)) fopen64 (const char * filename, const char * mode)
{ return fopen (filename, mode); }

int __attribute__((__cdecl__)) __attribute__((__nothrow__)) fseeko64 (FILE *, __off64_t, int);






extern inline __attribute__((__gnu_inline__)) __attribute__((__always_inline__)) __off64_t __attribute__((__cdecl__)) __attribute__((__nothrow__)) ftello64 (FILE *);
extern inline __attribute__((__gnu_inline__)) __attribute__((__always_inline__))
__off64_t __attribute__((__cdecl__)) __attribute__((__nothrow__)) ftello64 (FILE * stream)
{ fpos_t __pos; return (fgetpos(stream, &__pos)) ? -1LL : (__off64_t)(__pos); }
# 958 "c:\\mingw\\include\\stdio.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int fwprintf (FILE *, const wchar_t *, ...);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int wprintf (const wchar_t *, ...);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int vfwprintf (FILE *, const wchar_t *, __builtin_va_list);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int vwprintf (const wchar_t *, __builtin_va_list);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _snwprintf (wchar_t *, size_t, const wchar_t *, ...);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _vscwprintf (const wchar_t *, __builtin_va_list);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _vsnwprintf (wchar_t *, size_t, const wchar_t *, __builtin_va_list);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int fwscanf (FILE *, const wchar_t *, ...);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int wscanf (const wchar_t *, ...);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int swscanf (const wchar_t *, const wchar_t *, ...);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wint_t fgetwc (FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wint_t fputwc (wchar_t, FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wint_t ungetwc (wchar_t, FILE *);




 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int swprintf (wchar_t *, const wchar_t *, ...);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int vswprintf (wchar_t *, const wchar_t *, __builtin_va_list);



 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t * fgetws (wchar_t *, int, FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int fputws (const wchar_t *, FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wint_t getwc (FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wint_t getwchar (void);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wint_t putwc (wint_t, FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wint_t putwchar (wint_t);


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t * _getws (wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _putws (const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) FILE * _wfdopen(int, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) FILE * _wfopen (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) FILE * _wfreopen (const wchar_t *, const wchar_t *, FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) FILE * _wfsopen (const wchar_t *, const wchar_t *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t * _wtmpnam (wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t * _wtempnam (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wrename (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wremove (const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void _wperror (const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) FILE * _wpopen (const wchar_t *, const wchar_t *);






__attribute__((__cdecl__)) __attribute__((__nothrow__)) int snwprintf (wchar_t *, size_t, const wchar_t *, ...);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int vsnwprintf (wchar_t *, size_t, const wchar_t *, __builtin_va_list);
# 1016 "c:\\mingw\\include\\stdio.h" 3
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int vwscanf (const wchar_t *__restrict__, __builtin_va_list);
__attribute__((__cdecl__)) __attribute__((__nothrow__))
int vfwscanf (FILE *__restrict__, const wchar_t *__restrict__, __builtin_va_list);
__attribute__((__cdecl__)) __attribute__((__nothrow__))
int vswscanf (const wchar_t *__restrict__, const wchar_t * __restrict__, __builtin_va_list);






 __attribute__((__cdecl__)) __attribute__((__nothrow__)) FILE * wpopen (const wchar_t *, const wchar_t *);




 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wint_t _fgetwchar (void);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wint_t _fputwchar (wint_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _getw (FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _putw (int, FILE *);




 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wint_t fgetwchar (void);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wint_t fputwchar (wint_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int getw (FILE *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int putw (int, FILE *);





# 26 "main.c" 2
# 1 "c:\\mingw\\include\\stdlib.h" 1 3
# 34 "c:\\mingw\\include\\stdlib.h" 3
       
# 35 "c:\\mingw\\include\\stdlib.h" 3
# 55 "c:\\mingw\\include\\stdlib.h" 3
# 1 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 1 3 4
# 56 "c:\\mingw\\include\\stdlib.h" 2 3
# 90 "c:\\mingw\\include\\stdlib.h" 3

# 99 "c:\\mingw\\include\\stdlib.h" 3
extern int _argc;
extern char **_argv;




extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) int *__p___argc(void);
extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) char ***__p___argv(void);
extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t ***__p___wargv(void);
# 142 "c:\\mingw\\include\\stdlib.h" 3
   extern __attribute__((__dllimport__)) int __mb_cur_max;
# 166 "c:\\mingw\\include\\stdlib.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int *_errno(void);


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int *__doserrno(void);







extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) char ***__p__environ(void);

extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t ***__p__wenviron(void);
# 202 "c:\\mingw\\include\\stdlib.h" 3
extern __attribute__((__dllimport__)) int _sys_nerr;
# 227 "c:\\mingw\\include\\stdlib.h" 3
extern __attribute__((__dllimport__)) char *_sys_errlist[];
# 238 "c:\\mingw\\include\\stdlib.h" 3
extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) unsigned int *__p__osver(void);
extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) unsigned int *__p__winver(void);
extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) unsigned int *__p__winmajor(void);
extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) unsigned int *__p__winminor(void);
# 250 "c:\\mingw\\include\\stdlib.h" 3
extern __attribute__((__dllimport__)) unsigned int _osver;
extern __attribute__((__dllimport__)) unsigned int _winver;
extern __attribute__((__dllimport__)) unsigned int _winmajor;
extern __attribute__((__dllimport__)) unsigned int _winminor;
# 289 "c:\\mingw\\include\\stdlib.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char **__p__pgmptr(void);


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t **__p__wpgmptr(void);
# 325 "c:\\mingw\\include\\stdlib.h" 3
extern __attribute__((__dllimport__)) int _fmode;
# 335 "c:\\mingw\\include\\stdlib.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int atoi (const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) long atol (const char *);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) double strtod (const char *, char **);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) double atof (const char *);


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) double _wtof (const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wtoi (const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) long _wtol (const wchar_t *);
# 378 "c:\\mingw\\include\\stdlib.h" 3
__attribute__((__cdecl__)) __attribute__((__nothrow__))
float strtof (const char *__restrict__, char **__restrict__);

__attribute__((__cdecl__)) __attribute__((__nothrow__))
long double strtold (const char *__restrict__, char **__restrict__);


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) long strtol (const char *, char **, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) unsigned long strtoul (const char *, char **, int);







 __attribute__((__cdecl__)) __attribute__((__nothrow__))
long wcstol (const wchar_t *, wchar_t **, int);

 __attribute__((__cdecl__)) __attribute__((__nothrow__))
unsigned long wcstoul (const wchar_t *, wchar_t **, int);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) double wcstod (const wchar_t *, wchar_t **);





__attribute__((__cdecl__)) __attribute__((__nothrow__))
float wcstof (const wchar_t *__restrict__, wchar_t **__restrict__);

__attribute__((__cdecl__)) __attribute__((__nothrow__))
long double wcstold (const wchar_t *__restrict__, wchar_t **__restrict__);
# 451 "c:\\mingw\\include\\stdlib.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wgetenv (const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wputenv (const wchar_t *);

 __attribute__((__cdecl__)) __attribute__((__nothrow__))
void _wsearchenv (const wchar_t *, const wchar_t *, wchar_t *);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wsystem (const wchar_t *);

 __attribute__((__cdecl__)) __attribute__((__nothrow__))
void _wmakepath (wchar_t *, const wchar_t *, const wchar_t *, const wchar_t *,
    const wchar_t *
  );

 __attribute__((__cdecl__)) __attribute__((__nothrow__))
void _wsplitpath (const wchar_t *, wchar_t *, wchar_t *, wchar_t *, wchar_t *);

 __attribute__((__cdecl__)) __attribute__((__nothrow__))
wchar_t *_wfullpath (wchar_t *, const wchar_t *, size_t);





 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t wcstombs (char *, const wchar_t *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int wctomb (char *, wchar_t);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int mblen (const char *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t mbstowcs (wchar_t *, const char *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int mbtowc (wchar_t *, const char *, size_t);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int rand (void);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void srand (unsigned int);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void *calloc (size_t, size_t) __attribute__((__malloc__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void *malloc (size_t) __attribute__((__malloc__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void *realloc (void *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void free (void *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void abort (void) __attribute__((__noreturn__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void exit (int) __attribute__((__noreturn__));



int __attribute__((__cdecl__)) __attribute__((__nothrow__)) atexit (void (*)(void));

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int system (const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *getenv (const char *);






 __attribute__((__cdecl__)) void *bsearch
(const void *, const void *, size_t, size_t, int (*)(const void *, const void *));

 __attribute__((__cdecl__)) void qsort
(void *, size_t, size_t, int (*)(const void *, const void *));

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int abs (int) __attribute__((__const__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) long labs (long) __attribute__((__const__));
# 519 "c:\\mingw\\include\\stdlib.h" 3
typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) div_t div (int, int) __attribute__((__const__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) ldiv_t ldiv (long, long) __attribute__((__const__));






 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void _exit (int) __attribute__((__noreturn__));





 __attribute__((__cdecl__)) __attribute__((__nothrow__)) long long _atoi64 (const char *);
# 545 "c:\\mingw\\include\\stdlib.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void _beep (unsigned int, unsigned int) __attribute__((__deprecated__));

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void _seterrormode (int) __attribute__((__deprecated__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void _sleep (unsigned long) __attribute__((__deprecated__));



typedef int (* _onexit_t)(void);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) _onexit_t _onexit( _onexit_t );

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _putenv (const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__))
void _searchenv (const char *, const char *, char *);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_ecvt (double, int, int *, int *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_fcvt (double, int, int *, int *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_gcvt (double, int, char *);

 __attribute__((__cdecl__)) __attribute__((__nothrow__))
void _makepath (char *, const char *, const char *, const char *, const char *);

 __attribute__((__cdecl__)) __attribute__((__nothrow__))
void _splitpath (const char *, char *, char *, char *, char *);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_fullpath (char*, const char*, size_t);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_itoa (int, char *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_ltoa (long, char *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_ultoa(unsigned long, char *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_itow (int, wchar_t *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_ltow (long, wchar_t *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_ultow (unsigned long, wchar_t *, int);


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char* _i64toa (long long, char *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char* _ui64toa (unsigned long long, char *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) long long _wtoi64 (const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t* _i64tow (long long, wchar_t *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t* _ui64tow (unsigned long long, wchar_t *, int);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) unsigned int (_rotl)(unsigned int, int) __attribute__((__const__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) unsigned int (_rotr)(unsigned int, int) __attribute__((__const__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) unsigned long (_lrotl)(unsigned long, int) __attribute__((__const__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) unsigned long (_lrotr)(unsigned long, int) __attribute__((__const__));

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _set_error_mode (int);
# 628 "c:\\mingw\\include\\stdlib.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int putenv (const char*);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void searchenv (const char*, const char*, char*);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char* itoa (int, char*, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char* ltoa (long, char*, int);


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char* ecvt (double, int, int*, int*);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char* fcvt (double, int, int*, int*);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char* gcvt (double, int, char*);
# 649 "c:\\mingw\\include\\stdlib.h" 3
__attribute__((__cdecl__)) __attribute__((__nothrow__)) void _Exit(int) __attribute__((__noreturn__));






typedef struct { long long quot, rem; } lldiv_t;
__attribute__((__cdecl__)) __attribute__((__nothrow__)) lldiv_t lldiv (long long, long long) __attribute__((__const__));

__attribute__((__cdecl__)) __attribute__((__nothrow__)) long long llabs (long long);
# 670 "c:\\mingw\\include\\stdlib.h" 3
__attribute__((__cdecl__)) __attribute__((__nothrow__))
long long strtoll (const char *__restrict__, char **__restrict, int);

__attribute__((__cdecl__)) __attribute__((__nothrow__))
unsigned long long strtoull (const char *__restrict__, char **__restrict__, int);





__attribute__((__cdecl__)) __attribute__((__nothrow__)) long long atoll (const char *);
# 726 "c:\\mingw\\include\\stdlib.h" 3
__attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__deprecated__)) long long wtoll (const wchar_t *);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__deprecated__)) char *lltoa (long long, char *, int);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__deprecated__)) char *ulltoa (unsigned long long , char *, int);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__deprecated__)) wchar_t *lltow (long long, wchar_t *, int);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) __attribute__((__deprecated__)) wchar_t *ulltow (unsigned long long, wchar_t *, int);
# 766 "c:\\mingw\\include\\stdlib.h" 3
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int mkstemp (char *);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int __mingw_mkstemp (int, char *);
# 808 "c:\\mingw\\include\\stdlib.h" 3
extern inline __attribute__((__gnu_inline__)) __attribute__((__always_inline__))
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int mkstemp (char *__filename_template)
{ return __mingw_mkstemp( 0, __filename_template ); }
# 819 "c:\\mingw\\include\\stdlib.h" 3
__attribute__((__cdecl__)) __attribute__((__nothrow__)) char *mkdtemp (char *);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) char *__mingw_mkdtemp (char *);

extern inline __attribute__((__gnu_inline__)) __attribute__((__always_inline__))
__attribute__((__cdecl__)) __attribute__((__nothrow__)) char *mkdtemp (char *__dirname_template)
{ return __mingw_mkdtemp( __dirname_template ); }






__attribute__((__cdecl__)) __attribute__((__nothrow__)) int setenv( const char *, const char *, int );
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int unsetenv( const char * );

__attribute__((__cdecl__)) __attribute__((__nothrow__)) int __mingw_setenv( const char *, const char *, int );

extern inline __attribute__((__gnu_inline__)) __attribute__((__always_inline__))
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int setenv( const char *__n, const char *__v, int __f )
{ return __mingw_setenv( __n, __v, __f ); }

extern inline __attribute__((__gnu_inline__)) __attribute__((__always_inline__))
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int unsetenv( const char *__name )
{ return __mingw_setenv( __name, ((void *)0), 1 ); }





# 27 "main.c" 2
# 1 "c:\\mingw\\include\\ctype.h" 1 3
# 33 "c:\\mingw\\include\\ctype.h" 3
       
# 34 "c:\\mingw\\include\\ctype.h" 3
# 59 "c:\\mingw\\include\\ctype.h" 3
# 1 "c:\\mingw\\include\\wctype.h" 1 3
# 33 "c:\\mingw\\include\\wctype.h" 3
       
# 34 "c:\\mingw\\include\\wctype.h" 3
# 87 "c:\\mingw\\include\\wctype.h" 3
# 1 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 1 3 4
# 88 "c:\\mingw\\include\\wctype.h" 2 3

typedef wchar_t wctype_t;










 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int iswalnum (wint_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int iswalpha (wint_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int iswascii (wint_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int iswcntrl (wint_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int iswctype (wint_t, wctype_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int iswdigit (wint_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int iswgraph (wint_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int iswlower (wint_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int iswprint (wint_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int iswpunct (wint_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int iswspace (wint_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int iswupper (wint_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int iswxdigit (wint_t);

__attribute__((__deprecated__))





 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int is_wctype (wint_t, wctype_t);


__attribute__((__cdecl__)) __attribute__((__nothrow__)) int iswblank (wint_t);







 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wint_t towlower (wint_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wint_t towupper (wint_t);
# 182 "c:\\mingw\\include\\wctype.h" 3

# 60 "c:\\mingw\\include\\ctype.h" 2 3
# 68 "c:\\mingw\\include\\ctype.h" 3


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int isalnum(int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int isalpha(int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int iscntrl(int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int isdigit(int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int isgraph(int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int islower(int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int isleadbyte (int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int isprint(int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int ispunct(int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int isspace(int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int isupper(int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int isxdigit(int);


__attribute__((__cdecl__)) __attribute__((__nothrow__)) int isblank (int);



 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _isctype (int, int);






 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int tolower (int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int toupper (int);
# 108 "c:\\mingw\\include\\ctype.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _tolower (int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _toupper (int);
# 140 "c:\\mingw\\include\\ctype.h" 3
  extern __attribute__((__dllimport__)) unsigned short _ctype[];



  extern __attribute__((__dllimport__)) unsigned short *_pctype;
# 240 "c:\\mingw\\include\\ctype.h" 3
extern inline __attribute__((__gnu_inline__)) __attribute__((__cdecl__)) __attribute__((__nothrow__)) int isleadbyte (int c)
{ return (_pctype[(unsigned char)(c)] & 0x8000); }


__attribute__((__cdecl__)) __attribute__((__nothrow__)) int __isascii (int);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int __toascii (int);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int __iscsymf (int);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int __iscsym (int);
# 267 "c:\\mingw\\include\\ctype.h" 3
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int isascii (int);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int toascii (int);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int iscsymf (int);
__attribute__((__cdecl__)) __attribute__((__nothrow__)) int iscsym (int);





# 28 "main.c" 2
# 1 "c:\\mingw\\include\\string.h" 1 3
# 34 "c:\\mingw\\include\\string.h" 3
       
# 35 "c:\\mingw\\include\\string.h" 3
# 53 "c:\\mingw\\include\\string.h" 3
# 1 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 1 3 4
# 54 "c:\\mingw\\include\\string.h" 2 3
# 62 "c:\\mingw\\include\\string.h" 3
# 1 "c:\\mingw\\include\\strings.h" 1 3
# 33 "c:\\mingw\\include\\strings.h" 3
       
# 34 "c:\\mingw\\include\\strings.h" 3
# 59 "c:\\mingw\\include\\strings.h" 3
# 1 "c:\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 1 3 4
# 60 "c:\\mingw\\include\\strings.h" 2 3



int __attribute__((__cdecl__)) __attribute__((__nothrow__)) strcasecmp( const char *, const char * );
int __attribute__((__cdecl__)) __attribute__((__nothrow__)) strncasecmp( const char *, const char *, size_t );
# 80 "c:\\mingw\\include\\strings.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _stricmp( const char *, const char * );
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _strnicmp( const char *, const char *, size_t );
# 100 "c:\\mingw\\include\\strings.h" 3

# 63 "c:\\mingw\\include\\string.h" 2 3







 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void *memchr (const void *, int, size_t) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int memcmp (const void *, const void *, size_t) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void *memcpy (void *, const void *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void *memmove (void *, const void *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void *memset (void *, int, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strcat (char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strchr (const char *, int) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int strcmp (const char *, const char *) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int strcoll (const char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strcpy (char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t strcspn (const char *, const char *) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strerror (int);

 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t strlen (const char *) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strncat (char *, const char *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int strncmp (const char *, const char *, size_t) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strncpy (char *, const char *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strpbrk (const char *, const char *) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strrchr (const char *, int) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t strspn (const char *, const char *) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strstr (const char *, const char *) __attribute__((__pure__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strtok (char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t strxfrm (char *, const char *, size_t);




 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_strerror (const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void *_memccpy (void *, const void *, int, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _memicmp (const void *, const void *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_strdup (const char *) __attribute__((__malloc__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _strcmpi (const char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _stricoll (const char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_strlwr (char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_strnset (char *, int, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_strrev (char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_strset (char *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_strupr (char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void _swab (const char *, char *, size_t);
# 126 "c:\\mingw\\include\\string.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _strncoll(const char *, const char *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _strnicoll(const char *, const char *, size_t);






 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void *memccpy (void *, const void *, int, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int memicmp (const void *, const void *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strdup (const char *) __attribute__((__malloc__));
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int strcmpi (const char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int stricmp (const char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int stricoll (const char *, const char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strlwr (char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int strnicmp (const char *, const char *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strnset (char *, int, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strrev (char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strset (char *, int);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *strupr (char *);





 __attribute__((__cdecl__)) __attribute__((__nothrow__)) void swab (const char *, char *, size_t);
# 170 "c:\\mingw\\include\\string.h" 3
# 1 "c:\\mingw\\include\\wchar.h" 1 3
# 35 "c:\\mingw\\include\\wchar.h" 3
       
# 36 "c:\\mingw\\include\\wchar.h" 3
# 392 "c:\\mingw\\include\\wchar.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcscat (wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcschr (const wchar_t *, wchar_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int wcscmp (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int wcscoll (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcscpy (wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t wcscspn (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t wcslen (const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcsncat (wchar_t *, const wchar_t *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int wcsncmp (const wchar_t *, const wchar_t *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcsncpy (wchar_t *, const wchar_t *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcspbrk (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcsrchr (const wchar_t *, wchar_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t wcsspn (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcsstr (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcstok (wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) size_t wcsxfrm (wchar_t *, const wchar_t *, size_t);




 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wcsdup (const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wcsicmp (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wcsicoll (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wcslwr (wchar_t*);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wcsnicmp (const wchar_t *, const wchar_t *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wcsnset (wchar_t *, wchar_t, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wcsrev (wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wcsset (wchar_t *, wchar_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wcsupr (wchar_t *);


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wcsncoll (const wchar_t *, const wchar_t *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int _wcsnicoll (const wchar_t *, const wchar_t *, size_t);
# 445 "c:\\mingw\\include\\wchar.h" 3
int __attribute__((__cdecl__)) __attribute__((__nothrow__)) wcscmpi (const wchar_t *, const wchar_t *);
# 457 "c:\\mingw\\include\\wchar.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcsdup (const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int wcsicmp (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int wcsicoll (const wchar_t *, const wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcslwr (wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) int wcsnicmp (const wchar_t *, const wchar_t *, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcsnset (wchar_t *, wchar_t, size_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcsrev (wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcsset (wchar_t *, wchar_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *wcsupr (wchar_t *);
# 491 "c:\\mingw\\include\\wchar.h" 3
extern size_t __mingw_wcsnlen (const wchar_t *, size_t);


extern inline __attribute__((__gnu_inline__)) __attribute__((__always_inline__)) size_t wcsnlen (const wchar_t *__text, size_t __maxlen)
{ return __mingw_wcsnlen (__text, __maxlen); }
# 171 "c:\\mingw\\include\\string.h" 2 3
# 193 "c:\\mingw\\include\\string.h" 3
extern size_t __mingw_strnlen (const char *, size_t);


extern inline __attribute__((__gnu_inline__)) __attribute__((__always_inline__)) size_t strnlen (const char *__text, size_t __maxlen)
{ return __mingw_strnlen (__text, __maxlen); }
# 212 "c:\\mingw\\include\\string.h" 3
extern int strerror_r (int, char *, size_t);
# 227 "c:\\mingw\\include\\string.h" 3
extern inline __attribute__((__gnu_inline__)) __attribute__((__always_inline__)) int strerror_s (char *__buf, size_t __len, int __err)
{ return strerror_r (__err, __buf, __len); }





# 29 "main.c" 2


# 30 "main.c"
char *tokNames[]={"<<=", ">>=",

    "&&", "||", "==", "!=", "<=", ">=", "<<", ">>",
    "++", "--", "->",
    "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=",

    "<", ">", "!", "=", ",", ";", ".", "(", ")", "{", "}", "[", "]",
    "+", "-", "*", "/", "%", "&", "|", "^", "~",

    "return", "int", "char", "if", "else", "for", "while", "do", "break", "continue",
          "struct", "sizeof", "void"};

int numToks=56;
# 149 "main.c"
char *names[]={
  "LESSTHAN2_EQUAL",
  "GREATERTHAN2_EQUAL",
  "AMP2",
  "PIPE2",
  "EQUALS2",
  "EXCLAM_EQUAL",
  "LESSTHAN_EQUAL",
  "GREATERTHAN_EQUAL",
  "LESSTHAN2",
  "GREATERTHAN2",
  "PLUS2",
  "MINUS2",
  "MINUS_GREATERTHAN",
  "PLUS_EQUALS",
  "MINUS_EQUALS",
  "ASTERISK_EQUALS",
  "SLASH_EQUALS",
  "PERCENT_EQUALS",
  "AMP_EQUALS",
  "PIPE_EQUALS",
  "HAT_EQUALS",
  "LESSTHAN",
  "GREATERTHAN",
  "EXCLAM",
  "EQUALS",
  "COMMA",
  "SEMICOLON",
  "DOT",
  "OPEN_BRACKET",
  "CLOSE_BRACKET",
  "OPEN_BRACE",
  "CLOSE_BRACE",
  "OPEN_SQUARE",
  "CLOSE_SQUARE",
  "PLUS",
  "MINUS",
  "ASTERISK",
  "SLASH",
  "PERCENT",
  "AMP",
  "PIPE",
  "HAT",
  "TILDE",
  "RETURN",
  "INT_DECLARATION",
  "CHAR_DECLARATION",
  "IF",
  "ELSE",
  "FOR",
  "WHILE",
  "DO",
  "BREAK",
  "CONTINUE",
  "STRUCT",
  "SIZEOF",
  "VOID_DECLARATION",

  "INT_LITERAL",
  "IDENTIFIER",
  "STRING_LITERAL",
  "CHAR_LITERAL",

  "FUNCTION",
  "UNARY_MINUS",
  "UNARY_COMPLEMENT",
  "UNARY_NOT",
  "BINARY_PLUS",
  "BINARY_MINUS",
  "BINARY_TIMES",
  "BINARY_DIVIDE",
  "BINARY_AND",
  "BINARY_OR",
  "BINARY_EQUAL",
  "BINARY_NOT_EQUAL",
  "BINARY_LESS_THAN_OR_EQUAL",
  "BINARY_LESS_THAN",
  "BINARY_GREATER_THAN_OR_EQUAL",
  "BINARY_GREATER_THAN",
  "ASSIGNMENT",
  "VAR",
  "EXPR",
  "DECL",
  "BLOCK",
  "CALL",
  "ARG",
  "GLOBAL",
  "PROGRAM",
  "PROTOTYPE",
  "DEREF",
  "ADDRESS",
  "INDEX",
  "UNARY_PLUS",
  "BINARY_LEFT_SHIFT",
  "BINARY_RIGHT_SHIFT",
  "BINARY_BITWISE_AND",
  "BINARY_BITWISE_XOR",
  "BINARY_BITWISE_OR",
  "BINARY_MODULO",
  "INC",
  "ARROW",
  "DEC",
  "INC_AFTER",
  "DEC_AFTER",
  "CAST"
};

struct Token
{
  int type;
  char *id;
  int lineno;
  struct Token *next;
};


struct Type
{
    char data[32];
};

struct Node
{
  int type;
  char *id;
  struct Type varType;
  int lineno;
  struct Node *child;
  struct Node *child2;
  struct Node *child3;
  struct Node *child4;
  struct Node **line;
  int nlines;
};

struct Var
{
  char *id;
  struct Type varType;
  int level;
  int offset;
  int isArg;
  struct Node *structNode;
  struct Var *prev;
};

int g_offset;
struct Var *varEnd;
struct Token *tokenHead;
int lineno;

FILE* fps;


struct Node* parse_decl(int type);
struct Node *parse_exp();

void advance()
{
  if (tokenHead==
# 308 "main.c" 3 4
                ((void *)0)
# 308 "main.c"
                    )
  {
      printf("Unexpected end of file");
      exit(1);
  }
  tokenHead=tokenHead->next;
}

int getType()
{
  if (tokenHead==
# 318 "main.c" 3 4
                ((void *)0)
# 318 "main.c"
                    )
  {
      printf("Unexpected end of file");
      exit(1);
  }
  return tokenHead->type;
}



void fail(char *err)
{
    if (tokenHead->id==
# 330 "main.c" 3 4
                      ((void *)0)
# 330 "main.c"
                          )
        printf("Parse Error: %s got %s [lineno: %d]\n",err, names[getType()], tokenHead->lineno);
    else
        printf("Parse Error: %s got %s (%s) [lineno: %d]\n",err, names[getType()], tokenHead->id, tokenHead->lineno);
    exit(1);
}

void asmFail(char *err, struct Node* node)
{
    printf("ASM Write Error: %s [line: %d], node type:%s\n", err, node->lineno, names[node->type]);
    exit(2);
}



char* newStr(char *from)
{
  int len=strlen(from);
  char* to=(char*)malloc(len+1);
  strcpy(to,from);
  return to;
}

char* newStrStruct(char *from)
{
  int len=strlen(from+7);
  char* to=(char*)malloc(len+1);
  strcpy(to,"struct ");
  strcat(to,from);
  return to;
}

int isProtoOrFunc()
{
    struct Token* p = tokenHead;
    int isproto = 0;
    while (p->type != 26)
    {
        if (p->type == 24)
        {
            isproto = 0;
            break;
        }
        else if (p->type == 32)
        {
            isproto = 0;
            break;
        }
        else if (p->type == 28)
        {
            isproto = 1;
            break;
        }

        p = p->next;
    }

    return isproto;
}




int countArgs()
{
  struct Token *p=tokenHead;

  if (p->type==29)
    return 0;

  int nargs=1;
  int nlevel=0;
  while(1){
    if (p->type==28){
      nlevel++;
    }

    if (p->type==29){
      nlevel--;
      if (nlevel<0) break;
    }

    if (p->type==25 && nlevel==0)
      nargs++;

    p=p->next;
  }
  return nargs;
}




int countInit()
{
  struct Token *p=tokenHead;

  if (p->type==31)
    return 0;

  int nInit=1;
  while(p->type!=31)
  {
    if (p->type==25)
      nInit++;

    p=p->next;
  }
  return nInit;
}



int countLines(struct Token *p)
{
  if (p==
# 445 "main.c" 3 4
        ((void *)0)
# 445 "main.c"
            ) p=tokenHead;

  int nlines=0;
  int nlevel=0;
  while(1){
    if (p->type==30){
      if (nlevel==0) nlines++;
      nlevel++;
    }

    if (p->type==31){
      nlevel--;
      if (nlevel<0) break;
    }

    if (p->type==26 && nlevel==0)
      nlines++;

    if (p->type==47 && nlevel==0) nlines--;
    if (p->type==50 && nlevel==0) nlines--;
    if (p->type==48 && nlevel==0) nlines-=2;
    p=p->next;
  }
  return nlines;
}



int countArgsAndLines()
{


  int nargs=countArgs();

  struct Token *p=tokenHead;
  while(p->type!=30)
    p=p->next;

  p=p->next;
  int nlines=countLines(p);
  return nargs+nlines;
}



struct Node* parse_identifier()
{
    struct Node *exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=77;
    exp->lineno=tokenHead->lineno;
    exp->id=newStr(tokenHead->id);
    exp->child=
# 496 "main.c" 3 4
              ((void *)0)
# 496 "main.c"
                  ;
    exp->varType.data[0]='\0';
    advance();

    int type = getType();

    if (type==10 || type==11)
    {
       struct Node *after=(struct Node*)malloc(sizeof(struct Node));

       if (type==10)
          after->type=99;
       else
          after->type=100;

       after->lineno=tokenHead->lineno;

       after->child=exp;
       advance();
       return after;
    }

    return exp;
}




struct Node* parse_index()
{
  struct Node *factor=parse_identifier();
  int nextType=getType();
  while (nextType==32 || nextType==27 || nextType==12)
  {
    advance();
    struct Node *next_factor;

    if (nextType==32)
    {
        next_factor=parse_exp();
        if (getType()!=33)
            fail("expected ]");
        advance();
    }
    else
    {
        next_factor=parse_identifier();
    }

    struct Node *new_factor=(struct Node*)malloc(sizeof(struct Node));

    if (nextType==32)
        new_factor->type=88;
    else if (nextType==27)
        new_factor->type=27;
    else
        new_factor->type=97;

    new_factor->lineno=tokenHead->lineno;
    new_factor->child=factor;
    new_factor->child2=next_factor;
    factor=new_factor;
    nextType=getType();
  }

  return factor;
}

int isTypeDec(int type)
{
    return type==44 || type==45 || type==55 || type==53;
}




struct Node* parse_factor()
{
  struct Node *exp;
  int type=getType();

  if (type==28 && isTypeDec(tokenHead->next->type))
  {

      advance();
      exp=parse_decl(101);

      if (getType()!=29) fail("Expected )");
      advance();

      exp->child=parse_exp();
  }
  else if (type==28){
    advance();
    exp=parse_exp();
    if (getType() != 29) fail("Expected )");
    advance();
  }
  else if (type==56){
    exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=56;
    exp->lineno=tokenHead->lineno;
    exp->id=newStr(tokenHead->id);
    exp->child=
# 599 "main.c" 3 4
              ((void *)0)
# 599 "main.c"
                  ;
    advance();
  }
  else if (type==58){
    exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=58;
    exp->lineno=tokenHead->lineno;
    exp->id=newStr(tokenHead->id);
    exp->child=
# 607 "main.c" 3 4
              ((void *)0)
# 607 "main.c"
                  ;
    advance();
  }
  else if (type==59){
    exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=59;
    exp->lineno=tokenHead->lineno;
    exp->id=newStr(tokenHead->id);
    exp->child=
# 615 "main.c" 3 4
              ((void *)0)
# 615 "main.c"
                  ;
    advance();
  }
  else if (type==57 && tokenHead->next->type==28){
    exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=81;
    exp->lineno=tokenHead->lineno;
    exp->id=newStr(tokenHead->id);
    advance();
    advance();
    int nlines=countArgs();
    exp->nlines=nlines;
    exp->line=(struct Node**)malloc(nlines*sizeof(struct Node*));
    int i;
    for (i=0;i<nlines;i++){
      exp->line[i]=parse_exp();
      if (i<nlines-1 && getType()!=25) fail("expected ,");
      if (i<nlines-1) advance();
    }
    if (getType()!=29) fail("expected )");
    advance();
  }
  else if (type==39)
  {
      exp=(struct Node*)malloc(sizeof(struct Node));
      exp->type=87;
      exp->lineno=tokenHead->lineno;
      advance();
      exp->child=parse_factor();
  }
  else if (type==36)
  {
      exp=(struct Node*)malloc(sizeof(struct Node));
      exp->type=86;
      exp->lineno=tokenHead->lineno;
      advance();
      exp->child=parse_factor();
  }
  else if (type==35){
      exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=61;
    exp->lineno=tokenHead->lineno;
    advance();
    exp->child=parse_factor();
  }
  else if (type==34){
      exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=89;
    exp->lineno=tokenHead->lineno;
    advance();
    exp->child=parse_factor();
  }
  else if (type==10){
    exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=96;
    exp->lineno=tokenHead->lineno;
    advance();
    exp->child=parse_factor();
  }
  else if (type==11){
    exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=98;
    exp->lineno=tokenHead->lineno;
    advance();
    exp->child=parse_factor();
  }
  else if (type==42){
    exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=62;
    exp->lineno=tokenHead->lineno;
    advance();
    exp->child=parse_factor();
  }
  else if (type==23){
    exp=(struct Node*)malloc(sizeof(struct Node));
    exp->type=63;
    exp->lineno=tokenHead->lineno;
    advance();
    exp->child=parse_factor();
  }
  else if (type==57)
  {

      exp=parse_index();
  }
  else if (type==54)
  {
      advance();
      if (getType()==28)
          advance();

      if (getType()==57)
          exp=parse_identifier();
      else
          exp=parse_decl(54);

      if (getType()==29)
          advance();
  }
  else
    fail("Expected literal or unary operator");

  return exp;
}



struct Node* parse_term()
{
  struct Node *factor=parse_factor();
  int nextType=getType();
  while (nextType==36 || nextType==37 || nextType==38){
    advance();
    struct Node *next_factor=parse_factor();
    struct Node *new_factor=(struct Node*)malloc(sizeof(struct Node));

    if (nextType==36)
      new_factor->type=66;
    else if (nextType==37)
      new_factor->type=67;
    else
      new_factor->type=95;

    new_factor->lineno=tokenHead->lineno;
    new_factor->child=factor;
    new_factor->child2=next_factor;
    factor=new_factor;
    nextType=getType();
  }

  return factor;
}




struct Node* parse_additive_exp()
{
  struct Node *term=parse_term();
  int nextType=getType();
  while (nextType==34 || nextType==35){
    advance();
    struct Node *next_term=parse_term();
    struct Node *new_term=(struct Node*)malloc(sizeof(struct Node));

    if (nextType==34)
      new_term->type=64;
    else
      new_term->type=65;

    new_term->lineno=tokenHead->lineno;
    new_term->child=term;
    new_term->child2=next_term;
    term=new_term;
    nextType=getType();
  }

  return term;
}




struct Node* parse_shift_exp()
{
    struct Node* term = parse_additive_exp();
    int nextType = getType();
    while (nextType == 8 || nextType == 9) {
        advance();
        struct Node* next_term = parse_additive_exp();
        struct Node* new_term = (struct Node*)malloc(sizeof(struct Node));

        if (nextType == 8)
            new_term->type = 90;
        else
            new_term->type = 91;

        new_term->lineno=tokenHead->lineno;
        new_term->child = term;
        new_term->child2 = next_term;
        term = new_term;
        nextType = getType();
    }

    return term;
}




struct Node* parse_relational_exp()
{
  struct Node *term=parse_shift_exp();
  int nextType=getType();
  while (nextType==22 || nextType==21 ||
  nextType==7 || nextType==6){
    advance();
    struct Node *next_term=parse_shift_exp();
    struct Node *new_term=(struct Node*)malloc(sizeof(struct Node));

    if (nextType==22){
      new_term->type=75;
    }
    else if (nextType==21){
      new_term->type=73;
    }
    else if (nextType==7){
      new_term->type=74;
    }
    else{
      new_term->type=72;
    }

    new_term->lineno=tokenHead->lineno;
    new_term->child=term;
    new_term->child2=next_term;
    term=new_term;
    nextType=getType();
  }

  return term;
}




struct Node* parse_equality_exp()
{
  struct Node *term=parse_relational_exp();
  int nextType=getType();
  while (nextType==4 || nextType==5){
    advance();
    struct Node *next_term=parse_relational_exp();
    struct Node *new_term=(struct Node*)malloc(sizeof(struct Node));

    if (nextType==4)
      new_term->type=70;
    else
      new_term->type=71;

    new_term->lineno=tokenHead->lineno;
    new_term->child=term;
    new_term->child2=next_term;
    term=new_term;
    nextType=getType();
  }

  return term;
}




struct Node* parse_bitwise_and_exp()
{
    struct Node* term = parse_equality_exp();
    int nextType = getType();
    while (nextType == 39) {
        advance();
        struct Node* next_term = parse_equality_exp();
        struct Node* new_term = (struct Node*)malloc(sizeof(struct Node));

        new_term->type = 92;
        new_term->lineno=tokenHead->lineno;

        new_term->child = term;
        new_term->child2 = next_term;
        term = new_term;
        nextType = getType();
    }

    return term;
}




struct Node* parse_bitwise_xor_exp()
{
    struct Node* term = parse_bitwise_and_exp();
    int nextType = getType();
    while (nextType == 41) {
        advance();
        struct Node* next_term = parse_bitwise_and_exp();
        struct Node* new_term = (struct Node*)malloc(sizeof(struct Node));

        new_term->type = 93;
        new_term->lineno=tokenHead->lineno;

        new_term->child = term;
        new_term->child2 = next_term;
        term = new_term;
        nextType = getType();
    }

    return term;
}




struct Node* parse_bitwise_or_exp()
{
    struct Node* term = parse_bitwise_xor_exp();
    int nextType = getType();
    while (nextType == 40) {
        advance();
        struct Node* next_term = parse_bitwise_xor_exp();
        struct Node* new_term = (struct Node*)malloc(sizeof(struct Node));

        new_term->type = 94;
        new_term->lineno=tokenHead->lineno;

        new_term->child = term;
        new_term->child2 = next_term;
        term = new_term;
        nextType = getType();
    }

    return term;
}




struct Node* parse_and_exp()
{
  struct Node *term=parse_bitwise_or_exp();
  int nextType=getType();
  while (nextType==2){
    advance();
    struct Node *next_term=parse_bitwise_or_exp();
    struct Node *new_term=(struct Node*)malloc(sizeof(struct Node));

    new_term->type=68;
    new_term->lineno=tokenHead->lineno;

    new_term->child=term;
    new_term->child2=next_term;
    term=new_term;
    nextType=getType();
  }

  return term;
}




struct Node* parse_or_exp()
{
  struct Node *term=parse_and_exp();
  int nextType=getType();
  while (nextType==3){
    advance();
    struct Node *next_term=parse_and_exp();
    struct Node *new_term=(struct Node*)malloc(sizeof(struct Node));

    new_term->type=69;
    new_term->lineno=tokenHead->lineno;

    new_term->child=term;
    new_term->child2=next_term;
    term=new_term;
    nextType=getType();
  }

  return term;
}





struct Node* parse_exp()
{
    struct Node *temp=parse_or_exp();
    struct Node *exp;

    int nextType=getType();
    if (nextType==24 || (nextType >= 13 && nextType <= 20)
        || nextType == 0 || nextType == 1)
    {
        advance();
        exp=(struct Node*)malloc(sizeof(struct Node));

        if (nextType==24)
            exp->type=76;
        else
            exp->type=nextType;

        exp->lineno=tokenHead->lineno;
        exp->child=temp;
        exp->child2=parse_exp();
    }
    else
    {
        exp=temp;
    }
    return exp;
}
# 1025 "main.c"
struct Node* parse_decl(int type)
{
  struct Node *decl=(struct Node*)malloc(sizeof(struct Node));

    if (getType()==44)
        strcpy(decl->varType.data, "int");
    else if (getType()==45)
        strcpy(decl->varType.data, "char");
    else if (getType()==55)
        strcpy(decl->varType.data, "void");
    else if (getType()==53)
    {
         strcpy(decl->varType.data, "struct ");
         advance();
         strcat(decl->varType.data, tokenHead->id);
    }

    advance();
    decl->type=type;
    decl->lineno=tokenHead->lineno;

    while (getType()==36)
    {
        strcat(decl->varType.data,"*");
        advance();
    }

    decl->id=
# 1052 "main.c" 3 4
            ((void *)0)
# 1052 "main.c"
                ;
    if (type != 54 && type != 101)
    {
        if (getType()!=57)
            fail("expecting identifier");

        decl->id=newStr(tokenHead->id);
        advance();
    }

    while (getType()==32)
    {
        strcat(decl->varType.data,"[");
        advance();
        while(getType()!=33)
        {
            strcat(decl->varType.data,tokenHead->id);
            advance();
        }
        strcat(decl->varType.data,"]");
        advance();
    }

    if (getType()==24){
      advance();
      if (getType()==30)
      {
          advance();
          int n=countInit();
          struct Node* block=(struct Node*)malloc(sizeof(struct Node));
          block->type=80;
          block->lineno=tokenHead->lineno;

          block->nlines=n;
          block->line=(struct Node**)malloc(n*sizeof(struct Node*));

          int i;
          for (i=0; i<n; i++)
          {
            block->line[i]=parse_exp();
            if (getType()==25) advance();
          }

          decl->child=block;

          if (getType()!=31) fail("Expected }");
          advance();
      }
      else
        decl->child=parse_exp();
    }
    else
      decl->child=
# 1104 "main.c" 3 4
                 ((void *)0)
# 1104 "main.c"
                     ;

    if (type == 79 || type == 83)
    {
        if (getType()!=26) fail("Expected ; in DECL");
        advance();
    }

    return decl;
}




struct Node* parse_struct()
{
    struct Node *str=(struct Node*)malloc(sizeof(struct Node));
    str->type=53;
    str->lineno=tokenHead->lineno;

    advance();

    str->id=newStr(tokenHead->id);
    advance();

    if (getType()!=30)
    {
        fail("Expected { at beginning of struct");
        exit(1);
    }

    advance();

    int n=countLines(
# 1137 "main.c" 3 4
                    ((void *)0)
# 1137 "main.c"
                        );
    printf("Found struct with %d lines\n", n);

    str->nlines=n;
    str->line=(struct Node**)malloc(n*sizeof(struct Node*));

    int i;
    for (i=0; i<n; i++)
    {
        str->line[i]=parse_decl(79);
    }

    if (getType()!=31)
    {
        fail("Expected } at end of struct");
        exit(1);
    }
    advance();

    if (getType()!=26)
    {
        fail("Expected ; at end of struct");
        exit(1);
    }
    advance();

    return str;
}




struct Node* parse_statement()
{
  struct Node *statement=(struct Node*)malloc(sizeof(struct Node));
  statement->lineno=tokenHead->lineno;

  if (getType()==46){
    statement->type=46;
    advance();

    if (getType()!=28) fail("Expected ( in IF");
    advance();

    statement->child=parse_exp();

    if (getType()!=29) fail("Expected ) in IF");
    advance();

    statement->child2=parse_statement();

    if (getType()==47){
      advance();
      statement->child3=parse_statement();
    }
    else
      statement->child3=
# 1193 "main.c" 3 4
                       ((void *)0)
# 1193 "main.c"
                           ;
  }
  else if (getType()==49){
    statement->type=49;
    advance();

    if (getType()!=28) fail("Expected ( in WHILE");
    advance();

    statement->child=parse_exp();

    if (getType()!=29) fail("Expected ) in WHILE");
    advance();

    statement->child2=parse_statement();
  }
  else if (getType()==48){
    statement->type=48;
    advance();

    if (getType()!=28) fail("Expected ( in FOR");
    advance();

    statement->child=parse_exp();

    if (getType()!=26) fail("Expected ; in FOR");
    advance();

    statement->child2=parse_exp();

    if (getType()!=26) fail("Expected ; in FOR");
    advance();

    statement->child3=parse_exp();

    if (getType()!=29) fail("Expected ) in FOR");
    advance();

    statement->child4=parse_statement();
  }
  else if (getType()==50){
    statement->type=50;
    advance();

    statement->child=parse_statement();

    if (getType()!=49) fail("Expected WHILE");
    advance();

    if (getType()!=28) fail("Expected ( in WHILE");
    advance();

    statement->child2=parse_exp();

    if (getType()!=29) fail("Expected ) in WHILE");
    advance();

    if (getType()!=26) fail("Expected ;");
    advance();
  }
  else if (getType()==30){
    statement->type=80;
    advance();
    statement->nlines=countLines(
# 1256 "main.c" 3 4
                                ((void *)0)
# 1256 "main.c"
                                    );

    statement->line=(struct Node**)malloc((statement->nlines)*sizeof(struct Node*));
    int i;
    for (i=0; i<statement->nlines; i++)
      statement->line[i]=parse_statement();

    if (getType()!=31) fail("Expected }");
    advance();
  }
  else if (getType()==43){
    statement->type=43;
    advance();

    statement->child=parse_exp();

    if (getType()!=26) fail("Expected ;");
    advance();
  }
  else if(getType()==53 && tokenHead->next->next->type==30)
  {
      return parse_struct();
  }

  else if (getType()==44 || getType()==45 || getType()==53 || getType()==55)
  {
      return parse_decl(79);
  }
  else if(getType()==51)
  {
      advance();
      statement->type=51;
      statement->child=
# 1288 "main.c" 3 4
                      ((void *)0)
# 1288 "main.c"
                          ;

      if (getType()!=26) fail("Expected ;");
      advance();
  }
  else{
    statement->type=78;
    statement->child=parse_exp();

    if (getType()!=26) fail("Expected ;");
    advance();
  }
  return statement;
}



struct Node* parse_arg()
{
    return parse_decl(82);
}



struct Node* parse_function()
{
  struct Node* function=parse_decl(60);

  if (getType()!=28) fail("Expected (");
  advance();

  int ntot=countArgsAndLines();
  int nargs=countArgs();
  function->nlines=ntot;

  printf("found %d args and %d statements in function\n", nargs, ntot-nargs);

  function->line=(struct Node**)malloc(ntot*sizeof(struct Node*));

  int i;
  for (i=0;i<nargs;i++){
    function->line[i]=parse_arg();
    if (i<nargs-1){
      if (getType()!=25) fail("expected ,");
      advance();
    }
  }

  if (getType()!=29) fail("Expected )");
  advance();

  if (getType()!=30) fail("Expected {");
  advance();

  for (i=nargs; i < ntot; i++)
    function->line[i]=parse_statement();

  if (getType()!=31) fail("Expected }");
  advance();

  return function;
}



struct Node* parse_prototype()
{
# 1366 "main.c"
  struct Node *node=parse_decl(85);

  if (getType()!=28) fail("Expected (");
  advance();

  int nargs=countArgs();
  node->nlines=nargs;

  printf("found %d args in prototype\n", nargs);

  node->line=(struct Node**)malloc(nargs*sizeof(struct Node*));

  int i;
  for (i=0;i<nargs;i++){
    node->line[i]=parse_arg();
    if (i<nargs-1){
      if (getType()!=25) fail("expected ,");
      advance();
    }
  }

  if (getType()!=29) fail("Expected )");
  advance();

  if (getType()!=26) fail("Expected ;");
  advance();

  return node;
}



struct Node* parse_global()
{
    return parse_decl(83);
}
# 1412 "main.c"
int countGlobals()
{
  int count=0;
  int level=0;
  struct Token *p=tokenHead;
  struct Token *prev=p;
  while (p!=
# 1418 "main.c" 3 4
           ((void *)0)
# 1418 "main.c"
               ){
    if (p->type==30){
      if (level==0) count++;
      level++;
    }
    if (p->type==31)
      level--;
    if (level==0 && p->type==26 && prev->type!=31)
      count++;

    prev=p;
    p=p->next;
  }
  if (level!=0) fail("Mismatched braces");
  return count;
}




struct Node* parse_program()
{
  struct Node *program=(struct Node*)malloc(sizeof(struct Node));
  program->type=84;
  program->lineno=tokenHead->lineno;

  int n=countGlobals();

  printf("Found %d global objects in program\n",n);

  program->nlines=n;
  program->line=(struct Node**)malloc(n*sizeof(struct Node*));
# 1458 "main.c"
  int i;
  for (i=0; i<n; i++)
  {
    if (getType()==53 && tokenHead->next->next->type==30)
    {
        program->line[i]=parse_struct();
    }
    else if (!isProtoOrFunc())
    {
      program->line[i]=parse_global();
    }
    else
    {
      struct Token *p=tokenHead;
      while(p->type!=29)
      {
          if (p==
# 1474 "main.c" 3 4
                ((void *)0)
# 1474 "main.c"
                    ) fail("unexpected end of file");
             p=p->next;
      }
      p=p->next;
      if (p->type==26)
      program->line[i]=parse_prototype();
      else
      program->line[i]=parse_function();
    }
  }

  return program;
}





struct Token* getTok(char *st, char **ed)
{
  int i,j;

  int lenleft=strlen(st);
  if (*st=='\0' || lenleft==0) return 
# 1497 "main.c" 3 4
                                     ((void *)0)
# 1497 "main.c"
                                         ;

  while (isspace(*st))
  {
    if (*st=='\0') return 
# 1501 "main.c" 3 4
                         ((void *)0)
# 1501 "main.c"
                             ;
    if (*st == '\n') lineno++;
    st++;
  }

  struct Token *tok=(struct Token*) malloc(sizeof (struct Token));
  tok->next=
# 1507 "main.c" 3 4
           ((void *)0)
# 1507 "main.c"
               ;
  tok->id=
# 1508 "main.c" 3 4
         ((void *)0)
# 1508 "main.c"
             ;

  for (j=0;j<numToks;j++)
  {
    int lentok=strlen(tokNames[j]);
    if (lentok>=lenleft) continue;
    int puncTok=j<43;
    int good=1;
    for (i=0;i<lentok;i++)
    {
      if (*(st+i)!=tokNames[j][i])
      {
        good=0;
        break;
      }
    }
    if (good && (puncTok || !isalnum(*(st+lentok))))
    {
      *ed=st+lentok;
      tok->type=j;
      tok->lineno = lineno;
      return tok;
    }
  }

  if (*st=='"')
  {
    st++;
    char *p=st;
    while(*p!='\0')
    {
      if (*p=='"')
      {
        int sz=p-st;
        tok->id=(char*) malloc(sz+1);
        tok->type=58;
        memcpy(tok->id,st,sz);
        tok->id[sz]='\0';
        tok->lineno = lineno;
        *ed=p+1;
        return tok;
      }
      p++;
    }
    printf("Unexpected EOF while scanning string const\n");
    exit(1);
  }
  else if (*st=='\'')
  {
    st++;
    char *p=st;
    while(*p!='\0')
    {
      if (*p=='\'')
      {
        int sz=p-st;
        tok->id=(char*) malloc(sz+1);
        tok->type=59;
        memcpy(tok->id,st,sz);
        tok->id[sz]='\0';
        tok->lineno = lineno;
        *ed=p+1;
        return tok;
      }
      p++;
    }
    printf("Unexpected EOF while scanning char const\n");
    exit(1);
  }
  else
  {
    int idOK=isalpha(*st);
    int literalOK=isdigit(*st);
    char *p=st;

    while(*p!='\0')
    {
      if (!isalnum(*p))
      {

        if (idOK)
        {
          *ed=p;
          tok->type=57;
          int sz=*ed-st;
          tok->id=(char*) malloc(sz+1);
          memcpy(tok->id,st,sz);
          tok->id[sz]='\0';
          tok->lineno = lineno;
          return tok;
        }

        if (literalOK)
        {
          *ed=p;
          tok->type=56;
          int sz=*ed-st;
          tok->id=(char*) malloc(sz+1);
          memcpy(tok->id,st,sz);
          tok->id[sz]='\0';
          tok->lineno = lineno;
          return tok;
        }

        printf("Lexer: Unknown token: ");
        char *q;
        for (q=st; q<=p; q++) putchar(*q);
        putchar('\n');
        exit(1);
      }

      if (!isalnum(*p))
        idOK=0;

      if (!isdigit(*p))
        literalOK=0;

      p++;
    }
  }

  printf("Nothing left\n");
  free(tok);
  return 
# 1631 "main.c" 3 4
        ((void *)0)
# 1631 "main.c"
            ;
}



void writeTree(struct Node *node, int indent)
{
  int i;
  for (i=0;i<indent;i++)
    printf(" ");

  printf("%s",names[node->type]);

  int nodetype=node->type;

  if (nodetype==79 || nodetype==60 || nodetype==85 || nodetype==82 || nodetype==83)
    printf(": '%s' [%s]\n",node->id, node->varType.data);
  else if (nodetype==56 ||
      nodetype==77 || nodetype==81 ||
      nodetype==58 || nodetype==59 || nodetype==53)
    printf(": '%s'\n",node->id);
  else if (nodetype==54 || nodetype==101)
    printf(": [%s]\n",node->varType.data);
  else
    printf("\n");

  if (nodetype==76 || (nodetype >= 13 && nodetype <= 20))
  {
      writeTree(node->child,indent+3);
      writeTree(node->child2,indent+3);
  }
  else if (nodetype==88 || nodetype==27 || nodetype==97)
  {
      writeTree(node->child,indent+3);
      writeTree(node->child2,indent+3);
  }
  else if (nodetype==49){
    writeTree(node->child,indent+3);
    writeTree(node->child2,indent+3);
  }
  else if (nodetype==50){
    writeTree(node->child,indent+3);
    writeTree(node->child2,indent+3);
  }
  else if (nodetype==48){
    writeTree(node->child,indent+3);
    writeTree(node->child2,indent+3);
    writeTree(node->child3,indent+3);
    writeTree(node->child4,indent+3);
  }
  else if (nodetype==46){
    writeTree(node->child,indent+3);
    writeTree(node->child2,indent+3);
    if (node->child3!=
# 1684 "main.c" 3 4
                     ((void *)0)
# 1684 "main.c"
                         ) writeTree(node->child3,indent+3);
  }
  else if (nodetype==78 ||
      nodetype==43 ||
      nodetype==61 ||
      nodetype==89 ||
      nodetype==62 ||
      nodetype==63 ||
      nodetype==86 || nodetype==87 || nodetype==96 || nodetype==98 ||
      nodetype==99 || nodetype==100 || nodetype==101)
  {
    writeTree(node->child,indent+3);
  }
  else if (nodetype==64 ||
    nodetype==65 ||
    nodetype==66 ||
    nodetype==67 ||
    nodetype==95 ||
    nodetype==73 ||
    nodetype==72 ||
    nodetype==75 ||
    nodetype==74 ||
    nodetype==70 ||
    nodetype==71 ||
    nodetype==68 ||
    nodetype==69 ||
    nodetype==92 ||
    nodetype==94 ||
      nodetype==93 ||
       nodetype==90 ||
       nodetype==91)
  {
    writeTree(node->child,indent+3);
    writeTree(node->child2,indent+3);
  }
  else if (nodetype==60 || nodetype==85 || nodetype==80 || nodetype==81 ||
           nodetype==84 || nodetype==53){
    int i;
    for (i=0; i < node->nlines; i++)
    {
      writeTree(node->line[i],indent+3);
    }
  }
  else if (nodetype==56){
    return;
  }
  else if (nodetype==77){
    return;
  }
  else if (nodetype==82){
    return;
  }
  else if (nodetype==58){
    return;
  }
  else if (nodetype==59){
    return;
  }
  else if (nodetype==85){
    return;
  }
  else if (nodetype==51){
      return;
  }
  else if (nodetype==54)
  {
  }
  else if (nodetype==79 || nodetype==83)
  {
    if (node->child!=
# 1753 "main.c" 3 4
                    ((void *)0)
# 1753 "main.c"
                        ) writeTree(node->child,indent+3);
    return;
  }
  else{
    printf("Internal compiler error: illegal nodetype (writeTree). Got %d\n",nodetype);
    exit(1);
  }
}



void writeVars()
{
  struct Var *p=varEnd;

  fprintf(fps,"# ======================\n");
  while(p!=
# 1769 "main.c" 3 4
          ((void *)0)
# 1769 "main.c"
              )
  {
    fprintf(fps,"# %s %d %d [%s] %d\n", p->id, p->level, p->offset, p->varType.data, p->isArg);
    p=p->prev;
  }
  fprintf(fps,"# ======================\n");
}



int endsWith(char* t, char c)
{
    int l=strlen(t);
    return t[l-1]==c;
}

int startsWith(char *t, char *s)
{
    if (strlen(s) > strlen(t)) return 0;

    int i;
    for (i=0; i< strlen(s); i++)
    {
        if (t[i] != s[i])
            return 0;
    }
    return 1;
}


int getArray(char* t, int open[], int close[])
{
    int l=strlen(t);

    int i, ind=0;

    for (i=0;i<l;i++)
    {
        if (t[i]=='[')
        {
            open[ind]=i;
        }
        if (t[i]==']')
        {
            close[ind]=i;
            ind++;
        }
    }
    return ind;
}



int sizeOf(struct Type t, struct Node* node)
{

    if (strcmp(t.data,"void")==0)
    {
        printf("Cannot take sizeof void\n");
        exit(1);
    }

    if (strlen(t.data)==0) return 0;

    int i, n;
    int open[10], close[10];

    n = getArray(t.data, open, close);

    int nElem=1,st,len;
    char index[16];
    char* endptr = 
# 1840 "main.c" 3 4
                  ((void *)0)
# 1840 "main.c"
                      ;
    for (i=0; i<n; i++)
    {
        st=open[i]+1; len=close[i]-1-st+1;
        memcpy(index, t.data+st, len);
        index[len]='\0';

        if (strlen(index)==0)
        {
            printf("[%s]\n",index);
            asmFail("Empty array index", node);
        }
        
# 1852 "main.c" 3
       (*_errno()) 
# 1852 "main.c"
             = 0;

        nElem *= strtol(index, &endptr, 0);

        if (!(
# 1856 "main.c" 3
             (*_errno()) 
# 1856 "main.c"
                   == 0 && *endptr == '\0'))
        {
            printf("Failed to parse index number\n");
            exit(1);
        }
    }





    struct Type s = t;

    if (n>0)
    {
        s.data[open[0]]='\0';
    }

    if (endsWith(s.data, '*'))
        return 4*nElem;
    else if (strcmp(s.data, "int") == 0)
        return 4*nElem;
    else if (strcmp(s.data, "char") == 0)
        return nElem;
    else if (startsWith(s.data, "struct"))
    {
        struct Var *p=varEnd;
        struct Node* structNode;
        int found=0;
        while(p!=
# 1885 "main.c" 3 4
                ((void *)0)
# 1885 "main.c"
                    )
        {
            if (strcmp(s.data, p->id) == 0)
            {
                structNode=p->structNode;
                found=1;
                break;
            }
            p=p->prev;
        }
        if (found==0)
        {
            printf("Unknown struct %s\n",s.data);
            exit(1);
        }

        int tot=0;
        for (i=0; i < structNode->nlines; i++)
        {
            tot += sizeOf(structNode->line[i]->varType, node);
        }
        return nElem*tot;
    }
    else
    {
        printf("Cannot find sizeof %s\n", s.data);
        exit(1);
    }
}

int isPointer(struct Type t)
{
    return endsWith(t.data, '*');
}

int isArray(struct Type t)
{
    int n;
    int open[10], close[10];

    n = getArray(t.data, open, close);
    return n!=0;
}

int isStruct(struct Type t)
{
    return startsWith(t.data, "struct") && !isArray(t) && !isPointer(t);
}


struct Type removePointer(struct Type t)
{
    if (!isPointer(t))
    {
        printf("Can't removePointer if not pointer %s\n", t.data);
        exit(1);
    }


    struct Type s;
    s=t;
    int l=strlen(s.data);
    s.data[l-1]='\0';
    return s;
}


struct Type addPointer(struct Type t)
{
    struct Type s;
    s = t;
    strcat(s.data, "*");
    return s;
}


struct Type removeArray(struct Type t)
{
    int open[10], close[10];
    int n = getArray(t.data, open, close);
    if (n==0) return t;

    struct Type s = t;
    s.data[open[0]]='\0';

    char ind[16];
    int i, st, len;
    for (i=1;i<n;i++)
    {
        st=open[i]; len=close[i]-st+1;
        memcpy(ind, t.data+st, len);
        ind[len]='\0';
        strcat(s.data, ind);
    }
    return s;
}

int isInt(struct Type t)
{
    return strcmp(t.data,"int")==0;
}

int isChar(struct Type t)
{
    return strcmp(t.data,"char")==0;
}

struct Type writeBinOp(char* op, struct Type type1, struct Type type2, struct Node* node)
{
    struct Type varType;

    if (isChar(type1) && isInt(type2))
    {
        fprintf(fps,"movzx eax,al\n");
        fprintf(fps,"%s eax,ecx\n", op);
        strcpy(varType.data,"int");
    }
    else if (isInt(type1) && isChar(type2))
    {
        fprintf(fps,"movzx ecx,cl\n");
        fprintf(fps,"%s eax,ecx\n", op);
        strcpy(varType.data,"int");
    }
    else if (isChar(type1) && isChar(type2))
    {
        fprintf(fps,"%s al,cl\n", op);
        strcpy(varType.data,"char");
    }
    else if (isInt(type1) && isInt(type2))
    {
        fprintf(fps,"%s eax,ecx\n", op);
        strcpy(varType.data,"int");
    }
    else if (strstr("add,sub", op)!=0 && isPointer(type1) && isInt(type2))
    {
        fprintf(fps, "imul ecx,%d\n",sizeOf(removePointer(type1),node));
        fprintf(fps,"%s eax,ecx\n", op);
        varType=type1;
    }
    else if (strcmp(op,"add")==0 && isInt(type1) && isPointer(type2))
    {
        fprintf(fps, "imul eax,%d\n",sizeOf(removePointer(type2),node));
        fprintf(fps,"add eax,ecx\n");
        varType=type2;
    }
    else if (strcmp(op,"sub")==0 && isPointer(type1) && isPointer(type2))
    {
        if (strcmp(type1.data, type2.data)!=0)
        {
            printf("Pointers must be identical in subtraction\n");
            exit(1);
        }

        fprintf(fps,"sub eax,ecx\n");
        fprintf(fps,"cdq\n");
        fprintf(fps,"idiv eax,%d\n", sizeOf(removePointer(type1),node));
        strcpy(varType.data,"int");
    }
    else if (strcmp(op,"cmp")==0 && isPointer(type1) && isPointer(type2))
    {
        fprintf(fps,"%s eax,ecx\n", op);
        strcpy(varType.data,"int");
    }
    else
    {
        printf("Illegal combination of types during %s [%s, %s]\n", op, type1.data, type2.data);
        exit(1);
    }
    return varType;
}



struct Type writeAsm(struct Node *node, int level, int lvalue)
{
  static int s_label=0;
  int nodetype=node->type;
  struct Type varType, type1, type2;





  if (node->type==84){
    varEnd=
# 2069 "main.c" 3 4
          ((void *)0)
# 2069 "main.c"
              ;
    int i;
    for (i=0; i<node->nlines; i++){
      writeAsm(node->line[i], level, 0);
    }
  }







  else if (node->type==83)
  {
    fprintf(fps,".data\n");

    if (node->child==
# 2086 "main.c" 3 4
                    ((void *)0)
# 2086 "main.c"
                        )
    {
        fprintf(fps,".globl _%s\n",node->id);
        fprintf(fps,"_%s:\n",node->id);
        fprintf(fps,".long 0\n");
    }
    else if (node->child->type==56)
    {
        fprintf(fps,".globl _%s\n",node->id);
        fprintf(fps,"_%s:\n",node->id);
        fprintf(fps,".long %s\n",node->child->id);
    }
    else if (node->child->type==58)
    {
        fprintf(fps,"%s_string:\n",node->id);
        fprintf(fps,".asciz \"%s\"\n", node->child->id);
        fprintf(fps,".globl _%s\n",node->id);
        fprintf(fps,"_%s:\n",node->id);
        fprintf(fps,".long %s_string\n",node->id);
    }
    else if (node->child->type==80)
    {
        if (!isArray(node->varType))
        {
            asmFail("Block init must be to array", node);
        }

        type1=removeArray(node->varType);
        printf("type1=%s\n",type1.data);
        if (isInt(type1))
        {
            fprintf(fps,".globl _%s\n",node->id);
            fprintf(fps,"_%s:\n",node->id);
            int i;
            for (i=0;i<node->child->nlines;i++)
            {
                fprintf(fps,".long %s\n", node->child->line[i]->id);
            }
        }
        else if (strcmp(type1.data,"char*")==0)
        {
            int i;
            for (i=0; i < node->child->nlines; i++)
            {
                fprintf(fps,"%s_string%d:\n",node->id,i);
                fprintf(fps,".asciz \"%s\"\n", node->child->line[i]->id);
            }
            fprintf(fps,".globl _%s\n",node->id);
            fprintf(fps,"_%s:\n",node->id);
            for (i=0;i<node->child->nlines;i++)
            {
                fprintf(fps,".long %s_string%d\n",node->id,i);
            }
        }
        else
            asmFail("Only int[] and char*[] supported for block init", node);
    }

    fprintf(fps,".text\n");

    struct Var *oldVarEnd=varEnd;
    varEnd=malloc(sizeof(struct Var));
    varEnd->offset=0;
    varEnd->id=newStr(node->id);
    varEnd->varType=node->varType;
    varEnd->level=0;
    varEnd->isArg=0;
    varEnd->prev=oldVarEnd;
    writeVars();
  }
# 2167 "main.c"
  else if (node->type==60)
  {

    struct Var *oldVarEnd=varEnd;
    varEnd=malloc(sizeof(struct Var));
    varEnd->offset=0;
    varEnd->id=newStr(node->id);
    varEnd->varType=node->varType;
    varEnd->level=0;
    varEnd->isArg=0;
    varEnd->prev=oldVarEnd;

    g_offset = 0;

    int i=0;
    int tot=8;
    while(node->line[i]->type==82)
    {
      oldVarEnd=varEnd;
      varEnd=malloc(sizeof(struct Var));
      varEnd->offset=tot;
      varEnd->id=newStr(node->line[i]->id);
      varEnd->varType=node->line[i]->varType;
      varEnd->level=1;
      varEnd->isArg=1;
      varEnd->prev=oldVarEnd;
      i++;
      if (isArray(varEnd->varType))
          tot += 4;
      else
      {
          tot += sizeOf(varEnd->varType, node);
      }
    }

    writeVars();

    fprintf(fps,".globl _%s\n",node->id);
    fprintf(fps,"_%s:\n",node->id);

    fprintf(fps,"push ebp\n");
    fprintf(fps,"mov ebp,esp\n");

    for ( ; i<node->nlines; i++)
    {
      writeAsm(node->line[i], level+1, 0);
    }




    while(varEnd!=
# 2218 "main.c" 3 4
                 ((void *)0)
# 2218 "main.c"
                     ){
      if (varEnd->level>1) asmFail("Unexpected high level variable", node);
      if (varEnd->level!=1) break;
      struct Var *prev=varEnd->prev;
      free(varEnd);
      varEnd=prev;
    }

    fprintf(fps,"# ** End of function **\n");
    writeVars();

    fprintf(fps,"mov esp,ebp\n");
    fprintf(fps,"pop ebp\n");
    fprintf(fps,"ret\n");
  }
  else if (node->type==85)
  {
    struct Var *oldVarEnd=varEnd;
    varEnd=malloc(sizeof(struct Var));
    varEnd->offset=0;
    varEnd->id=newStr(node->id);
    varEnd->varType=node->varType;
    varEnd->level=0;
    varEnd->isArg=0;
    varEnd->prev=oldVarEnd;
  }







  else if (node->type==80){

    int i;
    for (i=0;i<node->nlines;i++){
      writeAsm(node->line[i], level+1, 0);
    }


    int count=0;
    int tot=0;
    while(varEnd!=
# 2261 "main.c" 3 4
                 ((void *)0)
# 2261 "main.c"
                     ){
      if (varEnd->level > level+1) asmFail("Error: Unexpected high level variable", node);
      if (varEnd->level != level+1) break;
      tot += sizeOf(varEnd->varType,node);
      struct Var *prev=varEnd->prev;
      free(varEnd);
      varEnd=prev;
    }
    fprintf(fps,"add esp,%d\n",4*count);
    g_offset += tot;
    fprintf(fps,"# ** End of block **\n");
    writeVars();
  }





  else if (node->type==46){
    int label = ++s_label;
    writeAsm(node->child,level,0);

    fprintf(fps,"cmp eax, 0\n");
    if (node->child3==
# 2284 "main.c" 3 4
                     ((void *)0)
# 2284 "main.c"
                         )
      fprintf(fps,"je _end%d\n",label);
    else
      fprintf(fps,"je _else%d\n",label);

    writeAsm(node->child2,level,0);

    if (node->child3!=
# 2291 "main.c" 3 4
                     ((void *)0)
# 2291 "main.c"
                         ){
      fprintf(fps,"jmp _end%d\n",label);
      fprintf(fps,"_else%d:\n",label);

      writeAsm(node->child3,level,0);
    }

    fprintf(fps,"_end%d:\n",label);
  }





  else if (node->type==49){
    int label = ++s_label;

    fprintf(fps,"_start%d:\n",label);

    writeAsm(node->child,level,0);

    fprintf(fps,"cmp eax, 0\n");
    fprintf(fps,"je _end%d\n",label);

    writeAsm(node->child2,level,0);
    fprintf(fps,"jmp _start%d\n",label);
    fprintf(fps,"_end%d:\n",label);
  }





  else if (node->type==50){
    int label = ++s_label;

    fprintf(fps,"_start%d:\n",label);

    writeAsm(node->child,level,0);

    writeAsm(node->child2,level,0);
    fprintf(fps,"cmp eax, 1\n");

    fprintf(fps,"je _start%d\n",label);
    fprintf(fps,"_end%d:\n",label);
  }





  else if (node->type==48){
    int label = ++s_label;

    writeAsm(node->child,level,0);

    fprintf(fps,"_start%d:\n",label);

    writeAsm(node->child2,level,0);

    fprintf(fps,"cmp eax, 0\n");
    fprintf(fps,"je _end%d\n",label);

    writeAsm(node->child4,level,0);

    fprintf(fps,"_inc%d:\n",label);
    writeAsm(node->child3,level,0);

    fprintf(fps,"jmp _start%d\n",label);
    fprintf(fps,"_end%d:\n",label);
  }





  else if (node->type==51)
  {
      fprintf(fps, "jmp _end%d\n", s_label);
  }
# 2382 "main.c"
  else if (node->type==43){
    type1 = writeAsm(node->child,level,0);


    if (sizeOf(type1, node)==1)
        fprintf(fps,"movzx eax,al\n");

    fprintf(fps,"mov esp,ebp\n");
    fprintf(fps,"pop ebp\n");

    fprintf(fps,"ret\n");
  }





  else if (node->type==78){
    writeAsm(node->child,level,0);
  }
# 2410 "main.c"
  else if (node->type==81){
    int i;
    int tot=0;
    int size;
    int paddedSize;

    for (i=node->nlines-1;i>=0;i--)
    {
      type1 = writeAsm(node->line[i],level,0);
      if (isArray(type1))
          size=4;
      else
          size = sizeOf(type1, node);

      paddedSize= size%4 == 0 ? size : (1+size/4)*4;
      tot += paddedSize;




      if (paddedSize==4)
        fprintf(fps,"push eax\n");
      else
      {
        fprintf(fps,"sub esp,%d\n",paddedSize);



        fprintf(fps,"mov ecx,esp\n");
        fprintf(fps,"push %d\n",sizeOf(type1, node));
        fprintf(fps,"push eax\n");
        fprintf(fps,"push ecx\n");
        fprintf(fps,"call _memcpy\n");
        fprintf(fps,"add esp,12\n");

      }
    }

    fprintf(fps,"call _%s\n",node->id);
    fprintf(fps,"add esp,%d\n",tot);

    strcpy(varType.data,"int");
    struct Var *p=varEnd;
    while(p!=
# 2453 "main.c" 3 4
            ((void *)0)
# 2453 "main.c"
                )
    {
        if (strcmp(node->id,p->id)==0)
        {
            varType=p->varType;
            break;
        }
        p=p->prev;
    }
  }





  else if (node->type==53)
  {
    struct Var *oldVarEnd=varEnd;
    varEnd=malloc(sizeof(struct Var));
    varEnd->offset=0;
    varEnd->id=newStrStruct(node->id);
    varEnd->varType.data[0]='\0';
    varEnd->level=level;
    varEnd->isArg=0;
    varEnd->structNode=node;
    varEnd->prev=oldVarEnd;

    writeVars();
  }
# 2490 "main.c"
  else if (node->type==79)
  {
       printf("decl '%s' [%s] %p\n", node->id, node->varType.data, node->child);
    int size=sizeOf(node->varType, node);
    int paddedSize= size%4 == 0 ? size : (1+size/4)*4;

    if (node->child!=
# 2496 "main.c" 3 4
                    ((void *)0)
# 2496 "main.c"
                        )
    {
        type1 = writeAsm(node->child,level,0);
        if (sizeOf(type1, node)==1) fprintf(fps,"movzx eax,al\n");
    }

    if (paddedSize==4)
        fprintf(fps,"push eax # declare %s (level %d)\n",node->id,level);
    else
        fprintf(fps,"sub esp,%d # declare %s (level %d)\n",paddedSize,node->id,level);

    if (isStruct(type1))
    {

        fprintf(fps,"mov ecx,esp\n");
        fprintf(fps,"push %d\n",sizeOf(type1, node));
        fprintf(fps,"push eax\n");
        fprintf(fps,"push ecx\n");
        fprintf(fps,"call _memcpy\n");
        fprintf(fps,"add esp,12\n");

        varType = type1;
    }

    g_offset -= paddedSize;

    struct Var *oldVarEnd=varEnd;
    varEnd=malloc(sizeof(struct Var));
    varEnd->offset=g_offset;
    varEnd->id=newStr(node->id);
    varEnd->varType=node->varType;
    varEnd->level=level;
    varEnd->isArg=0;
    varEnd->prev=oldVarEnd;

    writeVars();
  }
# 2541 "main.c"
  else if (node->type==88)
  {
    type2 = writeAsm(node->child2,level,0);
    fprintf(fps,"push eax\n");

    type1 = writeAsm(node->child,level,1);
    if (isPointer(type1)) fprintf(fps,"mov eax,[eax]\n");
    fprintf(fps,"pop ecx\n");

    if (isArray(type1))
        varType=removeArray(type1);
    else if (isPointer(type1))
        varType=removePointer(type1);
    else
        asmFail("Indexing can only be used on array or pointer type", node);

    printf("index %s\n",varType.data);
    fprintf(fps,"imul ecx,%d\n",sizeOf(varType, node));
    fprintf(fps,"add eax,ecx\n");

    if (lvalue==0 && !isStruct(varType) && !isArray(varType))
    {
        if (lvalue==0)
        {
            if (sizeOf(varType,node)==1)
                fprintf(fps,"mov al,[eax]\n");
            else
                fprintf(fps,"mov eax,[eax]\n");
        }
    }
  }





  else if (node->type==27 || node->type==97)
  {
    char* field = node->child2->id;

    type1 = writeAsm(node->child,level,1);

    if (node->type==97)
    {
        type1 = removePointer(type1);
        fprintf(fps,"mov eax,[eax]\n");
    }

    struct Var *p=varEnd;
    struct Node* structNode;
    int found=0;
    while(p!=
# 2592 "main.c" 3 4
            ((void *)0)
# 2592 "main.c"
                )
    {
        if (strcmp(type1.data, p->id) == 0)
        {
            structNode=p->structNode;
            found=1;
            break;
        }
        p=p->prev;
    }
    if (found==0)
    {
        printf("Unknown struct %s\n",type1.data);
        exit(1);
    }

    int tot=0;
    found=0;
    int i;
    for (i=0; i < structNode->nlines; i++)
    {
        if (strcmp(field, structNode->line[i]->id)==0)
        {
            varType = structNode->line[i]->varType;
            found=1;
            break;
        }
        tot += sizeOf(structNode->line[i]->varType, node);
    }
    if (found==0)
    {
        printf("Struct %s has no field %s\n", type1.data, field);
        exit(1);
    }

    fprintf(fps,"mov ecx,%d\n",tot);
    fprintf(fps,"add eax,ecx\n");

    if (lvalue==0 && !isStruct(varType) && !isArray(varType))
    {
        if (sizeOf(varType, node)==1)
            fprintf(fps,"mov al,[eax]\n");
        else
            fprintf(fps,"mov eax,[eax]\n");
    }
  }






  else if (node->type==76)
  {
    type1 = writeAsm(node->child,level,1);
    fprintf(fps,"push eax\n");

    type2 = writeAsm(node->child2,level,0);
    fprintf(fps,"pop ecx\n");

    if (isStruct(type1) && isStruct(type2))
    {
        if (strcmp(type1.data, type2.data)!=0)
        {
            printf("Different struct types in assignment\n");
            exit(1);
        }

        fprintf(fps,"push %d\n",sizeOf(type1, node));
        fprintf(fps,"push eax\n");
        fprintf(fps,"push ecx\n");
        fprintf(fps,"call _memcpy\n");
        fprintf(fps,"add esp,12\n");

        return type1;
    }


    if ((isInt(type1) || isChar(type1)) && (isInt(type2) || isChar(type2)))
    {
    }
    else if (isPointer(type1) && isPointer(type2))
    {
    }
    else
    {
        printf("Incompatible types for assignment: %s, %s\n", type1.data, type2.data);
        exit(1);
    }

    if (sizeOf(type1, node)==1)
    {
        if (sizeOf(type2, node)==4)
        {
            printf("Cannot narrow int to char\n");
            exit(1);
        }
        fprintf(fps,"mov [ecx],al\n");
    }
    else
    {
        if (sizeOf(type2, node)==1)
            fprintf(fps,"movzx eax,al\n");
        fprintf(fps,"mov [ecx],eax\n");
    }
    varType=type1;
  }
# 2713 "main.c"
  else if (node->type >= 13 && node->type <= 20)
  {
    type1 = writeAsm(node->child,level,1);
    fprintf(fps,"push eax\n");

    type2 = writeAsm(node->child2,level,0);
    fprintf(fps,"pop ecx\n");

    char* ops[]={"add","sub","imul","idiv","idiv","and","or","xor"};
    char* op;

    op = ops[node->type - 13];

    if (sizeOf(type1, node)==1)
    {
        if (sizeOf(type2, node)==4)
        {
            printf("Cannot narrow int to char\n");
            exit(1);
        }



        fprintf(fps,"mov dl,[ecx]\n");
        fprintf(fps,"%s dl,al\n",op);
        fprintf(fps,"mov [ecx],dl\n");
        fprintf(fps,"mov al,dl\n");
    }
    else
    {
        if (sizeOf(type2, node)==1)
            fprintf(fps,"movzx eax,al\n");


        fprintf(fps,"mov edx,[ecx]\n");
        fprintf(fps,"%s edx,eax\n",op);
        fprintf(fps,"mov [ecx],edx\n");
        fprintf(fps,"mov eax,edx\n");



    }
    varType=type1;
  }

  else if (node->type == 0 || node->type == 1)
  {
  }







  else if (node->type==86)
  {
    type1 = writeAsm(node->child,level,0);
    varType=removePointer(type1);
    if (lvalue==0)
    {
        if (sizeOf(varType, node)==1)
            fprintf(fps,"mov al,[eax]\n");
        else
            fprintf(fps,"mov eax,[eax]\n");
    }

    varType=removePointer(type1);
  }







  else if (node->type==87)
  {
      type1 = writeAsm(node->child,level,1);
      varType = addPointer(type1);
  }





  else if (node->type==54)
  {
      fprintf(fps,"mov eax,%d\n",sizeOf(node->varType, node));
      strcpy(varType.data,"int");
  }

  else if (node->type==101)
  {
      type1 = writeAsm(node->child,level,0);
      varType = node->varType;

      if (strcmp(varType.data, type1.data)==0)
      {

      }
      else if (isPointer(type1) && isPointer(varType))
      {

      }
      else if (isChar(type1) && isInt(varType))
      {
          fprintf(fps,"movzx eax,al\n");
      }
      else if (isInt(type1) && isChar(varType))
      {
      }
      else if (isPointer(varType) && isInt(type1))
      {
      }
      else
      {
          printf("Illegal cast!\n");
          exit(1);
      }
  }

  else if (node->type==61){
    type1 = writeAsm(node->child,level,0);
    if (sizeOf(type1, node)==1)
        fprintf(fps,"neg al\n");
    else
        fprintf(fps,"neg eax\n");

    varType = type1;
  }
  else if (node->type==89)
  {

  }
  else if (node->type==96)
  {
    varType = writeAsm(node->child,level,1);
    if (sizeOf(varType, node)==1)
    {
        fprintf(fps,"inc byte ptr [eax]\n");
        fprintf(fps,"mov al,[eax]\n");
    }
    else
    {
        fprintf(fps,"inc dword ptr [eax]\n");
        fprintf(fps,"mov eax,[eax]\n");
    }
  }
  else if (node->type==98)
  {
    varType = writeAsm(node->child,level,1);
    if (sizeOf(varType, node)==1)
    {
        fprintf(fps,"dec byte ptr [eax]\n");
        fprintf(fps,"mov al,[eax]\n");
    }
    else
    {
        fprintf(fps,"dec dword ptr [eax]\n");
        fprintf(fps,"mov eax,[eax]\n");
    }
  }
  else if (node->type==99)
  {
    varType = writeAsm(node->child,level,1);
    if (sizeOf(varType, node)==1)
    {
        fprintf(fps,"mov cl,[eax]\n");
        fprintf(fps,"inc byte ptr [eax]\n");
        fprintf(fps,"mov al,cl\n");
    }
    else
    {
        fprintf(fps,"mov ecx,[eax]\n");
        fprintf(fps,"inc dword ptr [eax]\n");
        fprintf(fps,"mov eax,ecx\n");
    }
  }
  else if (node->type==100)
  {
    varType = writeAsm(node->child,level,1);
    if (sizeOf(varType, node)==1)
    {
        fprintf(fps,"mov cl,[eax]\n");
        fprintf(fps,"dec byte ptr [eax]\n");
        fprintf(fps,"mov al,cl\n");
    }
    else
    {
        fprintf(fps,"mov ecx,[eax]\n");
        fprintf(fps,"dec dword ptr [eax]\n");
        fprintf(fps,"mov eax,ecx\n");
    }
  }
  else if (node->type==62){
    type1 = writeAsm(node->child,level,0);
    if (sizeOf(type1, node)==1)
        fprintf(fps,"not al\n");
    else
        fprintf(fps,"not eax\n");

    varType = type1;
  }
  else if (node->type==63){
    type1 = writeAsm(node->child,level,0);
    if (sizeOf(type1, node)==1)
    {
        fprintf(fps,"cmp al,0\n");
        fprintf(fps,"sete al\n");
    }
    else
    {
        fprintf(fps,"cmp eax,0\n");
        fprintf(fps,"mov eax,0\n");
        fprintf(fps,"sete al\n");
    }
    varType = type1;
  }






  else if (node->type==56){
    fprintf(fps,"mov eax,%s\n",node->id);
    strcpy(varType.data,"int");
  }
  else if (node->type==58){
    int label = ++s_label;

    fprintf(fps,".data\n");
    fprintf(fps,"_string%d:\n",label);
    fprintf(fps,".asciz \"%s\"\n",node->id);
    fprintf(fps,".text\n");
    fprintf(fps,"mov eax, offset _string%d\n",label);
    strcpy(varType.data,"char*");
  }

  else if (node->type==59){
      if (strcmp(node->id,"\\0")==0)
          fprintf(fps,"mov al,0\n");
      else
          fprintf(fps,"mov al,'%s'\n",node->id);
      strcpy(varType.data,"char");
  }
# 2969 "main.c"
  else if (node->type==77)
  {
    struct Var *p=varEnd;
    int offset=0;
    int found=0;
    int isArg;
    while(p!=
# 2975 "main.c" 3 4
            ((void *)0)
# 2975 "main.c"
                )
    {
        if (strcmp(node->id,p->id)==0)
        {
            offset=p->offset;
            varType=p->varType;
            isArg=p->isArg;
            found=1;
            break;
        }
        p=p->prev;
    }
    if (found==0) {printf("Refer to undeclared variable %s\n",node->id); writeVars(); fflush(fps); exit(1);}


    if (isArray(varType))
    {
        if (isArg)
        {
            if (offset==0)
                fprintf(fps,"mov eax,_%s\n",node->id);
            else
                fprintf(fps,"mov eax,[ebp%+d] # %s\n",offset,node->id);
        }
        else
        {
            if (offset==0)
                fprintf(fps,"mov eax,offset _%s\n",node->id);
            else
                fprintf(fps,"lea eax,[ebp%+d] # %s\n",offset,node->id);
        }
        return varType;
    }


    if (isStruct(varType) && !isPointer(varType))
    {
        if (offset==0)
            fprintf(fps,"mov eax,offset _%s\n",node->id);
        else
            fprintf(fps,"lea eax,[ebp%+d] # %s\n",offset,node->id);

        return varType;
    }

    printf("var %s\n",varType.data);
    char *reg;
    if (sizeOf(varType, node)==1)
        reg="al";
    else
        reg="eax";


    if (lvalue)
    {
        if (offset==0)
            fprintf(fps,"mov eax,offset _%s\n",node->id);
        else
            fprintf(fps,"lea eax,[ebp%+d] # %s\n",offset,node->id);
    }
    else
    {
        if (offset==0)
            fprintf(fps,"mov %s,_%s\n",reg,node->id);
        else
            fprintf(fps,"mov %s,[ebp%+d] # %s\n",reg,offset,node->id);
    }
  }
# 3052 "main.c"
  else if (node->type==64){
    type2 = writeAsm(node->child2,level,0);
    fprintf(fps,"push eax\n");

    type1 = writeAsm(node->child,level,0);
    fprintf(fps,"pop ecx\n");

    varType = writeBinOp("add", type1, type2, node);
  }
  else if (node->type==65){
    type2 = writeAsm(node->child2,level,0);
    fprintf(fps,"push eax\n");
    type1 = writeAsm(node->child,level,0);
    fprintf(fps,"pop ecx\n");

    varType = writeBinOp("sub", type1, type2, node);


  }
  else if (node->type==66){
    type2 = writeAsm(node->child2,level,0);
    fprintf(fps,"push eax\n");
    type1 = writeAsm(node->child,level,0);
    fprintf(fps,"pop ecx\n");

    varType = writeBinOp("imul", type1, type2, node);


  }
  else if (node->type==67){
    type2 = writeAsm(node->child2,level,0);
    fprintf(fps,"push eax\n");
    type1 = writeAsm(node->child,level,0);
    fprintf(fps,"pop ecx\n");
    fprintf(fps,"cdq\n");

    varType = writeBinOp("idiv", type1, type2, node);


  }
  else if (node->type==95){
    type2 = writeAsm(node->child2,level,0);
    fprintf(fps,"push eax\n");
    type1 = writeAsm(node->child,level,0);
    fprintf(fps,"pop ecx\n");
    fprintf(fps,"cdq\n");

    varType = writeBinOp("idiv", type1, type2, node);

    fprintf(fps,"mov eax,edx\n");
  }
  else if (node->type==92)
  {
    type2 = writeAsm(node->child2,level,0);
    fprintf(fps,"push eax\n");
    type1 = writeAsm(node->child,level,0);
    fprintf(fps,"pop ecx\n");

    varType = writeBinOp("and", type1, type2, node);
  }
  else if (node->type==94)
  {
    type2 = writeAsm(node->child2,level,0);
    fprintf(fps,"push eax\n");
    type1 = writeAsm(node->child,level,0);
    fprintf(fps,"pop ecx\n");

    varType = writeBinOp("or", type1, type2, node);
  }
  else if (node->type==93)
  {
    type2 = writeAsm(node->child2,level,0);
    fprintf(fps,"push eax\n");
    type1 = writeAsm(node->child,level,0);
    fprintf(fps,"pop ecx\n");

    varType = writeBinOp("xor", type1, type2, node);
  }
  else if (node->type==90)
  {
    type2 = writeAsm(node->child2,level,0);
    fprintf(fps,"push eax\n");
    type1 = writeAsm(node->child,level,0);
    fprintf(fps,"pop ecx\n");

    varType = writeBinOp("shl", type1, type2, node);
  }
  else if (node->type==91)
  {
    type2 = writeAsm(node->child2,level,0);
    fprintf(fps,"push eax\n");
    type1 = writeAsm(node->child,level,0);
    fprintf(fps,"pop ecx\n");

    varType = writeBinOp("shr", type1, type2, node);
  }
  else if (
    nodetype==73 ||
    nodetype==72 ||
    nodetype==75 ||
    nodetype==74 ||
    nodetype==70 ||
    nodetype==71){

    type2 = writeAsm(node->child2,level,0);
    fprintf(fps,"push eax\n");
    type1 = writeAsm(node->child,level,0);
    fprintf(fps,"pop ecx\n");

    varType = writeBinOp("cmp", type1, type2, node);



    fprintf(fps,"mov eax, 0\n");

    if (nodetype==73)
      fprintf(fps,"setl al\n");
    else if (nodetype==72)
      fprintf(fps,"setle al\n");
    else if (nodetype==75)
      fprintf(fps,"setg al\n");
    else if (nodetype==74)
      fprintf(fps,"setge al\n");
    else if (nodetype==70)
      fprintf(fps,"sete al\n");
    else
      fprintf(fps,"setne al\n");

    strcpy(varType.data,"int");
  }
  else if (nodetype==69){




    int label = ++s_label;
    type1 = writeAsm(node->child,level,0);

    if (sizeOf(type1, node)==1)
        fprintf(fps,"cmp al, 0\n");
    else
        fprintf(fps,"cmp eax, 0\n");

    fprintf(fps,"je _else%d\n",label);

    if (sizeOf(type1, node)==1)
        fprintf(fps,"mov al, 1\n");
    else
        fprintf(fps,"mov eax, 1\n");

    fprintf(fps,"jmp _end%d\n",label);
    fprintf(fps,"_else%d:\n",label);

    type2 = writeAsm(node->child2,level,0);

    if (sizeOf(type2, node)==1)
    {
        fprintf(fps,"cmp al, 0\n");
        fprintf(fps,"mov al, 0\n");
    }
    else
    {
        fprintf(fps,"cmp eax, 0\n");
        fprintf(fps,"mov eax, 0\n");
    }

    fprintf(fps,"setne al\n");
    fprintf(fps,"_end%d:\n",label);

    strcpy(varType.data,"int");
  }
  else if (nodetype==68){




    int label = ++s_label;
    type1 = writeAsm(node->child,level,0);

    if (sizeOf(type1, node)==1)
        fprintf(fps,"cmp al, 0\n");
    else
        fprintf(fps,"cmp eax, 0\n");

    fprintf(fps,"jne _else%d\n",label);

    if (sizeOf(type1, node)==1)
        fprintf(fps,"mov al, 0\n");
    else
        fprintf(fps,"mov eax, 0\n");

    fprintf(fps,"jmp _end%d\n",label);
    fprintf(fps,"_else%d:\n",label);

    type2 = writeAsm(node->child2,level,0);

    if (sizeOf(type2, node)==1)
    {
        fprintf(fps,"cmp al, 0\n");
        fprintf(fps,"mov al, 0\n");
    }
    else
    {
        fprintf(fps,"cmp eax, 0\n");
        fprintf(fps,"mov eax, 0\n");
    }

    fprintf(fps,"setne al\n");
    fprintf(fps,"_end%d:\n",label);

    strcpy(varType.data,"int");
  }
  else
  {
    printf("Internal compiler error: illegal nodetype (writeAsm). Got %d\n",nodetype);
    exit(1);
  }

  return varType;
}



int main(int argc, char **argv)
{

    int i;



    struct Type t;
    strcpy(t.data, "int*");
    printf("sizeOf int* =%d, isPointer=%d Array=%d\n", sizeOf(t, 
# 3284 "main.c" 3 4
                                                                ((void *)0)
# 3284 "main.c"
                                                                    ),isPointer(t), isArray(t));

    strcpy(t.data, "int");
    printf("sizeOf int =%d, isPointer=%d Array=%d\n", sizeOf(t, 
# 3287 "main.c" 3 4
                                                               ((void *)0)
# 3287 "main.c"
                                                                   ),isPointer(t), isArray(t));

    strcpy(t.data, "char");
    printf("sizeOf char =%d isPointer=%d Array=%d\n", sizeOf(t, 
# 3290 "main.c" 3 4
                                                               ((void *)0)
# 3290 "main.c"
                                                                   ), isPointer(t), isArray(t));

    strcpy(t.data, "char*");
    printf("sizeOf char* =%d isPointer=%d Array=%d\n", sizeOf(t, 
# 3293 "main.c" 3 4
                                                                ((void *)0)
# 3293 "main.c"
                                                                    ), isPointer(t), isArray(t));

    strcpy(t.data, "char*[2][3]");
    printf("sizeOf char*[2][3] =%d isPointer=%d is Array=%d\n", sizeOf(t, 
# 3296 "main.c" 3 4
                                                                         ((void *)0)
# 3296 "main.c"
                                                                             ), isPointer(t), isArray(t));

    int open[10], close[10];
    int n = getArray(t.data, open, close);

    for (i=0;i<n;i++)
        printf("o=%d c=%d\n",open[i],close[i]);

    struct Type s = removeArray(t);
    printf("After remove %s\n", s.data);





    const char* usage = "Usage:\n"
        "jcc [options] foo.c\n"
        "-dumpLex: dump lex tokens to stdout\n"
        "-dumpParse: dump Abstract Syntax Tree to stdout\n"
        "-lexOnly: lex input file but do not parse or create function calls (no output file)\n"
        "-parseOnly: lex and parse but don't create function calls (no output file)\n";

  int dumpLex=0;
  int dumpParse=0;
  int lexOnly=0;
  int parseOnly=0;
  char* fname = 
# 3322 "main.c" 3 4
               ((void *)0)
# 3322 "main.c"
                   ;

  if (argc == 1)
  {
    printf("Usage: %s\n",usage);
    exit(0);
  }

  for (i=0;i<argc;i++)
  {
      if (strcmp(argv[i],"-dumpLex")==0)
          dumpLex=1;
      else if (strcmp(argv[i],"-dumpParse")==0)
          dumpParse=1;
      else if (strcmp(argv[i],"-lexOnly")==0)
          lexOnly=1;
      else if (strcmp(argv[i],"-parseOnly")==0)
          parseOnly=1;
      else
          fname=argv[i];
  }

  if (fname==
# 3344 "main.c" 3 4
            ((void *)0)
# 3344 "main.c"
                )
  {
      printf("A .c file must be specified\n");
      exit(1);
  }





  char name[64];
  char sname[64];
  char exename[64];



  for (i=strlen(fname)-1; i>=0; i--)
  {
    char c = fname[i];
    if (c=='/' || c=='\\')
    {
      strcpy(name, fname+i+1);
      break;
    }
  }

  if (i<0)
    strcpy(name,fname);

  for(i=strlen(name);i>=0;i--)
  {
    if (name[i]=='.')
      break;
  }

  if (i<0)
  {
      printf("Expected file ending .c");
      exit(1);
  }

  strcpy(sname,name);
  sname[i]='\0';
  strcat(sname,".s");

  strcpy(exename,name);
  exename[i]='\0';
  strcat(exename,".exe");

  printf("name=%s\n",name);
  printf("sname=%s\n",sname);
  printf("exename=%s\n",exename);

  FILE* fp;
  fp=fopen(fname, "rb");
  if (fp==
# 3399 "main.c" 3 4
         ((void *)0)
# 3399 "main.c"
             )
  {
    printf("file not found\n");
    exit(1);
  }





  fseek(fp, 0L, 
# 3409 "main.c" 3
               2
# 3409 "main.c"
                       );
  int sz = ftell(fp);
  rewind(fp);

  char *source=(char*)malloc(sz+1);
  fread(source,1,sz,fp);
  fclose(fp);

  source[sz]='\0';
# 3426 "main.c"
  char *st, *ed;
  struct Token *head, *prev, *tok;

  head=getTok(source,&ed);
  prev=head;
  st=ed;

  lineno=1;

  while(1)
  {
    tok=getTok(st,&ed);
    if (tok==
# 3438 "main.c" 3 4
            ((void *)0)
# 3438 "main.c"
                ) break;

    prev->next=tok;
    prev=tok;
    st=ed;
  }





  if (dumpLex)
  {
      tok=head;
      while(tok!=
# 3452 "main.c" 3 4
                ((void *)0)
# 3452 "main.c"
                    )
      {
        printf("%s",names[tok->type]);
        if (tok->type==57 || tok->type==56 || tok->type==58 || tok->type == 59)
          printf(": '%s'\n",tok->id);
        else
          printf("\n");

        tok=tok->next;
      }
  }

  if (lexOnly) return 0;





  tokenHead=head;
  struct Node *tree=parse_program();





  if (dumpParse)
      writeTree(tree,0);

  if (parseOnly)
      return 0;





  fps=fopen(sname,"w");
  fprintf(fps,".intel_syntax noprefix\n");

  writeAsm(tree,0,0);

  fclose(fps);







  char cmd[256];
  sprintf(cmd,"gcc -o %s %s",exename,sname);
  printf("%s\n",cmd);
  system(cmd);

  return 0;
}
