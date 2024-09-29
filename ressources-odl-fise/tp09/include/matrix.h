#ifndef MATRIX_H
#define MATRIX_H

/**
 * @file matrix.h
 * @author Alain Lebret (alain.lebret@ensicaen.fr)
 *
 * This file contains the prototypes of the matrix library.
 */

#define SPACE_KEY  ' ' /*!< Used to display a cell as \b "  " */
#define HASH_KEY   '#' /*!< Used to display a cell as \b "# " */
#define DOT_KEY    '.' /*!< Used to display a cell as \b ". " */
#define X_KEY      'x' /*!< Used to display a cell as \b "x " */
#define TIMES_KEY  '*' /*!< Used to display a cell as \b "* " */

#define clrscr() printf("\e[1;1H\e[2J") /*!< Used to clear the terminal */

/**
 * @brief A 2D matrix.
 */
struct matrix_t {
	char **data;      /*!< The concrete matrix data. */
	unsigned rows;    /*!< The number of rows.       */
	unsigned columns; /*!< The number of columns.    */
};

/**
 * @brief Allocates memory for a matrix of a given size.
 *
 * @param rows    The number of rows.
 * @param columns The number of columns.
 *
 * @return The matrix that has been allocated.
 */
struct matrix_t alloc_matrix(unsigned rows, unsigned columns);

/**
 * @brief Initializes the given matrix with the given value.
 *
 * @param *m The initialized matrix.
 * @param value The initial value.
 */
void init_matrix(struct matrix_t *m, char value);

/**
 * @brief Checks if the cell with the given row and column is valid.
 *
 * @param m The matrix.
 * @param row The row of the cell to consider.
 * @param column The column of the cell to consider.
 * @return 1 if the row and the column are valid, 0 otherwise.
 */
int is_valid_cell(struct matrix_t *m, unsigned row, unsigned column);

/**
 * @brief Displays the given matrix.
 *
 * Depending on the values of cells within m->data, it will display:
 * - \b " "  if the cell is an \c SPACE_KEY
 * - \b "#"  if the cell is a \c HASH_KEY
 * - \b "." if the cell is a \c DOT_KEY
 * - \b "x " if the cell is a \c X_KEY
 * - \b "* " if the cell is a \c TIMES_KEY
 *
 * @param m The matrix to display.
 */
void display_matrix(struct matrix_t *m);

#endif
