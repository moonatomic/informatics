/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#include <stdio.h>
#include <math.h>

int main(void) {
    double number;
    double x[5];

    double my_exp;
    double math_exp;

    for (int i = 0; i < 5; i++) {
        printf("Enter x to calculate exp(x): ");
        scanf("%lf", &number);
        x[i] = number;
    }

    printf("x\t\tMy exponent\tmath.h exponent\tDelta\n");

    for (int i = 0; i < 5; i++) {
        my_exp = exponent(x[i]);
        math_exp = exp(x[i]);
        printf("%lf\t%lf\t%lf\t%lf\n", x[i], my_exp, math_exp, fabs(my_exp-math_exp));
    }

    return 0;
}
