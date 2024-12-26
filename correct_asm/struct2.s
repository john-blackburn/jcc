.intel_syntax noprefix
# ======================
# struct Point 0 0 [] 0
# ======================
# ======================
# struct Rect 0 0 [] 0
# struct Point 0 0 [] 0
# ======================
# ======================
# q 1 16 [struct Point] 1
# p 1 8 [struct Point] 1
# addPoints 0 0 [struct Point] 0
# struct Rect 0 0 [] 0
# struct Point 0 0 [] 0
# ======================
.globl _addPoints
_addPoints:
push ebp
mov ebp,esp
sub esp,8 # declare tot (level 1)
# ======================
# tot 1 -8 [struct Point] 0
# q 1 16 [struct Point] 1
# p 1 8 [struct Point] 1
# addPoints 0 0 [struct Point] 0
# struct Rect 0 0 [] 0
# struct Point 0 0 [] 0
# ======================
lea eax,[ebp-8] # tot
mov ecx,0
add eax,ecx
push eax
lea eax,[ebp+16] # q
mov ecx,0
add eax,ecx
mov eax,[eax]
push eax
lea eax,[ebp+8] # p
mov ecx,0
add eax,ecx
mov eax,[eax]
pop ecx
add eax,ecx
pop ecx
mov [ecx],eax
lea eax,[ebp-8] # tot
mov ecx,4
add eax,ecx
push eax
lea eax,[ebp+16] # q
mov ecx,4
add eax,ecx
mov eax,[eax]
push eax
lea eax,[ebp+8] # p
mov ecx,4
add eax,ecx
mov eax,[eax]
pop ecx
add eax,ecx
pop ecx
mov [ecx],eax
lea eax,[ebp-8] # tot
mov esp,ebp
pop ebp
ret
# ** End of function **
# ======================
# addPoints 0 0 [struct Point] 0
# struct Rect 0 0 [] 0
# struct Point 0 0 [] 0
# ======================
mov esp,ebp
pop ebp
ret
# ======================
# main 0 0 [int] 0
# addPoints 0 0 [struct Point] 0
# struct Rect 0 0 [] 0
# struct Point 0 0 [] 0
# ======================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp,16 # declare r (level 1)
# ======================
# r 1 -16 [struct Rect] 0
# main 0 0 [int] 0
# addPoints 0 0 [struct Point] 0
# struct Rect 0 0 [] 0
# struct Point 0 0 [] 0
# ======================
sub esp,16 # declare s (level 1)
# ======================
# s 1 -32 [struct Rect] 0
# r 1 -16 [struct Rect] 0
# main 0 0 [int] 0
# addPoints 0 0 [struct Point] 0
# struct Rect 0 0 [] 0
# struct Point 0 0 [] 0
# ======================
lea eax,[ebp-16] # r
mov ecx,0
add eax,ecx
mov ecx,0
add eax,ecx
push eax
mov eax,1
pop ecx
mov [ecx],eax
lea eax,[ebp-16] # r
mov ecx,0
add eax,ecx
mov ecx,4
add eax,ecx
push eax
mov eax,2
pop ecx
mov [ecx],eax
lea eax,[ebp-16] # r
mov ecx,8
add eax,ecx
mov ecx,0
add eax,ecx
push eax
mov eax,3
pop ecx
mov [ecx],eax
lea eax,[ebp-16] # r
mov ecx,8
add eax,ecx
mov ecx,4
add eax,ecx
push eax
mov eax,4
pop ecx
mov [ecx],eax
sub esp,8 # declare another (level 1)
# ======================
# another 1 -40 [struct Point] 0
# s 1 -32 [struct Rect] 0
# r 1 -16 [struct Rect] 0
# main 0 0 [int] 0
# addPoints 0 0 [struct Point] 0
# struct Rect 0 0 [] 0
# struct Point 0 0 [] 0
# ======================
lea eax,[ebp-40] # another
mov ecx,0
add eax,ecx
push eax
mov eax,10
pop ecx
mov [ecx],eax
lea eax,[ebp-40] # another
mov ecx,4
add eax,ecx
push eax
mov eax,20
pop ecx
mov [ecx],eax
lea eax,[ebp-32] # s
push eax
lea eax,[ebp-16] # r
pop ecx
push 16
push eax
push ecx
call _memcpy
add esp,12
lea eax,[ebp-32] # s
mov ecx,0
add eax,ecx
push eax
lea eax,[ebp-40] # another
pop ecx
push 8
push eax
push ecx
call _memcpy
add esp,12
sub esp,8 # declare p (level 1)
# ======================
# p 1 -48 [struct Point] 0
# another 1 -40 [struct Point] 0
# s 1 -32 [struct Rect] 0
# r 1 -16 [struct Rect] 0
# main 0 0 [int] 0
# addPoints 0 0 [struct Point] 0
# struct Rect 0 0 [] 0
# struct Point 0 0 [] 0
# ======================
lea eax,[ebp-48] # p
push eax
lea eax,[ebp-16] # r
mov ecx,0
add eax,ecx
sub esp,8
mov ecx,esp
push 8
push eax
push ecx
call _memcpy
add esp,12
lea eax,[ebp-40] # another
sub esp,8
mov ecx,esp
push 8
push eax
push ecx
call _memcpy
add esp,12
call _addPoints
add esp,16
pop ecx
push 8
push eax
push ecx
call _memcpy
add esp,12
lea eax,[ebp-48] # p
mov ecx,4
add eax,ecx
mov eax,[eax]
push eax
lea eax,[ebp-48] # p
mov ecx,0
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
lea eax,[ebp-32] # s
mov ecx,0
add eax,ecx
mov ecx,0
add eax,ecx
mov eax,[eax]
push eax
lea eax,[ebp-32] # s
mov ecx,8
add eax,ecx
mov ecx,4
add eax,ecx
mov eax,[eax]
pop ecx
add eax,ecx
mov esp,ebp
pop ebp
ret
# ** End of function **
# ======================
# main 0 0 [int] 0
# addPoints 0 0 [struct Point] 0
# struct Rect 0 0 [] 0
# struct Point 0 0 [] 0
# ======================
mov esp,ebp
pop ebp
ret
