.intel_syntax noprefix
# ======================
# main 0 0 [int] 0
# ======================
.globl _main
_main:
push ebp
mov ebp,esp
push eax # declare x (level 1)
# ======================
# x 1 -4 [int] 0
# main 0 0 [int] 0
# ======================
push eax # declare y (level 1)
# ======================
# y 1 -8 [int] 0
# x 1 -4 [int] 0
# main 0 0 [int] 0
# ======================
lea eax,[ebp-4] # x
push eax
lea eax,[ebp-8] # y
push eax
mov eax,0
pop ecx
mov [ecx],eax
pop ecx
mov [ecx],eax
lea eax,[ebp-4] # x
push eax # declare px (level 1)
# ======================
# px 1 -12 [int*] 0
# y 1 -8 [int] 0
# x 1 -4 [int] 0
# main 0 0 [int] 0
# ======================
push eax # declare py (level 1)
# ======================
# py 1 -16 [int*] 0
# px 1 -12 [int*] 0
# y 1 -8 [int] 0
# x 1 -4 [int] 0
# main 0 0 [int] 0
# ======================
lea eax,[ebp-16] # py
push eax
lea eax,[ebp-8] # y
pop ecx
mov [ecx],eax
mov eax,[ebp-16] # py
push eax
mov eax,3
push eax
mov eax,[ebp-12] # px
mov eax,[eax]
pop ecx
add eax,ecx
pop ecx
mov [ecx],eax
lea eax,[ebp-8] # y
push eax
mov eax,3
push eax
mov eax,[ebp-12] # px
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
pop ecx
mov [ecx],eax
sub esp,24 # declare a (level 1)
# ======================
# a 1 -40 [int[6]] 0
# py 1 -16 [int*] 0
# px 1 -12 [int*] 0
# y 1 -8 [int] 0
# x 1 -4 [int] 0
# main 0 0 [int] 0
# ======================
lea eax,[ebp-8] # y
push eax
mov eax,20
push eax
mov eax,2
push eax
lea eax,[ebp-40] # a
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
push eax
mov eax,3
pop ecx
imul eax,ecx
pop ecx
add eax,ecx
pop ecx
mov [ecx],eax
mov eax,4
push eax
lea eax,[ebp-40] # a
pop ecx
imul ecx,4
add eax,ecx
push eax
mov eax,1
pop ecx
mov [ecx],eax
sub esp,72 # declare foo (level 1)
# ======================
# foo 1 -112 [int[3][6]] 0
# a 1 -40 [int[6]] 0
# py 1 -16 [int*] 0
# px 1 -12 [int*] 0
# y 1 -8 [int] 0
# x 1 -4 [int] 0
# main 0 0 [int] 0
# ======================
sub esp,24 # declare bar (level 1)
# ======================
# bar 1 -136 [int[6]] 0
# foo 1 -112 [int[3][6]] 0
# a 1 -40 [int[6]] 0
# py 1 -16 [int*] 0
# px 1 -12 [int*] 0
# y 1 -8 [int] 0
# x 1 -4 [int] 0
# main 0 0 [int] 0
# ======================
mov eax,4
push eax
mov eax,2
push eax
lea eax,[ebp-112] # foo
pop ecx
imul ecx,24
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
push eax
mov eax,1
pop ecx
mov [ecx],eax
lea eax,[ebp-4] # x
push eax
mov eax,[ebp-8] # y
push eax
lea eax,[ebp-136] # bar
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
push eax
lea eax,[ebp-136] # bar
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
push eax
mov eax,1
pop ecx
add eax,ecx
pop ecx
mov [ecx],eax
lea eax,[ebp-8] # y
push eax
mov eax,5
push eax
mov eax,2
push eax
lea eax,[ebp-112] # foo
pop ecx
imul ecx,24
add eax,ecx
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
pop ecx
mov [ecx],eax
mov eax,[ebp-16] # py
mov eax,[eax]
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
