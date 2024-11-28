#include <stdio.h>
#include <string.h>

#define MAX 50

int main()
{
    char str[MAX];

    printf("What's your name? ");
    fgets(str, MAX, stdin);
    str[strlen(str) - 1] = '\0';

    printf("\nHello, %s!\n", str);

    return 0;
}
