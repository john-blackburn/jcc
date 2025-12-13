.intel_syntax noprefix
.data
.globl _tokentype
_tokentype:
.skip 4
.text
# =========================================
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
.data
.globl _token
_token:
.skip 100
.text
# =========================================
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
.data
.globl _name
_name:
.skip 100
.text
# =========================================
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
.data
.globl _datatype
_datatype:
.skip 100
.text
# =========================================
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
.data
.globl _out
_out:
.skip 1000
.text
# =========================================
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
.data
.globl _buf
_buf:
.skip 100
.text
# =========================================
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
.data
.globl _bufp
_bufp:
.long 0
.text
# =========================================
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
# =========================================
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
.globl _getch
_getch:
push ebp
mov ebp,esp
sub esp, offset locals_getch
mov eax,0
push eax
mov eax,_bufp
pop ecx
cmp eax,ecx
mov eax, 0
setg al
cmp eax, 0
je _else1
mov eax,offset _bufp
dec dword ptr [eax]
mov eax,[eax]
push eax
mov eax,offset _buf
pop ecx
imul ecx,1
add eax,ecx
mov al,[eax]
movzx eax,al
jmp _end1
_else1:
call _getchar
add esp,0
_end1:
mov esp,ebp
pop ebp
ret
.set locals_getch,0
# ** End of function **
# =========================================
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
# =========================================
# c l=1 o=8 [int] ARG
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
.globl _ungetch
_ungetch:
push ebp
mov ebp,esp
sub esp, offset locals_ungetch
mov eax,100
push eax
mov eax,_bufp
pop ecx
cmp eax,ecx
mov eax, 0
setge al
cmp eax, 0
je _else2
.data
_string3:
.asciz "ungetch: too many character\n"
.text
mov eax, offset _string3
push eax
call _printf
add esp,4
jmp _end2
_else2:
mov eax,offset _bufp
mov ecx,[eax]
inc dword ptr [eax]
mov eax,ecx
push eax
mov eax,offset _buf
pop ecx
imul ecx,1
add eax,ecx
push eax
mov eax,[ebp+8] # c
pop ecx
mov [ecx],al
_end2:
.set locals_ungetch,0
# ** End of function **
# =========================================
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
# =========================================
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
.globl _gettoken
_gettoken:
push ebp
mov ebp,esp
sub esp, offset locals_gettoken
# =========================================
# c l=1 o=-4 [int] 
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
mov eax,offset _token
mov [ebp-8],eax # declare p (level 1)
# =========================================
# p l=1 o=-8 [char*] 
# c l=1 o=-4 [int] 
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
_cont4:
_start4:
mov al,' '
push eax
lea eax,[ebp-4] # c
push eax
call _getch
add esp,0
pop ecx
mov [ecx],eax
pop ecx
movzx ecx,cl
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _else5
mov eax, 1
jmp _end5
_else5:
mov al,'\t'
push eax
mov eax,[ebp-4] # c
pop ecx
movzx ecx,cl
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
mov eax, 0
setne al
_end5:
cmp eax, 0
je _end4
jmp _start4
_end4:
mov al,'('
push eax
mov eax,[ebp-4] # c
pop ecx
movzx ecx,cl
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _else6
mov al,')'
push eax
lea eax,[ebp-4] # c
push eax
call _getch
add esp,0
pop ecx
mov [ecx],eax
pop ecx
movzx ecx,cl
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _else7
.data
_string8:
.asciz "()"
.text
mov eax, offset _string8
push eax
mov eax,offset _token
push eax
call _strcpy
add esp,8
mov eax,offset _tokentype
push eax
mov eax,1
pop ecx
mov [ecx],eax
mov esp,ebp
pop ebp
ret
# ** End of block **
# =========================================
# p l=1 o=-8 [char*] 
# c l=1 o=-4 [int] 
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
jmp _end7
_else7:
mov eax,[ebp-4] # c
push eax
call _ungetch
add esp,4
mov eax,offset _tokentype
push eax
mov al,'('
pop ecx
movzx eax,al
mov [ecx],eax
mov esp,ebp
pop ebp
ret
# ** End of block **
# =========================================
# p l=1 o=-8 [char*] 
# c l=1 o=-4 [int] 
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
_end7:
# ** End of block **
# =========================================
# p l=1 o=-8 [char*] 
# c l=1 o=-4 [int] 
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
jmp _end6
_else6:
mov al,'['
push eax
mov eax,[ebp-4] # c
pop ecx
movzx ecx,cl
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _else9
lea eax,[ebp-8] # p
mov ecx,[eax]
add dword ptr [eax],1
mov eax,ecx
push eax
mov eax,[ebp-4] # c
pop ecx
mov [ecx],al
_start10:
mov al,']'
push eax
lea eax,[ebp-8] # p
mov ecx,[eax]
add dword ptr [eax],1
mov eax,ecx
push eax
call _getch
add esp,0
pop ecx
mov [ecx],al
pop ecx
cmp al,cl
mov eax, 0
setne al
cmp eax, 0
je _end10
_cont10:
jmp _start10
_end10:
mov eax,[ebp-8] # p
push eax
mov al,0
pop ecx
mov [ecx],al
mov eax,offset _tokentype
push eax
mov eax,2
pop ecx
mov [ecx],eax
mov esp,ebp
pop ebp
ret
# ** End of block **
# =========================================
# p l=1 o=-8 [char*] 
# c l=1 o=-4 [int] 
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
jmp _end9
_else9:
mov eax,[ebp-4] # c
push eax
call _isalpha
add esp,4
cmp eax, 0
je _else11
lea eax,[ebp-8] # p
mov ecx,[eax]
add dword ptr [eax],1
mov eax,ecx
push eax
mov eax,[ebp-4] # c
pop ecx
mov [ecx],al
_start12:
lea eax,[ebp-4] # c
push eax
call _getch
add esp,0
pop ecx
mov [ecx],eax
push eax
call _isalnum
add esp,4
cmp eax, 0
je _end12
lea eax,[ebp-8] # p
mov ecx,[eax]
add dword ptr [eax],1
mov eax,ecx
push eax
mov eax,[ebp-4] # c
pop ecx
mov [ecx],al
_cont12:
jmp _start12
_end12:
mov eax,[ebp-8] # p
push eax
mov al,0
pop ecx
mov [ecx],al
mov eax,[ebp-4] # c
push eax
call _ungetch
add esp,4
mov eax,offset _tokentype
push eax
mov eax,0
pop ecx
mov [ecx],eax
mov esp,ebp
pop ebp
ret
# ** End of block **
# =========================================
# p l=1 o=-8 [char*] 
# c l=1 o=-4 [int] 
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
jmp _end11
_else11:
mov eax,offset _tokentype
push eax
mov eax,[ebp-4] # c
pop ecx
mov [ecx],eax
mov esp,ebp
pop ebp
ret
_end11:
_end9:
_end6:
.set locals_gettoken,8
# ** End of function **
# =========================================
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
# =========================================
# dcl l=0 o=0 [void] 
# dirdcl l=0 o=0 [void] 
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
.globl _dcl
_dcl:
push ebp
mov ebp,esp
sub esp, offset locals_dcl
# =========================================
# ns l=1 o=-4 [int] 
# dcl l=0 o=0 [void] 
# dirdcl l=0 o=0 [void] 
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
lea eax,[ebp-4] # ns
push eax
mov eax,0
pop ecx
mov [ecx],eax
_start13:
mov al,'*'
push eax
call _gettoken
add esp,0
pop ecx
movzx ecx,cl
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _end13
lea eax,[ebp-4] # ns
mov ecx,[eax]
inc dword ptr [eax]
mov eax,ecx
_cont13:
jmp _start13
_end13:
call _dirdcl
add esp,0
_cont14:
_start14:
mov eax,0
push eax
lea eax,[ebp-4] # ns
mov ecx,[eax]
dec dword ptr [eax]
mov eax,ecx
pop ecx
cmp eax,ecx
mov eax, 0
setg al
cmp eax, 0
je _end14
.data
_string15:
.asciz " pointer to"
.text
mov eax, offset _string15
push eax
mov eax,offset _out
push eax
call _strcat
add esp,8
jmp _start14
_end14:
.set locals_dcl,4
# ** End of function **
# =========================================
# dcl l=0 o=0 [void] 
# dirdcl l=0 o=0 [void] 
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
# =========================================
# dirdcl l=0 o=0 [void] 
# dcl l=0 o=0 [void] 
# dirdcl l=0 o=0 [void] 
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
.globl _dirdcl
_dirdcl:
push ebp
mov ebp,esp
sub esp, offset locals_dirdcl
# =========================================
# type l=1 o=-4 [int] 
# dirdcl l=0 o=0 [void] 
# dcl l=0 o=0 [void] 
# dirdcl l=0 o=0 [void] 
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
mov al,'('
push eax
mov eax,_tokentype
pop ecx
movzx ecx,cl
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _else16
call _dcl
add esp,0
mov al,')'
push eax
mov eax,_tokentype
pop ecx
movzx ecx,cl
cmp eax,ecx
mov eax, 0
setne al
cmp eax, 0
je _end17
.data
_string18:
.asciz "error: missing )\n"
.text
mov eax, offset _string18
push eax
call _printf
add esp,4
_end17:
# ** End of block **
# =========================================
# type l=1 o=-4 [int] 
# dirdcl l=0 o=0 [void] 
# dcl l=0 o=0 [void] 
# dirdcl l=0 o=0 [void] 
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
jmp _end16
_else16:
mov eax,0
push eax
mov eax,_tokentype
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _else19
mov eax,offset _token
push eax
mov eax,offset _name
push eax
call _strcpy
add esp,8
jmp _end19
_else19:
.data
_string20:
.asciz "error: expected name of (dcl)\n"
.text
mov eax, offset _string20
push eax
call _printf
add esp,4
_end19:
_end16:
_cont21:
_start21:
mov eax,1
push eax
lea eax,[ebp-4] # type
push eax
call _gettoken
add esp,0
pop ecx
mov [ecx],eax
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _else22
mov eax, 1
jmp _end22
_else22:
mov eax,2
push eax
mov eax,[ebp-4] # type
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
mov eax, 0
setne al
_end22:
cmp eax, 0
je _end21
mov eax,1
push eax
mov eax,[ebp-4] # type
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _else23
.data
_string24:
.asciz " function returning"
.text
mov eax, offset _string24
push eax
mov eax,offset _out
push eax
call _strcat
add esp,8
jmp _end23
_else23:
.data
_string25:
.asciz " array"
.text
mov eax, offset _string25
push eax
mov eax,offset _out
push eax
call _strcat
add esp,8
mov eax,offset _token
push eax
mov eax,offset _out
push eax
call _strcat
add esp,8
.data
_string26:
.asciz " of"
.text
mov eax, offset _string26
push eax
mov eax,offset _out
push eax
call _strcat
add esp,8
# ** End of block **
# =========================================
# type l=1 o=-4 [int] 
# dirdcl l=0 o=0 [void] 
# dcl l=0 o=0 [void] 
# dirdcl l=0 o=0 [void] 
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
_end23:
# ** End of block **
# =========================================
# type l=1 o=-4 [int] 
# dirdcl l=0 o=0 [void] 
# dcl l=0 o=0 [void] 
# dirdcl l=0 o=0 [void] 
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
jmp _start21
_end21:
.set locals_dirdcl,4
# ** End of function **
# =========================================
# dirdcl l=0 o=0 [void] 
# dcl l=0 o=0 [void] 
# dirdcl l=0 o=0 [void] 
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
# =========================================
# main l=0 o=0 [int] 
# dirdcl l=0 o=0 [void] 
# dcl l=0 o=0 [void] 
# dirdcl l=0 o=0 [void] 
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp, offset locals_main
_cont27:
_start27:
mov eax,1
neg eax
push eax
call _gettoken
add esp,0
pop ecx
cmp eax,ecx
mov eax, 0
setne al
cmp eax, 0
je _end27
mov eax,offset _token
push eax
mov eax,offset _datatype
push eax
call _strcpy
add esp,8
mov eax,0
push eax
mov eax,offset _out
pop ecx
imul ecx,1
add eax,ecx
push eax
mov al,0
pop ecx
mov [ecx],al
call _dcl
add esp,0
mov al,'\n'
push eax
mov eax,_tokentype
pop ecx
movzx ecx,cl
cmp eax,ecx
mov eax, 0
setne al
cmp eax, 0
je _end28
_cont29:
_start29:
mov al,'\n'
push eax
call _getchar
add esp,0
pop ecx
movzx ecx,cl
cmp eax,ecx
mov eax, 0
setne al
cmp eax, 0
je _end29
jmp _start29
_end29:
_end28:
mov eax,offset _datatype
push eax
mov eax,offset _out
push eax
mov eax,offset _name
push eax
.data
_string30:
.asciz "%s: %s %s\n"
.text
mov eax, offset _string30
push eax
call _printf
add esp,16
# ** End of block **
# =========================================
# main l=0 o=0 [int] 
# dirdcl l=0 o=0 [void] 
# dcl l=0 o=0 [void] 
# dirdcl l=0 o=0 [void] 
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
jmp _start27
_end27:
mov eax,0
mov esp,ebp
pop ebp
ret
.set locals_main,0
# ** End of function **
# =========================================
# main l=0 o=0 [int] 
# dirdcl l=0 o=0 [void] 
# dcl l=0 o=0 [void] 
# dirdcl l=0 o=0 [void] 
# gettoken l=0 o=0 [int] 
# ungetch l=0 o=0 [void] 
# getch l=0 o=0 [int] 
# bufp l=0 o=0 [int] 
# buf l=0 o=0 [char[100]] 
# out l=0 o=0 [char[1000]] 
# datatype l=0 o=0 [char[100]] 
# name l=0 o=0 [char[100]] 
# token l=0 o=0 [char[100]] 
# tokentype l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# strcmp l=0 o=0 [int] 
# strcat l=0 o=0 [char*] 
# getchar l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
