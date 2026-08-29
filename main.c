/**
 * @file main.c
 * @brief A main file.
 * @author Pshanichnaya Sofia
 * @date 2026-08-28
 */
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <TXLib.h>

#include "input_and_output.h"
#include "solving.h"
#include "choose_color.h"
#include "assert.h"
#include "plot_polynomial_2.h"
#include "run_all_tests.h"


int main(int argc, char* argv[])
{   
    int TURN_ON_TESTING = 0;
    if (argc == 2 && !strcmp("-turn_on_testing", argv[1]))
        TURN_ON_TESTING = 1;
    if (TURN_ON_TESTING)
        assert(run_all_tests());
    bool CREATING_WINDOW = false;

    printf(RED "Point of entry into the program: " BLACK);
    time_determination();
    
    while (ask_user_if_wanna_solve())
    {
        choose_color();
        double a = 0.0, b = 0.0, c = 0.0;
        double x1 = 0.0, x2 = 0.0;
        data_input(&a, &b, &c);
        int amount_real_roots = solving_quadratic(a, b, c, &x1, &x2);
        data_output(amount_real_roots, x1, x2);

        
        if (ask_user_if_wanna_plot())
        {
            plot_polynomial_2(a, b, c, CREATING_WINDOW);
            CREATING_WINDOW = true;
        }
        printf(BLACK "Let's try again! (Make parabola great again???)\n\n");
    }

    printf(RED "Point of exit from the program: " BLACK);
    time_determination();

    return 0;
}
