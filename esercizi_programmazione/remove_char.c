#include <stdio.h>

void remove_char(char* input, char c, char* output)
{
    // if we reach the end of the input string, terminate the output string
    if (*input == '\0')
    {
        *output = '\0';
        return;
    }

    // if the current character is NOT the one to be removed...
    if (*input != c)
    {
        // ... copy the current character to the output string
        *output = *input;
        // move to the next character in both strings
        remove_char(input + 1, c, output + 1);
    }
    // else if the current character matches the one to be removed...
    else
    {
        // ... skip it and continue with the next input character
        remove_char(input + 1, c, output);
    }
}

int main()
{
    char input1[] = "Ho attraversato gli oceani del tempo per trovarti";
    char output1[100];
    char c1 = 'o';

    remove_char(input1, c1, output1);
    printf("Input string:   %s\n", input1);
    printf("Char to remove: %c\n", c1);
    printf("Output string:  %s\n", output1);

    char input2[] = "Fatti non foste a viver come BRUTI ma per seguir virtute e canoscenza";
    char output2[100];
    char c2 = 'I';

    remove_char(input2, c2, output2);
    printf("Input string:   %s\n", input2);
    printf("Char to remove: %c\n", c2);
    printf("Output string:  %s\n", output2);

    return 0;
}
