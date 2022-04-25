/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#include <stdio.h>

double alpha;

int main(void) {
    double ans;
    int Err;

    printf("Hello! Please enter a for F(-x, x) = a: "); // Спрашиваем alpha для правой части
    scanf("%lf", &alpha);

    ans = root(primitive, derivative, -1 + 10e-3, 1 - 10e-3, &Err); // Вычисляем корень интегрального уравнения
    if (ans == 0) {
        printf("No root for a = %lf\n", alpha);
        return 0;
    }
    printf("The answer is x = %lf\n", ans);

    return 0;
}