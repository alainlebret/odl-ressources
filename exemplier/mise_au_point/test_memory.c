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
 */

/**
 * @file test_memory.c
 * 
 * Verify the memory leak problem using valgrind.
 *
 * Compile with: gcc -g -Wall -Wextra - ansi -pedantic test_memory.c -o test_memory
 *
 * Execute with: valgrind ./test_memory
 *
 * Re-execute with: valgrind --leak-check=full ./test_memory
 *
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.0 (1995)
 * @version   1.0.1 (2016)
 */
#include <stdio.h>
#include <stdlib.h>

#include "f.h"

int main(void) {
	f2(11, 2);

	exit(EXIT_SUCCESS);
}
