/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

// Функция подсчитывает количество единиц в двоичной записи числа

int countBits(int number) {
    return (__builtin_popcount(number));
}
