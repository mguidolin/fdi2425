#include <stdio.h>

void swap(int* a, int* b);
void printArray(const int arr[], unsigned size);
void reverseArray(int arr[], unsigned size);

int main()
{
    const unsigned size = 7;
    int steps[size] = {1, 2, 3, 4, 5, 10, 100};

    printf("Steps before reverse:\n");
    printArray(steps, size);

    reverseArray(steps, size);

    printf("Steps after reverse:\n");
    printArray(steps, size);

    return 0;
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void printArray(const int arr[], unsigned size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void reverseArray(int arr[], unsigned size)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(&arr[i], &arr[size - i - 1]);
    }
}
