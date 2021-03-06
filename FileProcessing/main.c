/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#include <stdio.h>
#define FILENAME_LEN 120
#define SIZE 36

int main(void) {
    FILE* fin;
    FILE* fout;
    char in_fn[FILENAME_LEN];
    char out_fn[FILENAME_LEN];
    char syms[SIZE] = {'#', '<', '>', '{', '}', '|', '[', ']', ';', '*', '(', ')', '=', '"', '%', '!', '\'', '\\', ' ', ',', '-', ':', '\n', '+', '&', '.', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int res;

    printf("Hello! This program transfers every word from input file to output file.\n");
    printf("Enter input file name: "); // Спрашиваем имя входного файла 
    scanf("%s", in_fn);
    fin = fopen(in_fn, "r");
    if (!fin) {
        printf("Unable to open %s\n", in_fn); // Если не удается открыть - выдаем ошибку
        return -1;
    }
    printf("Enter output file name: "); // Спрашиваем имя выходного файла
    scanf("%s", out_fn);
    fout = fopen(out_fn, "w");

    res = read(fin, fout, syms, SIZE); // Переписываем слова в выходной файл
    printf("Words read: %d\n", res);
    if (res == 0) {
        printf("File is empty\n");
    }

    fclose(fin);
    fclose(fout);
    return 0;
}