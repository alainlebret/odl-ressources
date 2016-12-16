#!/bin/sh

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
# Copyright (C) 1995-2016 Alain Lebret (alain.lebret@ensicaen.fr)
#

CPPFLAGS='-Wall -Wextra -ansi -pedantic'
MAIN='magic_board'

# Compilation of source files to object ones
gcc $CPPFLAGS -I. -c matrix.c
gcc $CPPFLAGS -I. -c $(MAIN).c

# Linking of object files and production of the executable
gcc $(MAIN).o matrix.o -o $(MAIN)

# Suppression of the object files
# rm *.o
