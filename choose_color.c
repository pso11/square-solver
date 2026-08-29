/**
 * @file choose_color.c
 * @brief File containing the program's text color selection functionю
 * @author Pshanichnaya Sofia
 * @date 2026-08-28
 */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <TXLib.h>

#include "input_and_output.h"
#include "choose_color.h"

void choose_color(void)
{   
    delayed_output("Enter color name from table to change text color of your programm\n" 
                    RESET, TIME_DELAY);
    printf("\n");
    printf("    1. %sBlack        " RESET"5. %sDark Blue\n" RESET               
           "    2. %sRed          " RESET"6. %sPink\n" RESET
           "    3. %sGreen        " RESET"7. %sLight Blue\n" RESET
           "    4. %sYellow       " RESET"8. %sWhite\n" RESET, BLACK, DARK_BLUE, 
                RED, PINK, GREEN, LIGHT_BLUE, YELLOW, WHITE);

    struct color_table array_color[] =
    {
        {"black",      BLACK},
        {"red",        RED},
        {"yellow",     YELLOW},
        {"dark blue",  DARK_BLUE},
        {"pink",       PINK},
        {"light blue", LIGHT_BLUE},
        {"white",      WHITE},
        {"green",      GREEN}
    };

    int amount_of_colors = sizeof(array_color) / sizeof(array_color[0]);   
    const char* selected_color = RESET;

    char input_color[MAX_LENGTH_COLOR_NAME] = "";                          
    char* p = input_color;
    int c = 0, length_color_name_input = 0;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        c = tolower(c);
        *(p++) = (char)c;
        length_color_name_input++;
    }
    *p = '\0';
    
    for (int i = 0; i < amount_of_colors; i++)                            
    {
        if (!strcmp(array_color[i].name, input_color))
        {
            selected_color = array_color[i].code;
            break;
        }
        
    }
    if (selected_color == RESET)
        delayed_output("Please OPEN your eyes and READ the table again to try your best next time", TIME_DELAY);
    printf("%s", selected_color);
}
