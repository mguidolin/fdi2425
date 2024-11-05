#include <stdio.h>

int main()
{
    int var;
    printf("Insert a value between 1 and 8: ");
    scanf("%d", &var);

    switch (var)
    {
        case 1:
            printf("Case 1 is matched.\n");
            break;

        case 2:
            printf("Case 2 is matched.\n");
            break;

        case 3:
            printf("Case 3 is matched.\n");

        case 4:
            printf("Case 4 is matched.\n");
            break;

        case 5:
        case 6:
        case 7:
        case 8:
            printf("Case 5 to 8 is matched.\n");
            break;

        default:
            printf("Default is matched.\n");
            break;
    }

    return 0;
}
