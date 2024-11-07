#include <stdio.h>

int main()
{
    int max = 100;

    for (int n = max; n >= 0; n--)
    {
        // printf("n: %d\n", n);

        if (n % 3 == 0 && n % 4 == 0 && n % 5 == 0)
        {
            printf("The largest number <= %d divisible by 3, 4, 5 is: %d\n", max, n);
            break;
        }
    }

    return 0;
}
