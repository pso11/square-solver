#include <stdio.h>
#include <time.h>

#include "input_and_output.h"
#include "solving.h"
#include "choose_color.h"
#include "assert.h"

int run_all_tests(void);

int main(void)
{
    time_t beginning_time;
    time(&beginning_time);
    printf("beginning_time = %s", ctime(&beginning_time));
    assert(run_all_tests());
    choose_color();
    if (ask_user_if_wanna_solve())
    {

        double a = 0.0, b = 0.0, c = 0.0;
        double x1 = 0.0, x2 = 0.0;
        data_input(&a, &b, &c);
        int amount_real_roots = solving_quadratic(a, b, c, &x1, &x2);
        data_output(amount_real_roots, x1, x2);
    }
    else
        printf("))))OK.\n");
    printf(RESET);
    time_t ending_time;
    time(&ending_time);
    printf("ending_time = %s", ctime(&ending_time));
    return 0;
}
