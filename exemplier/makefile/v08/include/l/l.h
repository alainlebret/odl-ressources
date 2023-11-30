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
 * Copyright (C) 1995-2023 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @file l.h
 *
 * Example to highligh projects with a more complex structure.
 *
 * @author    Alain Lebret <alain.lebret@ensicaen.fr>
 * @version   1.0 (1995)
 * @version   1.0.1 (2016)
 */

#ifndef EXEMPLIER_L_H
#define EXEMPLIER_L_H

struct ls {
	int l1;
	int l2;
};

typedef struct ls ls_t;

void l(ls_t vls);

#endif
