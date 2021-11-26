#include <stdio.h>

int main(void) {
    int bb = 1;
    for (int i = 0; i < 31; i++) {
        bb *= 2;
    }
    int number = -2;
    if ((number & bb) == bb) {
        printf("%d\n", bb);
    }
    return 0;
}