#include <stdio.h>
#include <stdbool.h>

void printArray(const int arr[], unsigned size);
void swap(int* a, int* b);
void bubble_sort(int arr[], unsigned size);

int main()
{
    const unsigned size = 5;
    int arr[size] = {64, 25, 12, 22, 11};

    printf("Original array: ");
    printArray(arr, size);

    bubble_sort(arr, size);

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

void bubble_sort(int arr[], unsigned size)
{
    // Keep track of the current step (size of the unordinered subarray = size - step)
    for (int step = 0; step < size - 1; step++)
    {
        // Used to check if the subarray is already ordered
        bool swapped = false;

        // Iterate from the first to the last unordered elements
        for (int current = 0; current < size - step - 1; current++)
        {
            // If the two elements are not in the correct order, swap them
            if (arr[current] > arr[current + 1])
            {
                swap(&arr[current], &arr[current + 1]);
                swapped = true;
            }
        }

        if (!swapped)
        {
            return;
        }
    }
}
