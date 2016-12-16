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
 * Copyright (C) 1995-2016 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.2 (2016-10-01)
 * @date      1995-2016
 */

/**
 * @file test04.c
 * A testing program to highlight the optimization step.
 *
 * Compile using the following commands:
 * \code{.bash}
 * gcc -O0 test04.c -o test04_O0
 * gcc -O1 test04.c -o test04_O1
 * gcc -O2 test04.c -o test04_O2
 * gcc -O3 test04.c -o test04_O3
 * gcc -Os test04.c -o test04_Os
 * \endcode
 *
 * Execution:
 * \code{.bash}
 * time ./test04_O0
 * time ./test04_O1
 * time ./test04_O2
 * time ./test04_O3
 * time ./test04_Os
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
	int i; /* index to browse the array */
	int ended_sort; /* a flag to indicate the end of sort */
	int temp; /* temporary value */

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
