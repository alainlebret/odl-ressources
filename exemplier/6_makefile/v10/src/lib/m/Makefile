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

CC = gcc
CPPFLAGS = -Wall -Wextra -ansi -pedantic
INCLUDE_PATH = ../../../include
CFLAGS = -I$(INCLUDE_PATH) -c -g
LDFLAGS = -o

m.a : m.o
	ar crv $@ $^ 
	
m.o : m.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ $(LDFLAGS) $@
