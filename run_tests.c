#include <stdio.h>
#include <math.h>

#include "solving.h"

struct test_case
{
    double a, b, c;
    double x1_exp, x2_exp;
    int n_roots_expected;
};

int run_test(test_case);

int run_all_tests(void)
{
    test_case test1 = {.a = 1.0, .b = 0.0, .c = 0.0, .x1_exp = 0.0, .x2_exp = 0,.n_roots_expected = 1};
    test_case test2 = {.a = 1.0, .b = -5.0, .c = 6.0, .x1_exp = 3.0, .x2_exp = 2.0, .n_roots_expected = 2};
    test_case test3 = {.a = 1.0, .b = 1.0, .c = 1.0, .x1_exp = 0.0, .x2_exp = 0.0, .n_roots_expected = 0};
    test_case test4 = {.a = 0.0, .b = 0.0, .c = 0.0, .x1_exp = 0.0, .x2_exp = 0.0, .n_roots_expected = -1};
    run_test(test1);
    run_test(test2);
    run_test(test3);
    run_test(test4);
}

int run_test(test_case test)
{
    double x1 = 0, x2 = 0;
    if (solving_quadratic(test.a, test.b, test.c, &x1, &x2) == test.n_roots_expected && 
        compare_doubles(x1, test.x1_exp) && compare_doubles(x2, test.x2_exp))
    {
        printf("Test is OK\n");
        return 1;
    }
    else
    {
        printf("Something is wrong: a = %lg  b = %lg  c = %lg\n"
               "expected %d roots : x1 = %lg, x2 = %lg\n"
               "got      %d roots : x1 = %lg, x2 = %lg\n", 
               test.a, test.b, test.c, test.n_roots_expected, test.x1_exp, 
               test.x2_exp, solving_quadratic(test.a, test.b, test.c, &x1, &x2), x1, x2);
        return 0;
    }
}