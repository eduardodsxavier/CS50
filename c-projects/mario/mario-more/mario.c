#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //number 1-8
    int height = 0;
    do
    {
        height = get_int("whats the height of the stair: ");
    }
    while (height < 1 || height > 8);

    for (int i = 1; i <= height; i++)
    {
        for (int j = 0; j < height - i; j++)
        {
            printf(" ");
        }
        for (int l = 0; l < i ; l++ )
        {
            printf("#");
        }
        for (int x = 0; x < 3; x++)
        {
            printf(" ");
        }
        for (int y = 0; y < i ; y++ )
        {
            printf("#");
        }
        printf("\n");
    }
}
