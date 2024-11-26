#include <stdio.h>
#include <string.h>

int main()
{
    char name[] = "Mattia";
    char surname[] = "Guidolin";

    int result1 = strcmp(name, surname);
    int result2 = strcmp(name, "Mattia");
    int result3 = strcmp("Guidolin", name);

    printf("result1 = %d\n", result1);
    printf("result2 = %d\n", result2);
    printf("result3 = %d\n", result3);

    return 0;
}
