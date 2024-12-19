#include <stdio.h>

int main()
{
    FILE* fptr;
    char file_path[] = "example_fputs.txt";

    fptr = fopen(file_path, "w");

    if (fptr == NULL)
    {
        printf("Error opening file %s\n", file_path);
        return 1;
    }

    fputs("\"Good news, everyone!\"\n", fptr);
    fputs("- Prof. Hubert J. Farnsworth\n", fptr);

    fclose(fptr);

    return 0;
}
