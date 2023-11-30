/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * Examples from the course "Software development tools"
 * Exemplier du cours "Outils de développement logiciel" (ODL)
 *
 * Chapter "The make command" / Chapitre "Commande make"
 *
 * Copyright (C) 1995-2023 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @file magic_board.c

 * Example from a labory exercise. This file only contains a main()
 * function. Other functions have been moved to matrix.c and their
 * prototypes to matrix.h.
 *
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.0
 * @date      2016
 */

#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

int main(void) {
	int matrix[NMAX][NMAX];

	printf("Jeu du carré magique\n");
	initialize(matrix, NMAX);
	fill(matrix, NMAX);
	display(matrix, NMAX);

	return 0;
}
