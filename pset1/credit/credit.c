#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{
    // Get credit card number from user
    long number = get_long_long("Enter your credit card number: \n");

    int length = 0;
    long digits = number;

    while (digits > 0)
    {
        digits = digits / 10;
        length ++;

    }

    printf("Number: %ld", number);

    // printf("Length is: %i", length);

    // Put digits in array
    int number_array[length];
    for (int i = 0; i < length; i++)
    {
        number_array[i] = number % 10;
        number = number / 10;
        // printf("%d", number_array[i]);

    }
    printf("\n");

    // Checksum function to validate if card number follows luhn's algo
    int checkSum = 0;
    // First loop calulates every other digit*2 and accounts for double digit nums
    for (int i = 1; i < length; i += 2)
    {
        if ((number_array[i] * 2) > 9)
        {
            checkSum += (((number_array[i] * 2) % 10) + 1);
        }
        else if (number_array[i] * 2 < 10)
        {
            checkSum += number_array[i] * 2;
        }
    }
    // Second loop adds the digits that werent multiplied to checkSum
    for (int i = 0; i < length; i += 2)
    {
        checkSum += number_array[i];
    }

    // Validates cards
    // If not correct length or doesnt follow Luhn's algo, invalid
    if (((length != 13) && (length != 15) && (length != 16)) || (checkSum % 10 != 0))
    {
        printf("INVALID\n");
    }
    else if (((length == 13) || (length == 15) || (length == 16)) && (checkSum % 10 == 0))
    {
        // If valid length/Luhns check the first two digits to determine card type
        if (number_array[length - 1] == 3 && (number_array[length - 2] == 4 || number_array[length - 2] == 7))
        {
            printf("AMEX\n");
        }
        else if (number_array[length - 1] == 3 && (number_array[length - 2] != 4 && number_array[length - 2] != 7))
        {
            printf("INVALID\n");
        }
        if (number_array[length - 1] == 5 && (number_array[length - 2] == 1 || number_array[length - 2] == 2
                                              || number_array[length - 2] == 3 || number_array[length - 2] == 4 || number_array[length - 2] == 5))
        {
            printf("MASTERCARD\n");
        }
        else if (number_array[length - 1] == 5 && (number_array[length - 2] != 1 && number_array[length - 2] != 2
                 && number_array[length - 2] != 3 && number_array[length - 2] != 4 && number_array[length - 2] != 5))
        {
            printf("INVALID\n");
        }
        if (number_array[length - 1] == 4)
        {
            printf("VISA\n");
        }
    }


    // // printf("Current checksum value is: %i", checkSum);
    // bool valid = true;
    // // Check if card number is valid length
    // while (valid)
    // {
    //     if (((length == 13) || (length == 15) || (length ==16)) && (checkSum % 10 ==0))
    //     {
    //         if (number_array[length-1]==3 && (number_array[length-2]==4 || number_array[length-2]==7) )
    //         {
    //         printf("AMEX\n");
    //         } else if (number_array[length-1]==3 && (number_array[length-2]!=4 && number_array[length-2]!=7))
    //         {
    //             valid = false;
    //         }
    //         if (number_array[length-1]==5 && (number_array[length-2]==1 || number_array[length-2]==2 || number_array[length-2]==3 || number_array[length-2]==4 || number_array[length-2]==5) )
    //         {
    //         printf("MASTERCARD\n");
    //         } else if (number_array[length-1]==5 && (number_array[length-2]!=1 && number_array[length-2]!=2 && number_array[length-2]!=3 && number_array[length-2]!=4 && number_array[length-2]!=5))
    //         {
    //             valid = false;
    //         }
    //         if (number_array[length-1]==4)
    //         {
    //             printf("VISA\n");
    //         }
    //         //  else if (number_array[length-1]!=4)
    //         // {
    //         //     printf("INVALID\n");
    //         // }
    //     } else if (!valid || ((length != 13) || (length != 15) || (length !=16)) || (checkSum % 10 ==0))
    //     {
    //         printf("INVALID\n");
    //     }
    //     valid = false;

    // }


}