#include <stdio.h>

#define LOGGING_LEVEL 5

int main()
{
#if LOGGING_LEVEL == 0
    printf("This is a level 0 message\n");
#elif LOGGING_LEVEL == 1
    printf("This is a level 1 message\n");
#elif LOGGING_LEVEL == 2
    printf("This is a level 2 message\n");
#else
    printf("Just to show the usage of #else\n");
#endif

    return 0;
}
