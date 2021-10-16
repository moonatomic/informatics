// Петров Михаил Вадимович группа 112
#include <stdio.h>

#define MASS_LEN 100 // Ограничиваем длины массива и имени файла
#define FN_LEN 100

// Задание №4
// Сравнить два неупорядоченных целочисленных массива A и B как 
// числовые множества без повторения элементов: A = B и A ⊂ B.

int compare(int *set_A, int *set_B, int len_A, int len_B); // Функция сравнения множеств

int has(int *set, int len, int num); // Функция проверки вхождения num в set

int main(void) {

    int set_A[MASS_LEN];
    int set_B[MASS_LEN];
    int index_A = 0;
    int index_B = 0;
    char filename_A[FN_LEN]; 
    char filename_B[FN_LEN]; 
    int result;

    int number; 

    FILE * file_A;
    FILE * file_B;
    
    printf("Enter A file name: ");   // Пользователь вводит адреса двух файлов 
    scanf("%s", filename_A);         // в которых содержатся исходные последовательности
    printf("Enter B file name: ");
    scanf("%s", filename_B);

    file_A = fopen(filename_A, "r"); // Открытие файлов
    file_B = fopen(filename_B, "r");

    if (!file_A) {
        printf("Couldn't open file A at: %s", filename_A); // Обработка случая 
        return -1;                                         // невозможности открытия
    }                                                      // каждого из файлов
    if (!file_B) {
        printf("Couldn't open file B at: %s", filename_B);
        return -1;
    }

    while (fscanf(file_A, "%d", &number) == 1) {       // Чтение последовательностей
                                                           // в соответствующие массивы
        if (has(set_A, index_A, number) == 0) {                     // Проверка на повторное вхождение
            set_A[index_A] = number;
        }
        if (index_A == MASS_LEN-1) {                       // Защита от переполнения массива
            break;
        }
        index_A++;
    }

    while (fscanf(file_B, "%d", &number) == 1) {

        if (has(set_B, index_B, number) == 0) {
            set_B[index_B] = number;
        }
        if (index_B == MASS_LEN-1) {
            break;
        }
        index_B++;
    }

    result = compare(set_A, set_B, index_A, index_B);
    switch (result)
    {
    case 1:
        printf("A is equal to B\n");
        break;
    
    case 2:
        printf("A includes B\n");
        break;
    
    case 3:
        printf("B includes A\n");
        break;
    
    default:
        printf("Sets are incomparable\n");
        break;
    }

    return 0;
}

int has(int *set, int len, int num) {
    for (int i = 0; i < len; i++) {
        if (set[i] == num) {
            return 1;
        }
    }
    return 0;
}

int compare(int *set_A, int *set_B, int len_A, int len_B) {
    int AiB = 1, BiA = 1; // Возможные отношения между множествами
    for (int i = 0; i < len_A; i++) {
        if (has(set_B, len_B, set_A[i]) == 0) { // Если B не содержит хотя бы один элемент из A
            BiA = 0; // B уже точно не содержит A
            break;
        }
    }
    for (int i = 0; i < len_B; i++) {
        if (has(set_A, len_A, set_B[i]) == 0) { // Если A не содержит хотя бы один элемент из B
            AiB = 0; // A уже точно не содержит B
            break;
        }
    }

    if (AiB && BiA == 1) {
        return 1;
    } else if (AiB == 1) {
        return 2;
    } else if (BiA == 1) {
        return 3;
    } else {
        return 4;
    }
}

// (c) Copyright 2021 Mikhail Petrov 112
// All rights reserved