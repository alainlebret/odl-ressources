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
CFLAGS = -I./include -c -g
LDFLAGS = -o
SRC_PATH = ./src
DEPS = l/l.h m/m.h
LPATH = $(SRC_PATH)/l
MPATH = $(SRC_PATH)/m
OBJS =  $(LPATH)/l.o $(MPATH)/m.o $(SRC_PATH)/main.o 
EXEC = ./bin/main

main : $(OBJS)
	mkdir bin
	$(CC) $(OBJS) $(LDFLAGS) $(EXEC)

main.o : $(SRC_PATH)/main.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ $(LDFLAGS) $(SRC_PATH)/$@
	
l.o : $(LPATH)/l.c $(DEPS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ $(LDFLAGS) $(LPATH)/$@

m.o : $(MPATH)/m.c $(DEPS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ $(LDFLAGS) $(MPATH)/$@

.PHONY : clean

clean : 
	rm $(OBJS) $(EXEC)
	rmdir bin
