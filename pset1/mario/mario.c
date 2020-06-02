#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>

int main(void)
{
    int height = get_int("What height would you like?\n");

    while (height < 0 || height == 0 || height > 8)
    {
        height = get_int("What height would you like?\n");
    }
    // for (int i = 0; i < height; i++)
    // {
    //     for (int k = abs(height - i); k > 1; k--) 
    //     {
    //         printf(" ");
    //     }
    //     for (int j = 0; j < i+1; j++) 
    //     {
    //         printf("#");
    //     }
    //     printf("\n");
    // }
    for (int i = 0; i < height; i++)
    {
        for (int k = abs(height - i); k > 1; k--) 
        {
            printf(" ");
        }
        for (int j = 0; j < i+1; j++) 
        {
            printf("#");
        }
        printf("  ");
        for (int j = 0; j < i+1; j++) 
        {
            printf("#");
        }
        printf("\n");

    }
}