.intel_syntax noprefix
# ======================
# main 0 0 [int] 0
# ======================
.globl _main
_main:
push ebp
mov ebp,esp
mov eax,2
push eax # declare i (level 1)
# ======================
# i 1 -4 [int] 0
# main 0 0 [int] 0
# ======================
mov eax,2
push eax # declare j (level 1)
# ======================
# j 1 -8 [int] 0
# i 1 -4 [int] 0
# main 0 0 [int] 0
# ======================
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
push eax # declare k (level 1)
# ======================
# k 1 -12 [int] 0
# j 1 -8 [int] 0
# i 1 -4 [int] 0
# main 0 0 [int] 0
# ======================
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
lea eax,[ebp-8] # j
push eax
mov eax,[ebp-12] # k
push eax
mov eax,3
pop ecx
imul eax,ecx
pop ecx
mov edx,[ecx]
add edx,eax
mov [ecx],edx
mov eax,edx
mov eax,100
push eax
mov eax,[ebp-8] # j
pop ecx
cmp eax,ecx
mov eax, 0
setg al
cmp eax, 0
je _end2
jmp _end1
_end2:
add esp,0
# ** End of block **
# ======================
# k 1 -12 [int] 0
# j 1 -8 [int] 0
# i 1 -4 [int] 0
# main 0 0 [int] 0
# ======================
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
# ** End of function **
# ======================
# main 0 0 [int] 0
# ======================
mov esp,ebp
pop ebp
ret
