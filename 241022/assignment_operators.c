#include <stdio.h>

int main()
{
    int a = 10;
    printf("a = %d\n", a);

    int b = 5;
    b += a; // Equivalent to: b = b + a;
    printf("b = %d\n", b);

    int c = 3;
    c -= b; // Equivalent to: c = c - b;
    printf("c = %d\n", c);

    int d = -2;
    d *= c; // Equivalent to: d = d * c;
    printf("d = %d\n", d);

    int e = 70;
    e /= d; // Equivalent to: e = e / d;
    printf("e = %d\n", e);

    return 0;
}
