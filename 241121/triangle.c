#include <stdio.h>
#include <math.h>

#define PI 3.14159265358979323846

int main(){

    double a, b, c;

    // get sides dimentions
    printf("Size of the first side: ");
    scanf("%lf", &a);
    printf("Size of the second side: ");
    scanf("%lf", &b);
    printf("Size of the third side: ");
    scanf("%lf", &c);

    // check sides are positive values
    if( a <= 0 || b <= 0 || c <= 0){
        printf("Sides cannot be negative");
        return 1;
    }

    // get max side
    double max_ab = a > b ? a : b;
    double max_abc = max_ab > c ? max_ab : c;

    // check if triangle
    if(a + b + c <= 2 * max_abc){
        printf("This is not a triangle\n");
        return 0;
    }

    // equilateral
    if(a == b && b == c){
        printf("\nThis is an equilateral triangle\n\n");
    }
    // isosceles
    else if(a == b || a == c || b == c){
        printf("\nThis is an iscosceles triangle\n\n");
    }
    // scalene
    else{
        printf("\nThis is a scalene triangle\n\n");
    }

    double alpha = acos((pow(b, 2) + pow(c, 2) - pow(a, 2)) / (2 * b * c));
    double beta = acos((pow(a, 2) + pow(c, 2) - pow(b, 2)) / (2 * a * c));
    double gamma = acos((pow(a, 2) + pow(b, 2) - pow(c, 2)) / (2 * a * b));

    printf("Alpha = %.2lf deg\n", alpha * 180 / PI);
    printf("Beta = %.2lf deg\n", beta * 180 / PI);
    printf("Gamma = %.2lf deg\n", gamma * 180 / PI);

    return 0;

}
