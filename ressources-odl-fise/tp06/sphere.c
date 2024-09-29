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
 * @file sphere.c
 *
 * A program to compute the surface area and the volume of a sphere.
 */
#include <stdio.h>

double PI = 3.14159265359;

/**
 * Gets the radius of the sphere by asking the user.
 * @return The radius of the sphere.
 */
double get_radius() {
	double radius;
	
	printf("Enter radius of the sphere (in cm) : ");
	scanf("%lf", &radius);

	return radius;
}

/**
 * Displays the given radius, surface area and volume of a sphere.
 * 
 * @param radius The radius of the sphere.
 * @param surface_area The surface area of the sphere.
 * @param volume The volume of the sphere.
 */
void show_results(double radius, double surface_area, double volume) {
	printf("The radius is: %.2f cm\n", radius);
	printf("The surface area is: %.2f cm^2\n", surface_area);
	printf("The volume is: %.2f cm^3\n", volume);
}

/** 
 * Computes the surface area and the volume of a sphere.
 */
int main(void) {
	double radius; 
	double surface_area;
	double volume;

	printf("This program computes surface area and volume of a sphere.\n");
	
	radius = get_radius();
	volume = surface_area * radius / 3.0;
	surface_area = 4.0 * PI * radius * radius;
	
	show_results(radius, surface_area, volume);

	return 0;
}

