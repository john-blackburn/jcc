.intel_syntax noprefix
# =========================================
# main l=0 o=0 [int] 
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp, offset locals_main
mov eax,3
mov [ebp-4],eax # declare c (level 1)
# =========================================
# c l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
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
.set locals_main,4
# ** End of function **
# =========================================
# main l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
