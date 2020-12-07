CC=gcc
CFLAGS=-Wall -Wextra -ansi -pedantic
INC_PATH= include
MATRIX_PATH= matrix

magic_square : magic_square.o construire_matrix
	$(CC) $< $(MATRIX_PATH)/matrix.o -o magic_square

magic_square.o : magic_square.c $(INC_PATH)/matrix.h
	$(CC) $(CFLAGS) -c -I $(INC_PATH) magic_square.c

construire_matrix:
	make -f matrix/Makefile

clean:
	rm magic_square magic_square.o $(MATRIX_PATH)/matrix.o