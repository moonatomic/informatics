/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#define EPS 10e-6

double fabs(double a) {
    return a > EPS ? a : a*(-1); // Возвращаем модуль числа
}

double function(double x) { // Полином для поиска корня
    return 3*x*x*x - 2*x*x + x - 1;
}

double derivative(double x) { // Производная полинома
    return 9*x*x - 4*x + 1;
}

double root(double (*f)(double x), double (*d)(double x), double a, double b, int *Err) {
    double c; // Переменная для корня
    *Err =  0;
    do {
        if (f(a)*f(b) > 0) { // Если значения функции на концах отрезка одного знака
            *Err = 1;        // Выдаем ошибку
            return 0;
        } // 0 = f'(x0)(x-x0) + f(x0) ~ f'(x0)x = f'(x0)x0 - f(x0) ~ x = x0 - f(x0)/f'(x0)
        if (fabs(d(a)) > fabs((f(b) - f(a))/(a-b))) { // Если точка C не "вываливается" за [a,b]
            c = b - f(a) / d(a);                      // Находим точку пересечения касательной с Ox
        } else {                                      // Иначе
            c = (a + b)/2;                            // Воспользуемся методом деления пополам
        }
        if (f(a)*f(c) > 0) { // Смотрим, какую часть отрезка можно отбросить
            a = c;
        } else if (f(b)*f(c) > 0) {
            b = c;
        } else {
            *Err = 1;
            return 0;
        }
    } while (fabs(f(c)) > EPS); // Повторяем пока значение функции в корне не станет меньше EPS
    return c;
}