.intel_syntax noprefix
.data
.globl _numToks
_numToks:
.long 56
.text
# =========================================
# numToks l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# malloc l=0 o=0 [void*] 
# =========================================
.data
names_string0:
.asciz "foo"
names_string1:
.asciz "bar"
.globl _names
_names:
.long names_string0
.long names_string1
.text
# =========================================
# names l=0 o=0 [char*[]] 
# numToks l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# malloc l=0 o=0 [void*] 
# =========================================
# =========================================
# struct Type l=0 o=0 [] 
# names l=0 o=0 [char*[]] 
# numToks l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# malloc l=0 o=0 [void*] 
# =========================================
# =========================================
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# names l=0 o=0 [char*[]] 
# numToks l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# malloc l=0 o=0 [void*] 
# =========================================
# =========================================
# main l=0 o=0 [int] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# names l=0 o=0 [char*[]] 
# numToks l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# malloc l=0 o=0 [void*] 
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp, offset locals_main
mov eax,64
push eax
call _malloc
add esp,4
mov [ebp-4],eax # declare node (level 1)
# =========================================
# node l=1 o=-4 [struct Node*] 
# main l=0 o=0 [int] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# names l=0 o=0 [char*[]] 
# numToks l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# malloc l=0 o=0 [void*] 
# =========================================
mov eax,[ebp-4] # node
mov ecx,0
add eax,ecx # .type
push eax
mov eax,10
pop ecx
mov [ecx],eax
.data
_string1:
.asciz "int**[3]"
.text
mov eax, offset _string1
push eax
mov eax,[ebp-4] # node
mov ecx,8
add eax,ecx # .varType
mov ecx,0
add eax,ecx # .data
push eax
call _strcpy
add esp,8
mov eax,[ebp-4] # node
mov ecx,8
add eax,ecx # .varType
mov ecx,0
add eax,ecx # .data
push eax
mov eax,[ebp-4] # node
mov ecx,0
add eax,ecx # .type
mov eax,[eax]
push eax
.data
_string2:
.asciz "%d %s\n"
.text
mov eax, offset _string2
push eax
call _printf
add esp,12
# =========================================
# array l=1 o=-16 [int[3]] 
# node l=1 o=-4 [struct Node*] 
# main l=0 o=0 [int] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# names l=0 o=0 [char*[]] 
# numToks l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# malloc l=0 o=0 [void*] 
# =========================================
mov eax,0
push eax
lea eax,[ebp-16] # array
pop ecx
imul ecx,4
add eax,ecx
mov [ebp-20],eax # declare p (level 1)
# =========================================
# p l=1 o=-20 [int*] 
# array l=1 o=-16 [int[3]] 
# node l=1 o=-4 [struct Node*] 
# main l=0 o=0 [int] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# names l=0 o=0 [char*[]] 
# numToks l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# malloc l=0 o=0 [void*] 
# =========================================
mov eax,2
push eax
lea eax,[ebp-20] # p
mov eax,[eax]
pop ecx
imul ecx,4
add eax,ecx
push eax
mov eax,1
pop ecx
mov [ecx],eax
mov eax,2
push eax
lea eax,[ebp-20] # p
mov eax,[eax]
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
push eax
mov eax,1
pop ecx
add eax,ecx
push eax
.data
_string3:
.asciz "1+p[2]=%d\n"
.text
mov eax, offset _string3
push eax
call _printf
add esp,8
mov eax,1
push eax
mov eax,1
push eax
mov eax,offset _names
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
pop ecx
imul ecx,1
add eax,ecx
push eax
mov al,'A'
pop ecx
mov [ecx],al
mov eax,0
push eax
mov eax,1
push eax
mov eax,offset _names
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
pop ecx
imul ecx,1
add eax,ecx
push eax
mov al,'B'
pop ecx
mov [ecx],al
mov eax,1
push eax
mov eax,offset _names
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
push eax
mov eax,0
push eax
mov eax,offset _names
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
push eax
.data
_string4:
.asciz "names=%s, %s\n"
.text
mov eax, offset _string4
push eax
call _printf
add esp,12
mov eax,20
mov [ebp-24],eax # declare i (level 1)
# =========================================
# i l=1 o=-24 [int] 
# p l=1 o=-20 [int*] 
# array l=1 o=-16 [int[3]] 
# node l=1 o=-4 [struct Node*] 
# main l=0 o=0 [int] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# names l=0 o=0 [char*[]] 
# numToks l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# malloc l=0 o=0 [void*] 
# =========================================
mov eax,30
mov [ebp-28],eax # declare j (level 1)
# =========================================
# j l=1 o=-28 [int] 
# i l=1 o=-24 [int] 
# p l=1 o=-20 [int*] 
# array l=1 o=-16 [int[3]] 
# node l=1 o=-4 [struct Node*] 
# main l=0 o=0 [int] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# names l=0 o=0 [char*[]] 
# numToks l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# malloc l=0 o=0 [void*] 
# =========================================
lea eax,[ebp-28] # j
push eax
lea eax,[ebp-24] # i
mov ecx,[eax]
inc dword ptr [eax]
mov eax,ecx
push eax
mov eax,[ebp-28] # j
pop ecx
imul eax,ecx
pop ecx
mov [ecx],eax
lea eax,[ebp-24] # i
push eax
lea eax,[ebp-28] # j
inc dword ptr [eax]
mov eax,[eax]
pop ecx
mov [ecx],eax
mov eax,[ebp-28] # j
push eax
mov eax,[ebp-24] # i
pop ecx
add eax,ecx
mov esp,ebp
pop ebp
ret
.set locals_main,28
# ** End of function **
# =========================================
# main l=0 o=0 [int] 
# struct Node l=0 o=0 [] 
# struct Type l=0 o=0 [] 
# names l=0 o=0 [char*[]] 
# numToks l=0 o=0 [int] 
# strcpy l=0 o=0 [char*] 
# malloc l=0 o=0 [void*] 
# =========================================
mov esp,ebp
pop ebp
ret
