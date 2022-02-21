/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

double function(double x); // Возвращает значение заданной функции в точке x
double fabs(double x); // Возвращает модуль вещественного числа x
double primitive(double x); // Возвращает значение первообразной к функции function в точке x
double integral(double (*f)(double x), double a, double b); // Принимает указатель на функцию ƒ и 2 вещественных числа a и b
// Возвращает значение определенного интеграла функции ƒ на интервале [a,b]