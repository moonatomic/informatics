/*
(c) 2021 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#include <stdio.h>
#define N 20

int main(void) {
    int CD[N];
    int Q;
    int nums[2]; // Массив для найденных чисел

    FILE * hist; // Файла для сохранения вывода

    hist = fopen("hist.txt", "w");

    generate(CD, N); // Заполняем массив случайными целыми числами
    
    for (int i = 0; i < N; i++) { // Печатаем массив
        printf("%d ", CD[i]);
        fprintf(hist, "%d ", CD[i]);
    }

    printf("\n"); // Сброс строки в выводе
    fprintf(hist, "\n");

    sort(CD, N); // Сортируем массив

    for (int i = 0; i < N; i++) { // Печатаем отсортированный массив
        printf("%d ", CD[i]);
        fprintf(hist, "%d ", CD[i]);
    }

    printf("\n"); // Сброс строки в выводе
    fprintf(hist, "\n");

    printf("Enter Q: "); // Считываем Q с клавиатуры
    scanf("%d", &Q);

    find(CD, N, Q, nums); // Ищем числа по условию задачи

    if (nums[0] == 201) { // Если Q меньше минимального элемента
        printf("Q is lower than min element. Min element: %d\n", CD[0]);
        fprintf(hist, "Q is lower than min element. Min element: %d\n", CD[0]);
        fclose(hist);
        return 0;
    }
    if (nums[0] == 202) { // Если Q равен минимальному элементу
        printf("Q is equal to min element. Next element: %d\n", CD[1]); // Можем вернуть только второй
        fprintf(hist, "Q is equal to min element. Next element: %d\n", CD[1]);
        fclose(hist);
        return 0;
    }
    if (nums[1] == 201) { // Если Q больше максимального элемента 
        printf("Q is greater than max element. Max element: %d\n", CD[N-1]); // Вернем максимальный
        fprintf(hist, "Q is greater than max element. Max element: %d\n", CD[N-1]);
        fclose(hist);
        return 0;
    }
    if (nums[1] == 202) { // Если Q равен максимальному элементу
        printf("Q is equal to max element. Previous element: %d\n", CD[N-2]); // Вернем предпоследний
        fprintf(hist, "Q is equal to max element. Previous element: %d\n", CD[N-2]);
        fclose(hist);
        return 0;
    }
    // Если ситуация неособая, то просто выводим найденные значения
    printf("Previous element to Q: %d\n", nums[0]);
    fprintf(hist, "Previous element to Q: %d\n", nums[0]);
    printf("Next element after Q: %d\n", nums[1]);
    fprintf(hist, "Next element after Q: %d\n", nums[1]);

    fclose(hist);
    return 0;
}