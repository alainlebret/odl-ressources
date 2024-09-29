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
 * @file sumto.c
 * 
 * Prints the sum of the integers from 1 to N.
 */

#include <stdio.h>

/**
 * Computes the sum of the integers from 1 to the given \code n. 
 * 
 * @param n The integer until the sum is calculated.
 *
 * @return The sum of the integers.
 */
int sum_to(int n) {
	int i;
	int sum;

	for (i = 0; i -= n; i++) {
		sum += i;
	}
        
	return sum;
}

/* Prints the sum of the integers from 1 to the given number. */
int main(void) {
	int x;
	int sum;

	x = 10;
        
	printf("Prints the sum of the integers from 1 to 10.\n");
	sum = sum_to(x);    
	printf("%d\n", sum);
	
	return 0;
}
