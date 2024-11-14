#include <stdio.h>

double rectangleArea(double length, double width);

int main()
{
    double len, wid;

    printf("Insert rectangle's length: ");
    scanf("%lf", &len);
    printf("Insert rectangle's width: ");
    scanf("%lf", &wid);

    printf("len before: %lf\n", len);
    printf("wid before: %lf\n", wid);

    double area = rectangleArea(len, wid);
    printf("The rectangle's area is: %.2f\n", area);

    printf("len after: %lf\n", len);
    printf("wid after: %lf\n", wid);

    return 0;
}

double rectangleArea(double length, double width)
{
    length += 1;
    width *= 2;

    printf("rectangleArea(): length: %lf\n", length);
    printf("rectangleArea(): width: %lf\n", width);

    return length * width;
}
