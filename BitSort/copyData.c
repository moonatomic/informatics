/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

void copyData(int * mass1, int * mass2, int len) {
    for (int i = 0; i < len; i++) {
        mass2[i] = mass1[i]; // Простое копирование одного массива в другой
    }
}