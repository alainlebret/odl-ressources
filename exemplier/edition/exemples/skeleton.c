/* -*- c-basic-offset: 4 -*- 
 *
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex 
 * 
 * This file is owned by ENSICAEN students.
 * No portion of this document may be reproduced, copied
 * or revised without written permission of the authors.
 */ 

/**
 * @author Auteur1 <mail@ecole.ensicaen.fr> 
 * @author Auteur2 <mail@ecole.ensicaen.fr> 
 * @version     0.0.1 - 08-12-2009
 * 
 * @todo the list of improvements suggested for the file.
 * @bug the list of known bugs.
 */

/**
 * @file skeleton.c
 *  
 * Description of the program objectives.
 * All necessary references.
 */

#include <stdio.h> 
#include <strings.h>

/**
 * A complete description of the function.
 *
 * @param par1 description of the parameter par1.
 * @param par2 description of the parameter par2.
 * @return description of the result.
 */
int function1(int par1, char par2) {
	int var = 0;
	/* ... */ 
	return var;
}

/*                                                                                                                 
 * Description of the command line if it uses arguments.
 */
int main(int argc, char* argv[]) {
#define USAGE "usage : %s fichier_texte\n" /* message for French users */

	int i;

	if ((argc > 1) && (!strcasecmp("-h", argv[1]))){
		fprintf(stderr, USAGE, argv[0]);
		return -1;
	}

	i = function1(3, 'c');

	return 0;
}
