#include <stdio.h>

int main()
{
    // This is a comment
    printf("1st\n"); // This is also a single line comment
    // printf("2nd\n");
    printf("3rd\n");

    /************************
     * This is a multi line *
     * comment              *
     ************************/

    int a = 1, b = 2, c = 3;
    int res = a /* + b */ + c;
    printf("res = %d\n", res);

    return 0;
}
