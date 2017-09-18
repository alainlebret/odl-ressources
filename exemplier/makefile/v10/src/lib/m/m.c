/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * Examples from the course "Software development tools"
 * Exemplier du cours "Outils de développement logiciel" (ODL)
 *
 * Chapter "The make command" / Chapitre "Commande make"
 *
 * Copyright (C) 1995-2017 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.0 (1995)
 * @version   1.0.1 (2016)
 */

/**
 * @file m.c
 *
 * Example to highligh projects with a more complex structure.
 */
#include <m/m.h>
#include <stdio.h>

void m(ms_t vms) {
	printf("Je suis dans m\n");
}
