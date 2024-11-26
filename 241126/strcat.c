#include <stdio.h>
#include <string.h>

int main()
{
    char destination[20] = "This is an";
    char source[20] = " example";

    printf("Destination before strcat(): '%s'\n", destination);

    strcat(destination, source);
    printf("Destination after strcat(): '%s'\n", destination);

    return 0;
}
