/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#define PACK 1000
#include "headers.h"
#include <stdio.h>

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
    if (timing[1] == -1) {
        printf("sorting failed\n");
    } else {
        printf("%lf seconds\n", timing[1]);
    }
}
