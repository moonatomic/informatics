#include "headers.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MASS_LEN 100

int main(void) {
    int mass1[MASS_LEN];
    int mass2[MASS_LEN];
    double duration_q, duration_h;
    clock_t start, stop;
    FILE * fout;

    srand(time(NULL));
    
    fout = fopen("out.txt", "w");

    fillData(mass1, MASS_LEN);
    copyData(mass1, mass2, MASS_LEN);

    start = clock();
    bitSort(mass1, MASS_LEN);
    stop = clock();
    duration_h = (double)(stop - start) / CLOCKS_PER_SEC;

    start = clock();
    qsort(mass1, MASS_LEN, sizeof(int), compare);
    stop = clock();
    duration_q = (double)(stop - start) / CLOCKS_PER_SEC;

    if (isSorted(mass1, MASS_LEN)) {
        fprintf(fout, "HeapSort: %lf\nQuickSort: %lf\n\n", duration_h, duration_q);
        printf("HeapSort: %lf\nQuickSort: %lf\n\nVerbose output in out.txt\n", duration_h, duration_q);
        output(fout, mass1, MASS_LEN);
    } else {
        printf("Sorting failed.\n");
    }
    fclose(fout);
    return 0;
}