#include <stdio.h>

int main()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j <= 4; j++)
        {
            if (j == 2)
            {
                continue;
            }
            else
            {
                printf("i = %d, j = %d\n", i, j);
            }
        }

        printf("----\n");
    }

    return 0;
}
