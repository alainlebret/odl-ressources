
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
 * @file buggy.c
 *
 * A program to highlight the use of precompiler options: \c -Wall, 
 * \c -Wextra, \c -ansi and \c -pedantic.
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int index;

    for (index; index < 10; i++) {
        printf("%d * %d = %p\n", index, index, square());
    }
    
    return EXIT_SUCCESS;
}

int square(int number) {
    return number * number;
}
