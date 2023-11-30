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
 * Copyright (C) 1995-2023 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @file bubbles.c
 * @brief A program demonstrating the bubble sort algorithm with Doxygen comments.
 *
 * The program sorts an array of random integers using the bubble sort algorithm.
 * It is designed to demonstrate different optimization levels during compilation.
 *
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @date 1995-2023
 * @version 1.0
 */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 123456

void sort_using_bubbles(uint32_t *array, size_t nbr_elements);

/**
 * @brief Main function to demonstrate bubble sort.
 *
 * Fills an array with random numbers, prints it, sorts it using bubble sort,
 * and then prints the sorted array.
 *
 * @return int The exit status.
 */
int main(void) {
    uint32_t array[SIZE];
    size_t index;

    srand((unsigned)time(NULL));

    for (index = 0; index < SIZE; index++) {
        array[index] = rand() % 1000;
    }

    for (index = 0; index < SIZE; index++) {
        printf("%" PRIu32 "%s", array[index], index == SIZE - 1 ? "\n" : " ");
    }

    sort_using_bubbles(array, SIZE);

    for (index = 0; index < SIZE; index++) {
        printf("%" PRIu32 "%s", array[index], index == SIZE - 1 ? "\n" : " ");
    }

    return 0;
}

/**
 * @brief Sorts an array using the bubble sort algorithm.
 *
 * @param array The array to be sorted.
 * @param nbr_elements The number of elements in the array.
 */
void sort_using_bubbles(uint32_t *array, size_t nbr_elements) {
    int ended_sort; /* a flag to indicate the end of sort */
    uint32_t temp; /* temporary value */
    size_t i;

    do {
        ended_sort = 1;
        for (i = 1; i < nbr_elements; i++) {
            if (array[i] < array[i - 1]) {
                temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
                ended_sort = 0;
            }
        }
    } while (!ended_sort);
}
