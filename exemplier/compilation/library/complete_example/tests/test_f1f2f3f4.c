#include "minunit.h"
#include "f.h"

static double pi = 0;
static const char *thestring = "Bonjour";

void test_setup(void) {
	pi = 3.14159;
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(test_f1) {
	mu_assert_int_eq(10, f1(1));
	mu_assert_int_eq(5, f1(0));
	mu_assert_int_eq(5, f1(-10));
}

MU_TEST(test_f2) {
	mu_assert_double_eq(pi, f2());
}

MU_TEST(test_f3) {
	mu_check('A' == f3());
}

MU_TEST(test_f4){
	mu_assert_string_eq(thestring, f4());
}


MU_TEST_SUITE(test_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(test_f1);
	MU_RUN_TEST(test_f2);
	MU_RUN_TEST(test_f3);
	MU_RUN_TEST(test_f4);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}


