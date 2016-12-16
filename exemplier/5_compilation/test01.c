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
 * @version   1.2
 * @date      1995-2016
 */

/**
 * @file test01.c
 *
 * A Testing program to highlight the use of precompiler options: \c -Wall,
 * \c -Wextra, \c -ansi and \c -pedantic.
 * Compile without or with the gcc option "-D INCLUSION" to show or not the
 * warning messages.
 */

#ifdef INCLUSION
#include <stdio.h>
#include <stdlib.h>
#endif

int main(void) {
	int voting_age;

	voting_age = 18;
	printf("Voting age in France is: %d\n", voting_age);

	exit(EXIT_SUCCESS);
}