#include <stdio.h>

int main()
{
    int i = 10;

    do
    {
        i++;
        printf("Hello %d\n", i);
    }
    while (i < 3);

    return 0;
}
