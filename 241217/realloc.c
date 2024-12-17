#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Get the number of elements for the array
    printf("Enter the number of elements: ");
    unsigned n_elements;
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
    printf("Array content after malloc()\n");
    for (int i = 0; i < n_elements; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Get the number of elements to add
    printf("Enter the number of elements to add: ");
    unsigned n_elems_to_add;
    scanf("%u", &n_elems_to_add);
    n_elements += n_elems_to_add;

    // Dynamically reallocate memory using realloc()
    printf("Allocating memoery for %u new elements\n", n_elems_to_add);
    ptr = (int*)realloc(ptr, n_elements * sizeof(int));

    // Check if the memory was correctly allocated
    if (ptr == NULL)
    {
        printf("Call to realloc() failed\n");
        return 1;
    }

    // Populate the array with the n_elements even numbers
    for (int i = n_elements - n_elems_to_add; i < n_elements; i++)
    {
        ptr[i] = 2 * i;
    }

    // Print the elements of the array
    printf("Array content after realloc()\n");
    for (int i = 0; i < n_elements; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");

    // Now we can free the memory
    free(ptr);
    printf("Memory succesfully freed\n");

    return 0;
}
