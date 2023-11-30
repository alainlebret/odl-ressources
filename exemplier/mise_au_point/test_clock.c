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
 * Copyright (C) 1995-2023 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @file test_clock.c
 * 
 * Measure time using f5().
 *
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.0 (1995)
 * @version   1.0.1 (2016)
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "f.h"

int main(void) {
	clock_t begin_time, end_time;

	begin_time = clock();
	f5();
	end_time = clock();
	printf("Duration of f5: %f seconds.\n",
			 (float) (end_time - begin_time) / CLOCKS_PER_SEC);

	exit(EXIT_SUCCESS);
}
