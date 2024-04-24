// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char replace(char input);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }

    for (int i = 0; i < strlen(argv[1]); i++)
    {
        printf("%c", replace(argv[1][i]));
    }

    printf("\n");
}

char replace(char input)
{

    char letter = tolower(input);

    switch (letter)
    {
        case 'a':
            return '6';
            break;
        case 'e':
            return '3';
            break;
        case 'i':
            return '1';
            break;
        case 'o':
            return '0';
            break;
        default:
            return input;
            break;
    }
}