.intel_syntax noprefix
# ======================
# main 0 0 [int] 0
# ======================
.globl _main
_main:
push ebp
mov ebp,esp
push eax # declare i (level 1)
# ======================
# i 1 -4 [int] 0
# main 0 0 [int] 0
# ======================
mov al,'a'
movzx eax,al
push eax # declare c (level 1)
# ======================
# c 1 -8 [char] 0
# i 1 -4 [int] 0
# main 0 0 [int] 0
# ======================
lea eax,[ebp-4] # i
push eax
mov eax,10
pop ecx
mov [ecx],eax
lea eax,[ebp-8] # c
push eax
mov al,'1'
pop ecx
mov [ecx],al
lea eax,[ebp-4] # i
push eax
mov al,[ebp-8] # c
push eax
mov eax,[ebp-4] # i
pop ecx
movzx ecx,cl
add eax,ecx
pop ecx
mov [ecx],eax
mov eax,[ebp-4] # i
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
