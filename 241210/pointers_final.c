#include <stdio.h>

// #define DEBUG

void addOne(int arr[], unsigned size);
void printArray(const int arr[], unsigned size);
float avg(const int arr[], unsigned size);

int main()
{
    const unsigned size = 5;
    int a[] = {50, 21, 32, 83, 44};

    printf("Array before addOne():\n");
    printArray(a, size);
    printf("Avg value before addOne(): %f\n", avg(a, size));

    addOne(a, size);

    printf("Array after addOne():\n");
    printArray(a, size);
    printf("Avg value after addOne(): %f\n", avg(a, size));

    return 0;
}


void addOne(int arr[], unsigned size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i]++;
    }
}

void printArray(const int arr[], unsigned size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

float avg(const int arr[], unsigned size)
{
    float sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
#ifdef DEBUG
        printf("#### Partial sum at iteration %d = %f\n", i, sum);
#endif
    }

    return sum / size;
}
