#include <cs50.h>
#include <stdio.h>
#include <string.h>

void printCode(string argv, string plaintext);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");

    printCode(argv[1],plaintext);

}

void printCode(string key, string plaintext)
{
    char keyLower[26];
    char keyUpper[26];

    for (int i = 0; i<26; i++)
    {
        if (key[i] >= 'A' && key[i] <= 'Z')
        {
            keyUpper[i] = key[i];
            keyLower[i] = key[i]+32;
        }
        else
        {
            keyLower[i] = key[i];
            keyUpper[i] = key[i]-32;
        }

    }

    for (int i = 0; i<strlen(plaintext); i++)
    {
        if (plaintext[i] < 'A' || (plaintext[i] > 'Z' && plaintext[i] < 'a') || plaintext[i] > 'z')
        {
            printf("%c",plaintext[i]);
        }
        else if (plaintext[i] >= 'A' && plaintext[i] <= 'Z')
        {
            printf("%c",keyUpper[plaintext[i]-'A']);
        }
        else
        {
            printf("%c",keyLower[plaintext[i]-'a']);
        }
    }
    printf("\n");
}