.intel_syntax noprefix
# =========================================
# struct Bar l=0 o=0 [] 
# struct Foo l=0 o=0 [] 
# =========================================
# =========================================
# struct Bar l=0 o=0 [] 
# struct Foo l=0 o=0 [] 
# =========================================
.data
.globl _x
_x:
.skip 24
.text
# =========================================
# x l=0 o=0 [struct Foo] 
# struct Bar l=0 o=0 [] 
# struct Foo l=0 o=0 [] 
# =========================================
.data
.globl _y
_y:
.skip 24
.text
# =========================================
# y l=0 o=0 [struct Foo] 
# x l=0 o=0 [struct Foo] 
# struct Bar l=0 o=0 [] 
# struct Foo l=0 o=0 [] 
# =========================================
# =========================================
# main l=0 o=0 [int] 
# y l=0 o=0 [struct Foo] 
# x l=0 o=0 [struct Foo] 
# struct Bar l=0 o=0 [] 
# struct Foo l=0 o=0 [] 
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp, offset locals_main
mov eax,offset _x
mov ecx,0
add eax,ecx # .a
push eax
mov eax,1
pop ecx
mov [ecx],eax
mov eax,offset _y
mov ecx,4
add eax,ecx # .b
push eax
mov eax,offset _x
mov ecx,0
add eax,ecx # .a
mov eax,[eax]
pop ecx
mov [ecx],eax
mov eax,offset _y
mov ecx,8
add eax,ecx # .a1
mov ecx,0
add eax,ecx # .p
push eax
mov eax,offset _x
mov ecx,0
add eax,ecx # .a
mov eax,[eax]
pop ecx
push eax
call _int2float
add esp,4
mov [ecx],eax
mov eax,24
push eax
mov eax,offset _y
mov ecx,4
add eax,ecx # .b
mov eax,[eax]
pop ecx
add eax,ecx
mov esp,ebp
pop ebp
ret
.set locals_main,0
# ** End of function **
# =========================================
# main l=0 o=0 [int] 
# y l=0 o=0 [struct Foo] 
# x l=0 o=0 [struct Foo] 
# struct Bar l=0 o=0 [] 
# struct Foo l=0 o=0 [] 
# =========================================
mov esp,ebp
pop ebp
ret
