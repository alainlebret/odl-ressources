/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex 
 * 
 * This file is owned by ENSICAEN students. No portion of this 
 * document may be reproduced, copied or revised without written 
 * permission of the authors.
 */

/**
 * @file util_csv.h
 * @brief The prototype of functions to extract columns from CSV files.
 */

/**
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @version 1.0.0
 * @date 13 septembre 2017
 */

#ifndef UTIL_CSV_H
#define UTIL_CSV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NB_SAMPLES 544

/**
 * @brief Returns the number of rows in the given file.
 *
 * @param filename The name of the CVS file.
 *
 * @return The number of rows.
 */
int number_of_rows(char *filename);

/**
 * @brief Returns the double values at the given column in the file with the
 * given name.
 *
 * @param filename  The name of the CSV file. 
 * @param column    The column where values are extracted.
 * @param delimiter The delimiter used to separate columns in the CSV file.
 *
 * @return The double values.
 */
double *get_double_column(char *filename, int column, const char * delimiter);

/**
 * @brief Returns the integer values for a given column in the file with the
 * given name.
 *
 * @param filename  The name of the CSV file. 
 * @param column    The column where values are extracted.
 * @param delimiter The delimiter used to separate columns in the CSV file.
 *
 * @return The integer values.
 */
void *get_int_column(char *filename, int column, const char * delimiter);

#endif /* UTIL_CSV_H */
