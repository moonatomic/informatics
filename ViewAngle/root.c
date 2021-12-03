#include "headers.h"
#include <stdio.h>

// Функция вычисления приближенного значения числа number
// Основана на итеративной формуле Герона
double root(double number) {
    if (number <= 0) {
        printf("Error computing square root of %lf\n", number); // Предотвращаем отрицательные числа под корнем
        return -1;
    }
    float ans = number;
    for (int i = 0; i < 10; i++) {
        ans = 0.5 * (ans + number/ans); // Применяем оценку
    }
    return ans;
}