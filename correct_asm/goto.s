.intel_syntax noprefix
# =========================================
# main l=0 o=0 [int]  
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
mov eax,0
push eax # declare i (level 1)
# =========================================
# i l=1 o=-4 [int]  
# main l=0 o=0 [int]  
# =========================================
_st:
mov eax,10
push eax
mov eax,[ebp-4] # i
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _end1
jmp _ed
_end1:
mov eax,[ebp-4] # i
push eax
.data
_string2:
.asciz "iteration %d\n"
.text
mov eax, offset _string2
push eax
call _printf
add esp,8
lea eax,[ebp-4] # i
mov ecx,[eax]
inc dword ptr [eax]
mov eax,ecx
jmp _st
_ed:
.data
_string3:
.asciz "Don't use goto!\n"
.text
mov eax, offset _string3
push eax
call _printf
add esp,4
mov eax,0
mov esp,ebp
pop ebp
ret
# ** End of function **
# =========================================
# main l=0 o=0 [int]  
# =========================================
mov esp,ebp
pop ebp
ret
