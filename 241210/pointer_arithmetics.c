#include <stdio.h>

int main()
{
    const unsigned size = 3;
    double arr[size] = {10.1, 100.2, 1000.3};

    // Basic operations
    double* ptr1 = arr;

    for (int i = 0; i < size; i++)
    {
        printf("Value of ptr1: %p\n", ptr1);
        printf("Value pointed by ptr1: %lf\n", *ptr1);
        ptr1++;
    }
    printf("----\n");

    ptr1 -= 2;
    printf("Value of ptr1: %p\n", ptr1);
    printf("Value pointed by ptr1: %lf\n", *ptr1);

    // Pointer subtraction
    double* ptr2 = &arr[size - 1];
    int diff = ptr1 - ptr2;
    printf("Diff: %d\n", diff);

    // Pointer comparison
    if (ptr1 < ptr2)
    {
        printf("ptr1 points to an element which is before the one pointed by ptr2\n");
    }
    else if (ptr1 > ptr2)
    {
        printf("ptr1 points to an element which is after the one pointed by ptr2\n");
    }
    else
    {
        printf("They both point to the same element\n");
    }

    // Pointer assignment
    double* ptr3 = ptr2;

    printf("Value of ptr2: %p\n", ptr2);
    printf("Value of ptr3: %p\n", ptr3);

    return 0;
}
