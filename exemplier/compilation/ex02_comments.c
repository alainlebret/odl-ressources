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
 * Copyright (C) 1995-2017 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.0
 * @date      1995-2017
 */

/**
 * @file ex02_comments.c
 *
 * A testing program to highlight the precompiling step. Compile using option
 * \c -E:
 * \code{.bash}
 * gcc -E -Wall -Wextra -ansi -pedantic ex02_comments.c > ex02_comments.i
 * \endcode
 */

int main(void) {
	int voting_age; /* A value between 16 and 21 */

	/* ... some stuff ... */

	voting_age = 18;

	/* ... some stuff ... */

	return 0;
}