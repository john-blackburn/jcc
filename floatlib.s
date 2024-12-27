.intel_syntax noprefix

.data
.globl _float_temp
_float_temp:
.float 0.0
.text

.globl _fneg
_fneg:
   push ebp
   mov ebp,esp
   
   FLD dword ptr [ebp+8]
   FCHS
   FSTP dword ptr [ebp+8]
   mov eax,[ebp+8]

   mov esp,ebp
   pop ebp

   ret

.globl _fadd
_fadd:
   push ebp
   mov ebp,esp

   FLD dword ptr [ebp+8]  # a
   FLD dword ptr [ebp+12] # b

   FADDP st(1),st(0) #  st(0)=a+b

   FSTP dword ptr [ebp+8] # corrupt a but we don't care
   mov eax,[ebp+8] # return value

   mov esp,ebp
   pop ebp

   ret

.globl _fsub
_fsub:
   push ebp
   mov ebp,esp

   FLD dword ptr [ebp+8]  # a
   FLD dword ptr [ebp+12] # b

   FSUBP st(1),st(0) #  st(0)=a-b

   FSTP dword ptr [ebp+8] # corrupt a but we don't care
   mov eax,[ebp+8] # return value

   mov esp,ebp
   pop ebp

   ret

.globl _fimul
_fimul:
   push ebp
   mov ebp,esp

   FLD dword ptr [ebp+8]  # a
   FLD dword ptr [ebp+12] # b

   FMULP st(1),st(0) #  st(0)=a*b

   FSTP dword ptr [ebp+8] # corrupt a but we don't care
   mov eax,[ebp+8] # return value

   mov esp,ebp
   pop ebp

   ret

.globl _fidiv
_fidiv:
   push ebp
   mov ebp,esp

   FLD dword ptr [ebp+8]  # a
   FLD dword ptr [ebp+12] # b

   FDIVP st(1),st(0) #  st(0)=a/b

   FSTP dword ptr [ebp+8] # corrupt a but we don't care
   mov eax,[ebp+8] # return value

   mov esp,ebp
   pop ebp

   ret


.globl _int2float
_int2float:
   push ebp
   mov ebp,esp

   FILD dword ptr [ebp+8]
   FSTP dword ptr [ebp+8]
   mov eax,[ebp+8]

   mov esp,ebp
   pop ebp
   ret
   
.globl _float2int
_float2int:
   push ebp
   mov ebp,esp

   FLD dword ptr [ebp+8]
   FISTP dword ptr [ebp+8]
   mov eax,[ebp+8]

   mov esp,ebp
   pop ebp
   ret
   