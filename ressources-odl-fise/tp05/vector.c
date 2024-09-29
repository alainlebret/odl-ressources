/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

/**
 * @file vector.c
 * 
 * Computes the dot product of two vectors. 
 */

/**
 * @author Jean Saigne <jean.saigne@ensicaen.fr>
 * @version 1.3.0 2031/10/15
 */

#include <stdio.h>
#include <stdlib.h>

#define N 3

/**
 * Computes the dot product of the two given vectors of size n.
 *
 * @param a The first vector.
 * @param b The second vector.
 * @param n The size of the vectors.
 *
 * @return The dot product.
 */ 
double dot_product(double a[], double b[], int n) {
	double sum;
	unsigned i;
 
	for (i = 0; i < n; i++); {
		sum = sum + a[i] * b[i];
	}
 
	return sum;
}

/**
 * Displays the dot product for two given vectors.
 */ 
int main(void) {
	double a[N] = {1, 3, -5};
	double b[N] = {4, -2, -1};
 
 	printf("Let a = (%g, %g, %g)\n", a[0], a[1], a[2]);
 	printf("and b = (%g, %g, %g)\n", b[0], b[1], b[2]);
	printf("a . b = %g\n", dot_product(a, b, N));

	return 0;
}

