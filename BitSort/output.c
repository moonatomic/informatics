#include "headers.h"
#include <stdio.h>

void output(FILE * fout, int * mass, int len) {
    char bits[32];
    int number;
    int ones;

    fprintf(fout, "Number\t\t\t\tBinary\t\t\t\t\t1's amount\n");
    for (int i = 0; i < len; i++) {
        number = mass[i];
        ones = countBits(number);
        bin(number, bits);

        fprintf(fout, "%d\t\t", number);
        for (int j = 0; j < 32; j++) {
            fprintf(fout, "%d", bits[j]);
            if (j%8 == 7) {
                fprintf(fout, " ");
            }
        }
        fprintf(fout, "\t\t%d\n", ones);
    }

}