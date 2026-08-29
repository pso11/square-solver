/**
 * @file choose_color.h
 * @brief Header file of choose_color.c
 * @author Pshanichnaya Sofia
 * @date 2026-08-28
 */

/**
 * @brief  ANSI color codes.
 * @details If you want to change color of your text you should do: printf("CODEtext");
 */ 
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define DARK_BLUE "\033[34m"
#define PINK "\033[35m"
#define LIGHT_BLUE "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"

/**
 * @brief  Maximum length of color name.
 * @details It's used when you want to put color name in array;
 */ 
#define MAX_LENGTH_COLOR_NAME 40

/**
 * @brief Lets you choose the text color in your program.
 * @note You must enter the color name itself, not the table number. If you enter the wrong name, there will be no second chance.
 * @warning Do not enter extra spaces after the color name; this will result in an error. 
 * @see delayed_output()
 */
void choose_color(void);

/**
 * @brief  Structure
 * @details color name corresponds to its ANSI code.
 */ 
struct color_table 
{
    const char* name;
    const char* code;
};
