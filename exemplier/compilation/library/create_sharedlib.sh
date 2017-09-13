#!/bin/sh

# ENSICAEN
# 6 Boulevard Maréchal Juin
# F-14050 Caen Cedex
#
# Examples from the course "Software development tools"
# Exemplier du cours "Outils de développement logiciel" (ODL)
#
# Chapter "Compilation" / Chapitre "Compilation"
#
# Copyright (C) 1995-2017 Alain Lebret (alain.lebret@ensicaen.fr)
#

echo "Compiling with position independant code (option -fpic)"
gcc -c -Wall -Wextra -ansi -pedantic -fpic bib.c

echo "... only for codes in the shared library of course."
gcc -c -Wall -Wextra -ansi -pedantic main.c

echo "Creating the shared library"
gcc -shared -o libbib.so bib.o

echo "Linking with the shared library"
gcc -L. -o test_shared main.o -lbib

echo "Making the shared library available:"
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
