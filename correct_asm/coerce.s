.intel_syntax noprefix
# =========================================
# main l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# isspace l=0 o=0 [int] 
# isdigit l=0 o=0 [int] 
# isalpha l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# isspace l=0 o=0 [int] 
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp, offset locals_main
mov al,'A'
movzx eax,al
mov [ebp-4],eax # declare c (level 1)
# =========================================
# c l=1 o=-4 [char] 
# main l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# isspace l=0 o=0 [int] 
# isdigit l=0 o=0 [int] 
# isalpha l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# isspace l=0 o=0 [int] 
# =========================================
mov al,[ebp-4] # c
movzx eax,al
push eax
call _isalnum
add esp,4
push eax
mov al,[ebp-4] # c
movzx eax,al
push eax
call _isalpha
add esp,4
push eax
mov al,[ebp-4] # c
movzx eax,al
push eax
call _isdigit
add esp,4
push eax
mov al,[ebp-4] # c
movzx eax,al
push eax
call _isspace
add esp,4
push eax
.data
_string1:
.asciz "%d %d %d %d\n"
.text
mov eax, offset _string1
push eax
call _printf
add esp,20
mov eax,0
mov esp,ebp
pop ebp
ret
.set locals_main,4
# ** End of function **
# =========================================
# main l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# isspace l=0 o=0 [int] 
# isdigit l=0 o=0 [int] 
# isalpha l=0 o=0 [int] 
# isalnum l=0 o=0 [int] 
# isspace l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
