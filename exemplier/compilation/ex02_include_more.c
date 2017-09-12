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
 * @version   1.0
 * @date      1995-2017
 */

/**
 * @file ex02_include_more.c
 *
 * A testing program to highlight the precompiling step, particularly the
 * inclusion of \em header files. Compile using command:
 * \code{.bash}
 * gcc -E -Wall -Wextra -ansi -pedantic ex02_include_more.c > ex02_include_more.i
 * \endcode
 */

#include <stdio.h>  /* for printf */
#include <stdlib.h> /* for exit() and EXIT_SUCCESS */
#include <math.h>
#include "ex02_include.h"

int main(void) {
	int voting_age;

	voting_age = FRANCE_VOTING_AGE;
	printf("Voting age in France is: %d\n", voting_age);

	exit(EXIT_SUCCESS);
}
