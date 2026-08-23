#include <stdio.h>
#include <ctype.h>

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
    int y = 0;
    bufer_cleaning();
    while ( (y = scanf("%lg %lg %lg", a, b, c)) != 3 || (getchar() != '\n'))
    {
        int ch = 0;
        while ((ch = getchar()) == ' ');
        if (ch != '\n')
        {
            printf("Error. Enter again\n");
            bufer_cleaning();
        }
        else
            break;
    }
}

bool ask_user_if_wanna_solve()
{
    printf("Do you want to solve a quadratic equation?\n");
    printf("Enter yes or no: ");
    int input = getchar();
    input = tolower(input);
    if (input == 'y')
    {
        printf("Today we'll serve quadratic equation type y(x)=ax^2+bx+c :)\n"
               "Enter a, b, c\n");
        return true;
    }
    else
        return false;
}

void triangle(char ALPHA)
{
    int lines = ALPHA - 'A' + 1;
    int i, j, k, z;
    for (i = 1; i <= lines; i++)
    {
        for (j = 0; j <= ALPHA - 'A' + 1 - i; j++)
            printf(" ");
        for (k = 0; k < i - 1; k++)
            printf("%c", 'A' + k);
        for (z = i - 1; z < i, z >= 0; z--)
            printf("%c", 'A' + z);
        for (j = 0; j <= ALPHA - 'A' + 1 - i; j++)
            printf("  ");
        for (k = 0; k < i - 1; k++)
            printf("%c", 'A' + k);
        for (z = i - 1; z < i, z >= 0; z--)
            printf("%c", 'A' + z);
        printf("\n");
    }
}
