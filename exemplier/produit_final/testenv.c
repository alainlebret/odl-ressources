/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * Examples from the course "Software development tools"
 * Exemplier du cours "Outils de développement logiciel" (ODL)
 *
 * Chapter "Final Product" / Chapitre "Produit final"
 *
 * Copyright (C) 1995-2016 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.0 (1995)
 * @version   1.0.1 (2016)
 */

/**
 * @file testenv.c
 * 
 * Test how to pass arguments to the \em main() function.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *env[]) {
	char *string;
	int counter;

	string = "";
	counter = 0;

	/* argc should be 1 */
	if (argc != 1) {
		/* We display usage. argv[0] is the name of the program file */
		printf("This program should not be called with any argument.\n");
		exit(EXIT_FAILURE);
	}

	while (string != NULL) {
		string = env[counter];
		printf("env[%d] : %s\n", counter, string);
		counter++;
	}

	exit(EXIT_SUCCESS);
}
