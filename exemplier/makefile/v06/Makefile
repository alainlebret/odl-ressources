#
# ENSICAEN
# 6 Boulevard Maréchal Juin
# F-14050 Caen Cedex
#
# Examples from the course "Software development tools"
# Exemplier du cours "Outils de développement logiciel" (ODL)
#
# Chapter "The make command" / Chapitre "Commande make"
#
# Copyright (C) 1995-2017 Alain Lebret (alain.lebret@ensicaen.fr)
#

CC = gcc
CPPFLAGS = -Wall -Wextra -ansi -pedantic
CFLAGS = -I. -c -g
LDFLAGS = -o
OBJS = magic_board.o matrix.o
EXEC = magic_board
DOXYGEN = doxygen

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) $(EXEC)

magic_board.o : magic_square.c matrix.h
	$(CC) $(CPPFLAGS) $(CFLAGS) magic_board.c

matrix.o : matrix.c matrix.h
	$(CC) $(CPPFLAGS) $(CFLAGS) matrix.c

.PHONY : clean doc
doc :
	$(DOXYGEN) Doxyfile
clean :
	rm $(OBJS) $(EXEC)
	rm -R doc
