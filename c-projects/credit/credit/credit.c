#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long i = get_long("card credit number: ");
    int validation = 0;
    int number1, number2, number3, number4, number5, number6, number7, number8, number9, number10, number11, number12, number13, number14, number15, number16;
    number1 = i%10;
    number2 = (i/10)%10;
    number3 = (i/100)%10;
    number4 = (i/1000)%10;
    number5 = (i/10000)%10;
    number6 = (i/100000)%10;
    number7 = (i/1000000)%10;
    number8 = (i/10000000)%10;
    number9 = (i/100000000)%10;
    number10 = (i/1000000000)%10;
    number11 = (i/10000000000)%10;
    number12 = (i/100000000000)%10;
    number13 = (i/1000000000000)%10;
    number14 = (i/10000000000000)%10;
    number15 = (i/100000000000000)%10;
    number16 = (i/1000000000000000)%10;


    validation += ((number2*2)/10)+((number2*2)%10);
    validation += ((number4*2)/10)+((number4*2)%10);
    validation += ((number6*2)/10)+((number6*2)%10);
    validation += ((number8*2)/10)+((number8*2)%10);
    validation += ((number10*2)/10)+((number10*2)%10);
    validation += ((number12*2)/10)+((number12*2)%10);
    validation += ((number14*2)/10)+((number14*2)%10);
    validation += ((number16*2)/10)+((number16*2)%10);

    validation += number1;
    validation += number3;
    validation += number5;
    validation += number7;
    validation += number9;
    validation += number11;
    validation += number13;
    validation += number15;

    if (validation%10 ==0)
    {
        if (number16 == 4)
        {
            printf("visa\n");
        }
        else if (number16 == 5 && (number15==1||number15==2||number15==3||number15==4||number15==5))
        {
            printf("MasterCard\n");
        }
        else if (number16 == 3 && (number15==4||number15==7))
        {
            printf("American Express\n");
        }
        else
        {
            printf("validating credit card numbers pass, but the card is unknown\n");
        }
    }
    else
    {
        printf("invalid\n");
    }
}