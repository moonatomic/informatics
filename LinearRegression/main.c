/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#include <stdio.h>
#define ARR_LEN 10

int main(void) {
    double pointsX[ARR_LEN]; // Координаты точек на вход
    double pointsY[ARR_LEN];
    double prX[3];           // Значения для предсказания 
    double prY[3];
    double ans[2];
    double maxX = 0;         // Границы отрезка 
    double minX = 0;
    double xval, yval;

    FILE * pts;   // Точки для интерполяции     
    FILE * prpts; // Предсказанные точки

    prpts = fopen("prpoints.txt", "w");
    pts = fopen("points.txt", "w");

    printf("Enter %d points to interpolate in 'X Y' format e.g. '5 10'\n", ARR_LEN); // Спрашиваем точки
    for (int i = 0; i < ARR_LEN; i++) {
        scanf("%lf %lf", &xval, &yval);
        pointsX[i] = xval;
        pointsY[i] = yval;
        if (xval > maxX) {
            maxX = xval;
        }
        if (pointsX[i] < minX) { // Обновляем границы
            minX = xval;
        }
        fprintf(pts, "%lf %lf\n", xval, yval); // Сохраняем точки в файл 
    }

    interpolate(pointsX, pointsY, ans); // Интерполируем, получаем коэффициенты
    
    printf("Coefficients calculated: a = %lf, b = %lf\n", ans[0], ans[1]); // Выводим их
    
    printf("Enter 3 X-values to predict Y\n"); // Запрашиваем 3 точки для предсказания
    for (int i = 0; i < 3; i++) {
        scanf("%lf", &xval);
        prX[i] = xval;
        if (xval < minX || xval > maxX) { // Если хотя бы одна вываливается из промежутка - БАН
            printf("Incorrect value: X-value doesn't belong to initial interval.\n");
            return -1;
        }
        
    }

    for (int i = 0; i < 3; i++) { // Получаем и выводим предсказанные точки
        prY[i] = predict(ans[0], ans[1], prX[i]);
    }

    printf("Predicted points:\n");
    for (int i = 0; i < 3; i++) {
        printf("%lf %lf\n", prX[i], prY[i]);
        fprintf(prpts, "%lf %lf\n", prX[i], prY[i]);
    }

    fclose(pts);
    fclose(prpts);
    return 0;
}
