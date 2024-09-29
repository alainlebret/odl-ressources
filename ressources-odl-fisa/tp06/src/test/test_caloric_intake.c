/*
 * ENSICAEN
 * 6 Boulevard Maréchal Juin
 * F-14050 Caen Cedex 
 * 
 * This file is owned by ENSICAEN students. No portion of this 
 * document may be reproduced, copied or revised without written 
 * permission of the authors.
 */

/*
 * Testing the functions of caloric_intake.c
 * @author  A COMPLETER
 * @version A COMPLETER
 * @date    A COMPLETER
 */

#include "minunit.h"
#include "util_csv.h"
#include "caloric_intake.h"

#undef MINUNIT_EPSILON
#define MINUNIT_EPSILON 1E-2

void test_setup(void) {
}

void test_teardown(void) {
}

MU_TEST(test_age_coefficient) {
}

MU_TEST(test_simplified_body_surface_area) {
}

MU_TEST(test_body_surface_area) {
}

MU_TEST(test_basal_metabolic_rate) {
}

MU_TEST(test_daily_caloric_intake_little) {
}

MU_TEST(test_daily_caloric_intake_light) {
}

MU_TEST(test_daily_caloric_intake_moderate) {
}

MU_TEST(test_daily_caloric_intake_heavy) {
}

MU_TEST(test_daily_caloric_intake_very_heavy) {
}

MU_TEST_SUITE(test_suite) {
    MU_SUITE_CONFIGURE(&test_setup, &test_teardown);
    MU_RUN_TEST(test_age_coefficient);
    MU_RUN_TEST(test_simplified_body_surface_area);
    MU_RUN_TEST(test_body_surface_area);
    MU_RUN_TEST(test_basal_metabolic_rate);
    MU_RUN_TEST(test_daily_caloric_intake_little);
    MU_RUN_TEST(test_daily_caloric_intake_light);
    MU_RUN_TEST(test_daily_caloric_intake_moderate);
    MU_RUN_TEST(test_daily_caloric_intake_heavy);
    MU_RUN_TEST(test_daily_caloric_intake_very_heavy);
}

int main(int argc, char *argv[]) {
    MU_RUN_SUITE(test_suite);
    MU_REPORT();
    return MU_EXIT_CODE;
}
