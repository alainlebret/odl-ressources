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
 * @file ex01_ansi_pedantic.c
 * @brief A testing program to highlight the use of precompiler options: -ansi and
 * -pedantic.
 *
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @date 1995-2023
 * @version 1.0
 */

int main(int argc, char *argv[]) {
	int voting_age;
	int ages[argc];

	voting_age = 18; // Not valid in Japan

	return 0;
}
