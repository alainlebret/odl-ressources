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

# 
# Specific Makefile of the project "project2"
#

# Variables
SRCDIR = src
OBJDIR = obj
DEPDIR = dep
BINDIR = bin
TESTDIR = tests
BINTESTDIR = $(BINDIR)/tests
INCDIR = include
EXEC = app2

CC = gcc
CPPFLAGS = -I$(INCDIR)
CFLAGS = -Wall -Wextra -ansi -pedantic
LDFLAGS = -Llib -lm

# Creation of "obj" and "dep" repertories if they were inexistant
$(shell mkdir -p $(OBJDIR) $(DEPDIR))

SRC =
OBJ =
DEP =
 
# Using wildcards to list source and objet files
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(SRC:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
DEP = $(OBJ:$(OBJDIR)/%.o=$(DEPDIR)/%.d)
TESTS = $(wildcard $(TESTDIR)/*.c)
TEST_BIN = $(TEST_SRC:$(TESTDIR)/%.c=$(BINDIR)/%)

# For debugging purpose
$(info SRC = $(SRC))
$(info OBJ = $(OBJ)) 
$(info DEP = $(DEP))

# Flags to manage dependances
CPPFLAGS += -MMD -MP

# Default target
all: $(BINDIR)/$(EXEC)

# Compile the application (linking)
$(BINDIR)/$(EXEC): $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

# Rule to generate object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@
	mv $(OBJDIR)/$*.d $(DEPDIR)/

# Include dependances 
-include $(DEP)

# Rule for the tests
tests: $(TESTS:$(TESTDIR)/%.c=$(BINTESTDIR)/%)

$(BINTESTDIR)/%: $(TESTDIR)/%.c $(OBJ)
	$(CC) $(CPPFLAGS) $(CFLAGS) $< $(filter-out $(OBJDIR)/main.o, $(OBJ)) -o $@ $(LDFLAGS)

# Cleaning
clean:
	rm -f $(OBJDIR)/*.o $(DEPDIR)/*.d $(BINTESTDIR)/*.d
	find . -name '.DS_Store' -type f -delete
	rmdir $(OBJDIR) $(DEPDIR)

distclean: clean
	rm -f $(BINDIR)/$(EXEC) $(BINTESTDIR)/test*

.PHONY: all clean tests
