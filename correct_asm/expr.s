.intel_syntax noprefix
# ======================
# bar 1 8 [int] 1
# foo 0 0 [int] 0
# ======================
.globl _foo
_foo:
push ebp
mov ebp,esp
mov eax,[ebp+8] # bar
push eax
mov eax,[ebp+8] # bar
pop ecx
imul eax,ecx
mov esp,ebp
pop ebp
ret
# ** End of function **
# ======================
# foo 0 0 [int] 0
# ======================
mov esp,ebp
pop ebp
ret
.data
.globl _globalMass
_globalMass:
.long 0
.text
# ======================
# globalMass 0 0 [int] 0
# foo 0 0 [int] 0
# ======================
.data
.globl _charge
_charge:
.long 10
.text
# ======================
# charge 0 0 [int] 0
# globalMass 0 0 [int] 0
# foo 0 0 [int] 0
# ======================
# ======================
# bar 0 0 [int] 0
# malloc 0 0 [void*] 0
# newStr 0 0 [char*] 0
# strlen 0 0 [int] 0
# putchar 0 0 [int] 0
# charge 0 0 [int] 0
# globalMass 0 0 [int] 0
# foo 0 0 [int] 0
# ======================
.globl _bar
_bar:
push ebp
mov ebp,esp
mov eax,3
push eax
mov eax,_globalMass
push eax
mov eax,2
pop ecx
imul eax,ecx
pop ecx
add eax,ecx
push eax # declare ret (level 1)
# ======================
# ret 1 -4 [int] 0
# bar 0 0 [int] 0
# malloc 0 0 [void*] 0
# newStr 0 0 [char*] 0
# strlen 0 0 [int] 0
# putchar 0 0 [int] 0
# charge 0 0 [int] 0
# globalMass 0 0 [int] 0
# foo 0 0 [int] 0
# ======================
mov eax,[ebp-4] # ret
mov esp,ebp
pop ebp
ret
# ** End of function **
# ======================
# bar 0 0 [int] 0
# malloc 0 0 [void*] 0
# newStr 0 0 [char*] 0
# strlen 0 0 [int] 0
# putchar 0 0 [int] 0
# charge 0 0 [int] 0
# globalMass 0 0 [int] 0
# foo 0 0 [int] 0
# ======================
mov esp,ebp
pop ebp
ret
# ======================
# main 0 0 [int] 0
# bar 0 0 [int] 0
# malloc 0 0 [void*] 0
# newStr 0 0 [char*] 0
# strlen 0 0 [int] 0
# putchar 0 0 [int] 0
# charge 0 0 [int] 0
# globalMass 0 0 [int] 0
# foo 0 0 [int] 0
# ======================
.globl _main
_main:
push ebp
mov ebp,esp
push eax # declare i (level 1)
# ======================
# i 1 -4 [int] 0
# main 0 0 [int] 0
# bar 0 0 [int] 0
# malloc 0 0 [void*] 0
# newStr 0 0 [char*] 0
# strlen 0 0 [int] 0
# putchar 0 0 [int] 0
# charge 0 0 [int] 0
# globalMass 0 0 [int] 0
# foo 0 0 [int] 0
# ======================
mov al,'H'
push eax
call _putchar
add esp,4
mov al,'\n'
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
push eax
call _putchar
add esp,4
mov eax,10
push eax # declare a (level 1)
# ======================
# a 1 -8 [int] 0
# i 1 -4 [int] 0
# main 0 0 [int] 0
# bar 0 0 [int] 0
# malloc 0 0 [void*] 0
# newStr 0 0 [char*] 0
# strlen 0 0 [int] 0
# putchar 0 0 [int] 0
# charge 0 0 [int] 0
# globalMass 0 0 [int] 0
# foo 0 0 [int] 0
# ======================
mov eax,1
push eax # declare b (level 1)
# ======================
# b 1 -12 [int] 0
# a 1 -8 [int] 0
# i 1 -4 [int] 0
# main 0 0 [int] 0
# bar 0 0 [int] 0
# malloc 0 0 [void*] 0
# newStr 0 0 [char*] 0
# strlen 0 0 [int] 0
# putchar 0 0 [int] 0
# charge 0 0 [int] 0
# globalMass 0 0 [int] 0
# foo 0 0 [int] 0
# ======================
mov eax,2
push eax # declare c (level 1)
# ======================
# c 1 -16 [int] 0
# b 1 -12 [int] 0
# a 1 -8 [int] 0
# i 1 -4 [int] 0
# main 0 0 [int] 0
# bar 0 0 [int] 0
# malloc 0 0 [void*] 0
# newStr 0 0 [char*] 0
# strlen 0 0 [int] 0
# putchar 0 0 [int] 0
# charge 0 0 [int] 0
# globalMass 0 0 [int] 0
# foo 0 0 [int] 0
# ======================
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
push eax # declare cmd (level 1)
# ======================
# cmd 1 -20 [char*] 0
# c 1 -16 [int] 0
# b 1 -12 [int] 0
# a 1 -8 [int] 0
# i 1 -4 [int] 0
# main 0 0 [int] 0
# bar 0 0 [int] 0
# malloc 0 0 [void*] 0
# newStr 0 0 [char*] 0
# strlen 0 0 [int] 0
# putchar 0 0 [int] 0
# charge 0 0 [int] 0
# globalMass 0 0 [int] 0
# foo 0 0 [int] 0
# ======================
mov eax,[ebp-20] # cmd
push eax
call _strlen
add esp,4
push eax
mov eax,[ebp-20] # cmd
push eax
mov eax,[ebp-20] # cmd
push eax
.data
_string4:
.asciz "cmd=%s %p %d\n"
.text
mov eax, offset _string4
push eax
call _printf
add esp,16
mov eax,[ebp-16] # c
push eax
mov eax,[ebp-8] # a
push eax
mov eax,4
pop ecx
imul eax,ecx
pop ecx
imul eax,ecx
push eax
mov eax,[ebp-12] # b
push eax
mov eax,[ebp-12] # b
pop ecx
imul eax,ecx
pop ecx
sub eax,ecx
push eax # declare disc (level 1)
# ======================
# disc 1 -24 [int] 0
# cmd 1 -20 [char*] 0
# c 1 -16 [int] 0
# b 1 -12 [int] 0
# a 1 -8 [int] 0
# i 1 -4 [int] 0
# main 0 0 [int] 0
# bar 0 0 [int] 0
# malloc 0 0 [void*] 0
# newStr 0 0 [char*] 0
# strlen 0 0 [int] 0
# putchar 0 0 [int] 0
# charge 0 0 [int] 0
# globalMass 0 0 [int] 0
# foo 0 0 [int] 0
# ======================
mov eax,0
push eax
mov eax,[ebp-24] # disc
pop ecx
cmp eax,ecx
mov eax, 0
setg al
cmp eax, 0
je _else5
call _bar
add esp,0
push eax
mov eax,[ebp-24] # disc
push eax
.data
_string6:
.asciz "+ve disc=%d %d\n"
.text
mov eax, offset _string6
push eax
call _printf
add esp,12
mov eax,[ebp-24] # disc
mov esp,ebp
pop ebp
ret
add esp,0
# ** End of block **
# ======================
# disc 1 -24 [int] 0
# cmd 1 -20 [char*] 0
# c 1 -16 [int] 0
# b 1 -12 [int] 0
# a 1 -8 [int] 0
# i 1 -4 [int] 0
# main 0 0 [int] 0
# bar 0 0 [int] 0
# malloc 0 0 [void*] 0
# newStr 0 0 [char*] 0
# strlen 0 0 [int] 0
# putchar 0 0 [int] 0
# charge 0 0 [int] 0
# globalMass 0 0 [int] 0
# foo 0 0 [int] 0
# ======================
jmp _end5
_else5:
mov eax,2
push eax
mov eax,[ebp-24] # disc
pop ecx
imul eax,ecx
push eax # declare ret (level 2)
# ======================
# ret 2 -28 [int] 0
# disc 1 -24 [int] 0
# cmd 1 -20 [char*] 0
# c 1 -16 [int] 0
# b 1 -12 [int] 0
# a 1 -8 [int] 0
# i 1 -4 [int] 0
# main 0 0 [int] 0
# bar 0 0 [int] 0
# malloc 0 0 [void*] 0
# newStr 0 0 [char*] 0
# strlen 0 0 [int] 0
# putchar 0 0 [int] 0
# charge 0 0 [int] 0
# globalMass 0 0 [int] 0
# foo 0 0 [int] 0
# ======================
mov eax,[ebp-28] # ret
push eax
.data
_string7:
.asciz "-ve disc=%d\n"
.text
mov eax, offset _string7
push eax
call _printf
add esp,8
mov eax,[ebp-28] # ret
mov esp,ebp
pop ebp
ret
add esp,4
# ** End of block **
# ======================
# disc 1 -24 [int] 0
# cmd 1 -20 [char*] 0
# c 1 -16 [int] 0
# b 1 -12 [int] 0
# a 1 -8 [int] 0
# i 1 -4 [int] 0
# main 0 0 [int] 0
# bar 0 0 [int] 0
# malloc 0 0 [void*] 0
# newStr 0 0 [char*] 0
# strlen 0 0 [int] 0
# putchar 0 0 [int] 0
# charge 0 0 [int] 0
# globalMass 0 0 [int] 0
# foo 0 0 [int] 0
# ======================
_end5:
# ** End of function **
# ======================
# main 0 0 [int] 0
# bar 0 0 [int] 0
# malloc 0 0 [void*] 0
# newStr 0 0 [char*] 0
# strlen 0 0 [int] 0
# putchar 0 0 [int] 0
# charge 0 0 [int] 0
# globalMass 0 0 [int] 0
# foo 0 0 [int] 0
# ======================
mov esp,ebp
pop ebp
ret
