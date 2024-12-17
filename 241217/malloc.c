#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned n_elements;

    // Get the number of elements for the array
    printf("Enter the number of elements: ");
    scanf("%u", &n_elements);

    // Dynamically allocate memory using malloc()
    printf("Allocationg memory for %u elements\n", n_elements);
    int* ptr = (int*)malloc(n_elements * sizeof(int));

    // Check if the memory was correctly allocated
    if (ptr == NULL)
    {
        printf("Call to malloc() failed\n");
        return 1;
    }

    // Populate the array with the first n_elements odd numbers
    for (int i = 0; i < n_elements; i++)
    {
        ptr[i] = 2 * i + 1;
    }

    // Print the elements of the array
    for (int i = 0; i < n_elements; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    free(ptr);
    printf("Memory succesfully freed\n");

    return 0;
}
