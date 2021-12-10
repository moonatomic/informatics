/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include <stdio.h>
#include <stdlib.h>

#include "headers.h"

void fillData(int * mass1, int * mass2, int * mass3, int size) { // Заполняем 3 массива ОДИНАКОВЫМИ случайными числами
    int number;
    FILE * data;
    data = fopen("data.txt", "w"); // Открываем файл для сохранения данных
    for (int i = 0; i < size; i++) {
        number = rand()%201 - 100; // Генерируем случайное число от -100 до 100
        mass1[i] = number; // Добавляем его в три массива
        mass2[i] = number;
        mass3[i] = number;
        fprintf(data, "%d ", number); // Исходные данные сохраняем в файле data.txt
    }
    fprintf(data, "\n\n");
    fclose(data); // Закрываем файл
}