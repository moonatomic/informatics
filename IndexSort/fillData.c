/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

void fillData(int * mass1, int * mass2, int size) { // Заполняем 2 массива случайными числами
    int number;
    FILE * data;
    data = fopen("data.txt", "w");
    for (int i = 0; i < size; i++) {
        number = rand()%201 - 100;
        mass1[i] = number;
        mass2[i] = number;
        fprintf(data, "%d ", number); // Исходные данные сохраняем в файле data.txt
    }
    fprintf(data, "\n\n");
    fclose(data);
}