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
 * @file game.h
 * Prototypes of the Connect 4 game.
 */

/**
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @version 1.0.1
 * @date 26/08/2017
 */

#ifndef GAME_H
#define GAME_H

#include "matrix.h"

/**
 * @brief Checks if four horizontal pawns are found around the given row and column.
 *
 * @param board The Connect 4 gameboard.
 * @param row The row to check.
 * @param column The column to check.
 *
 * @return 1 if four pawns have been found, 0 otherwise.
 */
int check_horizontal(struct matrix_t board, unsigned row, unsigned column, char pawn);

/**
 * @brief Checks if four vertical pawns are found around the given row and column.
 *
 * @param board The Connect 4 gameboard.
 * @param row The row to check.
 * @param column The column to check.
 *
 * @return 1 if four pawns have been found, 0 otherwise.
 */
int check_vertical(struct matrix_t board, unsigned row, unsigned column, char pawn);

/**
 * @brief Checks if four pawns are found around the upper left to lower right
 * diagonal.
 *
 * @param board The Connect 4 gameboard.
 * @param row The row to check.
 * @param column The column to check.
 *
 * @return 1 if four pawns have been found, 0 otherwise.
 */
int check_diagonal_ul2lr(struct matrix_t board, unsigned row, unsigned column, char pawn);

/**
 * @brief Checks if four pawns are found around the lower left to upper right
 * diagonal.
 *
 * @param board The Connect 4 gameboard.
 * @param row The row to check.
 * @param column The column to check.
 *
 * @return 1 if four pawns have been found, 0 otherwise.
 */
int check_diagonal_ll2ur(struct matrix_t board, unsigned row, unsigned column, char pawn);

/**
 * @brief Checks if four identical pawn are found on the given gameboard.
 *
 * @param board The Connect 4 gameboard.
 * @param row The row to check.
 * @param column The column to check.
 *
 * @return 1 if four pawns have been found, 0 otherwise.
 */
int check_winner(struct matrix_t board, unsigned row, unsigned column);

/**
 * @brief Handles the turn of the given player.
 *
 * @param *board The Connect 4 gameboard.
 * @param player The id of the player (1, or 2).
 */
void play(struct matrix_t *board, int player);

/**
 * @brief Asks the user to enter a valid column number.
 *
 * @param board The Connect 4 gameboard.
 * @param player the id of the player (1 or 2).
 *
 * @return The valid number of column.
 */
int input_column(struct matrix_t board, int player);

/**
 * @brief Checks if the game has ended.
 *
 * @param board The board to check.
 * @return 0 if nobody has won, 1 if player one has won and 2 if player two has
 *         won. If anything goes wrong, it returns -1.
 */
int check_finished(struct matrix_t board);

#endif
