/**
 * @file solving.h
 * @brief  Header file for solving.c.
 * @author Pshanichnaya Sofia
 * @date 2026-08-28
 */

/**
 * @brief Constant for comparing two numbers type double.
 * @details When we compare two doubles and difference between them less then DELTA they're equal.
 */ 
#define DELTA 10e-6

/**
 * @brief  Compares two double-precision numbers for equality.
 * @param[in] var1 A single variable of type double.
 * @param[in] var2 The second variable of type double.
 * @return return either true or false.
 */
int compare_doubles(double var1, double var2);

/**
 * @brief  Solves a quadratic equation.
 * @param[in] a The coefficient before x^2.
 * @param[in] b The coefficient before x.
 * @param[in] c The constant term.
 * @param[out] x1 Pointer to the first root.
 * @param[out] x2 Pointer to the second root.
 * @return return amount of real roots.
 * @see compare_doubles()
 */
int solving_quadratic(double a, double b, double c, double* x1, double* x2);

/**
 * @brief  Solves a linear equation type y(x) = a*x + b.
 * @param[in] a The coefficient before x.
 * @param[in] b The constant term.
 * @param[out] x1 Pointer to the root.
 * @return amount of real roots
 */
int solving_linear(double, double, double*);

/**
 * @brief  Clears the buffer.
 */
void buffer_cleaning(void);
