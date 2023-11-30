#
# ENSICAEN
# 6 Boulevard Maréchal Juin
# F-14050 Caen Cedex
#
# Examples from the course "Software development tools"
# Exemplier du cours "Outils de développement logiciel" (ODL)
#
# Chapter "Final product" / Chapitre "Produit final"
#
# Copyright (C) 1995-2023 Alain Lebret (alain.lebret@ensicaen.fr)
#

CC = gcc
CPPFLAGS = -I .
CFLAGS = -Wall -Wextra -ansi -pedantic
EXEC = testargs testenv
 
all : $(EXEC)

testargs : testargs.c
	 $(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@
	 
testenv : testenv.c
	 $(CC) $(CPPFLAGS) $(CFLAGS) $< -o $@
	 
clean :
	rm $(EXEC)

.PHONY: all clean

