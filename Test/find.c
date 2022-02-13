/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"

// Поиск предшествующего и следующего чисел.
// Принимает адрес массива, его длину, заданное число Q, и адрес для сохранения ответа
int find(int *CD, int N, int Q, int *nums) {
    int number;
    int value0 = 201;

    for (int i = 0; i < N; i++) {
        number = CD[i];
        if (number == Q) {
            if (i == 0) {
                nums[0] = 202;
                return -1;
            }
            if (i == N-1) {
                nums[1] = 202;
                return -1;
            }
        }
        if (number < Q) {
            if (i == N-1) {
                nums[1]= 201;
                return -1;
            } else {
                value0 = number;
            }
        }
        if (number > Q) {
            if (i == 0) {
                nums[0] = 201;
                return -1;
            } else {
                nums[1] = number;
                nums[0] = value0;
                return 0;
            }
        }
    }
    return 0;
}