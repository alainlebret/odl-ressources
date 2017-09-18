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
 * @file testargs.c
 * 
 * Test how to pass arguments to the \em main() function.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *env[]) {
	int counter;

	/* argc should be 3 */
	if (argc != 3) {
		/* We display usage. argv[0] is the name of the program */
		printf("Usage: %s [options] <filename>\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	for (counter = 0; counter < argc; counter++) {
		printf("argv[%d] : %s\n", counter, argv[counter]);
	}

	exit(EXIT_SUCCESS);
}
