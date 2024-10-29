#include <stdio.h>

int main()
{
    double PI = 3.14159;
    double r = 1.234;

    // double vol = 4 / 3 * PI * r * r * r; // Wrong: 4 / 3 = 1 because they are all integers
    // double vol = 4.0 / 3 * PI * r * r * r; // Correct: 3 is promoted from int to double
    double vol = 4 / 3.0 * PI * r * r * r; // Correct: 4 is promoted from int to double
    printf("The volume of a sphere with radius %f is: %f\n", r, vol);

    return 0;
}
