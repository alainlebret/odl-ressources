#
# ENSICAEN
# 6 Boulevard Maréchal Juin
# F-14050 Caen Cedex
#
# Examples from the course "Software development tools"
# Exemplier du cours "Outils de développement logiciel" (ODL)
#
# Chapter "Debugging, testing, profiling" / Chapitre "Mise au point"
#
# Copyright (C) 1995-2016 Alain Lebret (alain.lebret@ensicaen.fr)
#

CC = gcc
CPPFLAGS = -Wall -Wextra -ansi -pedantic
CFLAGS = -c -g -pg
LDFLAGS = -o
DEPS = f.h
EXEC = test_traces test_gdb test_memory test_assert test_gprof test_clock test_rand

all : $(EXEC)

%.o : %.c $(DEPS)
	$(CC) $(CFLAGS) -o $@ $< $(CPPFLAGS)
	
test_traces : test_traces.o f.o
	 $(CC) $^ $(LDFLAGS) $@
	 
test_gdb : test_gdb.o f.o
	 $(CC) $^ $(LDFLAGS) $@
	 
test_memory : test_memory.o f.o
	 $(CC) $^ $(LDFLAGS) $@
	 
test_assert : test_assert.o f.o
	 $(CC) $^ $(LDFLAGS) $@
	 
test_gprof : test_gprof.o f.o
	 $(CC) $^ $(LDFLAGS) $@

test_clock : test_clock.o f.o
	 $(CC) $^ $(LDFLAGS) $@

test_rand : test_rand.o f.o
	 $(CC) $^ $(LDFLAGS) $@

clean :
	rm -Rf *.o gmon.out gmon.txt $(EXEC) *.dSYM
