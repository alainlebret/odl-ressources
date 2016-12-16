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
 * @file f.c
 *
 * Examples to highlight using of the debugger, profiler, etc.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#include "f.h"

/** 
 * Count from 0 to upperBound-1 with an increment of 2.
 * @param upperBound The upper bound value
 */
void f1(int upperBound) {
	int counter;
	int jumps = 0;

	for (counter = 0; counter < upperBound; counter += 2) {
		jumps++;
	}
}

/**
 * Implementation of a memory leak when trying to allocate n integers in memory
 * without free.
 * @param n Size of the memory allocation
 * @param x Integer to put at the head of the allocated memory
 * @return CONSTANT (23) if the first integer within the allocated memory is
 * equal to 3, else return UNDEFINED (-1)
 */
int f2(int n, int x) {
	int *tab = (int *) malloc(n * sizeof(int));

	tab[0] = x;
	if (tab[0] == 3) {
		return CONSTANT;
	}

	return UNDEFINED;
}

/** 
 * Convert degrees to radians.
 * @param angle_degrees An angle in degrees
 * @return The angle in radians
 */
double f3(int angle_degres) {
	double angle_radians = M_PI * angle_degres / 180;

#ifdef DEBUG
	fprintf(stderr, "--- Ceci est une trace ---\n");
	fprintf(stderr, "Angle degrés  = %d\n", angle_degres);
	fprintf(stderr, "Angle radians = %f\n", angle_radians);
	fprintf(stderr, "--- Fin de la trace ---\n");
#endif

	return angle_radians;
}

/** 
 * Add 32 to the integer and return the result.
 *
 * @param value An integer between 65 and 90
 * @return The value of the integer + 32
 */
int f4(int value) {
	assert(value >= 65 && value <= 90);

	return (value + 32);
}

/** Perform f1, f2, f3 et f4 'ITERATIONS' times */
void f5() {
	int i = ITERATIONS;

	while (i--) {
		f1(2);
		f2(5, 3);
		f3(90);
		f4(69);
	}
}
