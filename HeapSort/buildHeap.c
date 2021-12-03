/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

void buildHeap(int * mass, int len) {
    int j;
    int temp;

    for (int i = 1; i < len; i++) { // Если дочерний элемент больше родительского
        if (mass[i] > mass[(i - 1) / 2]) {
            j = i;
            while (mass[j] > mass[(j - 1) / 2]) { // Меняем элементы местами пока родительский не станет больше
                temp = mass[j]; 
                mass[j] = mass[(j - 1) / 2];
                mass[(j - 1) / 2] = temp;
                j = (j - 1) / 2;
            }
        }
    }
}