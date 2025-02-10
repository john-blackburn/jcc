.intel_syntax noprefix
# =========================================
# main l=0 o=0 [int] 
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp, offset locals_main
mov eax,3
mov [ebp-4],eax # declare test (level 1)
# =========================================
# test l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
mov eax,1
push eax
mov eax,[ebp-4] # test
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _else1
.data
_string2:
.asciz ""
.text
mov eax, offset _string2
jmp _end1
_else1:
.data
_string3:
.asciz "s"
.text
mov eax, offset _string3
_end1:
push eax
mov eax,[ebp-4] # test
push eax
.data
_string4:
.asciz "You have %d item%s\n"
.text
mov eax, offset _string4
push eax
call _printf
add esp,12
mov eax,1
push eax
mov eax,[ebp-4] # test
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _end5
mov eax,1
cmp eax, 0
je _else6
mov eax,2
push eax
mov eax,3
pop ecx
cdq
idiv eax,ecx
mov eax,edx
jmp _end6
_else6:
mov eax,4
_end6:
mov [ebp-8],eax # declare a (level 2)
# =========================================
# a l=2 o=-8 [int] 
# test l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
mov eax,[ebp-8] # a
mov esp,ebp
pop ebp
ret
# ** End of block **
# =========================================
# test l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
_end5:
mov eax,2
push eax
mov eax,[ebp-4] # test
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _end7
mov eax,1
mov [ebp-8],eax # declare a (level 2)
# =========================================
# a l=2 o=-8 [int] 
# test l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
mov eax,2
push eax
mov eax,[ebp-8] # a
pop ecx
cmp eax,ecx
mov eax, 0
setne al
cmp eax, 0
je _else8
lea eax,[ebp-8] # a
push eax
mov eax,2
pop ecx
mov [ecx],eax
jmp _end8
_else8:
mov eax,0
_end8:
mov eax,[ebp-8] # a
mov esp,ebp
pop ebp
ret
# ** End of block **
# =========================================
# test l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
_end7:
mov eax,3
push eax
mov eax,[ebp-4] # test
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _end9
mov eax,10
mov [ebp-8],eax # declare a (level 2)
# =========================================
# a l=2 o=-8 [int] 
# test l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
mov eax,[ebp-8] # a
cmp eax, 0
je _else11
mov eax, 1
jmp _end11
_else11:
mov eax,0
cmp eax, 0
mov eax, 0
setne al
_end11:
cmp eax, 0
je _else10
mov eax,20
jmp _end10
_else10:
mov eax,0
_end10:
mov esp,ebp
pop ebp
ret
# ** End of block **
# =========================================
# test l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
_end9:
mov eax,4
push eax
mov eax,[ebp-4] # test
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _end12
mov eax,0
cmp eax, 0
je _else13
mov eax,1
jmp _end13
_else13:
mov eax,0
cmp eax, 0
je _else14
mov eax, 1
jmp _end14
_else14:
mov eax,2
cmp eax, 0
mov eax, 0
setne al
_end14:
_end13:
mov esp,ebp
pop ebp
ret
_end12:
mov eax,5
push eax
mov eax,[ebp-4] # test
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _end15
mov eax,1
mov [ebp-8],eax # declare a (level 2)
# =========================================
# a l=2 o=-8 [int] 
# test l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
mov eax,0
mov [ebp-12],eax # declare b (level 2)
# =========================================
# b l=2 o=-12 [int] 
# a l=2 o=-8 [int] 
# test l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
mov eax,[ebp-8] # a
cmp eax, 0
je _else16
lea eax,[ebp-12] # b
push eax
mov eax,1
pop ecx
mov [ecx],eax
jmp _end16
_else16:
lea eax,[ebp-12] # b
push eax
mov eax,2
pop ecx
mov [ecx],eax
_end16:
mov eax,[ebp-12] # b
mov esp,ebp
pop ebp
ret
# ** End of block **
# =========================================
# test l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# =========================================
_end15:
.set locals_main,12
# ** End of function **
# =========================================
# main l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
