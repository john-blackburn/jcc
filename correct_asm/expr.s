.intel_syntax noprefix
# =========================================
# bar l=1 o=8 [int] ARG
# foo l=0 o=0 [int] 
# =========================================
.globl _foo
_foo:
push ebp
mov ebp,esp
sub esp, offset locals_foo
mov eax,[ebp+8] # bar
push eax
mov eax,[ebp+8] # bar
pop ecx
imul eax,ecx
mov esp,ebp
pop ebp
ret
.set locals_foo,0
# ** End of function **
# =========================================
# foo l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
.data
_globalMass:
.skip 4
.text
# =========================================
# globalMass l=0 o=0 [int]  STATIC
# foo l=0 o=0 [int] 
# =========================================
.data
_charge:
.long 10
.text
# =========================================
# charge l=0 o=0 [int]  STATIC
# globalMass l=0 o=0 [int]  STATIC
# foo l=0 o=0 [int] 
# =========================================
# =========================================
# bar l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# newStr l=0 o=0 [char*] 
# strlen l=0 o=0 [int] 
# putchar l=0 o=0 [int] 
# charge l=0 o=0 [int]  STATIC
# globalMass l=0 o=0 [int]  STATIC
# foo l=0 o=0 [int] 
# =========================================
.globl _bar
_bar:
push ebp
mov ebp,esp
sub esp, offset locals_bar
mov eax,3
push eax
mov eax,_globalMass
push eax
mov eax,2
pop ecx
imul eax,ecx
pop ecx
add eax,ecx
mov [ebp-4],eax # declare ret (level 1)
# =========================================
# ret l=1 o=-4 [int] 
# bar l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# newStr l=0 o=0 [char*] 
# strlen l=0 o=0 [int] 
# putchar l=0 o=0 [int] 
# charge l=0 o=0 [int]  STATIC
# globalMass l=0 o=0 [int]  STATIC
# foo l=0 o=0 [int] 
# =========================================
mov eax,[ebp-4] # ret
mov esp,ebp
pop ebp
ret
.set locals_bar,4
# ** End of function **
# =========================================
# bar l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# newStr l=0 o=0 [char*] 
# strlen l=0 o=0 [int] 
# putchar l=0 o=0 [int] 
# charge l=0 o=0 [int]  STATIC
# globalMass l=0 o=0 [int]  STATIC
# foo l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
# =========================================
# main l=0 o=0 [int] 
# bar l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# newStr l=0 o=0 [char*] 
# strlen l=0 o=0 [int] 
# putchar l=0 o=0 [int] 
# charge l=0 o=0 [int]  STATIC
# globalMass l=0 o=0 [int]  STATIC
# foo l=0 o=0 [int] 
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp, offset locals_main
# =========================================
# i l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# bar l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# newStr l=0 o=0 [char*] 
# strlen l=0 o=0 [int] 
# putchar l=0 o=0 [int] 
# charge l=0 o=0 [int]  STATIC
# globalMass l=0 o=0 [int]  STATIC
# foo l=0 o=0 [int] 
# =========================================
mov al,'H'
movzx eax,al
push eax
call _putchar
add esp,4
mov al,'\n'
movzx eax,al
push eax
call _putchar
add esp,4
lea eax,[ebp-4] # i
push eax
mov eax,0
pop ecx
mov [ecx],eax
_start1:
mov eax,26
push eax
mov eax,[ebp-4] # i
pop ecx
cmp eax,ecx
mov eax, 0
setl al
cmp eax, 0
je _end1
mov eax,[ebp-4] # i
push eax
mov eax,65
pop ecx
add eax,ecx
push eax
call _putchar
add esp,4
_cont1:
lea eax,[ebp-4] # i
inc dword ptr [eax]
mov eax,[eax]
jmp _start1
_end1:
mov eax,10
push eax
call _foo
add esp,4
push eax
call _putchar
add esp,4
mov al,'\n'
movzx eax,al
push eax
call _putchar
add esp,4
.data
_a:
.long 10
.text
# =========================================
# a l=1 o=0 [int]  STATIC
# i l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# bar l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# newStr l=0 o=0 [char*] 
# strlen l=0 o=0 [int] 
# putchar l=0 o=0 [int] 
# charge l=0 o=0 [int]  STATIC
# globalMass l=0 o=0 [int]  STATIC
# foo l=0 o=0 [int] 
# =========================================
.data
_b:
.long 1
.text
# =========================================
# b l=1 o=0 [int]  STATIC
# a l=1 o=0 [int]  STATIC
# i l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# bar l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# newStr l=0 o=0 [char*] 
# strlen l=0 o=0 [int] 
# putchar l=0 o=0 [int] 
# charge l=0 o=0 [int]  STATIC
# globalMass l=0 o=0 [int]  STATIC
# foo l=0 o=0 [int] 
# =========================================
.data
_c:
.long 2
.text
# =========================================
# c l=1 o=0 [int]  STATIC
# b l=1 o=0 [int]  STATIC
# a l=1 o=0 [int]  STATIC
# i l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# bar l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# newStr l=0 o=0 [char*] 
# strlen l=0 o=0 [int] 
# putchar l=0 o=0 [int] 
# charge l=0 o=0 [int]  STATIC
# globalMass l=0 o=0 [int]  STATIC
# foo l=0 o=0 [int] 
# =========================================
mov eax,offset _globalMass
push eax
mov eax,4
pop ecx
mov [ecx],eax
mov eax,_globalMass
push eax
.data
_string2:
.asciz "globalMass=%d\n"
.text
mov eax, offset _string2
push eax
call _printf
add esp,8
.data
_string3:
.asciz "dir *.c"
.text
mov eax, offset _string3
mov [ebp-8],eax # declare cmd (level 1)
# =========================================
# cmd l=1 o=-8 [char*] 
# c l=1 o=0 [int]  STATIC
# b l=1 o=0 [int]  STATIC
# a l=1 o=0 [int]  STATIC
# i l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# bar l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# newStr l=0 o=0 [char*] 
# strlen l=0 o=0 [int] 
# putchar l=0 o=0 [int] 
# charge l=0 o=0 [int]  STATIC
# globalMass l=0 o=0 [int]  STATIC
# foo l=0 o=0 [int] 
# =========================================
mov eax,[ebp-8] # cmd
push eax
call _strlen
add esp,4
push eax
mov eax,[ebp-8] # cmd
push eax
mov eax,[ebp-8] # cmd
push eax
.data
_string4:
.asciz "cmd=%s %p %d\n"
.text
mov eax, offset _string4
push eax
call _printf
add esp,16
mov eax,_c
push eax
mov eax,_a
push eax
mov eax,4
pop ecx
imul eax,ecx
pop ecx
imul eax,ecx
push eax
mov eax,_b
push eax
mov eax,_b
pop ecx
imul eax,ecx
pop ecx
sub eax,ecx
mov [ebp-12],eax # declare disc (level 1)
# =========================================
# disc l=1 o=-12 [int] 
# cmd l=1 o=-8 [char*] 
# c l=1 o=0 [int]  STATIC
# b l=1 o=0 [int]  STATIC
# a l=1 o=0 [int]  STATIC
# i l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# bar l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# newStr l=0 o=0 [char*] 
# strlen l=0 o=0 [int] 
# putchar l=0 o=0 [int] 
# charge l=0 o=0 [int]  STATIC
# globalMass l=0 o=0 [int]  STATIC
# foo l=0 o=0 [int] 
# =========================================
mov eax,0
push eax
mov eax,[ebp-12] # disc
pop ecx
cmp eax,ecx
mov eax, 0
setg al
cmp eax, 0
je _else5
call _bar
add esp,0
push eax
mov eax,[ebp-12] # disc
push eax
.data
_string6:
.asciz "+ve disc=%d %d\n"
.text
mov eax, offset _string6
push eax
call _printf
add esp,12
mov eax,[ebp-12] # disc
mov esp,ebp
pop ebp
ret
# ** End of block **
# =========================================
# disc l=1 o=-12 [int] 
# cmd l=1 o=-8 [char*] 
# c l=1 o=0 [int]  STATIC
# b l=1 o=0 [int]  STATIC
# a l=1 o=0 [int]  STATIC
# i l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# bar l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# newStr l=0 o=0 [char*] 
# strlen l=0 o=0 [int] 
# putchar l=0 o=0 [int] 
# charge l=0 o=0 [int]  STATIC
# globalMass l=0 o=0 [int]  STATIC
# foo l=0 o=0 [int] 
# =========================================
jmp _end5
_else5:
mov eax,2
push eax
mov eax,[ebp-12] # disc
pop ecx
imul eax,ecx
mov [ebp-16],eax # declare ret (level 2)
# =========================================
# ret l=2 o=-16 [int] 
# disc l=1 o=-12 [int] 
# cmd l=1 o=-8 [char*] 
# c l=1 o=0 [int]  STATIC
# b l=1 o=0 [int]  STATIC
# a l=1 o=0 [int]  STATIC
# i l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# bar l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# newStr l=0 o=0 [char*] 
# strlen l=0 o=0 [int] 
# putchar l=0 o=0 [int] 
# charge l=0 o=0 [int]  STATIC
# globalMass l=0 o=0 [int]  STATIC
# foo l=0 o=0 [int] 
# =========================================
call _bar
add esp,0
push eax
mov eax,[ebp-16] # ret
push eax
.data
_string7:
.asciz "-ve disc=%d %d\n"
.text
mov eax, offset _string7
push eax
call _printf
add esp,12
mov eax,[ebp-16] # ret
mov esp,ebp
pop ebp
ret
# ** End of block **
# =========================================
# disc l=1 o=-12 [int] 
# cmd l=1 o=-8 [char*] 
# c l=1 o=0 [int]  STATIC
# b l=1 o=0 [int]  STATIC
# a l=1 o=0 [int]  STATIC
# i l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# bar l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# newStr l=0 o=0 [char*] 
# strlen l=0 o=0 [int] 
# putchar l=0 o=0 [int] 
# charge l=0 o=0 [int]  STATIC
# globalMass l=0 o=0 [int]  STATIC
# foo l=0 o=0 [int] 
# =========================================
_end5:
.set locals_main,16
# ** End of function **
# =========================================
# main l=0 o=0 [int] 
# bar l=0 o=0 [int] 
# printf l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# newStr l=0 o=0 [char*] 
# strlen l=0 o=0 [int] 
# putchar l=0 o=0 [int] 
# charge l=0 o=0 [int]  STATIC
# globalMass l=0 o=0 [int]  STATIC
# foo l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
