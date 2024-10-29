#include <stdio.h>

#define HOURS_IN_DAY 24

int main()
{
    const double pi = 3.14159;
    printf("Number of hours in a day: %d\n", HOURS_IN_DAY);

    double r = 123.4;
    double circumference = 2 * pi * r;
    printf("Circumference of circle with radius %lf = %lf\n", r, circumference);

    return 0;
}
