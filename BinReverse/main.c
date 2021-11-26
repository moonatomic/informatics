/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include <stdio.h>
#include "headers.h"

int main(void) {
    int number; 
    char bits[32]; // Массив для двоичного представления

    printf("Enter an integer value: "); // Запрашиваем ввод числа
    scanf("%d", &number);

    bin(number, bits); 
    printf("%d in BIN: ", number); // Считаем двоичное представление

    for (int i = 0; i < 32; i++) { // Выводим число в BIN
        printf("%d", bits[i]);
        if (i%8 == 7) {
            printf(" ");
        }
    }

    number = reverse(number); // Зеркально отражаем число и выводим десятичную форму
    bin(number, bits);
    printf("\nReversed BIN: ");
    for (int i = 0; i < 32; i++) {
        printf("%d", bits[i]);
        if (i%8 == 7) {
            printf(" ");
        }
    }
    printf("\nIn DEC it equals %d\n", number);

    return 0;
}