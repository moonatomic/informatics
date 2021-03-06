/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

double interpolate(double * pointsX, double * pointsY, int amount, double ptp, double * ans, char *Err); // Интерполяция методом одномерной
// линейной регрессии облака точек с координарами из pointsX, pointsY в количестве amount.
// полученные коэффициенты записываются в пару ans.
// возвращает ожидаемое значение в точке ptp. Статус ошибки хранится по адресу &Err.