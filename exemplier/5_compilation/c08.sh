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
gcc -O0 test03.c -o test03_O0
gcc -O1 test03.c -o test03_O1
gcc -O2 test03.c -o test03_O2
gcc -O3 test03.c -o test03_O3
gcc -Os test03.c -o test03_Os

echo "Testing optimization options for a larger program"
gcc -O0 test04.c -o test04_O0
gcc -O1 test04.c -o test04_O1
gcc -O2 test04.c -o test04_O2
gcc -O3 test04.c -o test04_O3
gcc -Os test04.c -o test04_Os

ls -l
echo "test03_O0"
time ./test03_O0
read a
echo "test03_O1"
time ./test03_O1
read a
echo "test03_O2"
time ./test03_O2
read a
echo "test03_O3"
time ./test03_O3
read a
echo "test03_Os"
time ./test03_Os
read a
echo "test04_O0"
time ./test04_O0
read a
echo "test04_O1"
time ./test04_O1
read a
echo "test04_O2"
time ./test04_O2
read a
echo "test04_O3"
time ./test04_O3
read a
echo "test04_Os"
time ./test04_Os
read a

echo "Suppressing unwanted files..."
rm test03_O0 test03_O1 test03_O2 test03_O3 test03_Os test04_O0 test04_O1 test04_O2 test04_O3 test04_Os a.out *.a *.s *.i *.o *.txt
