/* Минимальная разница между двумя переменными типа double для их равенства */
#define DELTA 10e-6

/* Сравнение двух чисел типа double */
int compare_doubles(double, double);

/* Решение квадратного уравнения вида y = ax^2 + bx + c */
int solving_quadratic(double, double, double, double*, double*);

/* Решение линейного уравнения вида y = ax + b */
int solving_linear(double, double, double*);

