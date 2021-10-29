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
    int mass1[MASS_LEN]; // Создаем 2 массива для сравнения времени работы сортировок
    int mass2[MASS_LEN];
    int N;

    FILE * data;

    double timing[2];

    srand(time(NULL)); // Для максимально случайной генерации чисел

    data = fopen("data.txt", "w"); // Очистка файла с данными в начале работы
    fclose(data);
    
    for (int i = 0; i <= STAGES; i++) {
        N = power(2, i);
        fillData(mass1, mass2, N * PACK);
        measureTime(mass1, mass2, N * PACK, timing);
        output(timing, N);
    }
    return 0;
}