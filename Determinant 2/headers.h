/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

void gauss(double * matrix, int size, char * Err);
// Приводит матрицу по адресу &matrix порядка size к верхнетреугольному виду
// Код ошибки (индикатор вырожденности) хранится по адресу &Err
// Ничего не возвращает 
void print_matrix(double * matrix, int size);
// Выводит матрицу matrix порядка size на экран
// Для отладки; ничего не возвращает
double fabs(double a);
// Возвращает модуль действительного числа a
int leader(double * matrix, int size, int col);
// Находит лидер в столбце col матрицы matrix порядка size
// Возвращает номер строки лидера
void swap_lines(double * matrix, int size, int former, int new);
// Меняет местями former-тую и new-тую строки матрицы matrix порядка size
// Ничего не возвращает
void subtract(double * matrix, int size, int line);
// Вычитает с коэффициентом line-тую строку из всех остальных строк матрицы matrix порядка size 
// Ничего не возвращает
double determinant(double * matrix, int size);
// Возвращает произведение элементов на главной диагонали матрицы matrix порядка size
void multiply(double * matrix, int size, double val);
// Умножает первую строку матрицы matrix порядка size на значение val
// Ничего не возвращает
void generate(double * matrix, int size);
// Генерирует матрицу порядка size по адресу &matrix с действительными коэффициентами от -1 до 1
// Ничего не возвращает
void save_matrix(double * matrix, int size);
// Записывает матрицу matrix порядка size в файл 
// Ничего не возвращает
int checkdet(double * matrix, int size, double ans);
// Проверяет правильность вычисления определителя матрицы matrix порядка size
// Возвращает 1 если ans - правильный ответ, иначе - 0
void copy_matrix(double * matrix, double * rmatrix, int size);
// Копирует матрицу matrix порядка size в матрицу rmatrix
// Ничего не возвращает