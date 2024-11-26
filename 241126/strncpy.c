#include <stdio.h>
#include <string.h>

int main()
{
    char source[] = "I am a string! :D";
    char destination[20];

    printf("Source: '%s'\n", source);
    printf("Destination: '%s'\n", destination);

    strncpy(destination, source, 13);
    printf("Destination after strcpy(): '%s'\n", destination);

    return 0;
}
