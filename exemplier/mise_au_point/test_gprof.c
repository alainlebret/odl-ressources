/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * Examples from the course "Software development tools"
 * Exemplier du cours "Outils de développement logiciel" (ODL)
 *
 * Chapter "Debugging, testing, profiling" / Chapitre "Mise au point"
 *
 * Copyright (C) 1995-2023 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @file test_gprof.c
 * 
 * Testing f5() and using the GNU profiler gprof.
 *
 * Compile with: gcc -pg -Wall -Wextra - ansi -pedantic test_gprof.c -o test_gprof
 *
 * Execute: ./test_gprof
 *
 * This produces a file named gmon.out
 * Re-execute with: gprof ./test_gprof > gmon.txt
 * 
 * Display profiling results: more gmon.txt
 *
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.0 (1995)
 * @version   1.0.1 (2016)
 */
#include <stdio.h>
#include <stdlib.h>
#include "f.h"

int main(void) {
	f5();

	exit(EXIT_SUCCESS);
}
