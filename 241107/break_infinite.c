#include <stdio.h>

int main()
{
    int i = 0;

    while (1)
    {
        printf("Help! %d\n", i);
        i++;

        if (i > 10)
        {
            break;
        }
    }

    return 0;
}
