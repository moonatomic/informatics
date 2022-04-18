/*
(c) 2022 Петров Михаил Вадимович группа 112
*/

#include <stdio.h>
#include <string.h>
#include "headers.h"
#define MAX_STR_LEN 64

int main(void) {
    char string1[MAX_STR_LEN];
    char string2[MAX_STR_LEN];
    char string3[MAX_STR_LEN] = {};
    char symb = 'a';

    int result;

    printf("Enter 1st string: "); // Запрашиваем строки для тестирования
    scanf("%s", string1);
    printf("Enter 2nd string: ");
    scanf("%s", string2);

    printf("\n/------- My strcmp_ -------/\n");
    result = strcmp_(string1, string2);
    printf("%d for string1 and string2\n", result);
    result = strcmp_(string1, string1);
    printf("%d for string1 and string1\n", result);

    printf("\n/------- String.h strcmp -------/\n");
    result = strcmp(string1, string2);
    printf("%d for string1 and string2\n", result);
    result = strcmp(string1, string1);
    printf("%d for string1 and string1\n", result);

    printf("\n/------- My strncmp_ -------/\n");
    result = strncmp_(string1, string2, 5);
    printf("%d for string1 and string2\n", result);
    result = strncmp_(string1, string1, 5);
    printf("%d for string1 and string1\n", result);

    printf("\n/------- String.h strncmp -------/\n");
    result = strncmp(string1, string2, 5);
    printf("%d for string1 and string2\n", result);
    result = strncmp(string1, string1, 5);
    printf("%d for string1 and string1\n", result);



    printf("\n/------- My strlen_ -------/\n");
    result = strlen_(string1);
    printf("1st string length is %d\n", result);

    printf("\n/------- String.h strlen -------/\n");
    result = strlen(string1);
    printf("1st string length is %d\n", result);



    printf("\n/------- My strcpy_ -------/\n");
    strcpy_(string3, string2);
    printf("Result is now %s\n", string3);

    printf("\n/------- String.h strcpy -------/\n");
    strcpy(string3, string2);
    printf("Result is now %s\n", string3);

    printf("\n/------- My strncpy_ -------/\n");
    strncpy_(string3, string2, 5);
    printf("Result is now %s\n", string3);

    printf("\n/------- String.h strncpy -------/\n");
    strncpy(string3, string2, 5);
    printf("Result is now %s\n", string3);



    printf("\n/------- My strcat_ -------/\n");
    strcat_(string3, string2);
    printf("%s for string2\n", string3);

    printf("\n/------- String.h strcat -------/\n");
    strcat(string3, string2);
    printf("%s for string2\n", string3);

    printf("\n/------- My strncat_ -------/\n");
    strncat_(string3, string2, 5);
    printf("%s for string2\n", string3);

    printf("\n/------- String.h strncat -------/\n");
    strncat(string3, string2, 5);
    printf("%s for string2\n", string3);




    printf("\n/------- My strset_ -------/\n");
    strset_(string3, symb);
    printf("Result is now %s\n", string3);

    printf("\n/------- My strnset_ -------/\n");
    strnset_(string3, symb, 5);
    printf("Result is now %s\n", string3);

    return 0;
}