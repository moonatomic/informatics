/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include <stdio.h>

void bitSort(int * mass, int len); // Сортировка по кол-ву единиц в двоичной записи числа
void buildHeap(int * mass, int len); // Постройка бинарного сортирующего дерева
int countBits(int number); // Подсчет кол-ва единиц в двоичной записи числа
void fillData(int * mass, int len); // Заполнение массива случайными числами
int isSorted(int * mass, int len); // Проверка успешности сортировки
void output(FILE * fout, int * mass, int len); // Вывод в удобочитаемом формате
void bin(int number, char * mass); // Двоичное представление числа