@echo off

del %1.z80

call j80 examples\%1.c
winmergeu correct_z80\%1.z80 %1.z80
