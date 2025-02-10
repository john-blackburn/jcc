.intel_syntax noprefix
# =========================================
# n l=1 o=8 [int] ARG
# fib l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# =========================================
.globl _fib
_fib:
push ebp
mov ebp,esp
sub esp, offset locals_fib
mov eax,0
push eax
mov eax,[ebp+8] # n
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _else2
mov eax, 1
jmp _end2
_else2:
mov eax,1
push eax
mov eax,[ebp+8] # n
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
mov eax, 0
setne al
_end2:
cmp eax, 0
je _else1
mov eax,[ebp+8] # n
mov esp,ebp
pop ebp
ret
# ** End of block **
# =========================================
# n l=1 o=8 [int] ARG
# fib l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# =========================================
jmp _end1
_else1:
mov eax,2
push eax
mov eax,[ebp+8] # n
pop ecx
sub eax,ecx
push eax
call _fib
add esp,4
push eax
mov eax,1
push eax
mov eax,[ebp+8] # n
pop ecx
sub eax,ecx
push eax
call _fib
add esp,4
pop ecx
add eax,ecx
mov esp,ebp
pop ebp
ret
# ** End of block **
# =========================================
# n l=1 o=8 [int] ARG
# fib l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# =========================================
_end1:
.set locals_fib,0
# ** End of function **
# =========================================
# fib l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
# =========================================
# main l=0 o=0 [int] 
# fib l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp, offset locals_main
mov eax,10
mov [ebp-4],eax # declare n (level 1)
# =========================================
# n l=1 o=-4 [int]  CONST
# main l=0 o=0 [int] 
# fib l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# =========================================
mov eax,[ebp-4] # n
push eax
call _fib
add esp,4
push eax
mov eax,[ebp-4] # n
push eax
.data
_string3:
.asciz "The %d-th Fibonacci number is %d\n"
.text
mov eax, offset _string3
push eax
call _printf
add esp,12
mov eax,0
mov esp,ebp
pop ebp
ret
.set locals_main,4
# ** End of function **
# =========================================
# main l=0 o=0 [int] 
# fib l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
