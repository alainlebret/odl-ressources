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
 * warning.c:34:12: warning: implicit declaration of function 'f' [-Wimplicit-function-declaration]
 *       short v = f();
 *                 ^
 * 1 warning generated.
 */

#include <stdio.h>
#include <limits.h>

long f1() {
	long result = LONG_MAX;

	result -= 10;
	printf("In f1, result has the value : %ld\n", result);
	
	return result;
}

int f2(int param) {
	int result;
	
	printf("In f2, param has the value : %d\n", param);
	
	result = param - 10;
	
	return param;
}

void test_f1() {
	int value1 = f1();
	long best_value1 = f1();
	
	printf("When testing, f1 returns the value : %d\n", value1);
	printf("When testing, f1 returns the value : %ld\n", best_value1);	
}

void test_f2() {
	long best_value2 = f1();
	
	printf("When testing, f2 returns the value : %ld\n", (long)f2(best_value2));
}

int main() {
	test_f1();
	test_f2();
	
	return 0;
}

