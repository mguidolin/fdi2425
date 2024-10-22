#include <stdio.h>

int main()
{
    int a = 10, b = 3;

    int sum = a + b;
    printf("sum = %d\n", sum);

    int diff = a - b;
    printf("diff = %d\n", diff);

    int mod = a % b; // 10 = 3 * 3 + 1
    printf("mod = %d\n", mod);

    double div = a / b;
    printf("div = %f\n", div);

    return 0;
}
