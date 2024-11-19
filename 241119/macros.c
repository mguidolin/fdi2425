#include <stdio.h>

#define SQUARE(x) (x * x)
#define SQUARE2(x) ((x) * (x))

int main()
{
    int a = -3;

    printf("(%d)^2 = %d\n", a, SQUARE(a));
    printf("(%d)^2 = %d\n", a + 1, SQUARE(a + 1)); // SQUARE(a + 1) -> (a + 1 * a + 1) -> (-3 + 1 * -3 + 1) -> -5
    printf("(%d)^2 = %d\n", a + 1, SQUARE2(a + 1)); // SQUARE2(a + 1) -> ((a + 1) * (a + 1)) -> ((-2) * (-2)) -> 4

    return 0;
}
