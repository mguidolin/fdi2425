#include <stdio.h>

int main()
{
    for (int i = 0; i < 2; ++i)
    {
        printf("Outer loop: i = %d\n", i);

        for (int j = 0; j < 3; ++j)
        {
            printf("    Inner loop: j = %d\n", j);
        }
    }

    return 0;
}
