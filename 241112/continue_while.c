#include <stdio.h>

int main()
{
    int i = -1;

    while (i < 10)
    {
        i++;

        if (i == 4)
        {
            continue;
        }

        printf("i = %d\n", i);
    }

    return 0;
}
