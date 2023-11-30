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
# Copyright (C) 1995-2023 Alain Lebret (alain.lebret@ensicaen.fr)
#

echo "Compiling"
gcc -c -Wall -Wextra -ansi -pedantic bib.c
gcc -c -Wall -Wextra -ansi -pedantic main.c

echo "Creating the static library"
ar crv libbib.a bib.o

echo "Linking with the static library"
gcc -o test_static main.o -L. libbib.a
