#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

void messageToBinary(char message);

int main(void)
{
    string message = get_string("message: ");

    for (int i = 0; i < strlen(message);i++)
    {
        messageToBinary(message[i]);
        printf("\n");
    }

}

void messageToBinary(char message)
{
    int ascii = message;
    int binary[] = {0,0,0,0,0,0,0,0};
    int binary2[] = {0,0,0,0,0,0,0,0};

    for (int i = 0; i < 8; i++)
    {
        if (ascii % 2 == 0)
        {
            binary[i] = 0;
        }
        else
        {
            binary[i] = 1;
        }

        ascii/=2;
    }

    for (int i = 0;i < 8;i++)
    {
        binary2[7-i] = binary[i];
    }

    for (int i = 0;i < 8;i++)
    {
        print_bulb(binary2[i]);
    }
}


void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
