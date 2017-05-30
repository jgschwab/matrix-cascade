CC=gcc
CFLAGS= -Wall -g -std=c99

matrix: matrix.o

clean:
	rm -f matrix matrix.o
