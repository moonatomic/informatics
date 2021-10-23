/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

int main(void) {
    int mass1[MASS_LEN]; // Создаем 2 массива для сравнения времени работы сортировок
    int mass2[MASS_LEN];
    int N;

    FILE * data;

    int index[MASS_LEN];
    double timing[2];

    srand(time(NULL)); // Для максимально случайной генерации чисел

    data = fopen("data.txt", "w"); // Очистка файла с данными в начале работы
    fclose(data);
    
    for (int i = 0; i < STAGES; i++) {
        N = power(2, i);
        fillData(mass1, mass2, N * PACK); // заполняем массивы ОДИНАКОВЫМИ случайными числами
        
        for (int i = 0; i < N * PACK; i++) { // заполняем массив индексов
            index[i] = i;
        }

        measureTime(mass1, mass2, N * PACK, timing, index); // замеряем время работы
        /*
        for (int i = 0; i < N * PACK; i++) {     // Отладка
            printf("%d ", index[i]);
        }
        */
        output(timing, N); // выводим результат в удобном для восприятия формате
    }
    return 0;
}