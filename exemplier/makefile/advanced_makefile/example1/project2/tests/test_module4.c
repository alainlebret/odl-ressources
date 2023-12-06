#include "minunit.h"
#include "module4.h"

void test_setup(void) {
	/* Nothing */
}

void test_teardown(void) {
	/* Nothing */
}

MU_TEST(test_f4) {
	mu_assert(f4() == 4, "f4 should be 4");
}

MU_TEST_SUITE(test_suite) {
	MU_SUITE_CONFIGURE(&test_setup, &test_teardown);

	MU_RUN_TEST(test_f4);
}

int main(int argc, char *argv[]) {
	MU_RUN_SUITE(test_suite);
	MU_REPORT();
	return MU_EXIT_CODE;
}
