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
# Copyright (C) 1995-2023 Alain Lebret (alain.lebret@ensicaen.fr)
#

echo "Precompiling step - include files insertion"
gcc -E -Wall -Wextra -ansi -pedantic ex02_include.c > ex02_include.i

echo "The precompiled file contains:"
less ex02_include.i