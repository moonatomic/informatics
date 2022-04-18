/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

char * strcat_(char * s1, char * s2); // Присоединяет s2 к s1, возвращает s1
char * strncat_(char * s1, char * s2, int n); // Присоединяет не более n символов s2 к s1, завершает строку символом '\0', возвращает s1
char * strcpy_(char * s1, char * s2); // Копирует строку s2 в строку s1, включая '\0', возвращает s1
char * strncpy_(char * s1, char * s2, int n); // Копирует не более n символов строки s2 в строку s1, возвращает s1;
char * strset_(char * s, char c); // Заполняет строку s символами, код которых равен значению c, возвращает указатель на строку s
char * strnset_(char * s, char c, int n); // Заменяет первые n символов строки s символами, код которых равен c, возвращает указатель на строку s
int strcmp_(char * s1, char * s2); // Сравнивает s1 и s2, возвращает значение 0, если строки эквивалентны
int strncmp_(char * s1, char * s2, int n); // Сравнивает не более n символов строк s1 и s2, возвращает значение 0, если начальные n символов строк эквивалентны
int strlen_(char * s); // Возвращает количество символов в строке s