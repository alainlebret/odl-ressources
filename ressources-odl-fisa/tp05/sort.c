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
 * @version 1.0 2018/10/06
 */

/**
 * @file sort.c
 *
 * A program to sort an array of integer values.
 */
#include <stdio.h>

/**
 * Displays the integers of the given array.
 * 
 * @param values An array of integers.
 * @param n The size of the given array.
 */
void display_array(int values[], int n) {
	int i;
	
	for (i = 0; i < n - 1; i++) {
		printf("%d, ", values[i]);
	} 
	printf("%d\n", values[n-1]);
}

/**
 * Sorts an array of n int values and returns the number of operations used.
 */
int sort(int values[], int size) {
	int a_value;
	int count;
	int i;
	int j;

	for (i = 1; i < size; i++) {
		a_value = values[i];
		j = i - 1;
		while ((j > 0) && (values[j] > a_value)) {
			values[j + 1] = values[j];
			j--;
			count++;
		}
		values[j + 1] = a_value;
	}

	return count;
}

/* 
 * Sorts an array of int values.
 */
int main(void) {
	int values[] = { 12, 1, -1, 32, 256, 15, 5, 270, 45, 75, 14, 255, 0, 4096}; 
	int count;
	
	printf("This program sorts an array of integer values.\n");
	printf("Unsorted values are:\n");
	display_array(values, 14);
	
	count = sort(values, 14);
	
	printf("Sorted values are:\n");
	display_array(values, 14);
	printf("\ndone in %d operations\n", count);

	return 0;
}
