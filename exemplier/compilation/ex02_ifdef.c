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
 * @file ex02_ifdef.c
 * @brief A Testing program to highlight the use of precompiler options. Compile without
 * and with the gcc option "-DINCLUSION" to show or not the warning messages.
 *
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @date 1995-2023
 * @version 1.0
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