/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

int isSorted(int *mass, int len, int * index) { 
    for (int i = 0; i < len-1; i++) {
        if (mass[index[i]] > mass[index[i+1]]) {
            return 0; // возвращаем 0 если массив не отсортирован
        }
    }
    return 1;
}