.intel_syntax noprefix
# ======================
# struct _iobuf 0 0 [] 0
# ======================
# ======================
# main 0 0 [int] 0
# struct _iobuf 0 0 [] 0
# ======================
.globl _main
_main:
push ebp
mov ebp,esp
push eax # declare n (level 1)
# ======================
# n 1 -4 [int] 0
# main 0 0 [int] 0
# struct _iobuf 0 0 [] 0
# ======================
push eax # declare p (level 1)
# ======================
# p 1 -8 [int*] 0
# n 1 -4 [int] 0
# main 0 0 [int] 0
# struct _iobuf 0 0 [] 0
# ======================
push eax # declare q (level 1)
# ======================
# q 1 -12 [int**] 0
# p 1 -8 [int*] 0
# n 1 -4 [int] 0
# main 0 0 [int] 0
# struct _iobuf 0 0 [] 0
# ======================
sub esp,32 # declare foo (level 1)
# ======================
# foo 1 -44 [struct _iobuf] 0
# q 1 -12 [int**] 0
# p 1 -8 [int*] 0
# n 1 -4 [int] 0
# main 0 0 [int] 0
# struct _iobuf 0 0 [] 0
# ======================
mov eax,2
push eax # declare index (level 1)
# ======================
# index 1 -48 [int] 0
# foo 1 -44 [struct _iobuf] 0
# q 1 -12 [int**] 0
# p 1 -8 [int*] 0
# n 1 -4 [int] 0
# main 0 0 [int] 0
# struct _iobuf 0 0 [] 0
# ======================
mov eax,[ebp-48] # index
mov esp,ebp
pop ebp
ret
# ** End of function **
# ======================
# main 0 0 [int] 0
# struct _iobuf 0 0 [] 0
# ======================
mov esp,ebp
pop ebp
ret
