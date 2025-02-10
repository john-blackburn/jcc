.intel_syntax noprefix
# =========================================
# struct _iobuf l=0 o=0 [] 
# =========================================
# =========================================
# _iob l=0 o=0 [struct _iobuf[]]  EXTERN
# struct _iobuf l=0 o=0 [] 
# =========================================
# =========================================
# mygetchar l=0 o=0 [int] 
# _filbuf l=0 o=0 [int] 
# _iob l=0 o=0 [struct _iobuf[]]  EXTERN
# struct _iobuf l=0 o=0 [] 
# =========================================
.globl _mygetchar
_mygetchar:
push ebp
mov ebp,esp
sub esp, offset locals_mygetchar
mov eax,0
push eax
mov eax,0
push eax
mov eax,offset __iob
pop ecx
imul ecx,32
add eax,ecx
mov ecx,4
add eax,ecx # ._cnt
dec dword ptr [eax]
mov eax,[eax]
pop ecx
cmp eax,ecx
mov eax, 0
setge al
cmp eax, 0
je _else1
mov eax,0
push eax
mov eax,offset __iob
pop ecx
imul ecx,32
add eax,ecx
mov ecx,0
add eax,ecx # ._ptr
mov ecx,[eax]
add dword ptr [eax],1
mov eax,ecx
mov al,[eax]
movzx eax,al
jmp _end1
_else1:
mov eax,0
push eax
mov eax,offset __iob
pop ecx
imul ecx,32
add eax,ecx
push eax
call __filbuf
add esp,4
_end1:
mov esp,ebp
pop ebp
ret
.set locals_mygetchar,0
# ** End of function **
# =========================================
# mygetchar l=0 o=0 [int] 
# _filbuf l=0 o=0 [int] 
# _iob l=0 o=0 [struct _iobuf[]]  EXTERN
# struct _iobuf l=0 o=0 [] 
# =========================================
mov esp,ebp
pop ebp
ret
# =========================================
# main l=0 o=0 [int] 
# mygetchar l=0 o=0 [int] 
# _filbuf l=0 o=0 [int] 
# _iob l=0 o=0 [struct _iobuf[]]  EXTERN
# struct _iobuf l=0 o=0 [] 
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp, offset locals_main
mov eax,0
mov [ebp-4],eax # declare tot (level 1)
# =========================================
# tot l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# mygetchar l=0 o=0 [int] 
# _filbuf l=0 o=0 [int] 
# _iob l=0 o=0 [struct _iobuf[]]  EXTERN
# struct _iobuf l=0 o=0 [] 
# =========================================
_cont2:
_start2:
mov eax,1
cmp eax, 0
je _end2
call _mygetchar
add esp,0
mov [ebp-8],eax # declare c (level 2)
# =========================================
# c l=2 o=-8 [int] 
# tot l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# mygetchar l=0 o=0 [int] 
# _filbuf l=0 o=0 [int] 
# _iob l=0 o=0 [struct _iobuf[]]  EXTERN
# struct _iobuf l=0 o=0 [] 
# =========================================
mov eax,0
push eax
mov eax,offset __iob
pop ecx
imul ecx,32
add eax,ecx
mov ecx,4
add eax,ecx # ._cnt
mov eax,[eax]
push eax
.data
_string3:
.asciz "_cnt=%d\n"
.text
mov eax, offset _string3
push eax
call _printf
add esp,8
mov al,'\n'
push eax
mov eax,[ebp-8] # c
pop ecx
movzx ecx,cl
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _end4
jmp _end2
_end4:
mov eax,[ebp-8] # c
push eax
lea eax,[ebp-4] # tot
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
# tot l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# mygetchar l=0 o=0 [int] 
# _filbuf l=0 o=0 [int] 
# _iob l=0 o=0 [struct _iobuf[]]  EXTERN
# struct _iobuf l=0 o=0 [] 
# =========================================
jmp _start2
_end2:
mov eax,[ebp-4] # tot
mov esp,ebp
pop ebp
ret
.set locals_main,8
# ** End of function **
# =========================================
# main l=0 o=0 [int] 
# mygetchar l=0 o=0 [int] 
# _filbuf l=0 o=0 [int] 
# _iob l=0 o=0 [struct _iobuf[]]  EXTERN
# struct _iobuf l=0 o=0 [] 
# =========================================
mov esp,ebp
pop ebp
ret
