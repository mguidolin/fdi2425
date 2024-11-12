#include <stdio.h>

int main()
{
    int i = -1;

    do
    {
        i++;

        if (i == 4)
        {
            continue;
        }

        printf("i = %d\n", i);
    }
    while (i < 10);

    return 0;
}
