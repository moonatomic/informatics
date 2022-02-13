#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>
int primalSearch(int);
int isPrimal(int);
 
int main(void)
{
    int n;
    double duration;
    clock_t start, stop;
    scanf("%d", &n);
    start = clock();
    printf("%d\n", primalSearch(n));
    stop = clock();
    duration = (double)(stop - start) / CLOCKS_PER_SEC;
    printf("Time for %d-th prime via non-array algorithm: %lf\n", n, duration);
    return 0;
}
 
int primalSearch(int n)
{
    int k, tmp, count, last_primal;
    if (n == 1)
        return 2;
    else if (n == 2)
        return 3;
    else
    {
        count = 2;
        k = 1;
        while (count < n)
        {
            tmp = 6 * k - 1;
            if (isPrimal(tmp) == 1)
            {
                count++;
                last_primal = tmp;
            }
            tmp = 6 * k + 1;
            if (isPrimal(tmp) == 1)
            {
                count++;
                last_primal = tmp;
            }
            k++;
        }
        if (count == n + 1)
            return 6 * (k - 1) + 1;
        else
            return last_primal;
    }
}
 
int isPrimal(int n)
{
    if (n % 2 == 0)
        return 0;
    for (int i = 3; i < sqrt(n) + 1; i += 2)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}