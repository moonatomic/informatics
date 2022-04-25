/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#include <stdio.h>
#define STR_LEN 120

// Выводит все слова из файла fin в файл fout в порядке их появления
// Возвращает количество прочитанных слов
int read(FILE* fin, FILE* fout) {
    int am = 0;
    char c[2];
    char str[STR_LEN];
    c[1] = '\0';
    c[0] = '\0';
    while (fscanf(fin, "%c", c) != EOF) { // Считываем слова из файла
        if (check_symbol(c[0])) { // Если символ разделительный и строка непустая
            if (str[0] != '\0') {
                fprintf(fout, "%s\n", str); // Добавляем слово в файл
                am++;
            }
            str[0] = '\0'; // Обнуляем строку
        }
        else {
            strcat_(str, c); // Иначе продолжаем собирать символы в строку
        }
	}
    return am;
}

// Проверяет символ c на валидность
// Возвращает 1, если символ плохой, иначе 0
int check_symbol(char c) {
    if (c == '#' || c == '<' || c == '>' || c == '{' || c == '}' || c == '|' ||
        c == '[' || c == ']' || c == ';' || c == '*' || c == '(' || c == ')' ||
        c == '=' || c == '"' || c == '%' || c == '!' || c == '\'' || c == '\\' ||
        c == ' ' || c == ',' || c == '-' || c == ':' || c == '\n' ||
        c == '+' || c == '&' || (c >= '0' && c <= '9')) {
        return 1;
    }
    return 0;
}

char* strcat_(char* s1, char* s2) { // Присоединяет s2 к s1, возвращает s1
    strcpy_(s1 + strlen_(s1), s2);
    return s1;
}

char* strcpy_(char* s1, char* s2) { // Копирует строку s2 в строку s1, включая '\0', возвращает s1
    int i = 0;
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return s1;
}

char* strset_(char* s, char c) { // Заполняет строку s символами, код которых равен значению c, возвращает указатель на строку s
    int i = 0;
    while (s[i] != '\0') {
        s[i] = c;
        i++;
    }
    return s;
}

int strcmp_(char* s1, char* s2){ // Сравнивает s1 и s2, возвращает значение 0, если строки эквивалентны
    char c1, c2;
    do {
        c1 = (char) * s1++;
        c2 = (char) * s2++;
        if (c1 == '\0') {
            return c1 - c2;
        }
    } while (c1 == c2);
    return c1 - c2;
}

int strlen_(char* s) { // Возвращает количество символов в строке s
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}