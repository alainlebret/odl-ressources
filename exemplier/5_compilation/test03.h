/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * Examples from the course "Software development tools"
 * Exemplier du cours "Outils de développement logiciel" (ODL)
 *
 * Chapter "Compilation" / Chapitre "Compilation"
 *
 * Copyright (C) 1995-2016 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.2 (2016-10-01)
 * @date      1995-2016
 */

/**
 * @file test03.h
 *
 * A testing program to highlight:
 * 1) The precompiling step, particularly the inclusion of \em header files.
 * Compile using command:
 * \code{.bash}
 * gcc -E -Wall -Wextra -ansi -pedantic test03.c > test03.i
 * \endcode
 * 2) The optimizing step. Compile using following commands:
 * \code{.bash}
 * gcc -O0 test03.c -o test03_O0
 * gcc -O1 test03.c -o test03_O1
 * gcc -O2 test03.c -o test03_O2
 * gcc -O3 test03.c -o test03_O3
 * gcc -Os test03.c -o test03_Os
 * \endcode
 */

#define AUSTRIA_VOTING_AGE 16
#define BRAZIL_VOTING_AGE 16
#define FRANCE_VOTING_AGE 18
#define JAPAN_VOTING_AGE 20
