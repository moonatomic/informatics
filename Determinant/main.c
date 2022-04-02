/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include <stdio.h>
#include "headers.h"
#define MAT_SIZE 20
#define NAME_LEN 100

int main(void) {
    double matrix[MAT_SIZE][MAT_SIZE];
    double number;

    char filename[NAME_LEN];
    
    int mode;
    int size;

    FILE * mat_in;
    FILE * mat_out;

    mat_out = fopen("matrix_out.txt", "w");

    printf("Enter matrix size:");
    scanf("%d", &size);

    printf("Select matrix input mode:\n1) From file\n2) Random generated");
    scanf("%d", &mode);

    if (mode == 1) {
        printf("Enter input fiile name: ");
        scanf("%s", filename);
        mat_in = fopen(filename, "r");
        if (!mat_in) {
            printf("Error while opening %s\n", filename);
            return -2;
        }
        for (int i = 0; i < size; i++) {
            for (int j = 0; i < size; i++) {
                if (fscanf(mat_in, "%lf", &number) == 1) {
                    matrix[i][j] = number;
                } else {
                    printf("Incorrect data in file %s\n", filename);
                    return -3;
                }
            }
        }
    } else if (mode == 2) {
        generate(matrix, size);
    } else {
        printf("Incorrect option.\n");
        return -1;
    }

    return 0;
}