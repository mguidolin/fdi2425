#include <stdio.h>

int main()
{
    FILE* fptr;
    char file_path[] = "secret_number.txt";
    char c;
    unsigned cnt = 0;

    fptr = fopen(file_path, "r");

    if (fptr == NULL)
    {
        printf("Error opening file %s\n", file_path);
        return 1;
    }

    printf("Content of file %s:\n", file_path);

    // Read content of file, char by char
    while ((c = fgetc(fptr)) != EOF)
    {
        // printf("char %u: '%c'\n", cnt++, c);
        printf("%c", c);
    }

    fclose(fptr);

    return 0;
}
