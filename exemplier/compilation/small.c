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
 * @file small.c
 *
 * A testing program to highlight the optimizing step. Compile using following
 * commands:
 * \code{.bash}
 * gcc -O0 small.c -o small_O0
 * gcc -O1 small.c -o small_O1
 * gcc -O2 small.c -o small_O2
 * gcc -O3 small.c -o small_O3
 * gcc -Os small.c -o small_Os
 * \endcode
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define AUSTRIA_VOTING_AGE 16
#define BRAZIL_VOTING_AGE 16
#define FRANCE_VOTING_AGE 18
#define JAPAN_VOTING_AGE 20

int main(void) {
	int voting_age;

	voting_age = FRANCE_VOTING_AGE;
	printf("Voting age in France is: %d\n", voting_age);

	exit(EXIT_SUCCESS);
}
