#include <stdio.h>

int main()
{
    int x = -10;
    int y = -3;

    if (x > 0)
    {
        printf("x is positive\n");

        if (y > 0)
        {
            printf("  y is positive\n");
        }
        else
        {
            printf("  y is not positive\n");
        }
    }
    else
    {
        printf("x is not positive\n");
    }

    printf("Goodbye\n");

    return 0;
}
