/*
(c) 2021 Петров Михаил Вадимович группа 112
*/
#include <stdio.h>
#include <time.h>
#include "headers.h"

void measureTime(int * mass1, int * mass2, int N, double * timing, int * index) { 
    // Функция замера времени. Принимает на вход два массива, 
    // их длину, адрес для помещения результата и массив индексов
    clock_t start, stop;
    double duration_s, duration_q;

    start = clock();
    selectionSort(mass1, N, index); // Засекаем время selectionSort()
    stop = clock();
    duration_s = (double)(stop - start) / CLOCKS_PER_SEC; // Переводим такты в секунды

    start = clock();
    qsort(mass2, N, sizeof(int), compare); // Засекаем время qSort()
    stop = clock();
    duration_q = (double)(stop - start) / CLOCKS_PER_SEC; // Переводим такты в секунды

    /*
    for (int i = 0; i < N; i++) {                         // Отладка
        printf("%d ", mass1[index[i]]);
    }
    */

    if (isSorted(mass1, N, index) == 1) { // Если массив отсортирован
        timing[0] = duration_s; // Фиксируем время сортировки
    } else {
        timing[0] = -1;   // Иначе отмечаем ошибку
    }
    timing[1] = duration_q;
}