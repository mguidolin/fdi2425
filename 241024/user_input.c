#include <stdio.h>

#define MINUTES_IN_HOUR 60

int main()
{
    int hh, mm;
    printf("What time is it (HH:MM)? ");
    scanf("%d:%d", &hh, &mm);

    int tot_mm = MINUTES_IN_HOUR * hh + mm;
    printf("%d minutes have passed since midnight.\n", tot_mm);

    return 0;
}
