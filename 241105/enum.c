#include <stdio.h>

enum Level { LOW = 1, MEDIUM, HIGH };

int main()
{
    enum Level battery = HIGH;

    switch (battery)
    {
        case LOW:
            printf("Attention, battery level: %d!\n", battery);
            break;

        case MEDIUM:
            printf("Medium battery: %d\n", battery);
            break;

        case HIGH:
            printf("High battery, no need to recharge (level = %d)\n", battery);
            break;

        default:
            printf("Error, you should not be here\n");
            break;
    }

    return 0;
}
