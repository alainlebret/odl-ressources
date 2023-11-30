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
 * Copyright (C) 1995-2023 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @file ex01_warnings.c
 * @brief A testing program to highlight the use of precompiler options: -Wall and
 * -Wextra.
 *
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @date 1995-2023
 * @version 1.0
 */

int main(void) {
	int voting_age = 18;
	int *ages;
	unsigned int threshold = 21;

	if (voting_age < threshold)
		ages[0] = voting_age;
}