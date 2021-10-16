#include <stdio.h>
#include "headers.h"

int compare(int *set_A, int *set_B, int len_A, int len_B) {
    int AiB = 1, BiA = 1; // Возможные отношения между множествами
    for (int i = 0; i < len_A; i++) {
        if (has(set_B, len_B, set_A[i]) == 0) { // Если B не содержит хотя бы один элемент из A
            BiA = 0; // B уже точно не содержит A
            break;
        }
    }
    for (int i = 0; i < len_B; i++) {
        if (has(set_A, len_A, set_B[i]) == 0) { // Если A не содержит хотя бы один элемент из B
            AiB = 0; // A уже точно не содержит B
            break;
        }
    }

    if (AiB && BiA == 1) {
        return 1;
    } else if (AiB == 1) {
        return 2;
    } else if (BiA == 1) {
        return 3;
    } else {
        return 4;
    }
}