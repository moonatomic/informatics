/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include <stdio.h>
#include "headers.h"

int main(void) {
    double a, b;
    int Err;
    double nil;

    printf("Enter a: "); // Запрашиваем границы отрезка для поиска корня
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);

    nil = root(function, derivative, a, b, &Err); // Вычисляем корень
    if (Err == 0) { // Если корень найден
        printf("%lf is a zero of the given function.\n", nil);
    } else { // Если корня нет
        printf("There are not any zeros in given [a,b].\n");
    }
    return 0;
}
