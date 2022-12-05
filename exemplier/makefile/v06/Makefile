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
CPPFLAGS = -I.
CFLAGS = -Wall -Wextra -ansi -pedantic -g
LDFLAGS =
OBJS = magic_board.o matrix.o
EXEC = magic_board
DOXYGEN = doxygen

.PHONY : clean doc

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) -o $(EXEC) $(LDFLAGS) 

magic_board.o : magic_square.c matrix.h
	$(CC) $(CPPFLAGS) $(CFLAGS) magic_board.c -c

matrix.o : matrix.c matrix.h
	$(CC) $(CPPFLAGS) $(CFLAGS) matrix.c -c

doc :
	$(DOXYGEN) Doxyfile
clean :
	rm $(OBJS) $(EXEC)
	rm -R doc
