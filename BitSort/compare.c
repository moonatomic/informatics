/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

int compare(const void * a, const void * b) { // Сравнение для qsort()
   return (countBits(*(int *)a) - countBits(*(int *)a));
}