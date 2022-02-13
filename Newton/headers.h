/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

double function(double x); // Возвращает значение многочлена в точке x
double derivative(double x); // Возвращает значение производной в точке x
double root(double (*f)(double x), double (*d)(double x), double a, double b, int *Err); // Возвращает ноль многочлена
double fabs(double x); // Возвращает модуль