/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#include <stdio.h>
#define ARR_LEN 100

int main(void) {
    double pointsX[ARR_LEN]; // Координаты точек на вход
    double pointsY[ARR_LEN];
    double ans[2]; // Пара для коэффициентов прямой регрессии
    double xval, yval; // Координаты вводимых точек
    double prx, pry; // Координаты предсказанной точки

    char Err;

    int amount = 0;

    FILE * pts;   // Точки для интерполяции     
    FILE * prpts; // Предсказанные точки

    prpts = fopen("prpoints.txt", "w"); // Открываем файлы для сохранения точек
    pts = fopen("points.txt", "w");

    printf("Enter the amount of points for interpolation (up to %d): ", ARR_LEN); // Спрашиваем количество точек
    scanf("%d", &amount);


    printf("Enter points to interpolate in 'X Y' format e.g. '5 10'\n"); // Спрашиваем точки
    for (int i = 0; i < amount; i++) {
        if (scanf("%lf %lf", &xval, &yval) != 2) {
            break;
        } else {
            pointsX[i] = xval;
            pointsY[i] = yval;
            fprintf(pts, "%lf %lf\n", xval, yval);
        }
    }

    printf("Enter X-value to predict Y: "); // Запрашиваем точку для предсказания
    scanf("%lf", &prx);
    pry = interpolate(pointsX, pointsY, amount, prx,  ans, &Err); // Интерполируем, получаем коэффициенты
    printf("Coefficients calculated: a = %lf, b = %lf\n", ans[0], ans[1]); // Выводим их
    if (Err == 0) {
        printf("Predicted point: %lf %lf\n", prx, pry);
        fprintf(prpts, "%lf %lf", prx, pry);
    } else {
        printf("You entered incorrect data: X-value you entered does not belong to interval\n");
    }
    

    fclose(pts);
    fclose(prpts);
    return 0;
}
