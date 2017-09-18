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

CLASS = TestingFrame.class Adapter.class

all : v7.jar

TestingFrame.class: TestingFrame.java
	javac TestingFrame.java

Adaptateur.class: Adaptateur.java
	javac Adapter.java

v7.jar: $(CLASS)
	jar -cfe v7.jar TestingFrame $(CLASS)

.PHONY: all clean

clean:
	rm -f $(CLASS) *.jar