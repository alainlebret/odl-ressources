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
# Copyright (C) 1995-2017 Alain Lebret (alain.lebret@ensicaen.fr)
#

echo "Compile with warnings, ANSI normalisation and pedantic..."
gcc -Wall -Wextra -ansi -pedantic ex01_ansi_pedantic.c