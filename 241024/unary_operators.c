#include <stdio.h>

int main()
{
    int x = 10;
    int a = ++x; // Becomes: x = x + 1; a = x;
    printf("Pre-increment: x = %d, a = %d\n", x, a);

    x = 10;
    a = x++; // Becomes: int tmp = x; x = x + 1; a = tmp;
    printf("Post-increment: x = %d, a = %d\n", x, a);

    x = 10;
    a = --x; // Becomes: x = x - 1; a = x;
    printf("Pre-decrement: x = %d, a = %d\n", x, a);

    x = 10;
    a = x--; // Becomes: int tmp = x; x = x - 1; a = tmp;
    printf("Post-decrement: x = %d, a = %d\n", x, a);

    x = 10;
    a = -x;
    printf("x = %d, a = %d\n", x, a);

    return 0;
}
