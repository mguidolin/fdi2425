#include <stdio.h>
#include <stdbool.h>

int main()
{
    int var;
    bool flag = true;

    var = flag ? 25 : -25;
    printf("var = %d\n", var);

    return 0;
}
