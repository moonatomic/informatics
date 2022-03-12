/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#include <stdio.h>
#define EPS 10e-4
#define tau 1.618033988

double fabs(double a) { // Возвращает модуль действительного числа a
    return a > 0 ? a : -a;   
}

double function(double x) { // Задает функцию ƒ(x)
    return 3*x*x*x*x - 5*x*x + 2;
}

double minimum(double (*f)(double x), double a, double b) { // Возвращает минимум функции f на отрезке [a,b]
    double m, l, fl, fm;

    while (fabs(b-a) > EPS) {
        m = a + (b-a)/tau; // Предположительное смещение точки a
        l = b - (b-a)/tau; // Предположительное смещение точки b
        fl = f(l); // Вычисляем функцию в этих точках, чтобы далее использовать результат
        fm = f(m);
        if (fl > fm) { 
            a = l;
            l = m;
        } else {
            b = m;
            m = l;
        }
    }
    return f((a+b)/2);
}

