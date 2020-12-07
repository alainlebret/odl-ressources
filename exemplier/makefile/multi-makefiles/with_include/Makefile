CC=gcc
CFLAGS=-Wall -Wextra -ansi -pedantic
INC_PATH= include
MATRIX_PATH= matrix

all: magic_square

magic_square : magic_square.o $(MATRIX_PATH)/matrix.o
	$(CC) $^ -o magic_square

magic_square.o : magic_square.c $(INC_PATH)/matrix.h
	$(CC) $(CFLAGS) -c -I $(INC_PATH) magic_square.c

include $(MATRIX_PATH)/Makefile

clean:
	rm magic_square magic_square.o $(MATRIX_PATH)/matrix.o