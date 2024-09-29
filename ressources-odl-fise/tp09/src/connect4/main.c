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
 * @file main.c
 * This file 
 */
#include <stdio.h>
#include <stdlib.h>

#include "connect4.h"

int main(int argc, char *argv[]) {
    int current_player;
    int winner;
    struct matrix_t m;

    /* Handle the given file */
    if (argc != 1) {
        printf("Usage: %s", argv[0]);
        return -1;
    }
    current_player = 0;
    m = alloc_matrix(6, 7);
    init_matrix(&m, DOT_KEY);
    display_matrix(&m);
    do {
        play(&m, current_player + 1);
        display_matrix(&m);
        current_player = (current_player + 1) % 2;
    } while ((winner = check_finished(m)) == 0);

    if (winner > 0) {
        printf("Player %d wins!\n", winner);
    } else {
        printf("Draw \n");
    }
    return 0;
}
