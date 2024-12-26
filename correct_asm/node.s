.intel_syntax noprefix
.data
.globl _numToks
_numToks:
.long 56
.text
# ======================
# numToks 0 0 [int] 0
# strcpy 0 0 [char*] 0
# malloc 0 0 [void*] 0
# ======================
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
# ======================
# names 0 0 [char*[]] 0
# numToks 0 0 [int] 0
# strcpy 0 0 [char*] 0
# malloc 0 0 [void*] 0
# ======================
# ======================
# struct Type 0 0 [] 0
# names 0 0 [char*[]] 0
# numToks 0 0 [int] 0
# strcpy 0 0 [char*] 0
# malloc 0 0 [void*] 0
# ======================
# ======================
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# names 0 0 [char*[]] 0
# numToks 0 0 [int] 0
# strcpy 0 0 [char*] 0
# malloc 0 0 [void*] 0
# ======================
# ======================
# main 0 0 [int] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# names 0 0 [char*[]] 0
# numToks 0 0 [int] 0
# strcpy 0 0 [char*] 0
# malloc 0 0 [void*] 0
# ======================
.globl _main
_main:
push ebp
mov ebp,esp
mov eax,64
push eax
call _malloc
add esp,4
push eax # declare node (level 1)
# ======================
# node 1 -4 [struct Node*] 0
# main 0 0 [int] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# names 0 0 [char*[]] 0
# numToks 0 0 [int] 0
# strcpy 0 0 [char*] 0
# malloc 0 0 [void*] 0
# ======================
lea eax,[ebp-4] # node
mov eax,[eax]
mov ecx,0
add eax,ecx
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
lea eax,[ebp-4] # node
mov eax,[eax]
mov ecx,8
add eax,ecx
mov ecx,0
add eax,ecx
push eax
call _strcpy
add esp,8
lea eax,[ebp-4] # node
mov eax,[eax]
mov ecx,8
add eax,ecx
mov ecx,0
add eax,ecx
push eax
lea eax,[ebp-4] # node
mov eax,[eax]
mov ecx,0
add eax,ecx
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
sub esp,12 # declare array (level 1)
# ======================
# array 1 -16 [int[3]] 0
# node 1 -4 [struct Node*] 0
# main 0 0 [int] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# names 0 0 [char*[]] 0
# numToks 0 0 [int] 0
# strcpy 0 0 [char*] 0
# malloc 0 0 [void*] 0
# ======================
mov eax,0
push eax
lea eax,[ebp-16] # array
pop ecx
imul ecx,4
add eax,ecx
push eax # declare p (level 1)
# ======================
# p 1 -20 [int*] 0
# array 1 -16 [int[3]] 0
# node 1 -4 [struct Node*] 0
# main 0 0 [int] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# names 0 0 [char*[]] 0
# numToks 0 0 [int] 0
# strcpy 0 0 [char*] 0
# malloc 0 0 [void*] 0
# ======================
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
push eax # declare i (level 1)
# ======================
# i 1 -24 [int] 0
# p 1 -20 [int*] 0
# array 1 -16 [int[3]] 0
# node 1 -4 [struct Node*] 0
# main 0 0 [int] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# names 0 0 [char*[]] 0
# numToks 0 0 [int] 0
# strcpy 0 0 [char*] 0
# malloc 0 0 [void*] 0
# ======================
mov eax,30
push eax # declare j (level 1)
# ======================
# j 1 -28 [int] 0
# i 1 -24 [int] 0
# p 1 -20 [int*] 0
# array 1 -16 [int[3]] 0
# node 1 -4 [struct Node*] 0
# main 0 0 [int] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# names 0 0 [char*[]] 0
# numToks 0 0 [int] 0
# strcpy 0 0 [char*] 0
# malloc 0 0 [void*] 0
# ======================
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
# ** End of function **
# ======================
# main 0 0 [int] 0
# struct Node 0 0 [] 0
# struct Type 0 0 [] 0
# names 0 0 [char*[]] 0
# numToks 0 0 [int] 0
# strcpy 0 0 [char*] 0
# malloc 0 0 [void*] 0
# ======================
mov esp,ebp
pop ebp
ret
