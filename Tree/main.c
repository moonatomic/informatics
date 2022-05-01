/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include <stdio.h>
#include "headers.h"
#define SIZE 36

int main(void) {
    node* root = NULL;
	char in_filename[120];
    char out_filename[120];
	char str[120] = "\0";
	char c[2];
	char syms[SIZE] = {'#', '<', '>', '{', '}', '|', '[', ']', ';', '*', '(', ')', '=', '"', '%', '!', '\'', '\\', ' ', ',', '-', ':', '\n', '+', '&', '.', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
	FILE* ifile;
	FILE* ofile;

	// Запрашиваем имя файла для обработки
	printf("Enter input file name: ");
	scanf("%s", in_filename);
	ifile = fopen(in_filename, "r");
	if (!ifile) {
		printf("Error while opening file %s\n", in_filename); // Если файл не читается - выдаем ошибку
		return -1;
	}
	printf("Enter output file name: ");
	scanf("%s", out_filename);
    ofile = fopen(out_filename, "w");

	c[1] = '\0';
	while (fscanf(ifile, "%c", c) != EOF) { // Считываем слова из файла
		if (check_symbol(c[0], syms, SIZE)) { // Если символ разделительный и строка непустая
			if (str[0] != '\0') {
                root = add(str, root); // Добавляем ее в дерево
            }
			str[0] = '\0'; // Обнуляем строку
		}
		else strcat_(str, c); // Иначе продолжаем собирать символы в строку
	}

	treeprint(root, ofile); // Выводим дерево
	return 0;
}