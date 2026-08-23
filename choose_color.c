#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define ALPHA 'H'

#include "choose_color.h"

void choose_color(void)
{   
    printf(DARK_BLUE"Enter color name from table to change text color of your programm\n");
    triangle(ALPHA);
    printf("\n");
    printf(RED"    1. Black        5. Dark Blue\n"
              "    2. Red          6. Pink\n"
              "    3. Green        7. Light Blue\n"
              "    4. Yellow       8. White\n"RESET);
    struct color_table array_color[] =
    {
        {"black", BLACK},
        {"red", RED},
        {"yellow", YELLOW},
        {"dark_blue", DARK_BLUE},
        {"pink", PINK},
        {"light_blue", BLUE},
        {"white", WHITE}
    };
    int amount_of_colors = sizeof(array_color) / sizeof(array_color[0]);
    const char* selected_color = RESET;
    char color_input[MAX_LENGTH_COLOR_NAME] = "";
    char* p = color_input;
    int c = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        c = tolower(c);
        *(p++) = c;
    }
    *p = '\0';
    int i = 0;
    for (int i = 0; i < amount_of_colors; i++)
    {
        if (!strcmp(color_input, array_color[i].name))
        {
            selected_color =  array_color[i].code;
            break;
        }
    }
    if (selected_color == RESET)
           printf(RED"Please OPEN your eyes and READ the table again!\n"
                  "Try next time\n"RESET);
    printf("%s", selected_color);
}
