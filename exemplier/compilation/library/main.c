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

/*
 * Test using functions from static and shared libraries.
 *
 * Alain Lebret <alain.lebret@ensicaen.fr>
 */
#include <stdio.h>
#include <stdlib.h>
#include "bib.h"

int main(void) {
	puts("Test of my library.");

	my_first_library_function();

	my_second_library_function();

	exit(EXIT_SUCCESS);
}
