
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
 * @file buggy.c
 * @brief This buggy program highlights the use of precompiler options: -Wall, 
 * -Wextra, -ansi and -pedantic.
 *
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @date 1995-2023
 * @version 1.0
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
