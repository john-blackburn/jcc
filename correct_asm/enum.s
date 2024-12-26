.intel_syntax noprefix
# ======================
# main 0 0 [int] 0
# ======================
.globl _main
_main:
push ebp
mov ebp,esp
mov eax,3
push eax # declare c (level 1)
# ======================
# c 1 -4 [int] 0
# main 0 0 [int] 0
# ======================
mov eax,3
push eax
mov eax,[ebp-4] # c
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _end1
lea eax,[ebp-4] # c
push eax
mov eax,1
push eax
mov eax,4
pop ecx
add eax,ecx
pop ecx
mov [ecx],eax
_end1:
mov eax,[ebp-4] # c
mov esp,ebp
pop ebp
ret
# ** End of function **
# ======================
# main 0 0 [int] 0
# ======================
mov esp,ebp
pop ebp
ret
