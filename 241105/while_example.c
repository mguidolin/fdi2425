#include <stdio.h>

int main()
{
    int age = -1;

    while (age < 0)
    {
        printf("Insert your age: ");
        scanf("%d", &age);
    }

    printf("Nice, you are %d years old!\n", age);

    // This for cycle...
    // for (int i = 0; i < 3; i++)
    // {
    //     printf("Hello!\n");
    // }
    // ... is equivalent to this while cycle
    // int i = 0;
    // while (i < 3)
    // {
    //     printf("Hello!\n");
    //     i++;
    // }

    return 0;
}
