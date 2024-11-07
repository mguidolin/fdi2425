#include <stdio.h>

int main()
{
    int age = 100;

    do
    {
        printf("Insert your age: ");
        scanf("%d", &age);
    }
    while (age < 0);

    printf("Nice, you are %d years old!\n", age);

    return 0;
}
