#include "Check.h"

int check()
{
    int a = 0;
    char str[100];
    while (scanf_s("%d", &a), getchar() != '\n') {
        printf("\nError\n");
        fgets(str, 100, stdin);
    }
    return a;
}

int pos_check()
{
    int a;
    for (; a = check(), a < 0; printf("\nError\n"));
    return a;
}