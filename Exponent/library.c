/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#define EPS 10e-4

double exponent(double x) { // Вычисляет значение экспоненты в точке x
    double numerator = 1;   // Числитель одночлена Тейлора
    double denominator = 1; // Знаменатель одночлена тейлора
    double prev = 1;
    double res = 1;
    double i = 1;

    do {
        numerator *= x;     // i+1-ый одночлен отличается от i-того в x/i+1 раз
        denominator *= i;
        prev = res;
        res += numerator/denominator;
        i++;
    } while (fabs(res - prev) > EPS); // Сравниваем новый результат со старым для определения точности

    return res;
}

double fabs(double x) { // Возвращает модуль вещественного числа x
    return x > 0 ? x : -x;
}
