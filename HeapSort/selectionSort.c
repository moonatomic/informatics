/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

void selectionSort(int * mass, int len) {
    int iter = 0; // Граница отсортрованной части массива
    int min; // Минимальное значение неотсортированной части
    int mindex;
    int temp; // Переменная для обмена значениями

    while (iter < len) {
        min = mass[iter];
        for (int i = iter; i < len; i++) { // Идём по неотсортированной части массива
            if (mass[i] < min) {
                min = mass[i];
                mindex = i;
            }
        }
        temp = mass[iter];
        mass[iter] = min; // Обмен индексов
        mass[mindex] = temp;
        iter++;
    }
}