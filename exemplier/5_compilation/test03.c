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
 * Copyright (C) 1995-2016 Alain Lebret (alain.lebret@ensicaen.fr)
 */


/**
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.2 (2016-10-01)
 * @date      1995-2016
 */

/**
 * @file test03.c
 *
 * A testing program to highlight:
 * 1) The precompiling step, particularly the inclusion of \em header files.
 * Compile using command:
 * \code{.bash}
 * gcc -E -Wall -Wextra -ansi -pedantic test03.c > test03.i
 * \endcode
 * 2) The optimizing step. Compile using following commands:
 * \code{.bash}
 * gcc -O0 test03.c -o test03_O0
 * gcc -O1 test03.c -o test03_O1
 * gcc -O2 test03.c -o test03_O2
 * gcc -O3 test03.c -o test03_O3
 * gcc -Os test03.c -o test03_Os
 * \endcode
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "test03.h"

int main(void) {
	int voting_age;

	voting_age = FRANCE_VOTING_AGE;
	printf("Voting age in France is: %d\n", voting_age);

	exit(EXIT_SUCCESS);
}
