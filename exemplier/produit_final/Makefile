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
# Copyright (C) 1995-2016 Alain Lebret (alain.lebret@ensicaen.fr)
#

CC = gcc
CPPFLAGS = -Wall -Wextra -ansi -pedantic
LDFLAGS = -o
EXEC = testargs testenv
 
all : $(EXEC)

testargs : testargs.c
	 $(CC) $(CPPFLAGS) $^ $(LDFLAGS) $@
	 
testenv : testenv.c
	 $(CC) $(CPPFLAGS) $^ $(LDFLAGS) $@
	 
clean :
	rm $(EXEC)
