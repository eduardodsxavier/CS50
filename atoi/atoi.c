#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input, int decimalHouse, int index);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input, 1, strlen(input) - 1));
}

int convert(string input, int decimalHouse, int index)
{
    // TODO 48
    int number = 0;

    if (index == 0)
    {
        return (input[index] - 48) * decimalHouse;
    }

    number += ((input[index] - 48) * decimalHouse);
    decimalHouse *= 10;
    index--;

    return number + convert(input, decimalHouse, index);
}