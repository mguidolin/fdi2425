#include <stdio.h>

int main()
{
    // array initialization using initializer list
    int array1[5] = {10, 20, 30, 40, 50};

    // array initialization using initializer list without specifing the size
    int array2[] = {1, 2, 3, 4, 5};

    // array initialization using for loop
    int array3[5];
    for (int i = 0; i < 5; i++)
    {
        array3[i] = (float)i * 2.1;
    }

    return 0;
}
