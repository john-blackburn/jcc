.intel_syntax noprefix
# ======================
# b 1 8 [int[][2]] 1
# transpose 0 0 [int] 0
# printf 0 0 [int] 0
# ======================
.globl _transpose
_transpose:
push ebp
mov ebp,esp
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
push eax # declare temp (level 1)
# ======================
# temp 1 -4 [int] 0
# b 1 8 [int[][2]] 1
# transpose 0 0 [int] 0
# printf 0 0 [int] 0
# ======================
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
# ** End of function **
# ======================
# transpose 0 0 [int] 0
# printf 0 0 [int] 0
# ======================
mov esp,ebp
pop ebp
ret
# ======================
# main 0 0 [int] 0
# transpose 0 0 [int] 0
# printf 0 0 [int] 0
# ======================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp,16 # declare a (level 1)
# ======================
# a 1 -16 [int[2][2]] 0
# main 0 0 [int] 0
# transpose 0 0 [int] 0
# printf 0 0 [int] 0
# ======================
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
# ** End of function **
# ======================
# main 0 0 [int] 0
# transpose 0 0 [int] 0
# printf 0 0 [int] 0
# ======================
mov esp,ebp
pop ebp
ret
