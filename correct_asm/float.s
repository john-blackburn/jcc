.intel_syntax noprefix
.data
.globl _pi
_pi:
.float 3.1415
.text
# ======================
# pi 0 0 [float] 0
# ======================
# ======================
# x 1 8 [float] 1
# square 0 0 [float] 0
# pi 0 0 [float] 0
# ======================
.globl _square
_square:
push ebp
mov ebp,esp
mov eax,[ebp+8] # x
push eax
mov eax,[ebp+8] # x
pop ecx
push ecx
push eax
call _fimul
add esp,8
mov [_float_temp],eax
FLD dword ptr [_float_temp]
mov esp,ebp
pop ebp
ret
# ** End of function **
# ======================
# square 0 0 [float] 0
# pi 0 0 [float] 0
# ======================
mov [_float_temp],eax
FLD dword ptr [_float_temp]
mov esp,ebp
pop ebp
ret
# ======================
# main 0 0 [int] 0
# square 0 0 [float] 0
# pi 0 0 [float] 0
# ======================
.globl _main
_main:
push ebp
mov ebp,esp
push eax # declare a (level 1)
# ======================
# a 1 -4 [float] 0
# main 0 0 [int] 0
# square 0 0 [float] 0
# pi 0 0 [float] 0
# ======================
mov eax,1
push eax # declare i (level 1)
# ======================
# i 1 -8 [int] 0
# a 1 -4 [float] 0
# main 0 0 [int] 0
# square 0 0 [float] 0
# pi 0 0 [float] 0
# ======================
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
add esp,8
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
add esp,8
push eax
mov eax,_pi
push eax
mov eax,[ebp-4] # a
pop ecx
push ecx
push eax
call _fadd
add esp,8
push eax
mov eax,0x40600000 # 3.500000
push eax
mov eax,[ebp-4] # a
pop ecx
push ecx
push eax
call _fadd
add esp,8
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
push eax # declare b (level 1)
# ======================
# b 1 -12 [float] 0
# i 1 -8 [int] 0
# a 1 -4 [float] 0
# main 0 0 [int] 0
# square 0 0 [float] 0
# pi 0 0 [float] 0
# ======================
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
add esp,8
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
# ** End of function **
# ======================
# main 0 0 [int] 0
# square 0 0 [float] 0
# pi 0 0 [float] 0
# ======================
mov esp,ebp
pop ebp
ret
