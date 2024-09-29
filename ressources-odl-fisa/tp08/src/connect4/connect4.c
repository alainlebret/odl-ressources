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
 * @file connect4.c
 */

#include <stdio.h>

#include "connect4.h"

int check_horizontal(struct matrix_t board, unsigned row, unsigned column, char pawn) {
    int result;
    int lower_index;
    int upper_index;

    result = 0;

    lower_index = column - 1;
    while ((lower_index >= 0) && (board.data[row][lower_index] == pawn)) {
        lower_index--;
    }
    lower_index = lower_index + 1;

    upper_index = column + 1;
    while ((upper_index < board.columns) && (board.data[row][upper_index] == pawn)) {
        upper_index++;
    }
    upper_index = upper_index - 1;

    if (upper_index - lower_index + 1 >= 4) {
        result = 1;
    }
    return result;
}

int check_vertical(struct matrix_t board, unsigned row, unsigned column, char pawn) {
    int result;
    int lower_index;
    int upper_index;

    result = 0;

    lower_index = row - 1;
    while ((lower_index >= 0) && (board.data[lower_index][column] == pawn)) {
        lower_index--;
    }
    lower_index = lower_index + 1;

    upper_index = row + 1;
    while ((upper_index < board.rows) && (board.data[upper_index][column] == pawn)) {
        upper_index++;
    }
    upper_index = upper_index - 1;

    if (upper_index - lower_index + 1 >= 4) {
        result = 1;
    }
    return result;
}

int check_diagonal_ul2lr(struct matrix_t board, unsigned row, unsigned column, char pawn) {
    int result;
    int k;
    int l;
    int n;

    result = 0;

    n = 1;
    k = row - 1;
    l = column - 1;

    while (((k >= 0) && (l >= 0)) && (board.data[k][l] == pawn)) {
        k--;
        l--;
        n++;
    }

    k = row + 1;
    l = column + 1;

    while (((k < board.rows) && (l < board.columns)) && (board.data[k][l] == pawn)) {
        k++;
        l++;
        n++;
    }

    if (n >= 4) {
        result = 1;
    }
    return result;
}

int check_diagonal_ll2ur(struct matrix_t board, unsigned row, unsigned column, char pawn) {
    int result;
    int k;
    int l;
    int n;

    result = 0;
    n = 0;
    k = row;
    l = column;

    while (((k >= 0) && (l < board.columns)) && (board.data[k][l] == pawn)) {
        k--;
        l++;
        n++;
    }

    k = row;
    l = column;
    while (((k < board.rows) && (l >= 0)) && (board.data[k][l] == pawn)) {
        k++;
        l--;
        n++;
    }
    n--;

    if (n >= 4) {
        result = 1;
    }
    return result;
}

int check_winner(struct matrix_t board, unsigned row, unsigned column) {
    char pawn;

    pawn = board.data[row][column];
    if (pawn == DOT_KEY) {
        return 0;
    }
    if (check_horizontal(board, row, column, pawn) == 1) {
        return 1;
    }
    if (check_vertical(board, row, column, pawn) == 1) {
        return 1;
    }
    if (check_diagonal_ul2lr(board, row, column, pawn) == 1) {
        return 1;
    }
    if (check_diagonal_ll2ur(board, row, column, pawn) == 1) {
        return 1;
    }
    return 0;
}

int input_column(struct matrix_t board, int player) {
    int valid;
    int value;
    char c;

    value = 0;
    valid = 0;

    printf("\nPlayer %d, enter a column number: ", player);
    do {
        /* Check if the value is an integer */
        while ((scanf("%d", &value) != 1)) {
            /* Clear the input buffer */
            while ((c = getchar()) != '\n' && c != EOF);
            printf("\nBad input, please enter a valid number: ");
        }
        if ((value < 1) || (value > board.columns)) {
            printf("\nThe column %d doesn't exist, please enter a valid column number (1-%d): ",
                   value, board.columns);
            continue;
        }
        if (board.data[0][value - 1] != DOT_KEY) {
            printf("\nThe column %d is full, please enter another column number (1-%d): ",
                   value, board.columns);
            continue;
        }
        valid = 1;
    } while (valid != 1); /* Check if the value is correct*/
    printf("\n");
    return value - 1;
}

int check_finished(struct matrix_t board) {
    int i;
    int j;
    int counter;

    counter = 0;
    for (i = 0; i < board.rows; i++) {
        for (j = 0; j < board.columns; j++) {
            if (board.data[i][j] == DOT_KEY) {
                counter++;
            } else {
                if (check_winner(board, i, j) == 1) {
                    if (board.data[i][j] == X_KEY) {
                        return 1;
                    }
                    return 2;
                }
            }
        }
    }

    if (counter > 0) {
        return 0;
    }
    return -1;
}

void play(struct matrix_t *board, int player) {
    int column;
    int i;

    column = input_column(*board, player);
    i = board->rows - 1;

    while (board->data[i][column] != DOT_KEY) {
        i--;
    }

    if (player == 1) {
        board->data[i][column] = X_KEY;
    } else {
        board->data[i][column] = TIMES_KEY;
    }
}
