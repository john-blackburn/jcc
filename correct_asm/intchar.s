.intel_syntax noprefix
# =========================================
# main l=0 o=0 [int] 
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp, offset locals_main
# =========================================
# i l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
mov al,'a'
movzx eax,al
mov [ebp-8],eax # declare c (level 1)
# =========================================
# c l=1 o=-8 [char] 
# i l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
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
.set locals_main,8
# ** End of function **
# =========================================
# main l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
