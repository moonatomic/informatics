/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#define MAT_SIZE 20
#define NAME_LEN 100

int main(void) {
    double ** matrix; // Указатель на матрицу
    double ** rmatrix; // Указатель на резервную матрицу
    double number;
    double ans;
    double rans;

    char gErr;
    char filename[NAME_LEN]; // Имя файла с матрицей на вход
    
    int mode; // Режим работы (из файла/случайная генерация)
    int size;

    FILE * mat_in;

    printf("Hello! This program calculates determinant of given matrix via Gauss method\nPlease enter matrix size: "); // Запрашиваем размер матрицы
    scanf("%d", &size);

    matrix = (double **)malloc(size * sizeof(double *)); // Выделяем память под матрицу (массив строк)
    for (int i = 0; i < size; i++) {
        matrix[i] = (double *)malloc(size * sizeof(double));
    }
    rmatrix = (double **)malloc(size * sizeof(double *)); // Выделяем память под резервную матрицу (массив строк)
    for (int i = 0; i < size; i++) {
        rmatrix[i] = (double *)malloc(size * sizeof(double));
    }

    printf("Select matrix input mode:\n1) From file\n2) Random generated\n"); // Спрашиваем режим работы
    scanf("%d", &mode);

    if (mode == 1) { // Если выбрано считывание из файла
        printf("Enter input file name: "); // Запрашиваем имя файла
        scanf("%s", filename);
        mat_in = fopen(filename, "r");
        if (!mat_in) { // Если не удалось открыть, выбрасываем ошибку
            printf("Error while opening %s\n", filename);
            return -2;
        }

        for (int i = 0; i < size; i++) { // Считываем матрицу
            for (int j = 0; j < size; j++) {
                if (fscanf(mat_in, "%lf", &number) == 1) {
                    matrix[i][j] = number;
                } else {
                    printf("Incorrect data in file %s\n", filename); // Если данные некорректные, выбрасываем ошибку
                    return -3;
                }
            }
        }
    } else if (mode == 2) { // Если выбрана случайная матрица, генерируем
        generate(matrix, size);
    } else {
        printf("Incorrect option.\n"); // Если выбрано что-то другое, выбрасываем ошибку
        return -1;
    }
    copy_matrix(matrix, rmatrix, size);
    save_matrix(matrix, size); // Сохраняем матрицу в файл для проверки
    gauss(matrix, size, &gErr); // Приводим матрицу к верхнетреугольному виду
    if (gErr) { // Если она вырожденная, определитель равен 0
        ans = 0;
    } else {
        ans = determinant(matrix, size); // Иначе - считаем его
    }

    if (checkdet(rmatrix, size, ans, &rans) == 1) {
        printf("Determinant of given matrix: %lf\n", ans); // Выводим результат
        printf("Determinant of copy of given matrix with interchanged lines 1 & 2: %lf\n", rans);
        printf("The answer is correct!\n");
    } else {
        printf("An error occured while computing determinant of the given matrix.\n");
    }
    free(matrix);
    free(rmatrix);
    fclose(mat_in);
    return 0;
}