/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MASS_LEN 32000
#define STAGES 6
#define PACK 1000

#include "headers.h"

int main(void) {
    int mass1[MASS_LEN]; // Создаем 3 массива для сравнения времени работы сортировок
    int mass2[MASS_LEN];
    int mass3[MASS_LEN];
    int N;

    FILE * data;

    int index[MASS_LEN];
    double timing[3];

    srand(time(NULL)); // Для максимально случайной генерации чисел

    data = fopen("data.txt", "w"); // Очистка файла с данными в начале работы
    fclose(data);
    
    for (int i = 0; i < STAGES; i++) {
        N = power(2, i);
        fillData(mass1, mass2, mass3, N * PACK); // заполняем массивы ОДИНАКОВЫМИ случайными числами
        measureTime(mass1, mass2, mass3, N * PACK, timing); // замеряем время работы
        output(timing, N); // выводим результат в удобном для восприятия формате
    }
    return 0;
}