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
 * @version   1.2
 * @date      1995-2016
 */

/**
 * @file test01a.c
 *
 * A Testing program to highlight the use of precompiler options: \c -Wall,
 * \c -Wextra, \c -ansi and \c -pedantic.
 */

int main(void) {
	int voting_age;
	int *ages;

	voting_age = 18; // Not valid for Japan
	ages[2] = voting_age;
	return 0;
}