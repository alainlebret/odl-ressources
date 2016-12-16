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
 * @file test_traces.c
 * 
 * Using traces in a program.
 */
#include <stdio.h>
#include <stdlib.h>
#include "f.h"

int main(void) {
	int angle_degrees;
	double angle_radians;

	angle_degrees = 90;
	angle_radians = f3(angle_degrees);

	if (angle_radians == M_PI)
		exit(EXIT_FAILURE);

	exit(EXIT_SUCCESS);
}
