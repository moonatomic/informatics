#include <stdio.h>
#define MAX_LEN 100

// Петров Михаил Вадимович группа 112
// задача на поиск максимального и минимального значения последовательности

double minmax(double numbers[], int size, double *min);

int main(void) {

    double min = 0, max = 0;
    double numbers[MAX_LEN];
    char filename[MAX_LEN];
    double number;
    int index;

    FILE * file;


    printf("Enter file name: ");
    scanf("%s", filename);

    file = fopen(filename, "r");
    if (!file) {
        printf("Unable to open %s\n", filename);
        return 1;
    }

    while (fscanf(file, "%lf", &number) == 1) {
        numbers[index] = number;
        index++;
        if (index == MAX_LEN-1) {
            break;
        }
    }
    fclose(file);
    max = minmax(numbers, index, &min);
    printf("Minimum of sequence is: %lf\n", min);
    printf("Maximum of sequence is: %lf\n", max);

    return 0;
}

double minmax(double numbers[], int size, double *min) {
    double max = numbers[0];
    for (int i = 1; i < size-1; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
        if (numbers[i] < *min) {
            *min = numbers[i];
        }
    }
    return max;
}
// (c) 2021 Петров Михаил Вадимович группа 112 
// All rights reserved