#!/bin/sh

#
# ENSICAEN
# 6 Boulevard Maréchal Juin
# F-14050 Caen Cedex
#
# Examples from the course "Software development tools"
# Exemplier du cours "Outils de développement logiciel" (ODL)
#
# Chapter "Compilation" / Chapitre "Compilation"
#
# Copyright (C) 1995-2016 Alain Lebret (alain.lebret@ensicaen.fr)
#

echo "Testing optimization options for a tiny program"
gcc -O0 small.c -o small_O0
gcc -O1 small.c -o small_O1
gcc -O2 small.c -o small_O2
gcc -O3 small.c -o small_O3
gcc -Os small.c -o small_Os

echo "Testing optimization options for a larger program"
gcc -O0 bubbles.c -o bubbles_O0
gcc -O1 bubbles.c -o bubbles_O1
gcc -O2 bubbles.c -o bubbles_O2
gcc -O3 bubbles.c -o bubbles_O3
gcc -Os bubbles.c -o bubbles_Os

ls -l
echo "small_O0"
time ./small_O0
read a
echo "small_O1"
time ./small_O1
read a
echo "small_O2"
time ./small_O2
read a
echo "small_O3"
time ./small_O3
read a
echo "small_Os"
time ./small_Os
read a
echo "bubbles_O0"
time ./bubbles_O0
read a
echo "bubbles_O1"
time ./bubbles_O1
read a
echo "bubbles_O2"
time ./bubbles_O2
read a
echo "bubbles_O3"
time ./bubbles_O3
read a
echo "bubbles_Os"
time ./bubbles_Os
read a

echo "Suppressing unwanted files..."
rm small_O0 small_O1 small_O2 small_O3 small_Os bubbles_O0 bubbles_O1 bubbles_O2 bubbles_O3 bubbles_Os a.out *.a *.s *.i *.o *.txt
