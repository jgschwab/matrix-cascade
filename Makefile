CC=gcc
CFLAGS= -Wall -g -std=c99

matrix: matrix.o
matrix.o: matrix.h matrix.c

clean:
	rm -f matrix matrix.o
