/**
 * @file input_and_output.c
 * @brief A file containing all user interactions.
 * @author Pshanichnaya Sofia
 * @date 2026-08-28
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <TXLib.h>

#include "input_and_output.h"
#include "solving.h"

void data_output(int amount_real_roots, double x1, double x2)
{
    design_output(20);
    switch(amount_real_roots)
    {
        case two_roots : 
            printf("Amount of real roots: %d\n", amount_real_roots);
            printf("x1 = (-b + sqrt(d))/(2 * a) = %lg\n", x1);
            printf("x2 = (-b - sqrt(d))/(2 * a) = %lg\n", x2);
            break;
        case one_root: 
            printf("Amount of real roots: %d\n", amount_real_roots);
            if (compare_doubles(x1, x2))
                printf("x1 = x2 = -b/(2 * a) = %lg\n", x1);
            else
            {
                printf("It isn't a quadratic eqaution: "
                       "Linear equation: x = -c / b = %lg\n", x1);
            }
            break;
        case no_roots: 
            printf("No real roots\n");
            break;
        case infinity_roots: 
            printf("Infinity roots\n");
            break;
        default: 
            break;
    }
    design_output(20);
}

void design_output(int amount_of_stars)
{
    for (int i = 0; i < amount_of_stars; i++)
        printf("*");
    putchar('\n');
}

void data_input(double* a, double* b, double* c)
{
    printf("Enter a, b, c:\n");
    int y = 0;
    while ( (y = scanf("%lg %lg %lg", a, b, c)) != 3 || (getchar() != '\n'))
    {
        int ch = 0;
        while ((ch = getchar()) == ' ');
        if (ch != '\n')
        {
            printf("Error. Enter again\n");
            txSpeak("Error. Enter again", 5000);
            buffer_cleaning();
        }
        else
            break;
    }
}

bool ask_user_if_wanna_solve()
{
    delayed_output("Do you REALLY want to solve a quadratic equation????\n"
                   "Enter yes or no: ", TIME_DELAY);

    char input[10] = "";
    char* p = input;
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        c = tolower(c);
        *(p++) = (char)c;
    }
    *p = '\0';

    if (!strcmp(input, "yes"))
    {
        delayed_output("Today we'll serve quadratic equation type y(x)=ax^2+bx+c :)\n\n", 
                        TIME_DELAY);
        return true;
    }
    else if (strcmp("no", input))
    {
        txSpeak("You entered kakuyu-to xrennn) You will be punished, you stupid!", 10000);
        delayed_output(PINK_ON_BLACK "You entered kakuyu-to xrennn) You will be punished, you stupid!\n" 
                       RESET_BACKGROUND_TEXT, TIME_DELAY);
        
        return false;
    }
    else
    {
        delayed_output("))))OK.\n", TIME_DELAY);
        return false;
    }
}

void delayed_output(const char* p, int time_delay)
{
    while(*p != '\0')
    {
        printf("%c", *(p++));
        txSleep(time_delay);
    }
}

bool ask_user_if_wanna_plot(void)
{
    delayed_output("Do you want to plot a polynomial?\n"
                   "Enter yes or no: ", TIME_DELAY);
    
    char input[10] = "";
    char* p = input;
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        c = tolower(c);
        *(p++) = (char)c;
    }
    *p = '\0';

    if (!strcmp(input, "yes"))
        return true;
    else
    {
        txSpeak("OK", 1000);
        delayed_output("OK.\n", TIME_DELAY);
        return false;
    }
}

void time_determination()
{
    time_t beginning_time = 0;
    time(&beginning_time);
    printf("%s", ctime(&beginning_time));
}
