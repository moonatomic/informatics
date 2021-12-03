/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include <stdio.h>
#include "headers.h"
#define FNAME_LEN 100
#define ARR_LEN 100

int main(void) {
    char filename_d[FNAME_LEN]; 
    char filename_z[FNAME_LEN];
    
    int xZero, yZero;     // Координата точки наблюдения
    int xCoords[ARR_LEN]; // x-координаты точек
    int yCoords[ARR_LEN]; // y-координаты точек
    int amount = 0;       // Количество вершин
    int xCoord, yCoord;

    double result;
    
    FILE *data;
    FILE *zero;

    printf("Enter data file name: "); // Запрашиваем имена файлов с данными
    scanf("%s", filename_d);
    printf("Enter view point file name: ");
    scanf("%s", filename_z);

    data = fopen("data.dat", "r");
    zero = fopen("zero.dat", "r");

    if (!data) { // Проверяем успешность открытия файлов с данными
        printf("Unable to open data file at %s\n", filename_d);
        return -1;
    }
    if (!zero) {
        printf("Unable to open view point file at %s\n", filename_z);
        return -1;
    }

    while (fscanf(data, "%d %d", &xCoord, &yCoord) == 2) { // Заполняем массивы координат и считаем вершины
        xCoords[amount] = xCoord;
        yCoords[amount] = yCoord;
        amount++;
    }

    if (fscanf(zero, "%d %d", &xZero, &yZero) != 2) { // Считываем точку наблюдения
        printf("Wrong data!\n");
        return -1;
    }

    result = angle(xZero, yZero, xCoords, yCoords, amount);
    printf("The view angle is %lf deg\n", result); // Выводим ответ
    fclose(zero);
    fclose(data);

    return 0;
}