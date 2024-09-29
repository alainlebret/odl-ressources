/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin 
 * F-14050 Caen Cedex 
 * 
 * This file is owned by ENSICAEN.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

/**
 * @author Jean Saigne <jean.saigne@ecole.ensicaen.fr>
 * @version 1.0 2018/09/15
 */

/**
 * @file polynomial.c
 * 
 * Prints the solution of (x - 1)/x + (1/2)(x-1)^2/x^2 
 *                  + (1/3)(x-1)^3/x^3 
 *                  + (1/4)(x-1)^4/x^4 
 *                  + (1/5)(x-1)^5/x^5
 * for a given x.
 */
#include <stdio.h>
#include <math.h>

int main() {
	float u;
	float x;
	float y;

	u = 0;
	y = 0;
	 
	printf("Enter a value for x: ");
	scanf("%f", &x);

	u = x - 1 / x;
	y = u + pow((u/2), 2.) + pow((u/3), 3.) + pow((u/4), 4.) + pow((u/5), 5.);
	
	printf("\nx = %f and y = %f\n", x, y);
	
	return 0;
}
