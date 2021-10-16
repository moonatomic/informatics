#include <stdio.h>

// Петров Михаил Вадимович группа 112

int processing(FILE * file);

int main(void) {
    char filename[120];
    int result;

    printf("Enter file name: ");
    scanf("%s", filename);

    FILE * file = fopen(filename, "r");
    if (!file) {
        printf("Unable to open %s\n", filename);
        return 1;
    }

    result = processing(file);
    printf("%d\n", result);
    return 0;
}
int processing(FILE * file) {
    int result = 0;
    double number; // Переменная для считывания чисел
    double maxn = 0; // Переменная для максимума последовательности
    int index = 0; // Порядковый номер максимального значения

    while (fscanf(file, "%lf", &number) != EOF) {
        if (number > maxn) {
            result = index;
            maxn = number;
        }
        index++;
    }
    return result; // Возвращаем индекс максимума (нумерация с 1)
}
