#include <stdio.h>
#include <stdbool.h>

int main()
{
    bool a = true, b = false, c = false;
    int x = 6, y = 7;

    printf("a && b = %d\n", a && b);
    printf("a || b = %d\n", a || b);
    printf("!a = %d\n", !a);

    bool res = (a || b) && !(x > y);
    // a || b = true || false = true
    // !c = !false = true
    // (a || b) && !c = true && true = true
    printf("res = %d\n", res);

    return 0;
}
