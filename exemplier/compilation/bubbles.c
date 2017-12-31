/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * Examples from the course "Software development tools"
 * Exemplier du cours "Outils de développement logiciel" (ODL)
 *
 * Chapter "Compilation" / Chapitre "Compilation"
 *
 * Copyright (C) 1995-2018 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.0
 * @date      1995-2018
 */

/**
 * @file bubbles.c
 * A testing program to highlight the optimization step (the bubble sort
 * algorithm).
 *
 * Compile using the following commands:
 * \code{.bash}
 * gcc -Wall -Wextra -pedantic -std=c99 -O0 bubbles.c -o bubbles_O0
 * gcc -Wall -Wextra -pedantic -std=c99 -O1 bubbles.c -o bubbles_O1
 * gcc -Wall -Wextra -pedantic -std=c99 -O2 bubbles.c -o bubbles_O2
 * gcc -Wall -Wextra -pedantic -std=c99 -O3 bubbles.c -o bubbles_O3
 * gcc -Wall -Wextra -pedantic -std=c99 -Os bubbles.c -o bubbles_Os
 * \endcode
 *
 * Execution:
 * \code{.bash}
 * time ./bubbles_O0
 * time ./bubbles_O1
 * time ./bubbles_O2
 * time ./bubbles_O3
 * time ./bubbles_Os
 * \endcode
 *
 */
#include <stdint.h>   /* C99 */
#include <inttypes.h> /* C99 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>  /* C99 */

#define SIZE 123456
#define TRUE 1
#define FALSE 0

void sort_using_bubbles(uint32_t *array, uint32_t nbr_elements) {
	bool ended_sort;	/* a flag to indicate the end of sort */
	uint32_t temp;	    /* temporary value */

	ended_sort = true;

	while (!ended_sort) {
		ended_sort = false;
		for (uint32_t  i = 1; i < nbr_elements; i++) {
			if (array[i] < array[i - 1]) {
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				ended_sort = true;
			}
		}
	}
}

int main(void) {
	uint32_t array[SIZE];
	uint32_t index;

	srand(time(NULL));

	for (index = 0; index < SIZE; index++) {
		array[index] = rand() % 1000;
	}

	for (index = 0; index < SIZE; index++) {
		printf("%" PRId32 "%s", array[index], index == SIZE - 1 ? "\n" : " ");
	}

	sort_using_bubbles(array, SIZE);

	for (index = 0; index < SIZE; index++) {
		printf("%" PRId32 "%s", array[index], index == SIZE - 1 ? "\n" : " ");
	}

	exit(EXIT_SUCCESS);
}
