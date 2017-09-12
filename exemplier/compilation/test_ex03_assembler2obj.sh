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

echo "Assembling step (produce an object code)"
gcc -c ex03_assembler.s

echo "The assembled file contains (using octal dump):"
od -x ex03_assembler.o > ex03_assembler.o.txt
less ex03_assembler.o.txt