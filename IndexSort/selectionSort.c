/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

void selectionSort(int *mass, int len, int * index) {
    int iter = 0; 
    int change; // Вспомогательная переменная для обмена
    int min;
    int min_ind;

    while (iter < len) {
        min_ind = 0;
        min = mass[iter];
        for (int i = iter; i < len; i++) {
            if (mass[index[i]] < min) {
                min = mass[index[i]];
                min_ind = i;
            }
        }
        change = index[iter];
        index[iter] = index[min_ind];
        index[min_ind] = change;
        // printf("%d -> %d\n", ind, change); // отладочная печать
        iter++;
    }
}