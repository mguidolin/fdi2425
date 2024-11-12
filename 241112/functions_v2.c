#include <stdio.h>

int magic_sum(int x, int y)
{
    return 2 * x + 3 * y;
}

int main()
{
    int v1, v2, v3;

    v1 = 10;
    v2 = 32;
    v3 = -5;

    printf("tot = %d\n", magic_sum(magic_sum(v1, v2), v3));

    return 0;
}
