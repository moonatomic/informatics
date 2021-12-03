/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

// Функция возвращает скалярное произведение векторов vec1 и vec2
int dot(int *vec1, int *vec2) {
    return vec1[0]*vec2[0] + vec1[1]*vec2[1];
}