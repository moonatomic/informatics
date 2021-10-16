#include <stdio.h>
#include "headers.h"

int has(int *set, int len, int num) {
    for (int i = 0; i < len; i++) {
        if (set[i] == num) {
            return 1;
        }
    }
    return 0;
}