/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex 
 * 
 * This file is owned by ENSICAEN students. No portion of this 
 * document may be reproduced, copied or revised without written 
 * permission of the authors.
 */

/**
 * @file util_csv.c
 * @brief The functions to extract columns from CSV files.
 */

/**
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @version 1.0.0
 * @date 13 septembre 2017
 */

#include "util_csv.h"

int number_of_rows(char *filename) {
    FILE *fp;
    char c;
    int row_count;

    fp = fopen(filename, "r");
    if (!fp) {
        perror("Can't open file\n");
        return -1;
    }

    row_count = 0;
    for (c = getc(fp); c != EOF; c = getc(fp)) {
        if (c == '\n') {
            row_count++;
        }
    }
    fclose(fp);

    return row_count;
}

double *get_double_column(char *filename, int column, const char *delimiters) {
    FILE *fp;
    double *data;
    char buf[1024];
    char *field;
    int nb_samples;
    int row_count;
    int field_count;
    int index;

    nb_samples = number_of_rows(filename);

    fp = fopen(filename, "r");
    if (!fp) {
        perror("Can't open file\n");
        return NULL;
    }

    row_count = 0;
    data = (double *) malloc(nb_samples * sizeof(double));

    while (fgets(buf, 1024, fp)) {
        field_count = 0;
        row_count++;

        if (row_count == 1) {
            continue;
        }

        field = strtok(buf, delimiters);
        while (field) {
            if (field_count == column - 1) {
                index = row_count - 2;
                data[index] = atof(field);
            }
            field = strtok(NULL, delimiters);
            field_count++;
        }
    }
    fclose(fp);

    return data;
}

void *get_int_column(char *filename, int column, const char *delimiters) {
    FILE *fp;
    int *data;
    char buf[1024];
    char *field;
    int nb_samples;
    int row_count;
    int field_count;
    int index;

    nb_samples = number_of_rows(filename);

    fp = fopen(filename, "r");
    if (!fp) {
        perror("Can't open file\n");
        return NULL;
    }

    data = (int *) malloc(nb_samples * sizeof(int));
    row_count = 0;

    while (fgets(buf, 1024, fp)) {
        field_count = 0;
        row_count++;

        if (row_count == 1) {
            continue;
        }

        field = strtok(buf, delimiters);
        while (field) {
            if (field_count == column - 1) {
                index = row_count - 2;
                data[index] = atoi(field);
            }
            field = strtok(NULL, delimiters);
            field_count++;
        }
    }
    fclose(fp);

    return data;
}

