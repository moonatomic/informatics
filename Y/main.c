#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

int main(void) {
    clock_t start, stop;

    double duration1, duration2;
    int amount = 0;
    unsigned long number = 2;
    char prime = 1;
    int k = 1;
    int n1, n2;
    int N;

    printf("Enter N: ");
    scanf("%d", &N);

    unsigned long *arr = (unsigned long *)malloc(N * sizeof(unsigned long));

    start = clock();
    while (amount < N) {
        for (int i = 0; i < amount; i++) {
            if (arr[i] > (int)sqrt(number)+1) {
                break;
            }
            if ((number%arr[i] == 0)){
                prime = 0;
                break;
            }
        }
        if (prime == 1) {
            arr[amount] = number;
            amount++;
        }
        number++;
        prime = 1;
    }

    stop = clock();
    duration1 = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("%lu\n", arr[N-1]);
    printf("Time for %d-th prime via array algorithm: %lf\n", N, duration1);

    amount = 0;
    number = 7;
    start = clock();
    prime = 1;

    while (amount < N) {
        if (number%6 == -1) {
            n1 = 6*k-1;
            n2 = 6*k+1;
            for (int k = 1; k < number-2/6; k++) {
                if (number%n2 == 0 || number%n1 == 0) {
                    prime = 0;
                    break;
                }
            }
            if (prime == 1) {
                amount++;
            }
        }
        if (number%6 == 1) {
            n1 = 6*k-1;
            n2 = 6*k+1;
            for (int k = 1; k < sqrt(number-2/6); k++) {
                if (number%n2 == 0 || number%n1 == 0) {
                    prime = 0;
                    break;
                }
            }
            if (prime == 1) {
                amount++;
            }
        }
        number++;
        prime = 1;
    }
    stop = clock();
    duration2 = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("%lu\n", number);
    printf("Time for %d-th prime via non-array algorithm: %lf\n", N, duration2);
    return 0;
}