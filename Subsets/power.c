/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

int power(int a) { // Бинарное возведение в степень
    int number = 1;
    for (int i = 0; i < a; i++) {
        number = number << 1;
    }
    return number;
}