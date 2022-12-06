/*
 * ENSICAEN
 * Exemplier du cours d'outils de développement logiciel (ODL)
 * Divers
 *
 * Copyright (C) 2016 Alain Lebret (alain.lebret (at) ensicaen.fr)
 */

/**
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @version	0.0.1 – 2016-10-01
 */

/**
 * @file boucles.c
 *
 * Quelques exemples de sortie de boucles infinies.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define EVER ;;
#define VRAI 1
#define FAUX 0

int sortir_boucle = FAUX;

/**
 * Sortir d'une boucle infinie lors de la mise à jour d'un drapeau.
 */
void sortir_avec_drapeau() {
	for (EVER) {

		/*
		 * Votre code ...
		 */
		printf("En cours...\n");

		if (sortir_boucle == VRAI) {
			break;
		}
	}

}

/**
 * Sortir d'une boucle infinie au bout d'un temps défini.
 * @param duree Durée au bout de laquelle on sort de la boucle en secondes
 */
void sortir_avec_duree(int duree) {
	time_t fin  = time(NULL) + duree;

	for (EVER) {

		/*
		 * Votre code ...
		 */
		printf("En cours...\n");

		if (time(NULL) >= fin) {
			break;
		}
	}

}

int main(void) {
	sortir_avec_duree(60);
	sortir_avec_drapeau();

	exit(EXIT_SUCCESS);
}
