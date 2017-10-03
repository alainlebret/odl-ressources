/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * Handout from the course "Software development tools"
 * Exemplier du cours "Outils de développement logiciel" (ODL)
 *
 * Chapter "Working out" / Chapitre "Mise au point"
 *
 * Copyright (C) 2016 Alain Lebret (alain.lebret (at) ensicaen.fr)
 */

/**
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @version	0.0.1 – 2016-10-01
 */

/**
 * @file warning.c
 *
 * Example to highlight this kind of warning:
 * $ gcc -Wall -Wextra -ansi -pedantic warning.c
 * warning.c:31:12: warning: implicit declaration of function 'f' [-Wimplicit-function-declaration]
 *       short v = f();
 *                 ^
 * 1 warning generated.
 */

#include <stdio.h>
#include <limits.h>

int main() {
	short v = f();
	
	printf("In the main function, f returns the value : %d\n", v);
	
	return 0;
}

/** 
 * Returns the int value INT_MAX-1.
 */
int f() {
	int result = INT_MAX;

	result -= 10;
	printf("In f, result has the value : %d\n", result);
	
	return result;
}
