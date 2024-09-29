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
 * @file mean_angle.c
 *
 * A program to compute the mean angle of an angle set.
 */
#include <math.h>
#include <stdio.h>
 
/**
 * Computes the mean angle of the given angle array.
 *
 * @param angles The array of angles.
 * @param size The size of the array.
 */
double mean_angle(double angles[], int size) {
	double x_part;
	double y_part;
	int i;
 
 	x_part = 0;
	y_part = 0;
	
	for (i = 1; i <= size; i++) {
		x_part += cos(angles[i] * M_PI / 180);
		y_part += sin(angles[i] * M_PI / 180);
	}
 
	return atan2(x_part / size, y_part / size) * 180 / M_PI;
}
 
/* 
 * Computes mean angles from multiple angle sets.
 */
int main (void) {
	double angle_set1[] = { 350, 10 };
	double angle_set2[] = { 90, 180, 270, 360 };
	double angle_set3[] = { 10, 20, 30 };
	double angle_set4[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
 
	printf("\nMean angle for 1st set: %.2f degrees", mean_angle(angle_set1, 2));
	printf("\nMean angle for 2nd set: %.2f degrees", mean_angle(angle_set2, 4));
	printf("\nMean angle for 3rd set: %.2f degrees", mean_angle(angle_set3, 3));
	printf("\nMean angle for 4th set: %.2f degrees\n", mean_angle(angle_set4, 10));

	return 0;
}
