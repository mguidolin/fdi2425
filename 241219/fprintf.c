#include <stdio.h>

int main()
{
    FILE* fptr;
    char file_path[] = "example_fprintf.txt";

    fptr = fopen(file_path, "w");

    if (fptr == NULL)
    {
        printf("Error opening file %s\n", file_path);
        return 1;
    }

    int n = 42;
    float f = 12.345;
    char name[] = "Mattia";

    fprintf(fptr, "Name: %s\n", name);
    fprintf(fptr, "Lucky number: %d\n", n);
    fprintf(fptr, "Formatted float: %.2f\n", f);

    fclose(fptr);

    return 0;
}
