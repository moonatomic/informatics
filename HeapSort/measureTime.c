/*
(c) 2021 Петров Михаил Вадимович группа 112
*/
#include <stdio.h>
#include <time.h>
#include "headers.h"

void measureTime(int * mass1, int * mass2, int * mass3, int N, double * timing) { 
    // Функция замера времени. Принимает на вход два массива, 
    // их длину, адрес для помещения результата и массив индексов
    clock_t start, stop;
    double duration_s, duration_q, duration_h;

    start = clock();
    selectionSort(mass1, N); // Засекаем время selectionSort()
    stop = clock();
    duration_s = (double)(stop - start) / CLOCKS_PER_SEC; // Переводим такты в секунды

    start = clock();
    heapSort(mass2, N); // Засекаем время qSort()
    stop = clock();
    duration_h = (double)(stop - start) / CLOCKS_PER_SEC; // Переводим такты в секунды

    start = clock();
    qsort(mass3, N, sizeof(int), compare); // Засекаем время qSort()
    stop = clock();
    duration_q = (double)(stop - start) / CLOCKS_PER_SEC; // Переводим такты в секунды

    if (isSorted(mass1, N) == 1) { // Если массив отсортирован
        timing[0] = duration_s; // Фиксируем время сортировки
    } else {
        timing[0] = -1;   // Иначе отмечаем ошибку
    }
    if (isSorted(mass2, N) == 1) { // Если массив отсортирован
        timing[1] = duration_h; // Фиксируем время сортировки
    } else {
        timing[1] = -1;   // Иначе отмечаем ошибку
    }
    if (isSorted(mass3, N) == 1) { // Если массив отсортирован
        timing[2] = duration_q; // Фиксируем время сортировки
    } else {
        timing[2] = -1;   // Иначе отмечаем ошибку
    }
}