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
 * @file year.c
 */
#include <stdio.h>

/** 
 * Prints a strange value for the current year. 
 */
int main(void) {
	int i;
	int year;
	int years[10];

	year = 2018;
	printf("The year is: %d\n", year);

	for (i = -1; i < 11; i++) {
		years[i] = 1984+i;
	}
	printf("I said, the year is: %d\n", year);
	
	return 0;
}
