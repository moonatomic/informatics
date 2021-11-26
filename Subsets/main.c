/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#include <stdio.h>

int main(void) {
    FILE * fout;
    int N;
    int k;
    int bitNumber; // Число, заданное номером бита
    int copy; // Копия маски
    int amount; // Мощность булеана N

    printf("Enter N: ");
    scanf("%d", &N); // Запрашиваем N
    printf("Enter k: ");
    scanf("%d", &k); // Запрашиваем k
    fout = fopen("out.txt", "w"); // Открываем файл для вывода

    amount = power(2, N);

    for (int i = 0; i < amount; i++) { // Перебираем k-значные маски булеана N
        if (countBits(i) == k) { 
            bitNumber = 1;
            copy = i;
            for (int j = 0; j < i; j++) { // Сравниваем маску с множеством
                if (copy & 1) {
                    printf("%d ", bitNumber); // Если на i-том месте 1, то i входит в подмножество
                    fprintf(fout, "%d ", bitNumber);
                }
                bitNumber += 1;
                copy = copy >> 1;
            }
            printf("\n");
            fprintf(fout, "\n");
        }
    }

    fclose(fout);
    return 0;
}
