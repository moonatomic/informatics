/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#include <stdlib.h>

// Генерация массива со случайными числами
// Принимает адрес массива и его длину
void generate(int *CD, int N) {
    int number;
    for (int i = 0; i < N; i++) {
        number = rand()%201 - 100; // Генерируем случайное число от -100 до 100
        CD[i] = number;
    }
}