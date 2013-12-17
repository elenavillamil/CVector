INCLUDE := $(wildcard *.c)

debug:
	gcc -g -I Headers/ Source/*.c main.c
