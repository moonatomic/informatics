#include <stdio.h>
#include <stdlib.h>
#define MASS_LEN 100
// Петров Михаил Вадимович группа 112

int processing(double numbers[], int amount);

int main(void) {
    char filename[120];
    int result;
    double number;
    int index = 0;
    double *numbers;

    printf("Enter file name: ");
    scanf("%s", filename);

    numbers = (double*)malloc(MASS_LEN * sizeof(double)); // Выделяем память под данные

    FILE * file = fopen(filename, "r");
    if (!file) {
        printf("Unable to open %s\n", filename);
        return 1;
    }


    while (fscanf(file, "%lf", &number) == 1) {
        numbers[index] = number;
        index++;
        if (index == MASS_LEN-1) { // Защита от переполнения массива 
            break;
        }
    }
    result = processing(numbers, index);
    free(numbers);
    printf("%d\n", result);
    return 0;
}

int processing(double numbers[], int amount) {
    int result = 0;
    double maxn = 0; // Переменная для максимума последовательности
    for (int i = 0; i < amount; i++) {
        if (numbers[i] > maxn) {
            maxn = numbers[i]; 
            result = i + 1;
        }
    }
    return result; // Возвращаем индекс максимума (нумерация с 1)
}
// (с) Copyright 2021 Mikhail Petrov 112
// All rights reserved