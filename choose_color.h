/* ANSI коды цветов */
#define BLACK "\033[30m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define DARK_BLUE "\033[34m"
#define PINK "\033[35m"
#define BLUE "\033[36m"
#define WHITE "\033[37m"
#define RESET "\033[0m"
#define MAX_LENGTH_COLOR_NAME 40

/* Функция, которая даёт выбрать цвет в программе */
void choose_color(void);

/* Функция, которая рисует треугольник из цифр */
void triangle(char);

struct color_table 
{
    const char* name;
    const char* code;
};
