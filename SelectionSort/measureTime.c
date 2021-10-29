/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include <stdio.h>
#include <time.h>
#include "headers.h"

void measureTime(int * mass1, int * mass2, int N, double * timing) {
    clock_t start, stop;
    double duration_s, duration_q;

    start = clock();
    selectionSort(mass1, N);
    stop = clock();
    duration_s = (double)(stop - start) / CLOCKS_PER_SEC;

    start = clock();
    qsort(mass2, N, sizeof(int), compare);
    stop = clock();
    duration_q = (double)(stop - start) / CLOCKS_PER_SEC;

    if (isSorted(mass1, N) == 1) {
        timing[0] = duration_s;
    } else {
        timing[0] = -1;
    }
    
    if (isSorted(mass2, N) == 1) {
        timing[1] = duration_q;
    } else {
        timing[1] = -1;
    }
}