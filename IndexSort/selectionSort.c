/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

void selectionSort(int *mass, int len, int * index) {
    int iter = 0; 
    int change; // Вспомогательная переменная для обмена
    int min;
    int ind = 0;

    while (iter < len) {
        min = mass[iter];
        for (int i = iter; i < len; i++) {
            if (mass[index[i]] < min) {
                min = mass[index[i]];
                ind = i;
            }
        }
        change = iter;
        index[iter] = ind;
        index[ind] = change;
        // printf("%d -> %d\n", ind, change); // отладочная печать
        iter++;
    }
}