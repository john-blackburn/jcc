.intel_syntax noprefix
# =========================================
# struct _iobuf l=0 o=0 [] 
# =========================================
# =========================================
# main l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# struct _iobuf l=0 o=0 [] 
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
sub esp, offset locals_main
mov eax,32
push eax
.data
_string1:
.asciz "sizeof FILE=%d\n"
.text
mov eax, offset _string1
push eax
call _printf
add esp,8
# =========================================
# n l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# struct _iobuf l=0 o=0 [] 
# =========================================
# =========================================
# m l=1 o=-8 [int] 
# n l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# struct _iobuf l=0 o=0 [] 
# =========================================
# =========================================
# p l=1 o=-12 [int*] 
# m l=1 o=-8 [int] 
# n l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# struct _iobuf l=0 o=0 [] 
# =========================================
# =========================================
# z l=1 o=-16 [int**] 
# p l=1 o=-12 [int*] 
# m l=1 o=-8 [int] 
# n l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# struct _iobuf l=0 o=0 [] 
# =========================================
# =========================================
# q l=1 o=-20 [int**] 
# z l=1 o=-16 [int**] 
# p l=1 o=-12 [int*] 
# m l=1 o=-8 [int] 
# n l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# struct _iobuf l=0 o=0 [] 
# =========================================
# =========================================
# k l=1 o=-24 [int**] 
# q l=1 o=-20 [int**] 
# z l=1 o=-16 [int**] 
# p l=1 o=-12 [int*] 
# m l=1 o=-8 [int] 
# n l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# struct _iobuf l=0 o=0 [] 
# =========================================
mov eax,32
push eax
call _malloc
add esp,4
mov [ebp-28],eax # declare fp (level 1)
# =========================================
# fp l=1 o=-28 [struct _iobuf*] 
# k l=1 o=-24 [int**] 
# q l=1 o=-20 [int**] 
# z l=1 o=-16 [int**] 
# p l=1 o=-12 [int*] 
# m l=1 o=-8 [int] 
# n l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# struct _iobuf l=0 o=0 [] 
# =========================================
mov eax,[ebp-28] # fp
mov ecx,12
add eax,ecx # ._flag
push eax
mov eax,9
pop ecx
mov [ecx],eax
mov eax,2
mov [ebp-32],eax # declare index (level 1)
# =========================================
# index l=1 o=-32 [int] 
# fp l=1 o=-28 [struct _iobuf*] 
# k l=1 o=-24 [int**] 
# q l=1 o=-20 [int**] 
# z l=1 o=-16 [int**] 
# p l=1 o=-12 [int*] 
# m l=1 o=-8 [int] 
# n l=1 o=-4 [int] 
# main l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# struct _iobuf l=0 o=0 [] 
# =========================================
mov eax,[ebp-28] # fp
mov ecx,12
add eax,ecx # ._flag
mov eax,[eax]
push eax
mov eax,[ebp-32] # index
pop ecx
add eax,ecx
mov esp,ebp
pop ebp
ret
.set locals_main,32
# ** End of function **
# =========================================
# main l=0 o=0 [int] 
# malloc l=0 o=0 [void*] 
# struct _iobuf l=0 o=0 [] 
# =========================================
mov esp,ebp
pop ebp
ret
