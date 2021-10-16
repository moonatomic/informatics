/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

void selectionSort(int *mass, int len) {
    int iter = 0; 
    int change; // Вспомогательная переменная для обмена
    int min;
    int ind;
    while (iter < len) {
        min = mass[iter];
        for (int i = iter; i < len; i++) {
            if (mass[i] < min) {
                min = mass[i];
                ind = i;
            }
        }
        change = mass[iter];
        mass[iter] = min;
        mass[ind] = change;
        iter++;
    }
}