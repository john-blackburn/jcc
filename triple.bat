gcc -o jcc.exe main.c

jcc -ojcc2.exe main.c
del main2.s
ren main.s main2.s

jcc2 -ojcc3.exe main.c
del main3.s
ren main.s main3.s

fc main2.s main3.s
