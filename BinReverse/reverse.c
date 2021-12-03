/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#define FIRST_BIT -2147483648

int reverse(int number) {
    int result = 0;
    for (int i = 0; i < 32; i++) {
        if ((number & FIRST_BIT) == FIRST_BIT) {
            result += power(i);
        }
        number = number << 1;
    }
    return result;
}