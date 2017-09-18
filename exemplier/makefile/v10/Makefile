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
MAKE=/usr/bin/make
SRC_PATH = src
LIB_L = $(SRC_PATH)/lib/l
LIB_M = $(SRC_PATH)/lib/m
LIB_N = $(SRC_PATH)/lib/n
LIBRARIES = $(LIB_L) $(LIB_M) $(LIB_N)
PROG = $(SRC_PATH)

.PHONY: all $(PROG) $(LIBRARIES)
	
all: $(PROG)
	
$(PROG) $(LIBRARIES):
	$(MAKE) --directory=$@
$(PROG): $(LIBRARIES)
$(LIB_N): $(LIB_L) $(LIB_M)