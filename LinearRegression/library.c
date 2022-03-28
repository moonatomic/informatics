/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#define ARR_LEN 10

void interpolate(double * pointsX, double * pointsY, double * ans) {
    // Интерполяция методом одномерной
    // линейной регрессии облака точек с координарами из pointsX, pointsY
    // полученные коэффициенты записываются в пару ans
    double sumX = 0; // Сумма абсцисс
    double sumY = 0; // Сумма ординат
    double medX;     // Среднее по X
    double medY;     // Среднее по Y
    double numerator = 0;
    double denominator = 0;

    for (int i = 0; i < ARR_LEN; i++) { // Вычисляем средние
        sumX += pointsX[i];
        sumY += pointsY[i];
    }
    medX = sumX / ARR_LEN;
    medY = sumY / ARR_LEN;
    for (int i = 0; i < ARR_LEN; i++) {
        numerator += (pointsX[i] - medX) * (pointsY[i] - medY); // Вычисляем ответ
        denominator += (pointsX[i] - medX)*(pointsX[i] - medX);
    }
    ans[1] = numerator / denominator;
    ans[0] = medY - ans[1]*medX;
}

double predict(double a, double b, double x) {
    // Возвращает значение ƒ = a + bx
    return a + b*x; // Возвращает предсказанное значение 
}