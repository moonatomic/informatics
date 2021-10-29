/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

int power(int a, int b) { // Простое возведение в степень
    int number = 1;
    for (int i = 0; i < b; i++) { // Умножаем число само на себя N раз, получаем a^N
        number *= a;
    }
    return number;
}