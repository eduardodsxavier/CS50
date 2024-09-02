#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int startSize, actualSize, endSize, years = 0;

    // TODO: Prompt for start size

    do
    {
        startSize = get_int("whats the start population size: ");
    }
    while (startSize < 9);
    actualSize = startSize;

    // TODO: Prompt for end size

    do
    {
        endSize = get_int("whats the end population size: ");
    }
    while (endSize < startSize);

    // TODO: Calculate number of years until we reach threshold
    while (actualSize < endSize)
    {
        actualSize += (actualSize/3)-(actualSize/4);
        years++;
    }

    // TODO: Print number of years
    printf("start population: %i\n",startSize);
    printf("end population: %i\n",endSize);
    printf("years: %i\n",years);
}
