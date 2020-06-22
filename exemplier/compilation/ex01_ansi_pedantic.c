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
 * @file ex01_ansi_pedantic.c
 *
 * A testing program to highlight the use of precompiler options: \c -ansi and
 * \c -pedantic.
 */

int main(int argc, char *argv[]) {
	int voting_age;
	int ages[argc];

	voting_age = 18; // Not valid in Japan

	return 0;
}
