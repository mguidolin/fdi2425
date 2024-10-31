#include <stdio.h>

int main()
{
    int first, second;
    printf("Insert the first number: ");
    scanf("%d", &first);

    printf("Insert the second number: ");
    scanf("%d", &second);

    if (first > second)
    {
        printf("%d is greater than %d\n", first, second);
    }
    else
    {
        printf("%d is less or equal than %d\n", first, second);
    }

    printf("Outside of the if-else\n");

    return 0;
}
