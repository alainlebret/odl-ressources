/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * Examples from the course "Software development tools"
 * Exemplier du cours "Outils de développement logiciel" (ODL)
 *
 * Chapter "Compilation" / Chapitre "Compilation"
 *
 * Copyright (C) 1995-2023 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @file bib.c
 * @details Functions needed for the example of static and shared libraries
 * construction.
 *
 * 1) Compiling with "Position independant code" (option -fPIC):
 * gcc -c -Wall -Wextra -ansi -pedantic -fPIC bib.c
 *
 * 2a) Creating a shared library:
 * gcc -shared -o libbib.so bib.o
 * 2b) Creating a static library:
 * ar crv -o libbib.a bib.o
 *
 * 3a) Linking with the shared library:
 * gcc -Wall -Wextra -ansi -pedantic -o test main.c -lbib
 * 3b) Linking with the static library:
 * gcc -Wall -Wextra -ansi -pedantic -o test main.c bib.a
 *
 * 4) Making the shared library available:
 * export LD_LIBRARY_PATH=<PATH OF YOUR SHARED LIBRARY>:$LD_LIBRARY_PATH
 *
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @date 1995-2023
 * @version 1.0
 */

#include <stdio.h>

void my_first_library_function(void) {
	puts("I am the first library function");
}

void my_second_library_function(void) {
	puts("I am the second library function");
}
