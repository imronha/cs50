#include <stdio.h>
#include <cs50.h>
#include <math.h>
float cents;
int coins = 0;

int main(void)
{

    cents = get_float("How much money do you have?\n");
    // int cents = round(cash * 100);

    while (cents <= 0.00)
    {
        cents = get_float("How much money do you have?\n");
    }

    printf("Change owed: %f", cents);
    cents *= 100;
    cents = round(cents);


    while (cents != 0)
    {
        // printf("\n");

        // printf("%f", cents);

        if (cents >= 25)
        {
            cents -= 25;
            // printf("%f", cents);

            coins ++;
            // printf("%d", coins);
        }
        else if (cents >= 10)
        {
            cents -= 10;
            coins ++;
        }
        else if (cents >= 5)
        {
            cents -= 5;
            coins ++;
        }
        else if (cents >= 1)
        {
            cents -= 1;
            coins ++;
        }



    }
    printf("\n");
    printf("%d", coins);
    printf("\n");

}