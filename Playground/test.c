#include <stdio.h>

int countBits(int number) {
    int amount = 0;
    while (number != 0) { // Пока число не занулилось
        if (number & 1) {
            amount++; // Проверяем последний элемент на равенство единице
        }
        number >>= 1; // Сдвигаем вправо на 1
    }
    return amount;
}

int main(void) {
    printf("%d\n", countBits());
}