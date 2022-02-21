/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#include <stdio.h>

int main(void) {
    double a, b;
    double ans;

    printf("Enter a:"); // Запрашиваем границы отрезка
    scanf("%lf", &a);
    printf("Enter b:");
    scanf("%lf", &b);

    ans = integral(function, a, b); // Считаем интеграл 
    printf("The answer is: %lf\n", ans); // Выводим ответ
    printf("The answer according to Newton-Leibniz formula is: %lf\n", primitive(b)-primitive(a)); // Выводим реальное значение
    return 0;
}
