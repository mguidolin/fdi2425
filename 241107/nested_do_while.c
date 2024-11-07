#include <stdio.h>

int main()
{
    int end = 5;
    int i = 1;

    do
    {
        int j = 1;

        do
        {
            printf("%d ", j);
            j++;
        }
        while (j <= i);

        printf("\n");
        i++;
    }
    while (i <= end);

    return 0;
}
