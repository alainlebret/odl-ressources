#!/bin/bash

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
CPPFLAGS='-I.'
CFLAGS='-Wall -Wextra -ansi -pedantic'
MAIN='magic_board'

# Compilation of source files to object ones
gcc $CPPFLAGS $CFLAGS -c matrix.c
gcc $CPPFLAGS $CFLAGS -c $(MAIN).c

# Linking of object files and production of the executable
gcc $(MAIN).o matrix.o -o $(MAIN)

# Suppression of the object files
# rm *.o
