/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

void bin(int number, char * arr) {
    for (int i = 0; i < 32; i++) {
        if (number & 1) {
            arr[31-i] = 1; // Перевод в двоичную систему счисления 
        } else {
            arr[31-i] = 0;
        }
        number >>= 1;
    }
}