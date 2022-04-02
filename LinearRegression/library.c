/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

double interpolate(double * pointsX, double * pointsY, int amount, double ptp, double * ans, char *Err) {
    // Интерполяция методом одномерной
    // линейной регрессии облака точек с координарами из pointsX, pointsY в количестве amount
    // полученные коэффициенты записываются в пару ans
    // Возвращает предполагаемое значение в точке ptp
    double sumX = 0; // Сумма абсцисс
    double sumY = 0; // Сумма ординат
    double medX;     // Среднее по X
    double medY;     // Среднее по Y
    double numerator = 0;
    double denominator = 0;
    double px, py;
    double left = 1e6, right = -1e6;

    *Err = 0;

    for (int i = 0; i < amount; i++) { // Вычисляем средние и попутно определяем границы отрезка
        px = pointsX[i];
        py = pointsY[i];
        if (px > right) {
            right = px;
        }
        if (px < left) {
            left = px;
        }
        sumX += px;
        sumY += py;
    }
    medX = sumX / amount;
    medY = sumY / amount;
    for (int i = 0; i < amount; i++) {
        numerator += (pointsX[i] - medX) * (pointsY[i] - medY); // Вычисляем ответ
        denominator += (pointsX[i] - medX)*(pointsX[i] - medX);
    }
    ans[1] = numerator / denominator;
    ans[0] = medY - ans[1]*medX;

    if (ptp > right || ptp < left) {
        *Err = 1;
        return 0;
    } else {
        return ans[1]*ptp + ans[0];
    }
}
