@echo off

jcc %1.c
fc %1.s correct_asm\%1.s
echo running %1.exe...
%1.exe
echo return %errorlevel%

gcc -o %1_gcc.exe %1.c
echo running %1_gcc.exe...
%1_gcc.exe
echo gcc return %errorlevel%
