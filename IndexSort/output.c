/*
(c) 2021 Петров Михаил Вадимович группа 112
*/
#define PACK 1000
#include "headers.h"
#include <stdio.h>

void output(double * timing, int N) {  // Функция вывода результатов в удобном виде
    printf("-----------------------\n");
    printf("Result for %d elements:\n", N * PACK); // Длина массива
    printf("\n");
    printf("SelectionSort:\n"); // Время для selectionSort()
    if (timing[0] == -1) {
        printf("sorting failed\n"); // Ошибка при сортировке
    } else {
        printf("%lf seconds\n", timing[0]);
    }
    printf("QuickSort:\n"); // Время для qSort()
    printf("%lf seconds\n", timing[1]);
}
