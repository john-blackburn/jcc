.intel_syntax noprefix
# =========================================
# struct Point l=0 o=0 [] 
# =========================================
.data
.globl _gp
_gp:
.skip 8
.text
# =========================================
# gp l=0 o=0 [struct Point] 
# struct Point l=0 o=0 [] 
# =========================================
# =========================================
# s l=1 o=12 [int] ARG
# p l=1 o=8 [struct Point*] ARG
# test l=0 o=0 [int] 
# gp l=0 o=0 [struct Point] 
# struct Point l=0 o=0 [] 
# =========================================
.globl _test
_test:
push ebp
mov ebp,esp
sub esp, offset locals_test
mov eax,[ebp+8] # p
mov ecx,0
add eax,ecx # .x
mov eax,[eax]
push eax
mov eax,[ebp+12] # s
pop ecx
imul eax,ecx
mov esp,ebp
pop ebp
ret
.set locals_test,0
# ** End of function **
# =========================================
# test l=0 o=0 [int] 
# gp l=0 o=0 [struct Point] 
# struct Point l=0 o=0 [] 
# =========================================
mov esp,ebp
pop ebp
ret
# =========================================
# main l=0 o=0 [int] 
# test l=0 o=0 [int] 
# gp l=0 o=0 [struct Point] 
# struct Point l=0 o=0 [] 
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp, offset locals_main
mov eax,8
push eax
.data
_string1:
.asciz "sizeof Point=%d\n"
.text
mov eax, offset _string1
push eax
call _printf
add esp,8
# =========================================
# p l=1 o=-24 [struct Point[3]] 
# main l=0 o=0 [int] 
# test l=0 o=0 [int] 
# gp l=0 o=0 [struct Point] 
# struct Point l=0 o=0 [] 
# =========================================
# =========================================
# pp l=1 o=-28 [struct Point*] 
# p l=1 o=-24 [struct Point[3]] 
# main l=0 o=0 [int] 
# test l=0 o=0 [int] 
# gp l=0 o=0 [struct Point] 
# struct Point l=0 o=0 [] 
# =========================================
# =========================================
# q l=1 o=-36 [struct Point] 
# pp l=1 o=-28 [struct Point*] 
# p l=1 o=-24 [struct Point[3]] 
# main l=0 o=0 [int] 
# test l=0 o=0 [int] 
# gp l=0 o=0 [struct Point] 
# struct Point l=0 o=0 [] 
# =========================================
lea eax,[ebp-36] # q
mov ecx,0
add eax,ecx # .x
push eax
mov eax,10
pop ecx
mov [ecx],eax
lea eax,[ebp-36] # q
mov ecx,4
add eax,ecx # .y
push eax
mov eax,20
pop ecx
mov [ecx],eax
mov eax,0
push eax
lea eax,[ebp-24] # p
pop ecx
imul ecx,8
add eax,ecx
mov ecx,0
add eax,ecx # .x
push eax
mov eax,1
pop ecx
mov [ecx],eax
mov eax,0
push eax
lea eax,[ebp-24] # p
pop ecx
imul ecx,8
add eax,ecx
mov ecx,4
add eax,ecx # .y
push eax
mov eax,3
pop ecx
mov [ecx],eax
mov eax,1
push eax
lea eax,[ebp-24] # p
pop ecx
imul ecx,8
add eax,ecx
mov ecx,0
add eax,ecx # .x
push eax
mov eax,11
pop ecx
mov [ecx],eax
mov eax,1
push eax
lea eax,[ebp-24] # p
pop ecx
imul ecx,8
add eax,ecx
mov ecx,4
add eax,ecx # .y
push eax
mov eax,22
pop ecx
mov [ecx],eax
lea eax,[ebp-28] # pp
push eax
lea eax,[ebp-36] # q
pop ecx
mov [ecx],eax
mov eax,[ebp-28] # pp
mov ecx,4
add eax,ecx # .y
push eax
mov eax,[ebp-28] # pp
mov ecx,0
add eax,ecx # .x
mov eax,[eax]
push eax
mov eax,3
pop ecx
add eax,ecx
pop ecx
mov [ecx],eax
mov eax,20
push eax
mov eax,[ebp-28] # pp
push eax
call _test
add esp,8
push eax
lea eax,[ebp-36] # q
mov ecx,4
add eax,ecx # .y
mov eax,[eax]
push eax
mov eax,1
push eax
lea eax,[ebp-24] # p
pop ecx
imul ecx,8
add eax,ecx
mov ecx,4
add eax,ecx # .y
mov eax,[eax]
pop ecx
add eax,ecx
pop ecx
add eax,ecx
mov esp,ebp
pop ebp
ret
.set locals_main,36
# ** End of function **
# =========================================
# main l=0 o=0 [int] 
# test l=0 o=0 [int] 
# gp l=0 o=0 [struct Point] 
# struct Point l=0 o=0 [] 
# =========================================
mov esp,ebp
pop ebp
ret
