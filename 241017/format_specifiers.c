#include <stdio.h>

int main()
{
    double n = 12345.67890;

    printf("n: %lf m/s\n", n);
    printf("n: %-lf m/s\n", n);
    printf("n: %20lf m/s\n", n);
    printf("n: %-20lf m/s\n", n);
    printf("n: %-20.2lf m/s\n", n);
    printf("n: %20.20lf m/s\n", n);

    return 0;
}
