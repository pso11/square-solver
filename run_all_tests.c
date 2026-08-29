/**
 * @file run_all_tests.c
 * @brief File with test checks.
 * @author Pshanichnaya Sofia
 * @date 2026-08-28
 */
#include <stdio.h>
#include <math.h>
#include <TXLib.h>

#include "solving.h"
#include "run_all_tests.h"

int run_all_tests(void)
{   
    FILE* fp = fopen("koeff.txt", "r");
    if (fp == NULL)
    {
        printf("Can't open file koeff.txt");
        return 0;
    }

    struct test_case arr_test[7] = {};
    unsigned int amount_of_tests = sizeof(arr_test) / sizeof(arr_test[0]);
    
    unsigned int amount_successful_tests = 0, i = 0;
    while (i < amount_of_tests)
    {
        if (run_test(arr_test[i], fp))
            amount_successful_tests++;
        i++;
    }
    if (amount_successful_tests == amount_of_tests)
        return 1;
    else
        return 0;
    fclose(fp);
}

int run_test(test_case test, FILE* fp)
{
    fscanf(fp, "%lg %lg %lg %d %lg %lg", &test.a, &test.b, &test.c, &test.n_roots_expected, &test.x1_exp, &test.x2_exp);
    double x1 = 0.0, x2 = 0.0;

    if (solving_quadratic(test.a, test.b, test.c, &x1, &x2) == test.n_roots_expected && 
       (compare_doubles(x1, test.x1_exp) || compare_doubles(x1, test.x2_exp)) &&
       (compare_doubles(x2, test.x2_exp) || compare_doubles(x2, test.x1_exp)))
    {
        printf("Test is OK\n");
        return 1;
    }
    else
    {
        printf("Something is wrong: a =  %lg  b =  %lg    c = %lg\n"
               "expected %d roots : x1 = %lg, x2 = %lg\n"
               "got      %d roots : x1 = %lg, x2 = %lg\n", 
               test.a, test.b, test.c, test.n_roots_expected, test.x1_exp, 
               test.x2_exp, solving_quadratic(test.a, test.b, test.c, &x1, &x2), x1, x2);
        return 0;
    }
}
