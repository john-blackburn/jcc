.intel_syntax noprefix
# =========================================
# b l=1 o=8 [int[][2]] ARG
# transpose l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# =========================================
.globl _transpose
_transpose:
push ebp
mov ebp,esp
sub esp, offset locals_transpose
mov eax,1
push eax
mov eax,0
push eax
mov eax,[ebp+8] # b
pop ecx
imul ecx,8
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
mov [ebp-4],eax # declare temp (level 1)
# =========================================
# temp l=1 o=-4 [int] 
# b l=1 o=8 [int[][2]] ARG
# transpose l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# =========================================
mov eax,1
push eax
mov eax,0
push eax
mov eax,[ebp+8] # b
pop ecx
imul ecx,8
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
push eax
mov eax,0
push eax
mov eax,1
push eax
mov eax,[ebp+8] # b
pop ecx
imul ecx,8
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
pop ecx
mov [ecx],eax
mov eax,0
push eax
mov eax,1
push eax
mov eax,[ebp+8] # b
pop ecx
imul ecx,8
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
push eax
mov eax,[ebp-4] # temp
pop ecx
mov [ecx],eax
mov eax,0
mov esp,ebp
pop ebp
ret
.set locals_transpose,4
# ** End of function **
# =========================================
# transpose l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
# =========================================
# main l=0 o=0 [int] 
# transpose l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp, offset locals_main
# =========================================
# a l=1 o=-16 [int[2][2]] 
# main l=0 o=0 [int] 
# transpose l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# =========================================
mov eax,0
push eax
mov eax,0
push eax
lea eax,[ebp-16] # a
pop ecx
imul ecx,8
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
push eax
mov eax,1
pop ecx
mov [ecx],eax
mov eax,1
push eax
mov eax,0
push eax
lea eax,[ebp-16] # a
pop ecx
imul ecx,8
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
push eax
mov eax,2
pop ecx
mov [ecx],eax
mov eax,0
push eax
mov eax,1
push eax
lea eax,[ebp-16] # a
pop ecx
imul ecx,8
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
push eax
mov eax,1
push eax
mov eax,0
push eax
lea eax,[ebp-16] # a
pop ecx
imul ecx,8
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
push eax
mov eax,3
pop ecx
imul eax,ecx
pop ecx
mov [ecx],eax
mov eax,1
push eax
mov eax,1
push eax
lea eax,[ebp-16] # a
pop ecx
imul ecx,8
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
push eax
mov eax,0
push eax
mov eax,1
push eax
lea eax,[ebp-16] # a
pop ecx
imul ecx,8
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
push eax
mov eax,4
pop ecx
imul eax,ecx
pop ecx
mov [ecx],eax
mov eax,1
push eax
mov eax,0
push eax
lea eax,[ebp-16] # a
pop ecx
imul ecx,8
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
push eax
mov eax,0
push eax
mov eax,0
push eax
lea eax,[ebp-16] # a
pop ecx
imul ecx,8
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
push eax
.data
_string1:
.asciz "%d %d\n"
.text
mov eax, offset _string1
push eax
call _printf
add esp,12
mov eax,1
push eax
mov eax,1
push eax
lea eax,[ebp-16] # a
pop ecx
imul ecx,8
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
push eax
mov eax,0
push eax
mov eax,1
push eax
lea eax,[ebp-16] # a
pop ecx
imul ecx,8
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
push eax
.data
_string2:
.asciz "%d %d\n\n"
.text
mov eax, offset _string2
push eax
call _printf
add esp,12
lea eax,[ebp-16] # a
push eax
call _transpose
add esp,4
mov eax,1
push eax
mov eax,0
push eax
lea eax,[ebp-16] # a
pop ecx
imul ecx,8
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
push eax
mov eax,0
push eax
mov eax,0
push eax
lea eax,[ebp-16] # a
pop ecx
imul ecx,8
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
push eax
.data
_string3:
.asciz "%d %d\n"
.text
mov eax, offset _string3
push eax
call _printf
add esp,12
mov eax,1
push eax
mov eax,1
push eax
lea eax,[ebp-16] # a
pop ecx
imul ecx,8
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
push eax
mov eax,0
push eax
mov eax,1
push eax
lea eax,[ebp-16] # a
pop ecx
imul ecx,8
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
push eax
.data
_string4:
.asciz "%d %d\n"
.text
mov eax, offset _string4
push eax
call _printf
add esp,12
mov eax,0
mov esp,ebp
pop ebp
ret
.set locals_main,16
# ** End of function **
# =========================================
# main l=0 o=0 [int] 
# transpose l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
