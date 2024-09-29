/*
 * ENSICAEN
 * 6 Boulevard Marechal Juin
 * F-14050 Caen Cedex
 *
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */

/**
 * @file matrix.c
 *
 * This file contains all the functions of the matrix library.
 */
#include <stdio.h>
#include <stdlib.h>

#include "matrix.h"

struct matrix_t alloc_matrix(unsigned rows, unsigned columns) {
	struct matrix_t m;

	/* TO COMPLETE */
	
	return m;
}

void init_matrix(struct matrix_t *m, char value) {
	unsigned row;
	unsigned column;

	/* TO COMPLETE */
}

void display_matrix(struct matrix_t *m) {
	unsigned row;
	unsigned column;

	clrscr();
	
	/* TO COMPLETE */	

	printf("\n");
}

int is_valid_cell(struct matrix_t *m, unsigned row, unsigned column) {
	return row < m->rows && column < m->columns;
}
