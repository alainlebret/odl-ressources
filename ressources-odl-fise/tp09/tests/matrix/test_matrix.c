/**
 * @file test_matrix.c
 * @brief Testing the functions of matrix.c
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @version 1.0.0
 * @date 13 septembre 2017
 */
#include <stdio.h>

#include "minunit.h"
#include "matrix.h"

#define N_ROWS_0     1
#define N_COLUMNS_0  1

#define N_ROWS_1     3
#define N_COLUMNS_1  3

#define N_ROWS_2     6
#define N_COLUMNS_2  7

#define N_ROWS_3    12
#define N_COLUMNS_3 15

char expected_m0_0[N_ROWS_0][N_COLUMNS_0] = {
        { 0 } };

char expected_m0_1[N_ROWS_1][N_COLUMNS_1] = {
        { 0, 0, 0 },
        { 0, 0, 0 },
        { 0, 0, 0 } };

char expected_m0_2[N_ROWS_2][N_COLUMNS_2] = {
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0 } };

char expected_m0_3[N_ROWS_3][N_COLUMNS_3] = {
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };

char expected_m1_0[N_ROWS_0][N_COLUMNS_0] = {
        { DOT_KEY } };

char expected_m1_1[N_ROWS_1][N_COLUMNS_1] = {
        { DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY } };

char expected_m1_2[N_ROWS_2][N_COLUMNS_2] = {
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY } };

char expected_m1_3[N_ROWS_3][N_COLUMNS_3] = {
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY },
        { DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY, DOT_KEY } };

void test_setup(void) {
}

void test_teardown(void) {
}

MU_TEST(test_init_matrix0) {
	int row;
	int column;

    printf("Testing init_matrix\n");
    struct matrix_t m = alloc_matrix(N_ROWS_0, N_COLUMNS_0);
    init_matrix(&m, DOT_KEY);
    mu_assert_int_eq(N_ROWS_0, m.rows);
    mu_assert_int_eq(N_COLUMNS_0, m.columns);
    for (row = 0; row < m.rows; row++) {
        for (column = 0; column < m.columns; column++) {
            mu_assert_int_eq(expected_m1_0[row][column], m.data[row][column]);
        }
    }
    printf(" -- passed\n");
    display_matrix(&m);
}

MU_TEST(test_init_matrix1) {
	int row;
	int column;

	printf("Testing init_matrix\n");
    struct matrix_t m = alloc_matrix(N_ROWS_1, N_COLUMNS_1);
    init_matrix(&m, DOT_KEY);
    mu_assert_int_eq(N_ROWS_1, m.rows);
    mu_assert_int_eq(N_COLUMNS_1, m.columns);
    for (row = 0; row < m.rows; row++) {
        for (column = 0; column < m.columns; column++) {
            mu_assert_int_eq(expected_m1_1[row][column], m.data[row][column]);
        }
    }
    printf(" -- passed\n");
    display_matrix(&m);
}

MU_TEST(test_init_matrix2) {
	int row;
	int column;

	printf("Testing init_matrix\n");
    struct matrix_t m = alloc_matrix(N_ROWS_2, N_COLUMNS_2);
    init_matrix(&m, DOT_KEY);
    mu_assert_int_eq(N_ROWS_2, m.rows);
    mu_assert_int_eq(N_COLUMNS_2, m.columns);
    for (row = 0; row < m.rows; row++) {
        for (column = 0; column < m.columns; column++) {
            mu_assert_int_eq(expected_m1_2[row][column], m.data[row][column]);
        }
    }
    printf(" -- passed\n");
    display_matrix(&m);
}

MU_TEST(test_init_matrix3) {
	int row;
	int column;

	printf("Testing init_matrix\n");
    struct matrix_t m = alloc_matrix(N_ROWS_3, N_COLUMNS_3);
    init_matrix(&m, DOT_KEY);
    mu_assert_int_eq(N_ROWS_3, m.rows);
    mu_assert_int_eq(N_COLUMNS_3, m.columns);
    for (row = 0; row < m.rows; row++) {
        for (column = 0; column < m.columns; column++) {
            mu_assert_int_eq(expected_m1_3[row][column],m.data[row][column]);
        }
    }
    printf(" -- passed\n");
    display_matrix(&m);
}

MU_TEST(test_alloc0) {
	int row;
	int column;

    printf("Testing alloc [%d][%d]\n", N_ROWS_0, N_COLUMNS_0);
    struct matrix_t m = alloc_matrix(N_ROWS_0, N_COLUMNS_0);
    mu_assert_int_eq(N_ROWS_0, m.rows);
    mu_assert_int_eq(N_COLUMNS_0, m.columns);
    for (row = 0; row < m.rows; row++) {
        for (column = 0; column < m.columns; column++) {
            mu_assert_int_eq(expected_m0_0[row][column], m.data[row][column]);
        }
    }
    printf(" -- passed\n");
}

MU_TEST(test_alloc1) {
	int row;
	int column;

	printf("Testing alloc [%d][%d]\n", N_ROWS_1, N_COLUMNS_1);
    struct matrix_t m = alloc_matrix(N_ROWS_1, N_COLUMNS_1);
    mu_assert_int_eq(N_ROWS_1, m.rows);
    mu_assert_int_eq(N_COLUMNS_1, m.columns);
    for (row = 0; row < m.rows; row++) {
        for (column = 0; column < m.columns; column++) {
            mu_assert_int_eq(expected_m0_1[row][column], m.data[row][column]);
        }
    }
    printf(" -- passed\n");
}

MU_TEST(test_alloc2) {
	int row;
	int column;

    printf("Testing alloc [%d][%d]\n", N_ROWS_2, N_COLUMNS_2);
    struct matrix_t m = alloc_matrix(N_ROWS_2, N_COLUMNS_2);
    mu_assert_int_eq(N_ROWS_2, m.rows);
    mu_assert_int_eq(N_COLUMNS_2, m.columns);
    for (row = 0; row < m.rows; row++) {
        for (column = 0; column < m.columns; column++) {
            mu_assert_int_eq(expected_m0_2[row][column], m.data[row][column]);
        }
    }
    printf(" -- passed\n");
}

MU_TEST(test_alloc3) {
    int row;
	int column;

    printf("Testing alloc [%d][%d]\n", N_ROWS_3, N_COLUMNS_3);
    struct matrix_t m = alloc_matrix(N_ROWS_3, N_COLUMNS_3);
    mu_assert_int_eq(N_ROWS_3, m.rows);
    mu_assert_int_eq(N_COLUMNS_3, m.columns);
    for (row = 0; row < m.rows; row++) {
        for (column = 0; column < m.columns; column++) {
            mu_assert_int_eq(expected_m0_3[row][column], m.data[row][column]);
        }
    }
    printf(" -- passed\n");
}

MU_TEST_SUITE(test_suite) {
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(test_alloc0);
    MU_RUN_TEST(test_alloc1);
    MU_RUN_TEST(test_alloc2);
    MU_RUN_TEST(test_alloc3);
    MU_RUN_TEST(test_init_matrix0);
    MU_RUN_TEST(test_init_matrix1);
    MU_RUN_TEST(test_init_matrix2);
    MU_RUN_TEST(test_init_matrix3);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
