.intel_syntax noprefix
# ======================
# main 0 0 [int] 0
# ======================
.globl _main
_main:
push ebp
mov ebp,esp
.data
_string1:
.asciz "Start\n"
.text
mov eax, offset _string1
push eax
call _printf
add esp,4
.data
_string2:
.asciz "Hello, world\n"
.text
mov eax, offset _string2
push eax # declare p (level 1)
# ======================
# p 1 -4 [char*] 0
# main 0 0 [int] 0
# ======================
mov eax,[ebp-4] # p
push eax
call _printf
add esp,4
sub esp,8 # declare array (level 1)
# ======================
# array 1 -12 [char[6]] 0
# p 1 -4 [char*] 0
# main 0 0 [int] 0
# ======================
mov eax,0
push eax
lea eax,[ebp-12] # array
pop ecx
imul ecx,1
add eax,ecx
push eax
mov al,'H'
pop ecx
mov [ecx],al
mov eax,1
push eax
lea eax,[ebp-12] # array
pop ecx
imul ecx,1
add eax,ecx
push eax
mov al,'e'
pop ecx
mov [ecx],al
mov eax,2
push eax
lea eax,[ebp-12] # array
pop ecx
imul ecx,1
add eax,ecx
push eax
mov al,0
pop ecx
mov [ecx],al
lea eax,[ebp-12] # array
push eax
.data
_string3:
.asciz "%s\n"
.text
mov eax, offset _string3
push eax
call _printf
add esp,8
.data
_string4:
.asciz "Hello"
.text
mov eax, offset _string4
push eax
lea eax,[ebp-12] # array
push eax
call _strcpy
add esp,8
mov eax,0
push eax
lea eax,[ebp-12] # array
pop ecx
imul ecx,1
add eax,ecx
push eax
mov al,'J'
pop ecx
mov [ecx],al
mov eax,[ebp-4] # p
push eax
lea eax,[ebp-12] # array
push eax
.data
_string5:
.asciz "%s: %s\n"
.text
mov eax, offset _string5
push eax
call _printf
add esp,12
mov eax,108
push eax
.data
_string6:
.asciz "%c\n"
.text
mov eax, offset _string6
push eax
call _printf
add esp,8
mov eax,2
push eax
lea eax,[ebp-12] # array
pop ecx
imul ecx,1
add eax,ecx
mov al,[eax]
movzx eax,al
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
