/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#include <stdlib.h>

void fillData(int * mass, int len) {
    for (int i = 0; i < len; i++) {
        mass[i] = rand()%200 - 99; // Заполняем массив случайными числами от -99 до 99
    }
}