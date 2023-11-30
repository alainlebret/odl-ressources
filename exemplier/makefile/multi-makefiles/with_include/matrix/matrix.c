/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * Handout from the course "Software development tools"
 * Exemplier du cours "Outils de développement logiciel" (ODL)
 *
 * Chapter "The make command" / Chapitre "Commande make"
 *
 * Copyright (C) 2016 Alain Lebret (alain.lebret (at) ensicaen.fr)
 */

/**
 * @file matrix.c
 *
 * Example from a laboratory exercise. This file contains definitions of
 * some matrix manipulations.
 *
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @version	0.0.1 – 2016-10-01
 */

#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

void initialize(int matrix[NMAX][NMAX], int size) {
	int x;
	int y;

	for (y = 0; y < size; y++) {
		for (x = 0; x < size; x++) {
			matrix[y][x] = 0;
		}
	}
	matrix[size / 2 + 1][size / 2] = 1;
}

void fill(int matrix[NMAX][NMAX], int size) {
	int i;
	int x;
	int y;

	y = size / 2 + 1;
	x = size / 2;

	for (i = 2; i <= size * size; i++) {
		x = (x + 1) % size;
		y = (y + 1) % size;

		if (matrix[y][x] != 0) {
			x = (x + (size - 1)) % size;
			y = (y + 1) % size;
		}

		matrix[y][x] = i;
	}
}

void display(int matrix[NMAX][NMAX], int size) {
	int x;
	int y;

	for (y = 0; y < size; y++) {
		for (x = 0; x < size; x++) {
			printf("\t%d", matrix[y][x]);
		}
		printf("\n");
	}
}
