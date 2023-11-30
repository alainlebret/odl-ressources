/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * Examples from the course "Software development tools"
 * Exemplier du cours "Outils de développement logiciel" (ODL)
 *
 * Chapter "Edition" / Chapitre "Édition"
 *
 * Copyright (C) 1995-2017 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @file knight.c
 *
 * Code based on the Rosetta code of the knight's tour.
 *
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.0
 * @date      2017
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define DEFAULT_BOARD_SIZE 8
#define EMPTY 0 
#define OCCUPIED 255
#define ESCAPE_SEQ "\x1B["

/* Knight's move deltas */
static const int dx[] = { -2, -2, -1, 1, 2,  2,  1, -1 };
static const int dy[] = { -1,  1,  2, 2, 1, -1, -2, -2 };

/* Function prototypes */
void init_board(int width, int height, cell **a, cell **b);
int walk_board(int width, int height, int x, int y, cell **b);
int solve(int width, int height);
 
/**
 * Initializes the chess board
 * \param b the chess board
 * \param a the chess board with 2 rows padded at each side 
 */
void init_board(int width, int height, cell **a, cell **b) {
	int i, j, k, x, y, p = width + 4, q = height + 4;
	a[0] = (cell*)(a + q);
	b[0] = a[0] + 2;
 
	for (i = 1; i < q; i++) {
		a[i] = a[i-1] + p;
		b[i] = a[i] + 2;
	}
 
	memset(a[0], OCCUPIED, p * q);
	for (i = 0; i < height; i++) {
		for (j = 0; j < width; j++) {
			for (k = 0; k < 8; k++) {
				x = j + dx[k], y = i + dy[k];
				if (b[i+2][j] == OCCUPIED) b[i+2][j] = EMPTY;
				b[i+2][j] += x >= 0 && x < width && y >= 0 && y < height;
			}
		}
	}
}
 
/**
 *
 */
int walk_board(int width, int height, int x, int y, cell **b) {
	int i;
	int nx;
	int ny;
	int least;
	int steps;

	steps = 0;
	printf(E"H"E"J"E"%d;%dH"E"32m[]"E"m", y + 1, 1 + 2 * x);
 
	for (;;) {
		/* occupy cell */
		b[y][x] = OCCUPIED;
 
		/* reduce all neighbors' neighbor count */
		for (i = 0; i < 8; i++)
			b[ y + dy[i] ][ x + dx[i] ]--;
 
		/* find neighbor with lowest neighbor count */
		least = OCCUPIED;
		for (i = 0; i < 8; i++) {
			if (b[ y + dy[i] ][ x + dx[i] ] < least) {
				nx = x + dx[i];
				ny = y + dy[i];
				least = b[ny][nx];
			}
		}
 
		if (least > 7) {
			printf(E"%dH", height + 2);
			return steps == width * height - 1;
		}
 
		if (steps++) printf(E"%d;%dH[]", y + 1, 1 + 2 * x);
		x = nx, y = ny;
		printf(E"%d;%dH"E"31m[]"E"m", y + 1, 1 + 2 * x);
		fflush(stdout);
		usleep(120000);
	}
}
 
int solve(int width, int height) {
	int x = 0, y = 0;
	cell **a, **b;
	a = malloc((width + 4) * (height + 4) + sizeof(cell*) * (height + 4));
	b = malloc((height + 4) * sizeof(cell*));
 
 	if (a == NULL || b == NULL) {
		perror("Unable to allocate memory properly!");
		exit(EXIT_FAILURE);
 	}
	
	for (;;) {
		init_board(width, height, a, b);
		if (walk_board(width, height, x, y, b + 2)) {
			printf("Success!\n");
/*			return 1;*/
		}
		if (++x >= width) x = 0, y++;
		if (y >= height) {
			printf("Failed to find a solution\n");
			return 0;
		}
		printf("Any key to try next start position");
		getchar(); 
	}
}
 
int main(int argc, char **argv) {
	int width, height;
	
	if (argc < 2 || (width = atoi(argv[1])) <= 0) width = DEFAULT_BOARD_SIZE;
	if (argc < 3 || (height = atoi(argv[2])) <= 0) height = width;
	solve(width, height);
 
	return 0;
}
