#include "minunit.h"
#include "f.h"

void test_setup(void) {
}

void test_teardown(void) {
}

MU_TEST(test_f1) {
	mu_assert_int_eq(10, f1(1));
	mu_assert_int_eq(5, f1(0));
	mu_assert_int_eq(5, f1(-10));
}

MU_TEST_SUITE(test_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(test_f1);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
