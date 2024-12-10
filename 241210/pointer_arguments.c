#include <stdio.h>

void change_sign_bugged(int n);
void change_sign(int* n);

int main()
{
    int a = 10, b = 20;

    printf("Values before change_sign_bugged(): a = %d, b = %d\n", a, b);
    change_sign_bugged(a);
    printf("Values after change_sign_bugged():  a = %d, b = %d\n", a, b);
    change_sign(&a);
    printf("Values after change_sign():  a = %d, b = %d\n", a, b);

    return 0;
}

void change_sign_bugged(int n)
{
    n = -n;
}

void change_sign(int* n)
{
    *n = -*n;
}
