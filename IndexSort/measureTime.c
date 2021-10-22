/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

void measureTime(int * mass1, int * mass2, int N, double * timing, int * index) {
    clock_t start, stop;
    double duration_s, duration_q;

    start = clock();
    selectionSort(mass1, N, index);
    stop = clock();
    duration_s = (double)(stop - start) / CLOCKS_PER_SEC;

    start = clock();
    qsort(mass2, N, sizeof(int), compare);
    stop = clock();
    duration_q = (double)(stop - start) / CLOCKS_PER_SEC;

    /*
    for (int i = 0; i < N; i++) {
        printf("%d ", mass1[index[i]]);
    }
    */

    if (isSorted(mass1, N, index) == 1) {
        timing[0] = duration_s;
    } else {
        timing[0] = -1;
    }
    timing[1] = duration_q;
}