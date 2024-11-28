#include <stdio.h>

int main()
{
    const unsigned size = 7;
    int arr[size] = {15, 25, 35, 45, 55, 65, 75};

    // printf("Element at arr[2]: %d\n", arr[2]);
    // printf("Element at arr[4]: %d\n", arr[4]);

    for (int i = 0; i < size; i++)
    {
        printf("Element at arr[%d]: %d\n", i, arr[i]);
    }

    return 0;
}
