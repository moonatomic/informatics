#include <stdio.h>
#include "headers.h"

#define MASS_LEN 100 // Ограничиваем длины массива и имени файла
#define FN_LEN 100

// Петров Михаил Вадимович группа 112

// Задание №4
// Сравнить два неупорядоченных целочисленных массива A и B как 
// числовые множества без повторения элементов: A = B и A ⊂ B.

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

// (c) 2021 Петров Михаил Вадимович группа 112 
// All rights reserved