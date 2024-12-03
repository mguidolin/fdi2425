#include <stdio.h>

int main()
{
    int var = 15 + 18;
    int* ptr = &var;

    printf("Before: ptr: %p\n", ptr);
    printf("Before: var: %d\n", var);
    printf("Before: *ptr: %d\n", *ptr);

    *ptr = 36;

    printf("After: ptr: %p\n", ptr);
    printf("After: var: %d\n", var);
    printf("After: *ptr: %d\n", *ptr);

    var = 42;

    printf("After2: ptr: %p\n", ptr);
    printf("After2: var: %d\n", var);
    printf("After2: *ptr: %d\n", *ptr);

    return 0;
}
