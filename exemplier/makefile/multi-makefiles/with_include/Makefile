CC = gcc
INC_PATH = include
MATRIX_PATH = matrix
CPPFLAGS = -I $(INC_PATH)
CFLAGS = -Wall -Wextra -ansi -pedantic

all: magic_square

magic_square : magic_square.o $(MATRIX_PATH)/matrix.o
	$(CC) $^ -o $@

magic_square.o : magic_square.c $(INC_PATH)/matrix.h
	$(CC) $(CPPFLAGS) $(CFLAGS) $< -c

include $(MATRIX_PATH)/Makefile

clean:
	rm magic_square magic_square.o $(MATRIX_PATH)/matrix.o

.PHONY: all clean
