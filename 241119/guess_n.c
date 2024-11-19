#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DEBUG

int main()
{
    unsigned attempts = 0;
    unsigned secret_number, user_guess;

    // Init pseudorandom number generator
    srand(time(0));

    // Randomly choose a number between 1 and 100
    secret_number = rand() % 100 + 1;

#ifdef DEBUG
    printf("Secret number: %d\n", secret_number);
#endif

    printf("************************************\n");
    printf("*** Guess the number! (1 to 100) ***\n");
    printf("************************************\n");

    do
    {
        // Ask the user for their guess
        printf("Your guess: ");
        scanf("%d", &user_guess);

        attempts++;

        // Check if too high, low, or correct
        if (user_guess < secret_number)
        {
            printf("Too low!\n");
        }
        else if (user_guess > secret_number)
        {
            printf("Too high!\n");
        }
        else
        {
            printf("Congratulations! It only took %d attempts!\n", attempts);
        }
    }
    while (secret_number != user_guess);

    return 0;
}
