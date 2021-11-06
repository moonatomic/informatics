#include "headers.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define MASS_LEN 100

int main(void) {
    int mass1[MASS_LEN]; // Создаем массивы для сортировки 
    double duration_h; 
    clock_t start, stop; // Переменные для засечения времени
    FILE * fout;

    srand(time(NULL)); // Для масимально случайной генерации чисел
    
    fout = fopen("out.txt", "w"); // Открываем и очищаем файл для вывода

    fillData(mass1, MASS_LEN); // Заполняем массив случайными числами 

    start = clock();
    bitSort(mass1, MASS_LEN); // Засекаем время сортировки
    stop = clock();
    duration_h = (double)(stop - start) / CLOCKS_PER_SEC;

    if (isSorted(mass1, MASS_LEN)) {
        fprintf(fout, "Successfully sorted in %lf s\n\n", duration_h);
        printf("Successfully sorted in %lf s\n\nVerbose output in out.txt\n", duration_h);
        output(fout, mass1, MASS_LEN);
    } else {
        printf("Sorting failed.\n");
    }
    fclose(fout);
    return 0;
}