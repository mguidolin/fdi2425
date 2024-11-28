#include <stdio.h>

int main()
{
    const unsigned n_rows = 2;
    const unsigned n_cols = 3;
    float matrix[n_rows][n_cols] = {{1.1, 2.2, 3.3},
                                    {4.4, 5.5, 6.6}};

    printf("2D array:\n");
    for (int row = 0; row < n_rows; row++)
    {
        for (int col = 0; col < n_cols; col++)
        {
            printf("%f ", matrix[row][col]);
        }
        printf("\n");
    }

    return 0;
}
