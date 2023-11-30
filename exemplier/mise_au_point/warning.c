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
 * Copyright (C) 2023 Alain Lebret (alain.lebret (at) ensicaen.fr)
 */

/**
 * @file warning.c
 *
 * An example to highlight some warnings using splint (http://www.splint.org) :
 * $ splint warning.c
 * Splint 3.1.2 --- 15 Apr 2016
 * warning.c: (in function test_f1)
 * warning.c:53:15: Variable value1 initialized to type long int, expects int:
 *                   f1()
 *  To ignore type qualifiers in type comparisons use +ignorequals.
 * warning.c: (in function test_f2)
 * warning.c:63:64: Function f2 expects arg 1 to be int gets long int: best_value2
 * warning.c:33:6: Function exported but not used outside warning: f1
 * A declaration is exported, but not used outside this module. Declaration can
 * use static qualifier. (Use -exportlocal to inhibit warning)
 * warning.c:40:1: Definition of f1
 * warning.c:42:5: Function exported but not used outside warning: f2
 * warning.c:50:1: Definition of f2
 * warning.c:52:6: Function exported but not used outside warning: test_f1
 * warning.c:58:1: Definition of test_f1
 * warning.c:60:6: Function exported but not used outside warning: test_f2
 * warning.c:64:1: Definition of test_f2
 * 
 * Finished checking --- 6 code warnings
 *
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @version	0.0.1 – 2016-10-01
 */

#include <stdio.h>
#include <limits.h>

long f1() {
	long result;
	
	result = LONG_MAX;

	result -= 10;
	printf("In f1, result has the value: %ld\n", result);
	
	return result;
}

int f2(int param) {
	int result;
	
	printf("In f2, param has the value: %d\n", param);
	
	result = param - 10;
	
	return param;
}

void test_f1() {
	int value1;
	long best_value1;
	
	value1 = f1();
	best_value1 = f1();
	printf("When testing, f1 returns the value: %d\n", value1);
	printf("When testing, f1 returns the value: %ld\n", best_value1);	
}

void test_f2() {
	long best_value2;
	
	best_value2 = f1();
	printf("When testing, f2 returns the value: %ld\n", (long)f2(best_value2));
}

int main() {
	test_f1();
	test_f2();
	
	return 0;
}
