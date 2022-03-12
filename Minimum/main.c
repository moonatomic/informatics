/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#include <stdio.h>

int main(void) {
    double a, b;
    double ans;

    printf("Enter a: "); // Запрашиваем границы отрезка
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);

    ans = minimum(function, a, b);
    printf("The minimum value of function is %lf\n", ans);
    return 0;
}
