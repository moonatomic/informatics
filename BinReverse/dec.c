/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

int dec(char * arr) {
    int result = 0;
    for (int i = 31; i >= 0; i--) {
        if (arr[i] == 1) { // Если i-тый с конца бит равен 1
            result += power(2, 31-i); // прибавляем к результату 2^i
        }
    }
    return result;
}