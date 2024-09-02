#include <cs50.h>
#include <stdio.h>
#include <string.h>

int integerKey(string argv);
void printCode(string text, int key);

int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string text = get_string("text: ");

    int key = integerKey(argv[1]);

    printCode(text, key);
}

int integerKey(string argv)
{
    int house = 1;
    int key = 0;

    for (int i = strlen(argv)-1 ; i >= 0 ; i--)
    {
        key += ((argv[i]-48)*house);
        house *= 10;
    }

    if (key > 26)
    {
        key = key % 26;
    }

    return key;
}

void printCode(string text, int key)
{
    for (int i = 0;i<strlen(text);i++)
    {

        if (text[i] < 'A' || (text[i] > 'Z' && text[i] < 'a') || text[i] > 'z')
        {
            printf("%c",text[i]);
        }
        else if ((text[i] >= 'a' && text[i] <= 'z') && text[i]+key >'z')
        {
            printf("%c",text[i]+key-26);
        }
        else if ((text[i] >= 'A' && text[i] <= 'Z') && (text[i]+key) > 'Z')
        {
            printf("%c",text[i]+key-26);
        }
        else
        {
            printf("%c",text[i]+key);
        }
    }
    printf("\n");
}