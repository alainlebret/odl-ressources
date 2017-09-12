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
 * @version   1.0
 * @date      1995-2017
 */

/**
 * @file ex02_macros.c
 *
 * Testing program to highlight the precompiling step. Compile using option
 * \c -E:
 * \code{.bash}
 * gcc -E -Wall -Wextra -ansi -pedantic ex02_macros.c > ex02_macros.i
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
