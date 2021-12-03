/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

// Функция возвращает косинус угла между векторами vec1 и vec2
double cosalpha(int *vec1, int *vec2) {
    return dot(vec1, vec2) / (length(vec1) * length(vec2));
}