#include <stdio.h>

int main()
{
    const unsigned size = 7;
    int arr[size] = {15, 25, 35, 45, 55, 65, 75};

    for (int i = 0; i < size; i++)
    {
        printf("Element at arr[%d] before: %d\n", i, arr[i]);
    }

    arr[2] = 33;
    arr[0] = 11;

    for (int i = 0; i < size; i++)
    {
        printf("Element at arr[%d] after: %d\n", i, arr[i]);
    }

    return 0;
}
