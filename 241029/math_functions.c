#include <stdio.h>
#include <math.h>

#define PI 3.14159265359

int main()
{
    double x = 1.5;
    int floor_x = (int)floor(x);
    // printf("floor(%lf) = %d\n", x, floor_x);

    printf("floor(%lf) = %lf\n", x, floor(x));
    printf("ceil(%lf) = %lf\n", x, ceil(x));
    printf("round(%lf) = %lf\n", x, round(x));

    double angle = PI / 4;
    double test = sin(angle);

    printf("sin(%lf) = %lf\n", angle * 180 / PI, test);
    printf("cos(%lf) = %lf\n", angle * 180 / PI, cos(angle));
    printf("tan(%lf) = %lf\n", angle * 180 / PI, tan(angle));

    double vol = 4. / 3. * PI * pow(x, 3);
    printf("Volume of sphere with radius %lf = %lf\n", x, vol);

    return 0;
}
