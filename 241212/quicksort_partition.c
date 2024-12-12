#include <stdio.h>
#include <stdbool.h>

void printArray(const int arr[], unsigned size);
void swap(int* a, int* b);
int* partition(int* low, int* high);

int main()
{
    const unsigned size = 5;
    int arr[size] = {64, 25, 12, 22, 11};

    printf("Original array: ");
    printArray(arr, size);

    return 0;
}

void printArray(const int arr[], unsigned size)
{
    for (int i =0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* a, int* b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int* partition(int* low, int* high)
{
    int* pivot = high;
    int* i = low - 1;

    for (int* j = low; j < high; ++j)
    {
        if (*j < *pivot)
        {
            swap(++i, j);
        }
    }

    swap(i + 1, pivot);
    return i + 1;
}
