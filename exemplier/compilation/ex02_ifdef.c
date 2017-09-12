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
 * @file ex02_ifdef.c
 *
 * A Testing program to highlight the use of precompiler options. Compile without
 * and with the gcc option "-DINCLUSION" to show or not the warning messages.
 */

#ifdef INCLUSION
#include <stdio.h>  /* for printf */
#include <stdlib.h> /* for exit() and EXIT_SUCCESS */
#endif

int main(void) {
	int voting_age;

	voting_age = 18; /* Not valid in Japan */
	printf("Voting age in France is: %d\n", voting_age);

	exit(EXIT_SUCCESS);
}