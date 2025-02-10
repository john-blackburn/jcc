.intel_syntax noprefix
# =========================================
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
# =========================================
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
# =========================================
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
.data
.globl _varEnd
_varEnd:
.skip 4
.text
# =========================================
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
# =========================================
# s l=1 o=12 [char*] ARG
# t l=1 o=8 [char*] ARG
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
.globl _startsWith
_startsWith:
push ebp
mov ebp,esp
sub esp, offset locals_startsWith
mov eax,[ebp+8] # t
push eax
call _strlen
add esp,4
push eax
mov eax,[ebp+12] # s
push eax
call _strlen
add esp,4
pop ecx
cmp eax,ecx
mov eax, 0
setg al
cmp eax, 0
je _end1
mov eax,0
mov esp,ebp
pop ebp
ret
_end1:
# =========================================
# i l=1 o=-4 [int] 
# s l=1 o=12 [char*] ARG
# t l=1 o=8 [char*] ARG
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
lea eax,[ebp-4] # i
push eax
mov eax,0
pop ecx
mov [ecx],eax
_start2:
mov eax,[ebp+12] # s
push eax
call _strlen
add esp,4
push eax
mov eax,[ebp-4] # i
pop ecx
cmp eax,ecx
mov eax, 0
setl al
cmp eax, 0
je _end2
mov eax,[ebp-4] # i
push eax
lea eax,[ebp+12] # s
mov eax,[eax]
pop ecx
imul ecx,1
add eax,ecx
mov al,[eax]
push eax
mov eax,[ebp-4] # i
push eax
lea eax,[ebp+8] # t
mov eax,[eax]
pop ecx
imul ecx,1
add eax,ecx
mov al,[eax]
pop ecx
cmp al,cl
mov eax, 0
setne al
cmp eax, 0
je _end3
mov eax,0
mov esp,ebp
pop ebp
ret
_end3:
# ** End of block **
# =========================================
# i l=1 o=-4 [int] 
# s l=1 o=12 [char*] ARG
# t l=1 o=8 [char*] ARG
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
_cont2:
lea eax,[ebp-4] # i
mov ecx,[eax]
inc dword ptr [eax]
mov eax,ecx
jmp _start2
_end2:
mov eax,1
mov esp,ebp
pop ebp
ret
.set locals_startsWith,4
# ** End of function **
# =========================================
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
# =========================================
# c l=1 o=12 [char] ARG
# t l=1 o=8 [char*] ARG
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
.globl _endsWith
_endsWith:
push ebp
mov ebp,esp
sub esp, offset locals_endsWith
mov eax,[ebp+8] # t
push eax
call _strlen
add esp,4
mov [ebp-4],eax # declare l (level 1)
# =========================================
# l l=1 o=-4 [int] 
# c l=1 o=12 [char] ARG
# t l=1 o=8 [char*] ARG
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
mov al,[ebp+12] # c
push eax
mov eax,1
push eax
mov eax,[ebp-4] # l
pop ecx
sub eax,ecx
push eax
lea eax,[ebp+8] # t
mov eax,[eax]
pop ecx
imul ecx,1
add eax,ecx
mov al,[eax]
pop ecx
cmp al,cl
mov eax, 0
sete al
mov esp,ebp
pop ebp
ret
.set locals_endsWith,4
# ** End of function **
# =========================================
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
# =========================================
# close l=1 o=16 [int[]] ARG
# open l=1 o=12 [int[]] ARG
# t l=1 o=8 [char*] ARG
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
.globl _getArray
_getArray:
push ebp
mov ebp,esp
sub esp, offset locals_getArray
mov eax,[ebp+8] # t
push eax
call _strlen
add esp,4
mov [ebp-4],eax # declare l (level 1)
# =========================================
# l l=1 o=-4 [int] 
# close l=1 o=16 [int[]] ARG
# open l=1 o=12 [int[]] ARG
# t l=1 o=8 [char*] ARG
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
# =========================================
# i l=1 o=-8 [int] 
# l l=1 o=-4 [int] 
# close l=1 o=16 [int[]] ARG
# open l=1 o=12 [int[]] ARG
# t l=1 o=8 [char*] ARG
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
mov eax,0
mov [ebp-12],eax # declare ind (level 1)
# =========================================
# ind l=1 o=-12 [int] 
# i l=1 o=-8 [int] 
# l l=1 o=-4 [int] 
# close l=1 o=16 [int[]] ARG
# open l=1 o=12 [int[]] ARG
# t l=1 o=8 [char*] ARG
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
lea eax,[ebp-8] # i
push eax
mov eax,0
pop ecx
mov [ecx],eax
_start4:
mov eax,[ebp-4] # l
push eax
mov eax,[ebp-8] # i
pop ecx
cmp eax,ecx
mov eax, 0
setl al
cmp eax, 0
je _end4
mov al,'['
push eax
mov eax,[ebp-8] # i
push eax
lea eax,[ebp+8] # t
mov eax,[eax]
pop ecx
imul ecx,1
add eax,ecx
mov al,[eax]
pop ecx
cmp al,cl
mov eax, 0
sete al
cmp eax, 0
je _end5
mov eax,[ebp-12] # ind
push eax
mov eax,[ebp+12] # open
pop ecx
imul ecx,4
add eax,ecx
push eax
mov eax,[ebp-8] # i
pop ecx
mov [ecx],eax
# ** End of block **
# =========================================
# ind l=1 o=-12 [int] 
# i l=1 o=-8 [int] 
# l l=1 o=-4 [int] 
# close l=1 o=16 [int[]] ARG
# open l=1 o=12 [int[]] ARG
# t l=1 o=8 [char*] ARG
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
_end5:
mov al,']'
push eax
mov eax,[ebp-8] # i
push eax
lea eax,[ebp+8] # t
mov eax,[eax]
pop ecx
imul ecx,1
add eax,ecx
mov al,[eax]
pop ecx
cmp al,cl
mov eax, 0
sete al
cmp eax, 0
je _end6
mov eax,[ebp-12] # ind
push eax
mov eax,[ebp+16] # close
pop ecx
imul ecx,4
add eax,ecx
push eax
mov eax,[ebp-8] # i
pop ecx
mov [ecx],eax
lea eax,[ebp-12] # ind
mov ecx,[eax]
inc dword ptr [eax]
mov eax,ecx
# ** End of block **
# =========================================
# ind l=1 o=-12 [int] 
# i l=1 o=-8 [int] 
# l l=1 o=-4 [int] 
# close l=1 o=16 [int[]] ARG
# open l=1 o=12 [int[]] ARG
# t l=1 o=8 [char*] ARG
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
_end6:
# ** End of block **
# =========================================
# ind l=1 o=-12 [int] 
# i l=1 o=-8 [int] 
# l l=1 o=-4 [int] 
# close l=1 o=16 [int[]] ARG
# open l=1 o=12 [int[]] ARG
# t l=1 o=8 [char*] ARG
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
_cont4:
lea eax,[ebp-8] # i
mov ecx,[eax]
inc dword ptr [eax]
mov eax,ecx
jmp _start4
_end4:
mov eax,[ebp-12] # ind
mov esp,ebp
pop ebp
ret
.set locals_getArray,12
# ** End of function **
# =========================================
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
# =========================================
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
.globl _sizeOf
_sizeOf:
push ebp
mov ebp,esp
sub esp, offset locals_sizeOf
mov eax,0
push eax
.data
_string8:
.asciz "void"
.text
mov eax, offset _string8
push eax
lea eax,[ebp+8] # t
mov ecx,0
add eax,ecx # .data
push eax
call _strcmp
add esp,8
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _end7
.data
_string9:
.asciz "Cannot take sizeof void\n"
.text
mov eax, offset _string9
push eax
call _printf
add esp,4
mov eax,1
push eax
call _exit
add esp,4
# ** End of block **
# =========================================
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
_end7:
mov eax,0
push eax
lea eax,[ebp+8] # t
mov ecx,0
add eax,ecx # .data
push eax
call _strlen
add esp,4
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _end10
mov eax,0
mov esp,ebp
pop ebp
ret
_end10:
# =========================================
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
# =========================================
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
# =========================================
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
# =========================================
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
lea eax,[ebp-8] # n
push eax
lea eax,[ebp-88] # close
push eax
lea eax,[ebp-48] # open
push eax
lea eax,[ebp+8] # t
mov ecx,0
add eax,ecx # .data
push eax
call _getArray
add esp,12
pop ecx
mov [ecx],eax
mov eax,1
mov [ebp-92],eax # declare nElem (level 1)
# =========================================
# nElem l=1 o=-92 [int] 
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
# =========================================
# st l=1 o=-96 [int] 
# nElem l=1 o=-92 [int] 
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
# =========================================
# len l=1 o=-100 [int] 
# st l=1 o=-96 [int] 
# nElem l=1 o=-92 [int] 
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
# =========================================
# index l=1 o=-116 [char[16]] 
# len l=1 o=-100 [int] 
# st l=1 o=-96 [int] 
# nElem l=1 o=-92 [int] 
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
mov eax,0
mov [ebp-120],eax # declare endptr (level 1)
# =========================================
# endptr l=1 o=-120 [char*] 
# index l=1 o=-116 [char[16]] 
# len l=1 o=-100 [int] 
# st l=1 o=-96 [int] 
# nElem l=1 o=-92 [int] 
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
lea eax,[ebp-4] # i
push eax
mov eax,0
pop ecx
mov [ecx],eax
_start11:
mov eax,[ebp-8] # n
push eax
mov eax,[ebp-4] # i
pop ecx
cmp eax,ecx
mov eax, 0
setl al
cmp eax, 0
je _end11
lea eax,[ebp-96] # st
push eax
mov eax,1
push eax
mov eax,[ebp-4] # i
push eax
lea eax,[ebp-48] # open
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
pop ecx
add eax,ecx
pop ecx
mov [ecx],eax
lea eax,[ebp-100] # len
push eax
mov eax,1
push eax
mov eax,[ebp-96] # st
push eax
mov eax,1
push eax
mov eax,[ebp-4] # i
push eax
lea eax,[ebp-88] # close
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
pop ecx
sub eax,ecx
pop ecx
sub eax,ecx
pop ecx
add eax,ecx
pop ecx
mov [ecx],eax
mov eax,[ebp-100] # len
push eax
mov eax,[ebp-96] # st
push eax
lea eax,[ebp+8] # t
mov ecx,0
add eax,ecx # .data
pop ecx
imul ecx,1
add eax,ecx
push eax
lea eax,[ebp-116] # index
push eax
call _memcpy
add esp,12
mov eax,[ebp-100] # len
push eax
lea eax,[ebp-116] # index
pop ecx
imul ecx,1
add eax,ecx
push eax
mov al,0
pop ecx
mov [ecx],al
call __errno
add esp,0
push eax
mov eax,0
pop ecx
mov [ecx],eax
mov eax,0
push eax
lea eax,[ebp-120] # endptr
push eax
lea eax,[ebp-116] # index
push eax
call _strtol
add esp,12
push eax
lea eax,[ebp-92] # nElem
pop ecx
push eax
mov eax,[eax]
imul eax,ecx
mov ecx,eax
pop eax
mov [eax],ecx
mov eax,ecx
mov eax,0
push eax
call __errno
add esp,0
mov eax,[eax]
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
jne _else13
mov eax, 0
jmp _end13
_else13:
mov al,0
push eax
mov eax,[ebp-120] # endptr
mov al,[eax]
pop ecx
cmp al,cl
mov eax, 0
sete al
cmp eax, 0
mov eax, 0
setne al
_end13:
cmp eax,0
mov eax,0
sete al
cmp eax, 0
je _end12
.data
_string14:
.asciz "Failed to parse index number\n"
.text
mov eax, offset _string14
push eax
call _printf
add esp,4
mov eax,1
push eax
call _exit
add esp,4
# ** End of block **
# =========================================
# endptr l=1 o=-120 [char*] 
# index l=1 o=-116 [char[16]] 
# len l=1 o=-100 [int] 
# st l=1 o=-96 [int] 
# nElem l=1 o=-92 [int] 
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
_end12:
# ** End of block **
# =========================================
# endptr l=1 o=-120 [char*] 
# index l=1 o=-116 [char[16]] 
# len l=1 o=-100 [int] 
# st l=1 o=-96 [int] 
# nElem l=1 o=-92 [int] 
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
_cont11:
lea eax,[ebp-4] # i
mov ecx,[eax]
inc dword ptr [eax]
mov eax,ecx
jmp _start11
_end11:
lea eax,[ebp+8] # t
lea ecx,[ebp-152]
push 32
push eax
push ecx
call _memcpy
add esp,12
# =========================================
# s l=1 o=-152 [struct Type] 
# endptr l=1 o=-120 [char*] 
# index l=1 o=-116 [char[16]] 
# len l=1 o=-100 [int] 
# st l=1 o=-96 [int] 
# nElem l=1 o=-92 [int] 
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
mov eax,0
push eax
mov eax,[ebp-8] # n
pop ecx
cmp eax,ecx
mov eax, 0
setg al
cmp eax, 0
je _end15
mov eax,0
push eax
lea eax,[ebp-48] # open
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
push eax
lea eax,[ebp-152] # s
mov ecx,0
add eax,ecx # .data
pop ecx
imul ecx,1
add eax,ecx
push eax
mov al,0
pop ecx
mov [ecx],al
# ** End of block **
# =========================================
# s l=1 o=-152 [struct Type] 
# endptr l=1 o=-120 [char*] 
# index l=1 o=-116 [char[16]] 
# len l=1 o=-100 [int] 
# st l=1 o=-96 [int] 
# nElem l=1 o=-92 [int] 
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
_end15:
mov al,'*'
push eax
lea eax,[ebp-152] # s
mov ecx,0
add eax,ecx # .data
push eax
call _endsWith
add esp,8
cmp eax, 0
je _else16
mov eax,[ebp-92] # nElem
push eax
mov eax,4
pop ecx
imul eax,ecx
mov esp,ebp
pop ebp
ret
jmp _end16
_else16:
mov eax,0
push eax
.data
_string18:
.asciz "int"
.text
mov eax, offset _string18
push eax
lea eax,[ebp-152] # s
mov ecx,0
add eax,ecx # .data
push eax
call _strcmp
add esp,8
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _else17
mov eax,[ebp-92] # nElem
push eax
mov eax,4
pop ecx
imul eax,ecx
mov esp,ebp
pop ebp
ret
jmp _end17
_else17:
mov eax,0
push eax
.data
_string20:
.asciz "char"
.text
mov eax, offset _string20
push eax
lea eax,[ebp-152] # s
mov ecx,0
add eax,ecx # .data
push eax
call _strcmp
add esp,8
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _else19
mov eax,[ebp-92] # nElem
mov esp,ebp
pop ebp
ret
jmp _end19
_else19:
.data
_string22:
.asciz "struct"
.text
mov eax, offset _string22
push eax
lea eax,[ebp-152] # s
mov ecx,0
add eax,ecx # .data
push eax
call _startsWith
add esp,8
cmp eax, 0
je _else21
mov eax,_varEnd
mov [ebp-156],eax # declare p (level 2)
# =========================================
# p l=2 o=-156 [struct Var*] 
# s l=1 o=-152 [struct Type] 
# endptr l=1 o=-120 [char*] 
# index l=1 o=-116 [char[16]] 
# len l=1 o=-100 [int] 
# st l=1 o=-96 [int] 
# nElem l=1 o=-92 [int] 
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
# =========================================
# structNode l=2 o=-160 [struct Node*] 
# p l=2 o=-156 [struct Var*] 
# s l=1 o=-152 [struct Type] 
# endptr l=1 o=-120 [char*] 
# index l=1 o=-116 [char[16]] 
# len l=1 o=-100 [int] 
# st l=1 o=-96 [int] 
# nElem l=1 o=-92 [int] 
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
mov eax,0
mov [ebp-164],eax # declare found (level 2)
# =========================================
# found l=2 o=-164 [int] 
# structNode l=2 o=-160 [struct Node*] 
# p l=2 o=-156 [struct Var*] 
# s l=1 o=-152 [struct Type] 
# endptr l=1 o=-120 [char*] 
# index l=1 o=-116 [char[16]] 
# len l=1 o=-100 [int] 
# st l=1 o=-96 [int] 
# nElem l=1 o=-92 [int] 
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
_cont23:
_start23:
mov eax,0
push eax
mov eax,[ebp-156] # p
pop ecx
cmp eax,ecx
mov eax, 0
setne al
cmp eax, 0
je _end23
mov eax,0
push eax
mov eax,[ebp-156] # p
mov ecx,0
add eax,ecx # .id
mov eax,[eax]
push eax
lea eax,[ebp-152] # s
mov ecx,0
add eax,ecx # .data
push eax
call _strcmp
add esp,8
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _end24
lea eax,[ebp-160] # structNode
push eax
mov eax,[ebp-156] # p
mov ecx,48
add eax,ecx # .structNode
mov eax,[eax]
pop ecx
mov [ecx],eax
lea eax,[ebp-164] # found
push eax
mov eax,1
pop ecx
mov [ecx],eax
jmp _end23
# ** End of block **
# =========================================
# found l=2 o=-164 [int] 
# structNode l=2 o=-160 [struct Node*] 
# p l=2 o=-156 [struct Var*] 
# s l=1 o=-152 [struct Type] 
# endptr l=1 o=-120 [char*] 
# index l=1 o=-116 [char[16]] 
# len l=1 o=-100 [int] 
# st l=1 o=-96 [int] 
# nElem l=1 o=-92 [int] 
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
_end24:
lea eax,[ebp-156] # p
push eax
mov eax,[ebp-156] # p
mov ecx,52
add eax,ecx # .prev
mov eax,[eax]
pop ecx
mov [ecx],eax
# ** End of block **
# =========================================
# found l=2 o=-164 [int] 
# structNode l=2 o=-160 [struct Node*] 
# p l=2 o=-156 [struct Var*] 
# s l=1 o=-152 [struct Type] 
# endptr l=1 o=-120 [char*] 
# index l=1 o=-116 [char[16]] 
# len l=1 o=-100 [int] 
# st l=1 o=-96 [int] 
# nElem l=1 o=-92 [int] 
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
jmp _start23
_end23:
mov eax,0
push eax
mov eax,[ebp-164] # found
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _end25
lea eax,[ebp-152] # s
mov ecx,0
add eax,ecx # .data
push eax
.data
_string26:
.asciz "Unknown struct %s\n"
.text
mov eax, offset _string26
push eax
call _printf
add esp,8
mov eax,1
push eax
call _exit
add esp,4
# ** End of block **
# =========================================
# found l=2 o=-164 [int] 
# structNode l=2 o=-160 [struct Node*] 
# p l=2 o=-156 [struct Var*] 
# s l=1 o=-152 [struct Type] 
# endptr l=1 o=-120 [char*] 
# index l=1 o=-116 [char[16]] 
# len l=1 o=-100 [int] 
# st l=1 o=-96 [int] 
# nElem l=1 o=-92 [int] 
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
_end25:
mov eax,0
mov [ebp-168],eax # declare tot (level 2)
# =========================================
# tot l=2 o=-168 [int] 
# found l=2 o=-164 [int] 
# structNode l=2 o=-160 [struct Node*] 
# p l=2 o=-156 [struct Var*] 
# s l=1 o=-152 [struct Type] 
# endptr l=1 o=-120 [char*] 
# index l=1 o=-116 [char[16]] 
# len l=1 o=-100 [int] 
# st l=1 o=-96 [int] 
# nElem l=1 o=-92 [int] 
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
lea eax,[ebp-4] # i
push eax
mov eax,0
pop ecx
mov [ecx],eax
_start27:
mov eax,[ebp-160] # structNode
mov ecx,60
add eax,ecx # .nlines
mov eax,[eax]
push eax
mov eax,[ebp-4] # i
pop ecx
cmp eax,ecx
mov eax, 0
setl al
cmp eax, 0
je _end27
mov eax,[ebp-4] # i
push eax
mov eax,[ebp-160] # structNode
mov ecx,56
add eax,ecx # .line
mov eax,[eax]
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
mov ecx,8
add eax,ecx # .varType
sub esp,32
mov ecx,esp
push 32
push eax
push ecx
call _memcpy
add esp,12
call _sizeOf
add esp,32
push eax
lea eax,[ebp-168] # tot
pop ecx
push eax
mov eax,[eax]
add eax,ecx
mov ecx,eax
pop eax
mov [eax],ecx
mov eax,ecx
# ** End of block **
# =========================================
# tot l=2 o=-168 [int] 
# found l=2 o=-164 [int] 
# structNode l=2 o=-160 [struct Node*] 
# p l=2 o=-156 [struct Var*] 
# s l=1 o=-152 [struct Type] 
# endptr l=1 o=-120 [char*] 
# index l=1 o=-116 [char[16]] 
# len l=1 o=-100 [int] 
# st l=1 o=-96 [int] 
# nElem l=1 o=-92 [int] 
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
_cont27:
lea eax,[ebp-4] # i
mov ecx,[eax]
inc dword ptr [eax]
mov eax,ecx
jmp _start27
_end27:
mov eax,[ebp-168] # tot
push eax
mov eax,[ebp-92] # nElem
pop ecx
imul eax,ecx
mov esp,ebp
pop ebp
ret
# ** End of block **
# =========================================
# s l=1 o=-152 [struct Type] 
# endptr l=1 o=-120 [char*] 
# index l=1 o=-116 [char[16]] 
# len l=1 o=-100 [int] 
# st l=1 o=-96 [int] 
# nElem l=1 o=-92 [int] 
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
jmp _end21
_else21:
lea eax,[ebp-152] # s
mov ecx,0
add eax,ecx # .data
push eax
.data
_string28:
.asciz "Cannot find sizeof %s\n"
.text
mov eax, offset _string28
push eax
call _printf
add esp,8
mov eax,1
push eax
call _exit
add esp,4
# ** End of block **
# =========================================
# s l=1 o=-152 [struct Type] 
# endptr l=1 o=-120 [char*] 
# index l=1 o=-116 [char[16]] 
# len l=1 o=-100 [int] 
# st l=1 o=-96 [int] 
# nElem l=1 o=-92 [int] 
# close l=1 o=-88 [int[10]] 
# open l=1 o=-48 [int[10]] 
# n l=1 o=-8 [int] 
# i l=1 o=-4 [int] 
# t l=1 o=8 [struct Type] ARG
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
_end21:
_end19:
_end17:
_end16:
.set locals_sizeOf,168
# ** End of function **
# =========================================
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
# =========================================
# t l=1 o=8 [struct Type] ARG
# isPointer l=0 o=0 [int] 
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
.globl _isPointer
_isPointer:
push ebp
mov ebp,esp
sub esp, offset locals_isPointer
mov al,'*'
push eax
lea eax,[ebp+8] # t
mov ecx,0
add eax,ecx # .data
push eax
call _endsWith
add esp,8
mov esp,ebp
pop ebp
ret
.set locals_isPointer,0
# ** End of function **
# =========================================
# isPointer l=0 o=0 [int] 
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
# =========================================
# argv l=1 o=12 [char**] ARG
# argc l=1 o=8 [int] ARG
# main l=0 o=0 [int] 
# isPointer l=0 o=0 [int] 
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp, offset locals_main
# =========================================
# t l=1 o=-32 [struct Type] 
# argv l=1 o=12 [char**] ARG
# argc l=1 o=8 [int] ARG
# main l=0 o=0 [int] 
# isPointer l=0 o=0 [int] 
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
.data
_string29:
.asciz "jo"
.text
mov eax, offset _string29
push eax
.data
_string30:
.asciz "John"
.text
mov eax, offset _string30
push eax
call _startsWith
add esp,8
push eax
.data
_string31:
.asciz "Jo"
.text
mov eax, offset _string31
push eax
.data
_string32:
.asciz "John"
.text
mov eax, offset _string32
push eax
call _startsWith
add esp,8
push eax
.data
_string33:
.asciz "startsWith %d %d\n"
.text
mov eax, offset _string33
push eax
call _printf
add esp,12
mov al,'N'
push eax
.data
_string34:
.asciz "John"
.text
mov eax, offset _string34
push eax
call _endsWith
add esp,8
push eax
mov al,'n'
push eax
.data
_string35:
.asciz "John"
.text
mov eax, offset _string35
push eax
call _endsWith
add esp,8
push eax
.data
_string36:
.asciz "endsWith %d %d\n"
.text
mov eax, offset _string36
push eax
call _printf
add esp,12
.data
_string37:
.asciz "int*"
.text
mov eax, offset _string37
push eax
lea eax,[ebp-32] # t
mov ecx,0
add eax,ecx # .data
push eax
call _strcpy
add esp,8
lea eax,[ebp-32] # t
sub esp,32
mov ecx,esp
push 32
push eax
push ecx
call _memcpy
add esp,12
call _isPointer
add esp,32
push eax
lea eax,[ebp-32] # t
sub esp,32
mov ecx,esp
push 32
push eax
push ecx
call _memcpy
add esp,12
call _sizeOf
add esp,32
push eax
.data
_string38:
.asciz "sizeOf int* =%d, isPointer=%d\n"
.text
mov eax, offset _string38
push eax
call _printf
add esp,12
.data
_string39:
.asciz "int"
.text
mov eax, offset _string39
push eax
lea eax,[ebp-32] # t
mov ecx,0
add eax,ecx # .data
push eax
call _strcpy
add esp,8
lea eax,[ebp-32] # t
sub esp,32
mov ecx,esp
push 32
push eax
push ecx
call _memcpy
add esp,12
call _isPointer
add esp,32
push eax
lea eax,[ebp-32] # t
sub esp,32
mov ecx,esp
push 32
push eax
push ecx
call _memcpy
add esp,12
call _sizeOf
add esp,32
push eax
.data
_string40:
.asciz "sizeOf int =%d, isPointer=%d\n"
.text
mov eax, offset _string40
push eax
call _printf
add esp,12
.data
_string41:
.asciz "char"
.text
mov eax, offset _string41
push eax
lea eax,[ebp-32] # t
mov ecx,0
add eax,ecx # .data
push eax
call _strcpy
add esp,8
lea eax,[ebp-32] # t
sub esp,32
mov ecx,esp
push 32
push eax
push ecx
call _memcpy
add esp,12
call _isPointer
add esp,32
push eax
lea eax,[ebp-32] # t
sub esp,32
mov ecx,esp
push 32
push eax
push ecx
call _memcpy
add esp,12
call _sizeOf
add esp,32
push eax
.data
_string42:
.asciz "sizeOf char =%d isPointer=%d\n"
.text
mov eax, offset _string42
push eax
call _printf
add esp,12
.data
_string43:
.asciz "char*"
.text
mov eax, offset _string43
push eax
lea eax,[ebp-32] # t
mov ecx,0
add eax,ecx # .data
push eax
call _strcpy
add esp,8
lea eax,[ebp-32] # t
sub esp,32
mov ecx,esp
push 32
push eax
push ecx
call _memcpy
add esp,12
call _isPointer
add esp,32
push eax
lea eax,[ebp-32] # t
sub esp,32
mov ecx,esp
push 32
push eax
push ecx
call _memcpy
add esp,12
call _sizeOf
add esp,32
push eax
.data
_string44:
.asciz "sizeOf char* =%d isPointer=%d\n"
.text
mov eax, offset _string44
push eax
call _printf
add esp,12
.data
_string45:
.asciz "char*[2][3]"
.text
mov eax, offset _string45
push eax
lea eax,[ebp-32] # t
mov ecx,0
add eax,ecx # .data
push eax
call _strcpy
add esp,8
lea eax,[ebp-32] # t
sub esp,32
mov ecx,esp
push 32
push eax
push ecx
call _memcpy
add esp,12
call _isPointer
add esp,32
push eax
lea eax,[ebp-32] # t
sub esp,32
mov ecx,esp
push 32
push eax
push ecx
call _memcpy
add esp,12
call _sizeOf
add esp,32
push eax
.data
_string46:
.asciz "sizeOf char*[2][3] =%d isPointer=%d\n"
.text
mov eax, offset _string46
push eax
call _printf
add esp,12
mov eax,0
mov esp,ebp
pop ebp
ret
.set locals_main,32
# ** End of function **
# =========================================
# main l=0 o=0 [int] 
# isPointer l=0 o=0 [int] 
# sizeOf l=0 o=0 [int] 
# getArray l=0 o=0 [int] 
# endsWith l=0 o=0 [int] 
# startsWith l=0 o=0 [int] 
# varEnd l=0 o=0 [struct Var*] 
# struct Var l=0 o=0 [] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# _errno l=0 o=0 [int*] 
# strtol l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# exit l=0 o=0 [void] 
# memcpy l=0 o=0 [void*] 
# printf l=0 o=0 [int] 
# strcmp l=0 o=0 [int] 
# strlen l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
