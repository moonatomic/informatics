/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define EPS 1e-8
#define MAT_SIZE 20

// Возвращает модуль действительного числа a
double fabs(double a) {
    return a > 0 ? a : -a;
}

// Приводит матрицу по адресу &&matrix порядка size к верхнетреугольному виду
// Код ошибки (индикатор вырожденности) хранится по адресу &Err
// Ничего не возвращает 
void gauss(double ** matrix, int size, char * Err) {
    int line;

    *Err = 0;

    for (int j = 0; j < size; j++) { // Идем по столбцам
        line = leader(matrix, size, j); // Находим лидер в j-том столбце
        if (line == -1) { // Если его нет - выбрасываем ошибку
            *Err = 1;
            return;
        }
        if (j != line) { // Далее, если он не в j-той строке
            swap_lines(matrix, size, j, line); // Переставляем
            multiply(matrix, size, -1); // Домножаем первую строку на -1
        }
        subtract(matrix, size, j); // Вычитаем первую строку из остальных 
    }    
}

// Находит лидер в столбце col матрицы matrix порядка size
// Возвращает номер строки лидера
int leader(double ** matrix, int size, int col) {
    int ans = 0;
    double max = 0;

    for (int i = col; i < size; i++) { // Ищем максимальный по модулю элемент в строке
        if (fabs(matrix[i][col]) > max) {
            ans = i;
            max = matrix[i][col];
        }
    }

    if (fabs(max) < EPS) { // Если столбец нулевой - матрица вырождена
        return -1;
    }
    return ans;
}

// Меняет местями former-тую и new-тую строки матрицы matrix порядка size
// Ничего не возвращает
void swap_lines(double ** matrix, int size, int former, int new) {
    double tmp;
    for (int j = 0; j < size; j++) {
        tmp = matrix[former][j]; // Поэлементный обмен значений строк
        matrix[former][j] = matrix[new][j];
        matrix[new][j] = tmp;
    }
}

// Вычитает с коэффициентом line-тую строку из всех остальных строк матрицы matrix порядка size 
// Ничего не возвращает
void subtract(double ** matrix, int size, int line) {
    double coeff;

    for (int i = line+1; i < size; i++) {
        if (matrix[i][line] != 0) { // Вычитаем из всех строк line-тую таким образом, чтобы под лидером оказались нули
            coeff = matrix[i][line] / matrix[line][line];
            for (int j = line; j < size; j++) {
                matrix[i][j] -= matrix[line][j] * coeff;
            }
        }
    }
}

// Выводит матрицу matrix порядка size на экран
// Для отладки; ничего не возвращает
void print_matrix(double ** matrix, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] >= 0) {
                printf(" ");
            }
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Возвращает произведение элементов на главной диагонали матрицы matrix порядка size
double determinant(double ** matrix, int size) {
    double ans = 1;
    for (int i = 0; i < size; i++) {
        ans *= matrix[i][i];
    }
    return ans;
}

// Умножает первую строку матрицы matrix порядка size на значение val
// Ничего не возвращает
void multiply(double ** matrix, int size, double val) {
    for (int i = 0; i < size; i++) {
        matrix[0][i] *= val;
    }
}

// Генерирует матрицу порядка size по адресу &&matrix с действительными коэффициентами от -1 до 1
// Ничего не возвращает
void generate(double ** matrix, int size) {
    double number;
    srand(time(NULL)); // Устанавливаем сид генератора

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            number = (double)(rand()%201 - 100) / 100; // Заполняем матрицу значениями от -1 до 1
            matrix[i][j] = number;
        }
    }
}

// Записывает матрицу matrix порядка size в файл 
// Ничего не возвращает
void save_matrix(double ** matrix, int size) {
    double number;
    FILE * f = fopen("matrix_out.txt", "w"); // Открываем файл для записи

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            number = matrix[i][j];
            if (number >= 0) {
                 fprintf(f, " ");
            }
            fprintf(f, "%.2f ", number); // Записываем числа в формате 2.2
        }
        fprintf(f, "\n");
    }
    fclose(f);
}