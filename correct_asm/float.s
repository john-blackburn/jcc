.intel_syntax noprefix
.data
.globl _pi
_pi:
.float 3.1415
.text
# =========================================
# pi l=0 o=0 [float] 
# sinf l=0 o=0 [float] 
# =========================================
# =========================================
# x l=1 o=8 [float] ARG
# square l=0 o=0 [float] 
# pi l=0 o=0 [float] 
# sinf l=0 o=0 [float] 
# =========================================
.globl _square
_square:
push ebp
mov ebp,esp
sub esp, offset locals_square
mov eax,[ebp+8] # x
push eax
mov eax,[ebp+8] # x
pop ecx
push ecx
push eax
call _fimul
pop ecx
pop ecx
mov [_float_temp],eax
FLD dword ptr [_float_temp]
mov esp,ebp
pop ebp
ret
.set locals_square,0
# ** End of function **
# =========================================
# square l=0 o=0 [float] 
# pi l=0 o=0 [float] 
# sinf l=0 o=0 [float] 
# =========================================
mov [_float_temp],eax
FLD dword ptr [_float_temp]
mov esp,ebp
pop ebp
ret
# =========================================
# main l=0 o=0 [int] 
# square l=0 o=0 [float] 
# pi l=0 o=0 [float] 
# sinf l=0 o=0 [float] 
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp, offset locals_main
# =========================================
# a l=1 o=-4 [float] 
# main l=0 o=0 [int] 
# square l=0 o=0 [float] 
# pi l=0 o=0 [float] 
# sinf l=0 o=0 [float] 
# =========================================
mov eax,1
mov [ebp-8],eax # declare i (level 1)
# =========================================
# i l=1 o=-8 [int] 
# a l=1 o=-4 [float] 
# main l=0 o=0 [int] 
# square l=0 o=0 [float] 
# pi l=0 o=0 [float] 
# sinf l=0 o=0 [float] 
# =========================================
lea eax,[ebp-4] # a
push eax
mov eax,0x40a00000 # 5.000000
pop ecx
mov [ecx],eax
mov eax,[ebp-4] # a
push eax
mov eax,_pi
push eax
.data
_string1:
.asciz "numbers: %0x %0x\n"
.text
mov eax, offset _string1
push eax
call _printf
add esp,12
mov eax,2
push eax
lea eax,[ebp-4] # a
pop ecx
push eax
mov eax,[eax]
push eax
push ecx
call _int2float
add esp,4
mov ecx,eax
pop eax
push ecx
push eax
call _fadd
pop ecx
pop ecx
mov ecx,eax
pop eax
mov [eax],ecx
mov eax,ecx
mov eax,0x3fc00000 # 1.500000
push eax
mov eax,[ebp-4] # a
pop ecx
push ecx
push eax
call _fsub
pop ecx
pop ecx
push eax
mov eax,_pi
push eax
mov eax,[ebp-4] # a
pop ecx
push ecx
push eax
call _fadd
pop ecx
pop ecx
push eax
mov eax,0x40600000 # 3.500000
push eax
mov eax,[ebp-4] # a
pop ecx
push ecx
push eax
call _fadd
pop ecx
pop ecx
push eax
.data
_string2:
.asciz "result: %0x %0x %0x\n"
.text
mov eax, offset _string2
push eax
call _printf
add esp,16
mov eax,0x40400000 # 3.000000
push eax
call _fneg
add esp,4
mov [ebp-12],eax # declare b (level 1)
# =========================================
# b l=1 o=-12 [float] 
# i l=1 o=-8 [int] 
# a l=1 o=-4 [float] 
# main l=0 o=0 [int] 
# square l=0 o=0 [float] 
# pi l=0 o=0 [float] 
# sinf l=0 o=0 [float] 
# =========================================
mov eax,[ebp-12] # b
push eax
call _square
add esp,4
FSTP dword ptr [_float_temp]
mov eax,[_float_temp]
push eax
mov eax,[ebp-8] # i
push eax
call _int2float
add esp,4
push eax
mov eax,[ebp-8] # i
push eax
mov eax,[ebp-12] # b
push eax
.data
_string3:
.asciz "b=%0x, i=%d, i(converted)=%0x, sq=%0x\n"
.text
mov eax, offset _string3
push eax
call _printf
add esp,20
mov eax,[ebp-12] # b
push eax
mov eax,[ebp-4] # a
pop ecx
push ecx
push eax
call _fcmp
pop ecx
pop ecx
mov eax, 0
seta al
cmp eax, 0
je _end4
.data
_string5:
.asciz "a>b\n"
.text
mov eax, offset _string5
push eax
call _printf
add esp,4
_end4:
mov eax,[ebp-12] # b
push eax
mov eax,[ebp-4] # a
pop ecx
push ecx
push eax
call _fcmp
pop ecx
pop ecx
mov eax, 0
setae al
cmp eax, 0
je _end6
.data
_string7:
.asciz "a>=b\n"
.text
mov eax, offset _string7
push eax
call _printf
add esp,4
_end6:
mov eax,[ebp-12] # b
push eax
mov eax,[ebp-4] # a
pop ecx
push ecx
push eax
call _fcmp
pop ecx
pop ecx
mov eax, 0
setb al
cmp eax, 0
je _end8
.data
_string9:
.asciz "a<b\n"
.text
mov eax, offset _string9
push eax
call _printf
add esp,4
_end8:
mov eax,[ebp-12] # b
push eax
mov eax,[ebp-4] # a
pop ecx
push ecx
push eax
call _fcmp
pop ecx
pop ecx
mov eax, 0
setbe al
cmp eax, 0
je _end10
.data
_string11:
.asciz "a<=b\n"
.text
mov eax, offset _string11
push eax
call _printf
add esp,4
_end10:
mov eax,[ebp-4] # a
push eax
mov eax,[ebp-12] # b
pop ecx
push ecx
push eax
call _fcmp
pop ecx
pop ecx
mov eax, 0
seta al
cmp eax, 0
je _end12
.data
_string13:
.asciz "b>a\n"
.text
mov eax, offset _string13
push eax
call _printf
add esp,4
_end12:
mov eax,[ebp-4] # a
push eax
mov eax,[ebp-12] # b
pop ecx
push ecx
push eax
call _fcmp
pop ecx
pop ecx
mov eax, 0
setae al
cmp eax, 0
je _end14
.data
_string15:
.asciz "b>=a\n"
.text
mov eax, offset _string15
push eax
call _printf
add esp,4
_end14:
mov eax,[ebp-4] # a
push eax
mov eax,[ebp-12] # b
pop ecx
push ecx
push eax
call _fcmp
pop ecx
pop ecx
mov eax, 0
setb al
cmp eax, 0
je _end16
.data
_string17:
.asciz "b<a\n"
.text
mov eax, offset _string17
push eax
call _printf
add esp,4
_end16:
mov eax,[ebp-4] # a
push eax
mov eax,[ebp-12] # b
pop ecx
push ecx
push eax
call _fcmp
pop ecx
pop ecx
mov eax, 0
setbe al
cmp eax, 0
je _end18
mov eax,[ebp-4] # a
push eax
call _sinf
add esp,4
FSTP dword ptr [_float_temp]
mov eax,[_float_temp]
push eax
.data
_string19:
.asciz "b<=a, sinf(a)=%0x\n"
.text
mov eax, offset _string19
push eax
call _printf
add esp,8
_end18:
lea eax,[ebp-8] # i
push eax
mov eax,[ebp-4] # a
push eax
mov eax,3
pop ecx
push eax
call _int2float
add esp,4
push ecx
push eax
call _fadd
pop ecx
pop ecx
pop ecx
push eax
call _float2int
add esp,4
mov [ecx],eax
mov eax,1
push eax
mov eax,[ebp-8] # i
pop ecx
add eax,ecx
mov esp,ebp
pop ebp
ret
.set locals_main,12
# ** End of function **
# =========================================
# main l=0 o=0 [int] 
# square l=0 o=0 [float] 
# pi l=0 o=0 [float] 
# sinf l=0 o=0 [float] 
# =========================================
mov esp,ebp
pop ebp
ret
