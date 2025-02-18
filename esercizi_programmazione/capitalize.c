#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>

void capitalize(char *str)
{
    bool new_word = true;

    // loop until the end of the string
    while (*str != '\0')
    {
        // if the current char is a ' ', the next one will be the start of a new word
        if (*str == ' ')
        {
            new_word = true;
        }
        else
        {
            // if we are at the start of a new word and the next char is either ' ' or '\0', it is a single-char word
            // and we need to make the first char lowercase
            if (new_word && (*(str + 1) == ' ' || *(str + 1) == '\0'))
            {
                *str = tolower(*str);
            }
            // else we need to make the first char uppercase
            else
            {
                *str = toupper(*str);
            }

            // set new_word to false since now we are inside a word
            new_word = false;
        }
        str++;
    }
}

int main()
{
    char str1[] = "Ho attraversato gli oceani del tempo per trovarti";
    printf("Original:    %s\n", str1);
    capitalize(str1);
    printf("Capitalized: %s\n", str1);

    char str2[] = "Fatti non foste a viver come BRUTI ma per seguir virtute e canoscenza";
    printf("Original:    %s\n", str2);
    capitalize(str2);
    printf("Capitalized: %s\n", str2);

    return 0;
}
