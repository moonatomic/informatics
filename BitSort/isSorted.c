/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

int isSorted(int * mass, int len) {
    for (int i = 0; i < len-1; i++) {
        if (countBits(mass[i]) > countBits(mass[i+1])) { // Если массив не отсортирован
            return 0; // Возвращаем 0
        }
    }
    return 1;
}