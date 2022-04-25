/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#include <math.h>
#include <stdio.h>
#define EPS 10e-5

extern double alpha;

// Возвращает значение подынтегральной функции в точке t
double function(double t) {
    return cos(t)/sqrt(1 - t*t);
}

// Возвращает разность значения интеграла и заданной правой части 
double primitive(double x) {
    return integral(function, -x, x) - alpha;
}

// Возвращает значение производной подынтегральной функции в точке t
double derivative(double t) {
    return ((t*t - 1)*sin(t)+t*cos(t))/((1-t*t)*sqrt(1-t*t));
}
 
// Возвращает значение определенного интеграла функции f на отрезке [a,b]
double integral(double (*f)(double x), double a, double b) {
    int base = 16;
    double prev;
    double ans = 0;
    double step; // Длина элементарного отрезка

    do {
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

// Ищет корень функции f с производной d на отрезке [a,b] методом Ньютона
// Код возможной ошибки хранится по адресу Err
// Возвращает корень функции
double root(double (*f)(double x), double (*d)(double x), double a, double b, int *Err) {
    double c; // Переменная для корня
    *Err =  0;
    double fa, fb, fc, da, db;
    do {
        fa = f(a);
        fb = f(b);
        da = d(a);
        db = d(b);
        if (fa*fb > 0) { // Если значения функции на концах отрезка одного знака
            *Err = 1;        // Выдаем ошибку
            return 0;
        } // 0 = f'(x0)(x-x0) + f(x0) ~ f'(x0)x = f'(x0)x0 - f(x0) ~ x = x0 - f(x0)/f'(x0)
        if (fabs(da) > fabs((fb - fa)/(a-b))) { // Если точка C не "вываливается" за [a,b]
            c = b - fa / da;                          // Находим точку пересечения касательной с Ox
        } else {                                      // Иначе
            c = (a + b)/2;                            // Воспользуемся методом деления пополам
        }
        fc = f(c);
        if (fa*fc > 0) { // Смотрим, какую часть отрезка можно отбросить
            a = c;
        } else if (fb*fc > 0) {
            b = c;
        } else {
            *Err = 1;
            return 0;
        }
    } while (fabs(fc) > EPS); // Повторяем пока значение функции в корне не станет меньше EPS
    return c;
}