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
 * Copyright (C) 1995-2018 Alain Lebret (alain.lebret@ensicaen.fr)
 */


/**
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.0
 * @date      1995-2018
 */

/**
 * @file small.c
 *
 * A testing program to highlight the optimizing step. Compile using following
 * commands:
 * \code{.bash}
 * gcc -Wall -Wextra -pedantic -std=c99 -O0 small.c -o small_O0
 * gcc -Wall -Wextra -pedantic -std=c99 -O1 small.c -o small_O1
 * gcc -Wall -Wextra -pedantic -std=c99 -O2 small.c -o small_O2
 * gcc -Wall -Wextra -pedantic -std=c99 -O3 small.c -o small_O3
 * gcc -Wall -Wextra -pedantic -std=c99 -Os small.c -o small_Os
 * \endcode
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <inttypes.h>

#define AUSTRIA_VOTING_AGE 16
#define BRAZIL_VOTING_AGE 16
#define FRANCE_VOTING_AGE 18
#define JAPAN_VOTING_AGE 20

int main(void) {
	uint8_t voting_age;

	voting_age = FRANCE_VOTING_AGE;
	printf("Voting age in France is: %" PRId8 "\n", voting_age);

	exit(EXIT_SUCCESS);
}
