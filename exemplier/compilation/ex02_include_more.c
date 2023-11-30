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
 * @file ex02_include_more.c
 * @brief A testing program to highlight the precompiling step, particularly the
 * inclusion of header files. 
 *
 * Compile using command:
 * gcc -E -Wall -Wextra -ansi -pedantic ex02_include_more.c > ex02_include_more.i
 *
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @date 1995-2023
 * @version 1.0
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
