#include <stdio.h>

void printArray(const int arr[], unsigned size);
void swap(int* a, int* b);
int* partition(int* low, int* high);
void quicksort_ptr(int* low, int* high);
void quicksort(int arr[], unsigned size);

int main()
{
    const unsigned size = 7;
    int arr[size] = {64, 25, 12, 22, 11, 0, 0};

    printf("Original array: ");
    printArray(arr, size);

    quicksort(arr, size);

    printf("Ordered array:  ");
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

void quicksort_ptr(int* low, int* high)
{
    if (low < high)
    {
        int* pivot = partition(low, high);

        quicksort_ptr(low, pivot - 1);
        quicksort_ptr(pivot + 1, high);
    }
}

void quicksort(int arr[], unsigned size)
{
    if (size <= 1)
    {
        return;
    }

    quicksort_ptr(arr, arr + size - 1);
}
