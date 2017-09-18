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
# Copyright (C) 1995-2017 Alain Lebret (alain.lebret@ensicaen.fr)
#

CC = gcc
CPPFLAGS = -Wall -Wextra -ansi -pedantic
CFLAGS = -I./include -c -g
LDFLAGS = -o
SRC_PATH = ./src
LPATH = $(SRC_PATH)/l
MPATH = $(SRC_PATH)/m
DEPS = l/l.h m/m.h
OBJS =  $(LPATH)/l.o $(MPATH)/m.o $(SRC_PATH)/main.o 
EXEC = ./bin/main

main : $(OBJS)
	mkdir bin
	$(CC) $(OBJS) $(LDFLAGS) $(EXEC)

main.o : $(SRC_PATH)/main.c
	$(CC) $(CPPFLAGS) $(CFLAGS) $(SRC_PATH)/main.c $(LDFLAGS) $(SRC_PATH)/main.o
	
l.o : $(LPATH)/l.c $(DEPS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(MPATH)/l.c $(LDFLAGS) $(LPATH)/l.o

m.o : $(MPATH)/m.c $(DEPS)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(MPATH)/m.c $(LDFLAGS) $(MPATH)/m.o

.PHONY : clean

clean : 
	rm $(OBJS) $(EXEC)
	rmdir bin
