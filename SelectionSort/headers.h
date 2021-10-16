/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MASS_LEN 32000
#define STAGES 5
#define PACK 1000

int compare (const void *, const void *); // Функция сравнения для qsort()
void selectionSort(int *, int); // Функция сортировки перестановками
int isSorted(int *, int); // Функция проверки успешности сортировки
void fillData(int *, int *, int); // Функция заполнения массива случайными числами
void output(double *, int); // Функция вывода результата 
int power(int, int); // Функция возведения в степень 
void measureTime(int *, int *, int, double *); // Функция замера времени