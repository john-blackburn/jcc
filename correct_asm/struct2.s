.intel_syntax noprefix
# =========================================
# struct Point l=0 o=0 [] 
# =========================================
# =========================================
# struct Rect l=0 o=0 [] 
# struct Point l=0 o=0 [] 
# =========================================
# =========================================
# q l=1 o=28 [struct Point] ARG
# p l=1 o=12 [struct Point] ARG
# addPoints l=0 o=0 [struct Point] 
# struct Rect l=0 o=0 [] 
# struct Point l=0 o=0 [] 
# =========================================
.globl _addPoints
_addPoints:
push ebp
mov ebp,esp
sub esp, offset locals_addPoints
# =========================================
# tot l=1 o=-16 [struct Point] 
# q l=1 o=28 [struct Point] ARG
# p l=1 o=12 [struct Point] ARG
# addPoints l=0 o=0 [struct Point] 
# struct Rect l=0 o=0 [] 
# struct Point l=0 o=0 [] 
# =========================================
lea eax,[ebp-16] # tot
mov ecx,0
add eax,ecx # .x
push eax
lea eax,[ebp+28] # q
mov ecx,0
add eax,ecx # .x
mov eax,[eax]
push eax
lea eax,[ebp+12] # p
mov ecx,0
add eax,ecx # .x
mov eax,[eax]
pop ecx
add eax,ecx
pop ecx
mov [ecx],eax
lea eax,[ebp-16] # tot
mov ecx,4
add eax,ecx # .y
push eax
lea eax,[ebp+28] # q
mov ecx,4
add eax,ecx # .y
mov eax,[eax]
push eax
lea eax,[ebp+12] # p
mov ecx,4
add eax,ecx # .y
mov eax,[eax]
pop ecx
add eax,ecx
pop ecx
mov [ecx],eax
lea eax,[ebp-16] # tot
mov ecx,8
add eax,ecx # .l
push eax
mov eax,0
pop ecx
mov [ecx],eax
lea eax,[ebp-16] # tot
mov ecx,12
add eax,ecx # .w
push eax
mov eax,0
pop ecx
mov [ecx],eax
lea eax,[ebp-16] # tot
mov ecx,[ebp+8]
push 16
push eax
push ecx
call _memcpy
add esp,12
mov eax,[ebp+8]
mov esp,ebp
pop ebp
ret
.set locals_addPoints,16
# ** End of function **
# =========================================
# addPoints l=0 o=0 [struct Point] 
# struct Rect l=0 o=0 [] 
# struct Point l=0 o=0 [] 
# =========================================
mov esp,ebp
pop ebp
ret
# =========================================
# main l=0 o=0 [int] 
# addPoints l=0 o=0 [struct Point] 
# struct Rect l=0 o=0 [] 
# struct Point l=0 o=0 [] 
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp, offset locals_main
# =========================================
# r l=1 o=-32 [struct Rect] 
# main l=0 o=0 [int] 
# addPoints l=0 o=0 [struct Point] 
# struct Rect l=0 o=0 [] 
# struct Point l=0 o=0 [] 
# =========================================
# =========================================
# s l=1 o=-64 [struct Rect] 
# r l=1 o=-32 [struct Rect] 
# main l=0 o=0 [int] 
# addPoints l=0 o=0 [struct Point] 
# struct Rect l=0 o=0 [] 
# struct Point l=0 o=0 [] 
# =========================================
lea eax,[ebp-32] # r
mov ecx,0
add eax,ecx # .top
mov ecx,0
add eax,ecx # .x
push eax
mov eax,1
pop ecx
mov [ecx],eax
lea eax,[ebp-32] # r
mov ecx,0
add eax,ecx # .top
mov ecx,4
add eax,ecx # .y
push eax
mov eax,2
pop ecx
mov [ecx],eax
lea eax,[ebp-32] # r
mov ecx,16
add eax,ecx # .bot
mov ecx,0
add eax,ecx # .x
push eax
mov eax,3
pop ecx
mov [ecx],eax
lea eax,[ebp-32] # r
mov ecx,16
add eax,ecx # .bot
mov ecx,4
add eax,ecx # .y
push eax
mov eax,4
pop ecx
mov [ecx],eax
# =========================================
# another l=1 o=-80 [struct Point] 
# s l=1 o=-64 [struct Rect] 
# r l=1 o=-32 [struct Rect] 
# main l=0 o=0 [int] 
# addPoints l=0 o=0 [struct Point] 
# struct Rect l=0 o=0 [] 
# struct Point l=0 o=0 [] 
# =========================================
lea eax,[ebp-80] # another
mov ecx,0
add eax,ecx # .x
push eax
mov eax,10
pop ecx
mov [ecx],eax
lea eax,[ebp-80] # another
mov ecx,4
add eax,ecx # .y
push eax
mov eax,20
pop ecx
mov [ecx],eax
lea eax,[ebp-64] # s
push eax
lea eax,[ebp-32] # r
pop ecx
push 32
push eax
push ecx
call _memcpy
add esp,12
lea eax,[ebp-64] # s
mov ecx,0
add eax,ecx # .top
push eax
lea eax,[ebp-80] # another
pop ecx
push 16
push eax
push ecx
call _memcpy
add esp,12
# =========================================
# p l=1 o=-96 [struct Point] 
# another l=1 o=-80 [struct Point] 
# s l=1 o=-64 [struct Rect] 
# r l=1 o=-32 [struct Rect] 
# main l=0 o=0 [int] 
# addPoints l=0 o=0 [struct Point] 
# struct Rect l=0 o=0 [] 
# struct Point l=0 o=0 [] 
# =========================================
lea eax,[ebp-96] # p
push eax
lea eax,[ebp-32] # r
mov ecx,0
add eax,ecx # .top
sub esp,16
mov ecx,esp
push 16
push eax
push ecx
call _memcpy
add esp,12
lea eax,[ebp-80] # another
sub esp,16
mov ecx,esp
push 16
push eax
push ecx
call _memcpy
add esp,12
# =========================================
# (str return) l=1 o=-112 [struct Point] 
# p l=1 o=-96 [struct Point] 
# another l=1 o=-80 [struct Point] 
# s l=1 o=-64 [struct Rect] 
# r l=1 o=-32 [struct Rect] 
# main l=0 o=0 [int] 
# addPoints l=0 o=0 [struct Point] 
# struct Rect l=0 o=0 [] 
# struct Point l=0 o=0 [] 
# =========================================
lea eax,[ebp-112]
push eax
call _addPoints
add esp,36
pop ecx
push 16
push eax
push ecx
call _memcpy
add esp,12
lea eax,[ebp-96] # p
mov ecx,4
add eax,ecx # .y
mov eax,[eax]
push eax
lea eax,[ebp-96] # p
mov ecx,0
add eax,ecx # .x
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
lea eax,[ebp-64] # s
mov ecx,0
add eax,ecx # .top
mov ecx,0
add eax,ecx # .x
mov eax,[eax]
push eax
lea eax,[ebp-64] # s
mov ecx,16
add eax,ecx # .bot
mov ecx,4
add eax,ecx # .y
mov eax,[eax]
pop ecx
add eax,ecx
mov esp,ebp
pop ebp
ret
.set locals_main,112
# ** End of function **
# =========================================
# main l=0 o=0 [int] 
# addPoints l=0 o=0 [struct Point] 
# struct Rect l=0 o=0 [] 
# struct Point l=0 o=0 [] 
# =========================================
mov esp,ebp
pop ebp
ret
