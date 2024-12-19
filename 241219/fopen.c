#include <stdio.h>

int main()
{
    FILE* fptr;
    char file_path[] = "test.txt";
    fptr = fopen(file_path, "w+");

    if (fptr == NULL)
    {
        printf("Error opening file %s\n", file_path);
        return 1;
    }

    printf("Succesfully opened file %s\n", file_path);
    printf("Now what?\n");

    fclose(fptr);

    return 0;
}
