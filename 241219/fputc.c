#include <stdio.h>

int main()
{
    FILE* fptr;
    char file_path[] = "example_fputc.txt";

    fptr = fopen(file_path, "w");

    if (fptr == NULL)
    {
        printf("Error opening file %s\n", file_path);
        return 1;
    }

    fputc('M', fptr);
    fputc('G', fptr);
    fputc('\n', fptr);

    fclose(fptr);

    return 0;
}
