.intel_syntax noprefix
# =========================================
# argv l=1 o=12 [char**] ARG
# argc l=1 o=8 [int] ARG
# main l=0 o=0 [int] 
# =========================================
.globl _main
_main:
push ebp
mov ebp,esp
.data
_string1:
.asciz "jcc [options] foo.c\n-c: compile only\n-dumpLex: dump lex tokens to stdout\n-dumpParse: dump Abstract Syntax Tree to stdout\n-lexOnly: lex input file but do not parse or create function calls (no output file)\n-parseOnly: lex and parse but don't create function calls (no output file)\n"
.text
mov eax, offset _string1
push eax # declare usage (level 1)
# =========================================
# usage l=1 o=-4 [char*]  CONST
# argv l=1 o=12 [char**] ARG
# argc l=1 o=8 [int] ARG
# main l=0 o=0 [int] 
# =========================================
mov eax,0
push eax
lea eax,[ebp+12] # argv
mov eax,[eax]
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
push eax
.data
_string2:
.asciz "prog name=%s\n"
.text
mov eax, offset _string2
push eax
call _printf
add esp,8
mov eax,1
push eax
mov eax,[ebp+8] # argc
pop ecx
cmp eax,ecx
mov eax, 0
sete al
cmp eax, 0
je _else3
mov eax,[ebp-4] # usage
push eax
.data
_string4:
.asciz "Usage:\n%s\n"
.text
mov eax, offset _string4
push eax
call _printf
add esp,8
jmp _end3
_else3:
mov eax,1
push eax
lea eax,[ebp+12] # argv
mov eax,[eax]
pop ecx
imul ecx,4
add eax,ecx
mov eax,[eax]
push eax
.data
_string5:
.asciz "compiling... %s\n"
.text
mov eax, offset _string5
push eax
call _printf
add esp,8
_end3:
mov eax,0
mov esp,ebp
pop ebp
ret
# ** End of function **
# =========================================
# main l=0 o=0 [int] 
# =========================================
mov esp,ebp
pop ebp
ret
