#include <stdio.h>

int sum(int x, int y)
{
    int result = x + y;
    return result;
}

int main()
{
    int v1, v2, v3, tot;

    v1 = 10;
    v2 = 32;
    v3 = -5;

    tot = sum(v1, v2);
    printf("tot = %d\n", tot);

    tot = sum(tot, v3);
    printf("tot = %d\n", tot);

    return 0;
}
