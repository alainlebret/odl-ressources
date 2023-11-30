#include "factorial.h"
#include "minunit.h"

char *une_chaine = "chaîne de vérification";

void setup() {
    printf("Ceci est le préambule\n");
}

void teardown() {
	printf("Ceci est le postambule\n");
}

MU_TEST(test_pour_la_valeur_0) {
	mu_check(1 == factorial(0));
}

MU_TEST(autre_test_pour_la_valeur_0) {
	mu_assert_int_eq(1, factorial(0));
}

MU_TEST(test_pour_la_valeur_1) {
	mu_check(1 == factorial(1));
}

MU_TEST(test_pour_la_valeur_2) {
	mu_check(2 == factorial(2));
}

MU_TEST(test_pour_la_valeur_3) {
	mu_check(6 == factorial(3));
}

MU_TEST(test_pour_la_valeur_10) {
	mu_check(3628800 == factorial(10));
}

MU_TEST(test_circonference_2) {
	mu_assert_double_eq(12.56637061435, circumference(2));
}

MU_TEST(test_chaines) {
	mu_assert_string_eq("Ma chaîne de vérification...", une_chaine);
}

MU_TEST_SUITE(test_suite) {
	MU_SUITE_CONFIGURE(&setup, &teardown);

	MU_RUN_TEST(test_pour_la_valeur_0);
	MU_RUN_TEST(autre_test_pour_la_valeur_0);
	MU_RUN_TEST(test_pour_la_valeur_1);
	MU_RUN_TEST(test_pour_la_valeur_2);
	MU_RUN_TEST(test_pour_la_valeur_3);
	MU_RUN_TEST(test_pour_la_valeur_10);
	MU_RUN_TEST(test_circonference_2);
	MU_RUN_TEST(test_chaines);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return 0;
}

