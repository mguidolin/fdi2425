#include <stdio.h>

#define AVG_DAYS_PER_MONTH 30.437
#define MONTHS_PER_YEAR 12

int main(){

    int dd_born, mm_born, yy_born;
    int dd_today, mm_today, yy_today;

    printf("When where you born (DD/MM/YYYY)? ");
    scanf("%d/%d/%d", &dd_born, &mm_born, &yy_born);

    printf("What's the date today (DD/MM/YYYY)?");
    scanf("%d/%d/%d", &dd_today, &mm_today, &yy_today);

    int yy_diff = yy_today - yy_born;
    int mm_diff = mm_today - mm_born;
    int dd_diff = dd_today - dd_born;

    float dd_age = dd_diff + mm_diff * AVG_DAYS_PER_MONTH + yy_diff * MONTHS_PER_YEAR * AVG_DAYS_PER_MONTH;

    printf("\nYour are approximately %d days old!\n", (int)dd_age);

    return 0;
}
