.intel_syntax noprefix
# =========================================
# main l=0 o=0 [int]  
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
mov al,'A'
movzx eax,al
push eax # declare c (level 1)
# =========================================
# c l=1 o=-4 [char]  
# main l=0 o=0 [int]  
# =========================================
mov eax,0
push eax # declare i (level 1)
# =========================================
# i l=1 o=-8 [int]  
# c l=1 o=-4 [char]  
# main l=0 o=0 [int]  
# =========================================
mov al,'A'
push eax
mov al,[ebp-4] # c
pop ecx
cmp al,cl
mov eax, 0
sete al
cmp eax, 0
je _else1
jmp _a1
jmp _end1
_else1:
jmp _agn
_end1:
_a1:
lea eax,[ebp-8] # i
push eax
mov eax,1
pop ecx
mov [ecx],eax
_agn:
mov al,'A'
push eax
mov al,[ebp-4] # c
pop ecx
cmp al,cl
mov eax, 0
sete al
cmp eax, 0
je _end2
jmp _skp
_end2:
lea eax,[ebp-4] # c
push eax
mov al,'C'
pop ecx
mov [ecx],al
_skp:
mov al,[ebp-4] # c
cmp al,'A'
je _caseA3
cmp al,'B'
je _caseB3
jmp _default3
_caseA3:
mov eax,7
push eax
lea eax,[ebp-8] # i
pop ecx
push eax
mov eax,[eax]
add eax,ecx
mov ecx,eax
pop eax
mov [eax],ecx
mov eax,ecx
jmp _end3
_caseB3:
mov eax,6
push eax
lea eax,[ebp-8] # i
pop ecx
push eax
mov eax,[eax]
add eax,ecx
mov ecx,eax
pop eax
mov [eax],ecx
mov eax,ecx
jmp _end3
_default3:
mov eax,5
push eax
lea eax,[ebp-8] # i
pop ecx
push eax
mov eax,[eax]
add eax,ecx
mov ecx,eax
pop eax
mov [eax],ecx
mov eax,ecx
jmp _end3
add esp,0
# ** End of block **
# =========================================
# i l=1 o=-8 [int]  
# c l=1 o=-4 [char]  
# main l=0 o=0 [int]  
# =========================================
_end3:
mov eax,[ebp-8] # i
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
