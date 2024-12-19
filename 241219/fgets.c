#include <stdio.h>

int main()
{
    FILE* fptr;
    char file_path[] = "intro.txt";
    char buffer[256];
    unsigned cnt = 0;

    fptr = fopen(file_path, "r");

    if (fptr == NULL)
    {
        printf("Error opening file %s\n", file_path);
        return 1;
    }

    printf("Content of file %s:\n", file_path);

    // Read content of file, line by line
    while (fgets(buffer, 256, fptr) != NULL)
    {
        // printf("line %u: '%s'\n", cnt++, buffer);
        printf("%s", buffer);
    }

    fclose(fptr);

    return 0;
}
