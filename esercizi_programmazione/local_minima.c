#include <stdio.h>

void local_minima(int *matrix, int* local_map, int size)
{
    for (int row = 0; row < size; ++row)
    {
        for (int col = 0; col < size; ++col)
        {
            // calcualte the 1D index corresponding to (row, col)
            int idx = row * size + col;
            int curr = matrix[idx];
            // start by assuming the current element is a local minimum
            int is_min = 1;

            // check the element above (if it exists)
            if (row > 0 && matrix[idx - size] < curr)
            {
                // if any neighbor is smaller, it's not a local minimum
                is_min = 0;
            }

            // check the element below (if it exists)
            if (row < size - 1 && matrix[idx + size] < curr)
            {
                // if any neighbor is smaller, it's not a local minimum
                is_min = 0;
            }

            // check the element to the left (if it exists)
            if (col > 0 && matrix[idx - 1] < curr)
            {
                // if any neighbor is smaller, it's not a local minimum
                is_min = 0;
            }

            // check the element to the right (if it exists)
            if (col < size - 1 && matrix[idx + 1] < curr)
            {
                // if any neighbor is smaller, it's not a local minimum
                is_min = 0;
            }

            // store the result in the local minima map (1 if local minimum, 0 otherwise)
            local_map[idx] = is_min;
        }
    }
}

void print_matrix(int* matrix, int size)
{
    for (int row = 0; row < size; ++row)
    {
        for (int col = 0; col < size; ++col)
        {
            printf("%d ", matrix[row * size + col]);
        }
        printf("\n");
    }
}

int main()
{
    int matrix[] = {1,  2,  2,
                    3,  2,  2,
                    0, -1,  5};
    int size = 3;
    int local_map[9];

    local_minima(matrix, local_map, size);

    printf("Initial matrix:\n");
    print_matrix(matrix, size);

    printf("Local map:\n");
    print_matrix(local_map, size);

    return 0;
}
