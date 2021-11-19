/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

void reverse(char * arr) {
    int temp;
    for (int i = 0; i < 16; i++) {
        temp = arr[i];      //
        arr[i] = arr[31-i]; // Обмен значений симметричных битов 
        arr[31-i] = temp;   //
    }
}