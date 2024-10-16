#include <stdio.h>

int main()
{
    unsigned int size_of_int = sizeof(int);
    unsigned int size_of_float = sizeof(float);
    unsigned int size_of_double = sizeof(double);

    printf("The size of int is %u bytes\n", size_of_int);
    printf("The size of float is %u bytes\n", size_of_float);
    printf("The size of double is %u bytes\n", size_of_double);

    return 0;
}
