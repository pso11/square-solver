/* Вывод данных */
void data_output(int, double, double);

/* Дизайн вывода типа *** */
void design_output(int);

/* Спрашивает, хотим ли мы решить квадратное решение или нет */
bool ask_user_if_wanna_solve(void);

/* Ввод данных */
void data_input(double*, double*, double*);

/* Очистка буфера */
void bufer_cleaning(void);

/* Функция, которая выводит ушки котика из букв */
void triangle(int);

/* enum для значений amount_real_roots */
enum AMOUNT_REAL_ROOTS
{
    two_roots = 2,
    one_root = 1,
    no_roots = 0,
    infinity_roots = -1
};