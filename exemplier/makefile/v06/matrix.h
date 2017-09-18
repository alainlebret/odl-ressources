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
 * Copyright (C) 1995-2016 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.0
 * @date      2017
 */

/**
 * @file matrix.h
 *
 * Example from a laboratory work exercise. This file contains prototypes of
 * some matrix manipulations.
 */
#ifndef EXEMPLIER_MATRIX_H
#define EXEMPLIER_MATRIX_H

#define NMAX 3

void initialize(int matrix[NMAX][NMAX], int size);

void fill(int matrix[NMAX][NMAX], int size);

void display(int matrix[NMAX][NMAX], int size);

#endif
