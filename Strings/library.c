/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include "headers.h"
#define MAX_STR_LEN 64

int strlen_(char * s) { // Возвращает количество символов в строке s
    int i = 0;
    while (s[i] != '\0') {
        i++;
    }
    return i;
}

int strcmp_(char * s1, char * s2){ // Сравнивает s1 и s2, возвращает значение 0, если строки эквивалентны
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

int strncmp_(char * s1, char * s2, int n) { // Сравнивает не более n символов строк s1 и s2, возвращает значение 0, если начальные n символов строк эквивалентны
    char c1, c2;
    int cnt;
    do {
        cnt++;
        c1 = (char) * s1++;
        c2 = (char) * s2++;
        if (c1 == '\0') {
            return c1 - c2;
        }
    } while (c1 == c2 && cnt < n);
    return c1 - c2;
}

char * strset_(char * s, char c) { // Заполняет строку s символами, код которых равен значению c, возвращает указатель на строку s
    int i = 0;
    while (s[i] != '\0') {
        s[i] = c;
        i++;
    }
    return s;
}

char * strnset_(char * s, char c, int n) { // Заменяет первые n символов строки s символами, код которых равен c, возвращает указатель на строку s
    int i = 0;
    while ((i < n) && (s[i] != '\0')) {
        s[i] = c;
        i++;
    }
    return s;
}

char * strcpy_(char * s1, char * s2) { // Копирует строку s2 в строку s1, включая '\0', возвращает s1
    int i = 0;
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return s1;
}

char * strncpy_(char * s1, char * s2, int n) { // Копирует не более n символов строки s2 в строку s1, возвращает s1;
    int i = 0;
    while (s2[i] != '\0' && i < n) {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return s1;
}

char * strcat_(char * s1, char * s2) { // Присоединяет s2 к s1, возвращает s1
    strcpy_(s1 + strlen_(s1), s2);
    return s1;
}

char * strncat_(char * s1, char * s2, int n) { // Присоединяет не более n символов s2 к s1, завершает строку символом '\0', возвращает s1
    strncpy_(s1 + strlen_(s1), s2, n);
    return s1;
}
