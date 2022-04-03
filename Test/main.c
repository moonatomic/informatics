#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main(void) {
    srand(time(NULL));
    for (int i = 0; i < 50; i++) printf("%2.2f\n", (double)(rand()%201 - 100) / 100);
}