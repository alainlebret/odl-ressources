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
 * @file test_eratosthenes.c
 * @brief Testing the functions of eratosthenes.c
 * @author Alain Lebret <alain.lebret@ensicaen.fr>
 * @version 1.0.0
 * @date 13 septembre 2017
 */

#include "minunit.h"
#include "eratosthenes.h"

#define SIZE 100
int prime_numbers[SIZE];
int expected_initialized_numbers[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                      1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                                      1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

int expected_until_10[] = {1, 1, 1, 1, 0, 1, 0, 1, 0, 0,
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
                           1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

int expected_until_100[] = {1, 1, 1, 1, 0, 1, 0, 1, 0, 0,
                            0, 1, 0, 1, 0, 0, 0, 1, 0, 1,
                            0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
                            0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
                            0, 1, 0, 1, 0, 0, 0, 1, 0, 0,
                            0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
                            0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
                            0, 1, 0, 1, 0, 0, 0, 0, 0, 1,
                            0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
                            0, 0, 0, 0, 0, 0, 0, 1, 0, 0 };

void test_setup(void) {
}

void test_teardown(void) {
}

MU_TEST(test_initialize) {
	int i;
	
    printf("Testing initialize()\n");
    initialize(prime_numbers, SIZE);
    for (i = 0; i < SIZE; i++) {
        mu_check(expected_initialized_numbers[i] == prime_numbers[i]);
    }
    printf(" -- passed\n");
}

MU_TEST(test_select_until_10) {
	int i;
	
    printf("Testing select_numbers(10)\n");
    initialize(prime_numbers, SIZE);
    select_multiples(prime_numbers, 10);
    for (i = 0; i < SIZE; i++) {
        printf("%3d >> %d\t%d\n", i, expected_until_10[i], prime_numbers[i]);
        mu_assert_int_eq(expected_until_10[i], prime_numbers[i]);
    }
    printf(" -- passed\n");
}

MU_TEST(test_select_until_100) {
	int i;
	
    printf("Testing select_numbers(100)\n");
    initialize(prime_numbers, SIZE);
    select_multiples(prime_numbers, 100);
    for (i = 0; i < SIZE; i++) {
        printf("%3d >> %d\t%d\n", i, expected_until_100[i], prime_numbers[i]);
        mu_assert_int_eq(expected_until_100[i], prime_numbers[i]);
    }
    printf(" -- passed\n");
}

MU_TEST(test_sieve) {
	int i;
	
    printf("Testing sieve\n");
    initialize(prime_numbers, SIZE);
    sieve(prime_numbers, 100);
    mu_assert_int_eq(0, prime_numbers[0]);
    mu_assert_int_eq(0, prime_numbers[1]);
    for (i = 2; i < SIZE; i++) {
        printf("%3d >> %d\t%d\n", i, expected_until_10[i], prime_numbers[i]);
        mu_assert_int_eq(expected_until_100[i], prime_numbers[i]);
    }
    printf(" -- passed\n");
}

MU_TEST_SUITE(test_suite) {
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(test_initialize);
    MU_RUN_TEST(test_select_until_10);
    MU_RUN_TEST(test_select_until_100);
    MU_RUN_TEST(test_sieve);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
