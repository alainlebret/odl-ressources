CC = gcc
INC_PATH = include
MATRIX_PATH = matrix
CPPFLAGS = -I $(INC_PATH)
CFLAGS = -Wall -Wextra -ansi -pedantic

magic_square : magic_square.o construire_matrix
	$(CC) $< $(MATRIX_PATH)/matrix.o -o magic_square

magic_square.o : magic_square.c $(INC_PATH)/matrix.h
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -c

construire_matrix:
	make -f matrix/Makefile

clean:
	rm magic_square magic_square.o $(MATRIX_PATH)/matrix.o

.PHONY: all clean
