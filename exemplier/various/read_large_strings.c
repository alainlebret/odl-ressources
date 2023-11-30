/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex
 *
 * Examples from the course "Software development tools"
 * Exemplier du cours "Outils de développement logiciel" (ODL)
 *
 *
 * Copyright (C) 1995-2023 Alain Lebret (alain.lebret@ensicaen.fr)
 */

/**
 * @file read_large_strings.c
 *
 * @brief Shows how to read large strings.
 *
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @date 1995-2023
 * @version 1.0
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 15

/**
 * Reads a string from standard input.
 *
 * @return A pointer to the dynamically allocated string.
 */
char *read_input() {
    char *input = NULL;
    char temp_buf[MAX_LENGTH];
    size_t input_len = 0;
	size_t temp_len = 0;

    do {
        if (fgets(temp_buf, MAX_LENGTH, stdin) == NULL) {
            if (feof(stdin)) {
                break; /* End of file */
            } else {
                perror("read_input - fgets");
                free(input);
                return NULL;
            }
        }

        temp_len = strlen(temp_buf);
        if (temp_buf[temp_len - 1] == '\n') {
            temp_buf[temp_len - 1] = '\0'; /* Remove newline */
            temp_len--;
        }

        char *new_input = realloc(input, input_len + temp_len + 1);
        if (new_input == NULL) {
            perror("read_input - realloc");
            free(input);
            return NULL;
        }
        input = new_input;
        strcpy(input + input_len, temp_buf);
        input_len += temp_len;
    } while (temp_len == MAX_LENGTH - 1);

    return input;
}

int main(void) {
    char *result = read_input();
    if (result != NULL) {
        printf("Have read large string: %s\n", result);
        free(result);
    }

    return 0;
}
