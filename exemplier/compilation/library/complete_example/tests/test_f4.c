#include "minunit.h"
#include "f.h"

static const char *thestring = "Bonjour";

void test_setup(void) {
}

void test_teardown(void) {
}

MU_TEST(test_f4) {
	mu_assert_string_eq(thestring, f4());
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
