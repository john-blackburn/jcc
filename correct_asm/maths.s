.intel_syntax noprefix
# =========================================
# main l=0 o=0 [int] 
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp, offset locals_main
mov eax,2
mov [ebp-4],eax # declare i (level 1)
# =========================================
# i l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
mov eax,2
mov [ebp-8],eax # declare j (level 1)
# =========================================
# j l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
lea eax,[ebp-4] # i
inc dword ptr [eax]
mov eax,[eax]
lea eax,[ebp-8] # j
push eax
mov eax,[ebp-8] # j
push eax
mov eax,[ebp-4] # i
pop ecx
and eax,ecx
pop ecx
mov [ecx],eax
# =========================================
# k l=1 o=-12 [int] 
# j l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
lea eax,[ebp-12] # k
push eax
mov eax,0
pop ecx
mov [ecx],eax
_start1:
mov eax,10
push eax
mov eax,[ebp-12] # k
pop ecx
cmp eax,ecx
mov eax, 0
setl al
cmp eax, 0
je _end1
# =========================================
# z l=2 o=-16 [int] 
# k l=1 o=-12 [int] 
# j l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
mov eax,[ebp-12] # k
push eax
mov eax,3
pop ecx
imul eax,ecx
push eax
lea eax,[ebp-8] # j
pop ecx
push eax
mov eax,[eax]
add eax,ecx
mov ecx,eax
pop eax
mov [eax],ecx
mov eax,ecx
mov eax,100
push eax
mov eax,[ebp-8] # j
pop ecx
cmp eax,ecx
mov eax, 0
setg al
cmp eax, 0
je _end2
# =========================================
# q l=3 o=-20 [int] 
# z l=2 o=-16 [int] 
# k l=1 o=-12 [int] 
# j l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
jmp _end1
# ** End of block **
# =========================================
# z l=2 o=-16 [int] 
# k l=1 o=-12 [int] 
# j l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
_end2:
# ** End of block **
# =========================================
# k l=1 o=-12 [int] 
# j l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
_cont1:
lea eax,[ebp-12] # k
inc dword ptr [eax]
mov eax,[eax]
jmp _start1
_end1:
mov eax,[ebp-8] # j
mov esp,ebp
pop ebp
ret
.set locals_main,20
# ** End of function **
# =========================================
# main l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
