/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

void selectionSort(int *mass, int len, int * index) {
    int iter = 0; // Граница отсортрованной части массива
    int min; // Минимальное значение неотсортированной части
    int mindex;
    int temp; // Переменная для обмена значениями

    while (iter < len) {
        min = mass[index[iter]];
        for (int i = iter; i < len; i++) { // Идём по неотсортированной части массива
            if (mass[index[i]] <= min) {
                min = mass[index[i]];
                mindex = i; // Индекс для последующего обмена
            }
        }
        temp = index[iter];
        index[iter] = index[mindex]; // Обмен индексов
        index[mindex] = temp;

        iter++;
    }
}