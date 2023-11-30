#include "util.h"
#include "minunit.h"

void setup() {
/*	printf("C'est un préambule au test\n"); */
}

void teardown() {
/*	printf("C'est un postambule au test\n"); */
}

MU_TEST(test_f1_avec_int) {
    int *result = (int *)f1(1);
	mu_check(10 == *result);
}

MU_TEST(test_f1_avec_int_et_assert) {
    int *result = (int *)f1(1);
    mu_assert(11 == *result, "Faire des tests c'est important !");
}

MU_TEST(test_encore_f1_avec_int) {
    int *result = (int *)f1(1);
	mu_assert_int_eq(10, *result);
}

MU_TEST(test_f1_avec_double) {
    double *result = (double *)f1(2);
	mu_assert_double_eq(23.5, *result);
}

MU_TEST(test_f1_avec_chaine) {
    char *result = (char *)f1(3);
	mu_assert_string_eq("Bonjour", result);
}

MU_TEST(test_f1_avec_structure) {
    character_t *result = (character_t *)f1(4);
	mu_assert_int_eq(100, result->health);
	mu_assert_string_eq("The Equalizer", result->name);
}

MU_TEST_SUITE(test_suite) {
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(test_f1_avec_int);
	MU_RUN_TEST(test_f1_avec_int_et_assert);
	MU_RUN_TEST(test_encore_f1_avec_int);
	MU_RUN_TEST(test_f1_avec_double);
	MU_RUN_TEST(test_f1_avec_chaine);
	MU_RUN_TEST(test_f1_avec_structure);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}

