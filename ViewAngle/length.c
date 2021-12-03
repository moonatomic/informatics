/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

// Функция вычисляет евклидову норму вектора vec 
double length(int *vec) {
    return root(vec[0]*vec[0] + vec[1]*vec[1]);
}