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
 * @file test02.c
 *
 * Testing program to highlight:
 * 1) The precompiling step. Compile using option \c -E:
 * \code{.bash}
 * gcc -E -Wall -Wextra -ansi -pedantic test02.c > test02.i
 * \endcode
 * 2) The assembling step. Compile using option \c -S:
 * \code{.bash}
 * gcc -S test02.i
 * \endcode
 */

#define AUSTRIA_VOTING_AGE 16
#define BRAZIL_VOTING_AGE 16
#define FRANCE_VOTING_AGE 18
#define JAPAN_VOTING_AGE 20

int main(void) {
	int voting_age;

	voting_age = FRANCE_VOTING_AGE; /* You have to change this if necessary */

	return 0;
}
