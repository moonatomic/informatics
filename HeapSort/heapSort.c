#include "headers.h"

void heapSort(int * mass, int len) {
    int j;
    int index;
    int temp;
    
    buildHeap(mass, len); // Строим бинарное сортирующее дерево

    for (int i = len - 1; i > 0; i--) {

        temp = mass[0]; // Меняем местами первый и последний элемент (убираем корень дерева)
        mass[0] =  mass[i];
        mass[i] = temp;

        j = 0;

        do {
            index = (2 * j + 1);
            if (mass[index] < mass[index + 1] && index < (i - 1)) {
                index++;
            }

            if (mass[j] < mass[index] && index < i){ // 
                temp = mass[j];
                mass[j] = mass[index];
                mass[index] = temp;
            }
            j = index;
        } while (index < i);
    }
}