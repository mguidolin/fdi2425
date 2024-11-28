#include <stdio.h>

int main()
{
    // declare string
    char str[50];

    // read string
    printf("What's your name? ");
    scanf("%s", str);

    // print string
    printf("\nHello, %s!\n", str);

    return 0;
}
