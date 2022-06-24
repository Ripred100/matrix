CC=gcc
CFLAGS=-I.

make: main.o matrix.o utils.o test.o
     $(CC) -o main matrix.o utils.o test.o