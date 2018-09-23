all: 32 64
32:
	gcc -m32 -masm=intel demo.c -o demo32
64:
	gcc -masm=intel demo.c -o demo64
