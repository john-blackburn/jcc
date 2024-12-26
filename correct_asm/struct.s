.intel_syntax noprefix
# ======================
# struct Point 0 0 [] 0
# ======================
.data
.globl _gp
_gp:
.long 0
.text
# ======================
# gp 0 0 [struct Point] 0
# struct Point 0 0 [] 0
# ======================
# ======================
# s 1 12 [int] 1
# p 1 8 [struct Point*] 1
# test 0 0 [int] 0
# gp 0 0 [struct Point] 0
# struct Point 0 0 [] 0
# ======================
.globl _test
_test:
push ebp
mov ebp,esp
lea eax,[ebp+8] # p
mov eax,[eax]
mov ecx,0
add eax,ecx
mov eax,[eax]
push eax
mov eax,[ebp+12] # s
pop ecx
imul eax,ecx
mov esp,ebp
pop ebp
ret
# ** End of function **
# ======================
# test 0 0 [int] 0
# gp 0 0 [struct Point] 0
# struct Point 0 0 [] 0
# ======================
mov esp,ebp
pop ebp
ret
# ======================
# main 0 0 [int] 0
# test 0 0 [int] 0
# gp 0 0 [struct Point] 0
# struct Point 0 0 [] 0
# ======================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp,24 # declare p (level 1)
# ======================
# p 1 -24 [struct Point[3]] 0
# main 0 0 [int] 0
# test 0 0 [int] 0
# gp 0 0 [struct Point] 0
# struct Point 0 0 [] 0
# ======================
push eax # declare pp (level 1)
# ======================
# pp 1 -28 [struct Point*] 0
# p 1 -24 [struct Point[3]] 0
# main 0 0 [int] 0
# test 0 0 [int] 0
# gp 0 0 [struct Point] 0
# struct Point 0 0 [] 0
# ======================
sub esp,8 # declare q (level 1)
# ======================
# q 1 -36 [struct Point] 0
# pp 1 -28 [struct Point*] 0
# p 1 -24 [struct Point[3]] 0
# main 0 0 [int] 0
# test 0 0 [int] 0
# gp 0 0 [struct Point] 0
# struct Point 0 0 [] 0
# ======================
lea eax,[ebp-36] # q
mov ecx,0
add eax,ecx
push eax
mov eax,10
pop ecx
mov [ecx],eax
lea eax,[ebp-36] # q
mov ecx,4
add eax,ecx
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
add eax,ecx
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
add eax,ecx
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
add eax,ecx
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
add eax,ecx
push eax
mov eax,22
pop ecx
mov [ecx],eax
lea eax,[ebp-28] # pp
push eax
lea eax,[ebp-36] # q
pop ecx
mov [ecx],eax
lea eax,[ebp-28] # pp
mov eax,[eax]
mov ecx,4
add eax,ecx
push eax
lea eax,[ebp-28] # pp
mov eax,[eax]
mov ecx,0
add eax,ecx
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
add eax,ecx
mov eax,[eax]
push eax
mov eax,1
push eax
lea eax,[ebp-24] # p
pop ecx
imul ecx,8
add eax,ecx
mov ecx,4
add eax,ecx
mov eax,[eax]
pop ecx
add eax,ecx
pop ecx
add eax,ecx
mov esp,ebp
pop ebp
ret
# ** End of function **
# ======================
# main 0 0 [int] 0
# test 0 0 [int] 0
# gp 0 0 [struct Point] 0
# struct Point 0 0 [] 0
# ======================
mov esp,ebp
pop ebp
ret
