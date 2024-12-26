.intel_syntax noprefix
# ======================
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
# ======================
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
# ======================
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
.data
.globl _varEnd
_varEnd:
.long 0
.text
# ======================
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
# ======================
# s 1 12 [char*] 1
# t 1 8 [char*] 1
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
.globl _startsWith
_startsWith:
push ebp
mov ebp,esp
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
push eax # declare i (level 1)
# ======================
# i 1 -4 [int] 0
# s 1 12 [char*] 1
# t 1 8 [char*] 1
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
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
add esp,0
# ** End of block **
# ======================
# i 1 -4 [int] 0
# s 1 12 [char*] 1
# t 1 8 [char*] 1
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
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
# ** End of function **
# ======================
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
mov esp,ebp
pop ebp
ret
# ======================
# c 1 12 [char] 1
# t 1 8 [char*] 1
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
.globl _endsWith
_endsWith:
push ebp
mov ebp,esp
mov eax,[ebp+8] # t
push eax
call _strlen
add esp,4
push eax # declare l (level 1)
# ======================
# l 1 -4 [int] 0
# c 1 12 [char] 1
# t 1 8 [char*] 1
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
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
# ** End of function **
# ======================
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
mov esp,ebp
pop ebp
ret
# ======================
# close 1 16 [int[]] 1
# open 1 12 [int[]] 1
# t 1 8 [char*] 1
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
.globl _getArray
_getArray:
push ebp
mov ebp,esp
mov eax,[ebp+8] # t
push eax
call _strlen
add esp,4
push eax # declare l (level 1)
# ======================
# l 1 -4 [int] 0
# close 1 16 [int[]] 1
# open 1 12 [int[]] 1
# t 1 8 [char*] 1
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
push eax # declare i (level 1)
# ======================
# i 1 -8 [int] 0
# l 1 -4 [int] 0
# close 1 16 [int[]] 1
# open 1 12 [int[]] 1
# t 1 8 [char*] 1
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
mov eax,0
push eax # declare ind (level 1)
# ======================
# ind 1 -12 [int] 0
# i 1 -8 [int] 0
# l 1 -4 [int] 0
# close 1 16 [int[]] 1
# open 1 12 [int[]] 1
# t 1 8 [char*] 1
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
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
add esp,0
# ** End of block **
# ======================
# ind 1 -12 [int] 0
# i 1 -8 [int] 0
# l 1 -4 [int] 0
# close 1 16 [int[]] 1
# open 1 12 [int[]] 1
# t 1 8 [char*] 1
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
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
add esp,0
# ** End of block **
# ======================
# ind 1 -12 [int] 0
# i 1 -8 [int] 0
# l 1 -4 [int] 0
# close 1 16 [int[]] 1
# open 1 12 [int[]] 1
# t 1 8 [char*] 1
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
_end6:
add esp,0
# ** End of block **
# ======================
# ind 1 -12 [int] 0
# i 1 -8 [int] 0
# l 1 -4 [int] 0
# close 1 16 [int[]] 1
# open 1 12 [int[]] 1
# t 1 8 [char*] 1
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
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
# ** End of function **
# ======================
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
mov esp,ebp
pop ebp
ret
# ======================
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
.globl _sizeOf
_sizeOf:
push ebp
mov ebp,esp
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
add eax,ecx
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
add esp,0
# ** End of block **
# ======================
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
_end7:
mov eax,0
push eax
lea eax,[ebp+8] # t
mov ecx,0
add eax,ecx
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
push eax # declare i (level 1)
# ======================
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
push eax # declare n (level 1)
# ======================
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
sub esp,40 # declare open (level 1)
# ======================
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
sub esp,40 # declare close (level 1)
# ======================
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
lea eax,[ebp-8] # n
push eax
lea eax,[ebp-88] # close
push eax
lea eax,[ebp-48] # open
push eax
lea eax,[ebp+8] # t
mov ecx,0
add eax,ecx
push eax
call _getArray
add esp,12
pop ecx
mov [ecx],eax
mov eax,1
push eax # declare nElem (level 1)
# ======================
# nElem 1 -92 [int] 0
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
push eax # declare st (level 1)
# ======================
# st 1 -96 [int] 0
# nElem 1 -92 [int] 0
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
push eax # declare len (level 1)
# ======================
# len 1 -100 [int] 0
# st 1 -96 [int] 0
# nElem 1 -92 [int] 0
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
sub esp,16 # declare index (level 1)
# ======================
# index 1 -116 [char[16]] 0
# len 1 -100 [int] 0
# st 1 -96 [int] 0
# nElem 1 -92 [int] 0
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
mov eax,0
push eax # declare endptr (level 1)
# ======================
# endptr 1 -120 [char*] 0
# index 1 -116 [char[16]] 0
# len 1 -100 [int] 0
# st 1 -96 [int] 0
# nElem 1 -92 [int] 0
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
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
add eax,ecx
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
lea eax,[ebp-92] # nElem
push eax
mov eax,0
push eax
lea eax,[ebp-120] # endptr
push eax
lea eax,[ebp-116] # index
push eax
call _strtol
add esp,12
pop ecx
mov edx,[ecx]
imul edx,eax
mov [ecx],edx
mov eax,edx
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
add esp,0
# ** End of block **
# ======================
# endptr 1 -120 [char*] 0
# index 1 -116 [char[16]] 0
# len 1 -100 [int] 0
# st 1 -96 [int] 0
# nElem 1 -92 [int] 0
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
_end12:
add esp,0
# ** End of block **
# ======================
# endptr 1 -120 [char*] 0
# index 1 -116 [char[16]] 0
# len 1 -100 [int] 0
# st 1 -96 [int] 0
# nElem 1 -92 [int] 0
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
_cont11:
lea eax,[ebp-4] # i
mov ecx,[eax]
inc dword ptr [eax]
mov eax,ecx
jmp _start11
_end11:
lea eax,[ebp+8] # t
sub esp,32 # declare s (level 1)
mov ecx,esp
push 32
push eax
push ecx
call _memcpy
add esp,12
# ======================
# s 1 -152 [struct Type] 0
# endptr 1 -120 [char*] 0
# index 1 -116 [char[16]] 0
# len 1 -100 [int] 0
# st 1 -96 [int] 0
# nElem 1 -92 [int] 0
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
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
add eax,ecx
pop ecx
imul ecx,1
add eax,ecx
push eax
mov al,0
pop ecx
mov [ecx],al
add esp,0
# ** End of block **
# ======================
# s 1 -152 [struct Type] 0
# endptr 1 -120 [char*] 0
# index 1 -116 [char[16]] 0
# len 1 -100 [int] 0
# st 1 -96 [int] 0
# nElem 1 -92 [int] 0
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
_end15:
mov al,'*'
push eax
lea eax,[ebp-152] # s
mov ecx,0
add eax,ecx
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
add eax,ecx
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
add eax,ecx
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
add eax,ecx
push eax
call _startsWith
add esp,8
cmp eax, 0
je _else21
mov eax,_varEnd
push eax # declare p (level 2)
# ======================
# p 2 -156 [struct Var*] 0
# s 1 -152 [struct Type] 0
# endptr 1 -120 [char*] 0
# index 1 -116 [char[16]] 0
# len 1 -100 [int] 0
# st 1 -96 [int] 0
# nElem 1 -92 [int] 0
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
push eax # declare structNode (level 2)
# ======================
# structNode 2 -160 [struct Node*] 0
# p 2 -156 [struct Var*] 0
# s 1 -152 [struct Type] 0
# endptr 1 -120 [char*] 0
# index 1 -116 [char[16]] 0
# len 1 -100 [int] 0
# st 1 -96 [int] 0
# nElem 1 -92 [int] 0
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
mov eax,0
push eax # declare found (level 2)
# ======================
# found 2 -164 [int] 0
# structNode 2 -160 [struct Node*] 0
# p 2 -156 [struct Var*] 0
# s 1 -152 [struct Type] 0
# endptr 1 -120 [char*] 0
# index 1 -116 [char[16]] 0
# len 1 -100 [int] 0
# st 1 -96 [int] 0
# nElem 1 -92 [int] 0
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
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
lea eax,[ebp-156] # p
mov eax,[eax]
mov ecx,0
add eax,ecx
mov eax,[eax]
push eax
lea eax,[ebp-152] # s
mov ecx,0
add eax,ecx
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
lea eax,[ebp-156] # p
mov eax,[eax]
mov ecx,48
add eax,ecx
mov eax,[eax]
pop ecx
mov [ecx],eax
lea eax,[ebp-164] # found
push eax
mov eax,1
pop ecx
mov [ecx],eax
jmp _end23
add esp,0
# ** End of block **
# ======================
# found 2 -164 [int] 0
# structNode 2 -160 [struct Node*] 0
# p 2 -156 [struct Var*] 0
# s 1 -152 [struct Type] 0
# endptr 1 -120 [char*] 0
# index 1 -116 [char[16]] 0
# len 1 -100 [int] 0
# st 1 -96 [int] 0
# nElem 1 -92 [int] 0
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
_end24:
lea eax,[ebp-156] # p
push eax
lea eax,[ebp-156] # p
mov eax,[eax]
mov ecx,52
add eax,ecx
mov eax,[eax]
pop ecx
mov [ecx],eax
add esp,0
# ** End of block **
# ======================
# found 2 -164 [int] 0
# structNode 2 -160 [struct Node*] 0
# p 2 -156 [struct Var*] 0
# s 1 -152 [struct Type] 0
# endptr 1 -120 [char*] 0
# index 1 -116 [char[16]] 0
# len 1 -100 [int] 0
# st 1 -96 [int] 0
# nElem 1 -92 [int] 0
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
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
add eax,ecx
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
add esp,0
# ** End of block **
# ======================
# found 2 -164 [int] 0
# structNode 2 -160 [struct Node*] 0
# p 2 -156 [struct Var*] 0
# s 1 -152 [struct Type] 0
# endptr 1 -120 [char*] 0
# index 1 -116 [char[16]] 0
# len 1 -100 [int] 0
# st 1 -96 [int] 0
# nElem 1 -92 [int] 0
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
_end25:
mov eax,0
push eax # declare tot (level 2)
# ======================
# tot 2 -168 [int] 0
# found 2 -164 [int] 0
# structNode 2 -160 [struct Node*] 0
# p 2 -156 [struct Var*] 0
# s 1 -152 [struct Type] 0
# endptr 1 -120 [char*] 0
# index 1 -116 [char[16]] 0
# len 1 -100 [int] 0
# st 1 -96 [int] 0
# nElem 1 -92 [int] 0
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
lea eax,[ebp-4] # i
push eax
mov eax,0
pop ecx
mov [ecx],eax
_start27:
lea eax,[ebp-160] # structNode
mov eax,[eax]
mov ecx,60
add eax,ecx
mov eax,[eax]
push eax
mov eax,[ebp-4] # i
pop ecx
cmp eax,ecx
mov eax, 0
setl al
cmp eax, 0
je _end27
lea eax,[ebp-168] # tot
push eax
mov eax,[ebp-4] # i
push eax
lea eax,[ebp-160] # structNode
mov eax,[eax]
mov ecx,56
add eax,ecx
mov eax,[eax]
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
mov ecx,8
add eax,ecx
sub esp,32
mov ecx,esp
push 32
push eax
push ecx
call _memcpy
add esp,12
call _sizeOf
add esp,32
pop ecx
mov edx,[ecx]
add edx,eax
mov [ecx],edx
mov eax,edx
add esp,0
# ** End of block **
# ======================
# tot 2 -168 [int] 0
# found 2 -164 [int] 0
# structNode 2 -160 [struct Node*] 0
# p 2 -156 [struct Var*] 0
# s 1 -152 [struct Type] 0
# endptr 1 -120 [char*] 0
# index 1 -116 [char[16]] 0
# len 1 -100 [int] 0
# st 1 -96 [int] 0
# nElem 1 -92 [int] 0
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
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
add esp,16
# ** End of block **
# ======================
# s 1 -152 [struct Type] 0
# endptr 1 -120 [char*] 0
# index 1 -116 [char[16]] 0
# len 1 -100 [int] 0
# st 1 -96 [int] 0
# nElem 1 -92 [int] 0
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
jmp _end21
_else21:
lea eax,[ebp-152] # s
mov ecx,0
add eax,ecx
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
add esp,0
# ** End of block **
# ======================
# s 1 -152 [struct Type] 0
# endptr 1 -120 [char*] 0
# index 1 -116 [char[16]] 0
# len 1 -100 [int] 0
# st 1 -96 [int] 0
# nElem 1 -92 [int] 0
# close 1 -88 [int[10]] 0
# open 1 -48 [int[10]] 0
# n 1 -8 [int] 0
# i 1 -4 [int] 0
# t 1 8 [struct Type] 1
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
_end21:
_end19:
_end17:
_end16:
# ** End of function **
# ======================
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
mov esp,ebp
pop ebp
ret
# ======================
# t 1 8 [struct Type] 1
# isPointer 0 0 [int] 0
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
.globl _isPointer
_isPointer:
push ebp
mov ebp,esp
mov al,'*'
push eax
lea eax,[ebp+8] # t
mov ecx,0
add eax,ecx
push eax
call _endsWith
add esp,8
mov esp,ebp
pop ebp
ret
# ** End of function **
# ======================
# isPointer 0 0 [int] 0
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
mov esp,ebp
pop ebp
ret
# ======================
# argv 1 12 [char**] 1
# argc 1 8 [int] 1
# main 0 0 [int] 0
# isPointer 0 0 [int] 0
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp,32 # declare t (level 1)
# ======================
# t 1 -32 [struct Type] 0
# argv 1 12 [char**] 1
# argc 1 8 [int] 1
# main 0 0 [int] 0
# isPointer 0 0 [int] 0
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
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
add eax,ecx
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
add eax,ecx
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
add eax,ecx
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
add eax,ecx
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
add eax,ecx
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
# ** End of function **
# ======================
# main 0 0 [int] 0
# isPointer 0 0 [int] 0
# sizeOf 0 0 [int] 0
# getArray 0 0 [int] 0
# endsWith 0 0 [int] 0
# startsWith 0 0 [int] 0
# varEnd 0 0 [struct Var*] 0
# struct Var 0 0 [] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# _errno 0 0 [int*] 0
# strtol 0 0 [int] 0
# strcpy 0 0 [char*] 0
# exit 0 0 [void] 0
# memcpy 0 0 [void*] 0
# printf 0 0 [int] 0
# strcmp 0 0 [int] 0
# strlen 0 0 [int] 0
# ======================
mov esp,ebp
pop ebp
ret
