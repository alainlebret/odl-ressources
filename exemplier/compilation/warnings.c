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
 * @file warnings.c
 *
 * A Testing program to highlight the use of precompiler options: \c -Wall and
 * \c -Wextra.
 */

int main(void) {
	int voting_age = 18;
	int *ages;
	unsigned int seuil = 21;

	if (voting_age < seuil)
		ages[0] = voting_age;
}