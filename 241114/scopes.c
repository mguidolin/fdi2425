#include <stdio.h>

int main()
{
    int x = 10, y = 20;

    {
        printf("x = %d, y = %d\n", x, y);

        {
            x++;
            y++;
            int z = 30;

            printf("x = %d, y = %d, z = %d\n", x, y, z);
        }

        printf("x = %d\n", x);
        printf("y = %d\n", y);
        // printf("z = %d\n", z);
    }

    return 0;
}
