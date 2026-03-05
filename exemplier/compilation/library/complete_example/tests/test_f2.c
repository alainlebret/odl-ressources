#include "minunit.h"
#include "f.h"

static double pi = 0;

void test_setup(void) {
	pi = 3.14159;
}

void test_teardown(void) {
}

MU_TEST(test_f2) {
	mu_assert_double_eq(pi, f2());
}

MU_TEST_SUITE(test_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(test_f2);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
