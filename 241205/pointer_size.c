#include <stdio.h>

int main()
{
    int a = 10;
    double b = 4.2;

    printf("Size of int:    %lu bytes\n", sizeof(a));
    printf("Size of double: %lu bytes\n", sizeof(b));

    int* ptr2a = &a;
    double* ptr2b = &b;

    printf("Size of ptr to int:    %lu bytes\n", sizeof(ptr2a));
    printf("Size of ptr to double: %lu bytes\n", sizeof(ptr2b));

    return 0;
}
