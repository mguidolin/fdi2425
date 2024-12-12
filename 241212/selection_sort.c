#include <stdio.h>

void printArray(const int arr[], unsigned size);
void swap(int* a, int* b);
void selection_sort(int arr[], unsigned size);

int main()
{
    const unsigned size = 5;
    int arr[size] = {64, 25, 12, 22, 11};

    printf("Original array: ");
    printArray(arr, size);

    selection_sort(arr, size);

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

void selection_sort(int arr[], unsigned size)
{
    for (int next = 0; next < size - 1; next++)
    {
        // Search the minimum value of the subarray from idx = next to idx = size - 1
        int min_idx = next;

        // Iterate through the unsorted portion of the array
        for (int idx = next + 1; idx < size; idx++)
        {
            if (arr[idx] < arr[min_idx])
            {
                min_idx = idx;
            }
        }

        // Swap the first element of the subarray with the minimum
        swap(&arr[next], &arr[min_idx]);
    }
}
