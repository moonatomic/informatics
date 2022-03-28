/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

void interpolate(double * pointsX, double * pointsY, double * ans); // Интерполяция методом одномерной
// линейной регрессии облака точек с координарами из pointsX, pointsY
// полученные коэффициенты записываются в пару ans
double predict(double a, double b, double x); // Возвращает значение ƒ = a + bx