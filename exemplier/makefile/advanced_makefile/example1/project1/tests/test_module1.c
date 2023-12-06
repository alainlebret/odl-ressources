#include "minunit.h"
#include "module1.h"

void test_setup(void) {
	/* Nothing */
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(test_f1) {
	mu_assert(f1() == 1, "f1 should be 1");
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
