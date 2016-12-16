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
 * @file test_rand.c
 * 
 * Testing \em f4() with some random values.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "f.h"

/**
 * Test of f4() with some values between \c min and \c max.
 */
void test(int min, int max) {
	int value;
	int down_counter;

	down_counter = max - min;

	srand(time(0));

	while (down_counter--) {
		value = min + (int) ((max - min) * (double) rand() / RAND_MAX);
		printf("Before: %c | After: %c\n", value, f4(value));
	}
}

int main(void) {
	test(65, 91);

	exit(EXIT_SUCCESS);
}
