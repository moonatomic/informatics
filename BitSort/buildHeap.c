/*
(c) Петров Михаил Вадимович 112 группа
*/

#include "headers.h"

// Функция строит бинарное сортирующее дерево
 
void buildHeap(int * mass, int len) {
    int j;
    int temp;

    for (int i = 1; i < len; i++) { // Если дочерний элемент больше родительского
        if (countBits(mass[i]) > countBits(mass[(i - 1) / 2])) {
            j = i;
            while (countBits(mass[j]) > countBits(mass[(j - 1) / 2])) { // Меняем элементы местами пока родительский не станет больше
                temp = mass[j]; 
                mass[j] = mass[(j - 1) / 2];
                mass[(j - 1) / 2] = temp;
                j = (j - 1) / 2;
            }
        }
    }
}