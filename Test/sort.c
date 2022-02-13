/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

// Сортировка выбором
// Принимает на вход адрес массива и его длину 
void sort(int *CD, int N) {
    int iter = 0; // Граница отсортрованной части массива
    int min; // Минимальное значение неотсортированной части
    int mindex;
    int temp; // Переменная для обмена значениями

    while (iter < N) {
        min = CD[iter];
        for (int i = iter; i < N; i++) { // Идём по неотсортированной части массива
            if (CD[i] < min) {
                min = CD[i];
                mindex = i;
            }
        }
        temp = CD[iter];
        CD[iter] = min; // Обмен индексов
        CD[mindex] = temp;
        iter++;
    }
}