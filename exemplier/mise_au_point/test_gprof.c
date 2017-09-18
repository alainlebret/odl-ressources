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
 * Copyright (C) 1995-2016 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.0 (1995)
 * @version   1.0.1 (2016)
 */

/**
 * @file test_gprof.c
 * 
 * Testing \em f5() and using the GNU profiler \em gprof.
 *
 * Compile with:
 * \code{.bash}
 * gcc -pg -Wall -Wextra - ansi -pedantic test_gprof.c -o test_gprof
 * \endcode
 *
 * Execute:
 * \code{.bash}
 * ./test_gprof
 * \endcode
 *
 * This produces a file named \em gmon.out
 * Re-execute with:
 * \code{.bash}
 * gprof ./test_gprof > gmon.txt
 * \endcode
 *
 * Display profiling results:
 * \code{.bash}
 * more gmon.txt
 * \endcode
 */
#include <stdio.h>
#include <stdlib.h>
#include "f.h"

int main(void) {
	f5();

	exit(EXIT_SUCCESS);
}
