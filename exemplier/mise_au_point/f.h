/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * Examples from the course "Software development tools"
 * Exemplier du cours "Outils de développement logiciel" (ODL)
 *
 * Chapter "Debugging, testing, profiling" / Chapitre "Mise au point"
 *
 * Copyright (C) 1995-2023 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @file f.h
 *
 * Examples to highlight using of the debugger, profiler, etc.
 *
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.0 (1995)
 * @version   1.0.1 (2016)
 */

#ifndef EXEMPLIER_F_H
#define EXEMPLIER_F_H

#define CONSTANT 23
#define UNDEFINED -1
#define ITERATIONS 300000
/* #define DEBUG */

#ifndef M_PI
#define M_PI 3.14159
#endif

/** 
 * Count from 0 to \c upperBound - 1 with an increment of 2.
 * @param upperBound The upper bound value
 */
void f1(int borne_sup);

/**
 * Implementation of a memory leak when trying to allocate n integers in memory
 * without free.
 * @param n Size of the memory allocation
 * @param x Integer to put at the head of the allocated memory
 * @return CONSTANT (23) if the first integer within the allocated memory is
 * equal to 3, else return UNDEFINED (-1)
 */
int f2(int n, int x);

/** 
 * Convert degrees to radians.
 * @param angle_degrees An angle in degrees
 * @return The angle in radians
 */
double f3(int angle_degrees);

/** 
 * Add 32 to the integer and return the result.
 *
 * @param value An integer between 65 and 90
 * @return The value of the integer + 32
 */
int f4(int entier);

/** Perform f1, f2, f3 et f4 'ITERATIONS' times */
void f5();

#endif
