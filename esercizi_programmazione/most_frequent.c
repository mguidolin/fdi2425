#include <ctype.h>
#include <stdio.h>

char most_frequent(char *str, int *count)
{
    // array to store the frequency of each letter (A-Z)
    int freq[26] = {0};
    // store the most frequent letter, initialize to 'A'
    char most_freq = 'A';
    // initialize the counter of the most frequent letter to 0
    *count = 0;

    // iterate through the input string
    while (*str != '\0')
    {
        // check if the character is a letter
        if (*str >= 'A' && *str <= 'Z')
        {
            // get the index of the array corresponding to the current letter
            int idx = *str - 'A';
            // increase its freuency count by 1
            ++freq[idx];

            // update the most frequent letter if:
            // - current letter's frequency > previous max
            // - OR same frequency, but current letter alphabetically smaller
            if (freq[idx] > *count || (freq[idx] == *count && *str < most_freq))
            {
                most_freq = *str;
                *count = freq[idx];
            }
        }

        // move to the next character in the string
        ++str;
    }

    // return the most frequent letter
    return most_freq;
}

int main()
{
    char str[] = "THE MOST FREQUENT LETTER IS NO ONE";
    int cnt;
    char letter = most_frequent(str, &cnt);

    printf("Input string: %s\n", str);
    printf("The most frequent letter is: %c counting up to: %d\n", letter, cnt);

    return 0;
}
