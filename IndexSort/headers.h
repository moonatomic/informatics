/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MASS_LEN 32000
#define STAGES 6
#define PACK 1000

int compare(const void * a, const void * b); // Функция сравнения для qsort()
void selectionSort(int *mass, int len, int * index); // Функция сортировки перестановками
int isSorted(int *mass, int len, int * index); // Функция проверки успешности сортировки
void fillData(int * mass1, int * mass2, int size); // Функция заполнения массива случайными числами
void output(double * timing, int N); // Функция вывода результата 
int power(int a, int b); // Функция возведения в степень 
void measureTime(int * mass1, int * mass2, int N, double * timing, int * index); // Функция замера времени