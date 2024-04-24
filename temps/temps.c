// Practice working with structs
// Practice applying sorting algorithms

#include <cs50.h>
#include <stdio.h>

#define NUM_CITIES 10

typedef struct
{
    string city;
    int temp;
} avg_temp;

avg_temp temps[NUM_CITIES];

void sort_cities(int arraySize, avg_temp originalArray[]);
void merge_sort(avg_temp originalArray[], avg_temp leftPart[], avg_temp rightPart[], int arraySize);

int main(void)
{
    temps[0].city = "Austin";
    temps[0].temp = 97;

    temps[1].city = "Boston";
    temps[1].temp = 82;

    temps[2].city = "Chicago";
    temps[2].temp = 85;

    temps[3].city = "Denver";
    temps[3].temp = 90;

    temps[4].city = "Las Vegas";
    temps[4].temp = 105;

    temps[5].city = "Los Angeles";
    temps[5].temp = 82;

    temps[6].city = "Miami";
    temps[6].temp = 97;

    temps[7].city = "New York";
    temps[7].temp = 85;

    temps[8].city = "Phoenix";
    temps[8].temp = 107;

    temps[9].city = "San Francisco";
    temps[9].temp = 66;

    sort_cities(NUM_CITIES, temps);

    printf("\nAverage July Temperatures by City\n\n");

    for (int i = 0; i < NUM_CITIES; i++)
    {
        printf("%s: %i\n", temps[i].city, temps[i].temp);
    }
}

// TODO: Sort cities by temperature in descending order
void sort_cities(int arraySize, avg_temp originalArray[])
{
    // Add your code here
    if (arraySize < 2)
    {
        return;
    }

    int midIndex = arraySize / 2;

    avg_temp leftPart[midIndex];
    avg_temp rightPart[arraySize - midIndex];

    for (int i = 0; i < midIndex; i++)
    {
        leftPart[i] = originalArray[i];
    }
    for (int i = midIndex; i < arraySize; i++)
    {
        rightPart[i - midIndex] = originalArray[i];
    }

    sort_cities(midIndex, leftPart);
    sort_cities(arraySize - midIndex, rightPart);

    merge_sort(originalArray, leftPart, rightPart, arraySize);

    return;
}

void merge_sort(avg_temp originalArray[], avg_temp leftPart[], avg_temp rightPart[], int arraySize)
{
    int midIndex = arraySize / 2;
    int i = 0, j = 0, k = 0;
    int leftPartSize = midIndex;
    int rightPartSize = arraySize - midIndex;

    while (i < leftPartSize && j < rightPartSize)
    {
        if (leftPart[i].temp >= rightPart[j].temp)
        {
            originalArray[k] = leftPart[i];
            i++;
        }
        else
        {
            originalArray[k] = rightPart[j];
            j++;
        }

        k++;
    }

    while (i < leftPartSize)
    {
        originalArray[k] = leftPart[i];
        i++;
        k++;
    }
    while (j < rightPartSize)
    {
        originalArray[k] = rightPart[j];
        j++;
        k++;
    }

    return;
}