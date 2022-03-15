/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#define EPS 10e-6

// Возвращает модуль вещественного числа а
double fabs(double a) {
    return a > EPS ? a : -a;
}

// Возвращает значение заданной функции в точке x
double function(double x) {
    return 4*x*x*x - 2*x + 2;
}

// Возвращает значение первообразной к функции function в точке x
double primitive(double x) {
    return x*x*x*x -  x*x + 2*x;
}

// Принимает указатель на функцию ƒ и 2 вещественных числа a и b
// Возвращает значение определенного интеграла функции ƒ на интервале [a,b]
double integral(double (*f)(double x), double a, double b) {
    int base = 16;
    double prev;
    double ans = 0;
    double step; // Длина элементарного отрезка

    do
    {
        prev = ans;
        ans = 0;
        step = (b - a) / base;
        for (int i = 0; i < base; i++) { // Считаем и складываем площади base элементарных прямоугольников
            ans += f(a + i*step) * step;
        }
        base *= 2; // Удваиваем количество элементарных отрезков
    } while (fabs(ans - prev) > EPS); // Повторяем пока погрешность не станет меньше EPS
    return ans;
}
