#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <stdbool.h>

// #define DEBUG

int rand_from_to(int from, int to);
bool game_loop(unsigned level);

int main()
{
    // Init pseudorandom number generator
    srand(time(0));

    printf("*************************\n");
    printf("*** Guess the number! ***\n");
    printf("*************************\n");

    int level = 0;

    while (game_loop(++level))
    {
    }

    return 0;
}

int rand_from_to(int from, int to)
{
    return (rand() % (to - from + 1) + from);
}

bool game_loop(unsigned level)
{
    unsigned max_n = (unsigned)pow(10, level);
    unsigned max_attempts = (unsigned)ceil(log2(max_n));

    unsigned attempts = 0;
    unsigned secret_number, user_guess;

    secret_number = rand_from_to(1, max_n);

    printf("\n* Level %d (1 to %d) [max attempts: %d]\n", level, max_n, max_attempts);

#ifdef DEBUG
    printf("Secret number: %d\n", secret_number);
#endif

    do
    {
        attempts++;
        if (attempts > max_attempts)
        {
            printf("  - You lost! The number was %d\n", secret_number);
            return false;
        }

        // Ask the user for their guess
        printf("  Your guess (%d/%d): ", attempts, max_attempts);
        scanf("%d", &user_guess);

        // Check if too high, low, or correct
        if (user_guess < secret_number)
        {
            printf("  - Too low!\n");
        }
        else if (user_guess > secret_number)
        {
            printf("  - Too high!\n");
        }
        else
        {
            printf("Congratulations!\n");
        }
    }
    while (secret_number != user_guess);

    return true;
}
