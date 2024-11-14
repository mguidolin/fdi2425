#include <stdio.h>

double rectangleArea(double length, double width);

int main()
{
    double len, wid;

    printf("Insert rectangle's length: ");
    scanf("%lf", &len);
    printf("Insert rectangle's width: ");
    scanf("%lf", &wid);

    double area = rectangleArea(len, wid);
    printf("The rectangle's area is: %.2f\n", area);

    return 0;
}

double rectangleArea(double length, double width)
{
    return length * width;
}
