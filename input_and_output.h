/**
 * @file input_and_output.h
 * @brief Header file of input_and_output.c
 * @author Pshanichnaya Sofia
 * @date 2026-08-28
 */

/**
 * @brief ANSI code for pink text on black background.
 * @details To use it you should do: printf(CODEtext);.
 */
#define PINK_ON_BLACK "\033[40;95m"

/**
 * @brief ANSI code for reset all colors.
 * @details To use it you should do: printf(CODEtext);.
 */
#define RESET_BACKGROUND_TEXT "\033[0;0m"

/**
 * @brief Time delay for text output.
 * @details Use it when you want to output text with delay.
 */
#define TIME_DELAY 50

/**
 * @brief  Displays the number of roots, their formulas, and their values ​​in a stylized format. If it is a linear equation, you will find out.
 * @param[amount_real_roots] The number of real roots of the equationю
 * @param[in] x1 The first root.
 * @param[in] x2 The second root.
 * @see delayed_output(), compare_doubles()
 */
void data_output(int amount_real_roots, double x1, double x2);

/**
 * @brief  Beautiful star-themed design like *****
 * @param[in] amount_of_stars The number of stars you want.
 */
void design_output(int);

/**
 * @brief  Asks the user if we want to solve a quadratic equation..
 * @warning Enter clearly "yes" or "no" without extra spaces; otherwise, the program will terminate.
 * @return Returns either true or false.
 * @see delayed_output()
 */
bool ask_user_if_wanna_solve();

/**
 * @brief  Data entry.
 * @param[in, out] a The coefficient before x^2
 * @param[in, out] b The coefficient before x
 * @param[in, out] c The constant term.
 * @note If you enter the numbers separated by single spaces, everything will be fine,
         however, do not enter symbols instead of numbers, or you will have to start over.
 * @see buffer_cleaning()
 */
void data_input(double*, double*, double*);

/**
 * @brief Outputs text with a delay.
 * @param[out] p Pointer to the string to be displayed with a delay
 * @param[in] time_delay Time delay between the output of each letter
 * @warning It won't output a line containing a %...
 */
void delayed_output(const char*, int);

/**
 * @brief  Asks the user if we want to plot second_order polynomial.
 * @warning Enter clearly "yes" or "no" without extra spaces; otherwise, the program will terminate.
 * @return Returns either true or false.
 * @see delayed_output()
 */
bool ask_user_if_wanna_plot(void);

/**
 * @brief Determinate time.
 * @details Outputs the year, date, and time when the function was called.
 */
void time_determination();

/**
 * @brief Enum for amount of real roots.
 * @details Used when it is necessary to output the number of roots of a quadratic equation along with their values.
 */
enum amount_real_roots
{
    two_roots = 2,      ///<two roots when discriminant > 0
    one_root = 1,       ///<one root when discriminant = 0 or linear equation
    no_roots = 0,       ///<no real roots when discriminant < 0 or a = 0, b = 0, c = 0
    infinity_roots = -1 ///<infinity roots when b = 0, c = 0
};
