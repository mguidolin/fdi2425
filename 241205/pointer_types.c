#include <stdio.h>

struct Point
{
    float x;
    float y;
};

int main()
{
    // Pointers to primitive data types
    float x = 42.0;
    float* ptr2x = &x;

    printf("Value of ptr2x: %p\n", ptr2x);
    printf("Value pointed: %f\n", *ptr2x);
    printf("----\n");

    // Pointers to arrays
    int arr[] = {10, 9, 8, 7};
    int* ptr2arr = arr;

    printf("Value of ptr2arr: %p\n", ptr2arr);
    printf("Value pointed: %d\n", *ptr2arr);
    printf("----\n");

    // Pointers to structs
    struct Point origin = {.x = 0., .y = 0.};
    struct Point *ptr2origin = &origin;

    printf("Value of ptr2origin: %p\n", ptr2origin);
    printf("Value pointed (x): %f\n", ptr2origin->x);
    printf("Value pointed (y): %f\n", ptr2origin->y);
    printf("----\n");

    // Double pointers
    int n = 134567;

    int* ptr2n = &n;
    int** ptr2ptr2n = &ptr2n;

    printf("Value of ptr2n: %p\n", ptr2n);
    printf("Value of ptr2ptr2n: %p\n", ptr2ptr2n);
    printf("Value pointed by ptr2n: %d\n", *ptr2n);
    printf("Value pointed by ptr2ptr2n: %p\n", *ptr2ptr2n);
    printf("Value of n: %d\n", **ptr2ptr2n);
    printf("----\n");

    // Pointers to NULL
    int* ptr2int = NULL;
    struct Point* ptr2point = NULL;

    printf("Value of ptr2int: %p\n", ptr2int);
    printf("Value of ptr2point: %p\n", ptr2point);
    printf("----\n");

    // Void pointers
    void* ptr_void;
    ptr_void = &n;

    printf("Value of ptr_void: %p\n", ptr_void);
    printf("Value pointed by ptr_void: %d\n", *(int*)ptr_void);

    return 0;
}
