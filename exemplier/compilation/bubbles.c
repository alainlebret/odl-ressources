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
 * Copyright (C) 1995-2017 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.0
 * @date      1995-2017
 */

/**
 * @file bubbles.c
 * A testing program to highlight the optimization step (the bubble sort
 * algorithm).
 *
 * Compile using the following commands:
 * \code{.bash}
 * gcc -O0 bubbles.c -o bubbles_O0
 * gcc -O1 bubbles.c -o bubbles_O1
 * gcc -O2 bubbles.c -o bubbles_O2
 * gcc -O3 bubbles.c -o bubbles_O3
 * gcc -Os bubbles.c -o bubbles_Os
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
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

#define SIZE 12345
#define TRUE 1
#define FALSE 0

void sort_using_bubbles(int *array, int nbr_elements) {
	int i;		/* index to browse the array */
	int ended_sort;	/* a flag to indicate the end of sort */
	int temp;	/* temporary value */

	ended_sort = TRUE;

	while (!ended_sort) {
		ended_sort = FALSE;
		for (i = 1; i < nbr_elements; i++) {
			if (array[i] < array[i - 1]) {
				temp = array[i];
				array[i] = array[i - 1];
				array[i - 1] = temp;
				ended_sort = TRUE;
			}
		}
	}
}

int main(void) {
	int array[SIZE];
	int index;

	srand(time(NULL));

	for (index = 0; index < SIZE; index++) {
		array[index] = rand() % 1000;
	}

	for (index = 0; index < SIZE; index++) {
		printf("%d%s", array[index], index == SIZE - 1 ? "\n" : " ");
	}

	sort_using_bubbles(array, SIZE);

	for (index = 0; index < SIZE; index++) {
		printf("%d%s", array[index], index == SIZE - 1 ? "\n" : " ");
	}

	exit(EXIT_SUCCESS);
}
