/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * Examples from the course "Software development tools"
 * Exemplier du cours "Outils de développement logiciel" (ODL)
 *
 * Chapter "Debugging, testing, profiling" / Chapitre "Mise au point"
 *
 * Copyright (C) 1995-2016 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.0 (1995)
 * @version   1.0.1 (2016)
 */

/**
 * @file test_assert.c
 * 
 * Call \em f4() to test the \em assert() function.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "f.h"

int main(void) {
	int value;

	value = f4(70);
	printf("Letter: %c\n", value);

	value = f4(12);
	printf("Letter: %c\n", value);

	exit(EXIT_SUCCESS);
}
