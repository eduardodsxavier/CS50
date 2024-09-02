#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int text_letters(string text);
int text_words(string text);
int text_sentences(string text);

int main(void)
{
    string text = get_string("text: ");

    int letters = text_letters(text);

    int words = text_words(text);

    int sentences = text_sentences(text);

    float L = ((float)letters/(float)words)*100;

    float S = ((float)sentences/(float)words)*100;

    float readerLevel = (0.0588 * L) - (0.296 * S) - 15.8;

    readerLevel = round(readerLevel);

    if (readerLevel >= 16)
    {
        printf("Grade 16+");
    }
    else if (readerLevel <= 0)
    {
        printf("Before grade 1");
    }
    else
    {
        printf("Grade: %.0f\n",readerLevel);
    }
}

int text_letters(string text)
{
    int letters = 0;
    bool validLetter = false;

    for (int i = 0; i<strlen(text); i++)
    {
        validLetter = ((text[i] >= 'a') && (text[i] <= 'z')) || ((text[i] >='A') && (text[i] <= 'Z'));

        if (validLetter)
        {
            letters++;
        }
    }

    return letters;
}

int text_words(string text)
{
    int words = 0;
    bool validWord = false;

    for (int i = 0; i<strlen(text); i++)
    {
        validWord = (text[i-1] != ' ' ) && (text[i] == ' ');

        if (validWord)
        {
            words++;
        }
    }

    char fistChar = text[0];
    if (fistChar == ' ')
    {
        words--;
    }

    char lastChar = text[strlen(text)-1];
    if (lastChar != ' ')
    {
        words++;
    }

    return words;
}

int text_sentences(string text)
{
    int sentences = 0;
    bool validSentence = false;

    for (int i = 0; i<strlen(text); i++)
    {
        validSentence = (text[i] == '.' || text[i] == '!' || text[i] == '?')
        && (text[i-1] != '.' && text[i-1] != '!' && text[i-1] != '?');

        if (validSentence)
        {
            sentences++;
        }
    }

    return sentences;
}