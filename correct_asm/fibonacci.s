.intel_syntax noprefix
# ======================
# n 1 8 [int] 1
# fib 0 0 [int] 0
# ======================
.globl _fib
_fib:
push ebp
mov ebp,esp
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
add esp,0
# ** End of block **
# ======================
# n 1 8 [int] 1
# fib 0 0 [int] 0
# ======================
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
add esp,0
# ** End of block **
# ======================
# n 1 8 [int] 1
# fib 0 0 [int] 0
# ======================
_end1:
# ** End of function **
# ======================
# fib 0 0 [int] 0
# ======================
mov esp,ebp
pop ebp
ret
# ======================
# main 0 0 [int] 0
# fib 0 0 [int] 0
# ======================
.globl _main
_main:
push ebp
mov ebp,esp
mov eax,10
push eax # declare n (level 1)
# ======================
# n 1 -4 [int] 0
# main 0 0 [int] 0
# fib 0 0 [int] 0
# ======================
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
# ** End of function **
# ======================
# main 0 0 [int] 0
# fib 0 0 [int] 0
# ======================
mov esp,ebp
pop ebp
ret
