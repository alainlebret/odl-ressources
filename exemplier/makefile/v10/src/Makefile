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
# Copyright (C) 1995-2023 Alain Lebret (alain.lebret@ensicaen.fr)
#

CC = gcc
CPPFLAGS = -Wall -Wextra -ansi -pedantic
CFLAGS = -I../include -c -g
LIB_L = $(SRC_PATH)/lib/l
LIB_M = $(SRC_PATH)/lib/m
LIB_N = $(SRC_PATH)/lib/n
LIBRARIES = $(LIB_L)/l.a $(LIB_M)/m.a $(LIB_N)/n.a
LFLAGS = -o

$(EXEC): main.o $(LIBRARIES)
	$(CC) $(LIBRARIES) $< $(LFLAGS) $(EXEC)

main.o : main.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ $(LFLAGS) $@
	