/**
 * @file test_matrix.c
 * @brief Testing the functions of matrix.c
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @version 1.0.0
 * @date 13 septembre 2017
 */

#include <string.h>

#include "minunit.h"
#include "connect4.h"

#define N_ROWS 6
#define N_COLUMNS 7

char m0[N_ROWS][N_COLUMNS] = {
        { X_KEY,     X_KEY,   X_KEY,   X_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY,   X_KEY,   X_KEY,   X_KEY,   X_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY,   X_KEY,   X_KEY,   X_KEY,   X_KEY } };

char m1[N_ROWS][N_COLUMNS] = {
        { X_KEY,   X_KEY,   X_KEY,   X_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { X_KEY,   X_KEY,   X_KEY, DOT_KEY,   X_KEY,   X_KEY,   X_KEY },
        { X_KEY, DOT_KEY,   X_KEY, DOT_KEY,   X_KEY, DOT_KEY,   X_KEY },
        { X_KEY,   X_KEY, DOT_KEY,   X_KEY,   X_KEY, DOT_KEY,   X_KEY },
        { X_KEY,   X_KEY,   X_KEY,   X_KEY,   X_KEY,   X_KEY,   X_KEY },
        { X_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY,   X_KEY } };

char m2[N_ROWS][N_COLUMNS] = {
        {   X_KEY,   X_KEY, DOT_KEY,   X_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        {   X_KEY, DOT_KEY,   X_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        {   X_KEY, DOT_KEY,   X_KEY, DOT_KEY, DOT_KEY, DOT_KEY,   X_KEY },
        {   X_KEY, DOT_KEY,   X_KEY, DOT_KEY, DOT_KEY,   X_KEY,   X_KEY },
        { DOT_KEY, DOT_KEY,   X_KEY, DOT_KEY, DOT_KEY, DOT_KEY,   X_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY,   X_KEY } };

char m3[N_ROWS][N_COLUMNS] = {
        {   X_KEY, DOT_KEY, DOT_KEY, X_KEY,   X_KEY,   X_KEY,     X_KEY },
        {   X_KEY,   X_KEY,   X_KEY, X_KEY, DOT_KEY, DOT_KEY,     X_KEY },
        { DOT_KEY,   X_KEY, DOT_KEY, X_KEY,   X_KEY,   X_KEY, TIMES_KEY },
        {   X_KEY,   X_KEY,   X_KEY, X_KEY, DOT_KEY, DOT_KEY, TIMES_KEY },
        {   X_KEY,   X_KEY,   X_KEY, X_KEY,   X_KEY,   X_KEY, TIMES_KEY },
        { DOT_KEY, DOT_KEY,   X_KEY, X_KEY, DOT_KEY,   X_KEY, TIMES_KEY } };

char m4[N_ROWS][N_COLUMNS] = {
        { DOT_KEY,   X_KEY,   X_KEY,   X_KEY, TIMES_KEY,   X_KEY,   X_KEY },
        {   X_KEY, DOT_KEY,   X_KEY,   X_KEY,   DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY,   X_KEY, DOT_KEY,   X_KEY,     X_KEY,   X_KEY, DOT_KEY },
        {   X_KEY, DOT_KEY,   X_KEY, DOT_KEY, TIMES_KEY,   X_KEY, DOT_KEY },
        { DOT_KEY,   X_KEY, DOT_KEY,   X_KEY,   DOT_KEY,   X_KEY, DOT_KEY },
        {   X_KEY, DOT_KEY,   X_KEY, DOT_KEY,   DOT_KEY, DOT_KEY,   X_KEY } };

void test_setup(void) {
}

void test_teardown(void) {
}

void copy(char **dest, char orig[][N_COLUMNS]) {
    int i;
    int j;

    for (i = 0; i < N_ROWS; i++) {
        for (j = 0; j < N_COLUMNS; j++) {
            dest[i][j] = orig[i][j];
        }
    }
}

MU_TEST(test_check_horizontal) {
    printf("Testing check_horizontal\n");
    struct matrix_t m = alloc_matrix(N_ROWS, N_COLUMNS);
    init_matrix(&m, DOT_KEY);
    copy(m.data, m0);
    mu_assert_int_eq(1, check_horizontal(m, 0, 2, X_KEY));
    mu_assert_int_eq(0, check_horizontal(m, 1, 2, X_KEY));
    mu_assert_int_eq(0, check_horizontal(m, 2, 1, X_KEY));
    mu_assert_int_eq(1, check_horizontal(m, 3, 1, X_KEY));
    mu_assert_int_eq(0, check_horizontal(m, 4, 1, X_KEY));
    mu_assert_int_eq(1, check_horizontal(m, 5, 2, X_KEY));
    copy(m.data, m1);
    mu_assert_int_eq(1, check_horizontal(m, 0, 4, X_KEY));
    mu_assert_int_eq(0, check_horizontal(m, 1, 4, X_KEY));
    mu_assert_int_eq(0, check_horizontal(m, 2, 4, X_KEY));
    mu_assert_int_eq(0, check_horizontal(m, 3, 4, X_KEY));
    mu_assert_int_eq(1, check_horizontal(m, 4, 4, X_KEY));
    mu_assert_int_eq(0, check_horizontal(m, 5, 4, X_KEY));
    printf("\n-- passed\n");
}

MU_TEST(test_check_vertical) {
    printf("Testing check_vertical\n");
    struct matrix_t m = alloc_matrix(N_ROWS, N_COLUMNS);
    init_matrix(&m, DOT_KEY);
    copy(m.data, m2);
    mu_assert_int_eq(1, check_vertical(m, 2, 0, X_KEY));
    mu_assert_int_eq(0, check_vertical(m, 1, 1, X_KEY));
    mu_assert_int_eq(1, check_vertical(m, 3, 2, X_KEY));
    mu_assert_int_eq(0, check_vertical(m, 0, 3, X_KEY));
    mu_assert_int_eq(0, check_vertical(m, 4, 4, X_KEY));
    mu_assert_int_eq(0, check_vertical(m, 5, 5, X_KEY));
    mu_assert_int_eq(1, check_vertical(m, 2, 6, X_KEY));
    copy(m.data, m3);
    mu_assert_int_eq(0, check_vertical(m, 0, 0, X_KEY));
    mu_assert_int_eq(1, check_vertical(m, 1, 1, X_KEY));
    mu_assert_int_eq(0, check_vertical(m, 3, 2, X_KEY));
    mu_assert_int_eq(1, check_vertical(m, 1, 3, X_KEY));
    mu_assert_int_eq(0, check_vertical(m, 4, 4, X_KEY));
    mu_assert_int_eq(0, check_vertical(m, 5, 5, X_KEY));
    mu_assert_int_eq(0, check_vertical(m, 2, 6, X_KEY));
    printf("\n-- passed\n");
}

MU_TEST(test_check_diagonal_ul2lr) {
    printf("Testing check_diagonal_ul2lr\n");
    struct matrix_t m = alloc_matrix(N_ROWS, N_COLUMNS);
    init_matrix(&m, DOT_KEY);
    copy(m.data, m4);
    mu_assert_int_eq(0, check_diagonal_ul2lr(m, 0, 0, X_KEY));
    mu_assert_int_eq(1, check_diagonal_ul2lr(m, 1, 0, X_KEY));
    mu_assert_int_eq(0, check_diagonal_ul2lr(m, 2, 0, X_KEY));
    mu_assert_int_eq(0, check_diagonal_ul2lr(m, 3, 0, X_KEY));
    mu_assert_int_eq(0, check_diagonal_ul2lr(m, 4, 0, X_KEY));
    mu_assert_int_eq(0, check_diagonal_ul2lr(m, 5, 0, X_KEY));
    mu_assert_int_eq(0, check_diagonal_ul2lr(m, 0, 1, X_KEY));
    mu_assert_int_eq(1, check_diagonal_ul2lr(m, 0, 2, X_KEY));
    mu_assert_int_eq(0, check_diagonal_ul2lr(m, 0, 3, X_KEY));
    mu_assert_int_eq(0, check_diagonal_ul2lr(m, 0, 4, X_KEY));
    mu_assert_int_eq(0, check_diagonal_ul2lr(m, 0, 5, X_KEY));
    mu_assert_int_eq(0, check_diagonal_ul2lr(m, 0, 6, X_KEY));
    printf("\n-- passed\n");
}

MU_TEST(test_check_diagonal_ll2ur) {
    printf("Testing check_diagonal_ll2ur\n");
    struct matrix_t m = alloc_matrix(N_ROWS, N_COLUMNS);
    init_matrix(&m, DOT_KEY);
    copy(m.data, m4);
    mu_assert_int_eq(0, check_diagonal_ll2ur(m, 0, 0, X_KEY));
    mu_assert_int_eq(0, check_diagonal_ll2ur(m, 1, 0, X_KEY));
    mu_assert_int_eq(0, check_diagonal_ll2ur(m, 2, 0, X_KEY));
    mu_assert_int_eq(1, check_diagonal_ll2ur(m, 3, 0, X_KEY));
    mu_assert_int_eq(0, check_diagonal_ll2ur(m, 4, 0, X_KEY));
    mu_assert_int_eq(1, check_diagonal_ll2ur(m, 5, 0, X_KEY));
    mu_assert_int_eq(0, check_diagonal_ll2ur(m, 5, 1, X_KEY));
    mu_assert_int_eq(0, check_diagonal_ll2ur(m, 5, 2, X_KEY));
    mu_assert_int_eq(0, check_diagonal_ll2ur(m, 5, 3, X_KEY));
    mu_assert_int_eq(0, check_diagonal_ll2ur(m, 5, 4, X_KEY));
    mu_assert_int_eq(0, check_diagonal_ll2ur(m, 5, 5, X_KEY));
    mu_assert_int_eq(0, check_diagonal_ll2ur(m, 5, 6, X_KEY));
    printf("\n-- passed\n");
}

MU_TEST_SUITE(test_suite) {
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(test_check_horizontal);
    MU_RUN_TEST(test_check_vertical);
    MU_RUN_TEST(test_check_diagonal_ul2lr);
    MU_RUN_TEST(test_check_diagonal_ll2ur);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
