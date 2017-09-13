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
 * Copyright (C) 1995-2017 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.0
 * @date      1995-2017
 */

/**
 * @file bib.c
 * @details Functions needed for the example of static and shared libraries
 * construction.
 *
 * 1) Compiling with "Position independant code" (option \c -fpic):
 * \code{.bash}
 * gcc -c -Wall -Wextra -ansi -pedantic -fpic bib.c
 * \endcode
 *
 * 2a) Creating a shared library:
 * \code{.bash}
 * gcc -shared -o libbib.so bib.o
 * \endcode
 * 2b) Creating a static library:
 * \code{.bash}
 * ar crv -o libbib.a bib.o
 * \endcode
 *
 * 3a) Linking with the shared library:
 * \code{.bash}
 * gcc -Wall -Wextra -ansi -pedantic -o test main.c -lbib
 * \endcode
 * 3b) Linking with the static library:
 * \code{.bash}
 * gcc -Wall -Wextra -ansi -pedantic -o test main.c bib.a
 * \endcode
 *
 * 4) Making the shared library available:
 * \code{.bash}
 * export LD_LIBRARY_PATH=<PATH OF YOUR SHARED LIBRARY>:$LD_LIBRARY_PATH
 * \endcode
 *
 */
#include <stdio.h>

void my_first_library_function(void) {
	puts("I am the first library function");
}

void my_second_library_function(void) {
	puts("I am the second library function");
}
