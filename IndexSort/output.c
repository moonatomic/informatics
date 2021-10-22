/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

void output(double * timing, int N) {
    printf("-----------------------\n");
    printf("Result for %d elements:\n", N * PACK);
    printf("\n");
    printf("SelectionSort:\n");
    if (timing[0] == -1) {
        printf("sorting failed\n");
    } else {
        printf("%lf seconds\n", timing[0]);
    }
    printf("QuickSort:\n");
    printf("%lf seconds\n", timing[1]);
}
