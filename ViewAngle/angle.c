/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

// Функция нахождения угла видимости многоугольника из точки
// Принимает координаты точки наблюдения, два массива координат x и y, 
// а также количество углов многоугольника.
// Возвращает угол видимости.
double angle(int xZero, int yZero, int *xCoords, int *yCoords, int amount) {
    int vec1[2];
    int vec2[2];
    double ang = 0;
    double mincos = 1;
    double cosab;

    for (int i = 0; i < amount; i++) {
        for (int j = 0; j < amount; j++) {
            if (j != i) {
                vec1[0] = xCoords[i]; // Сравниваем косинусы между радиус-векторами
                vec1[1] = yCoords[i]; // в каждую из вершин
                vec2[0] = xCoords[j]; // Таким образом, минимальный найденный косинус будет
                vec2[1] = yCoords[j]; // отвечать искомому углу
                cosab = cosalpha(vec1, vec2); 
                if (cosab < mincos) {
                    mincos = cosab;
                }
            }
        }
    }
    return arccos(mincos);
}
