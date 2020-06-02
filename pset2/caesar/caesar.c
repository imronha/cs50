#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>


int main(int argc, string argv[])
{

    if (argc == 2)
    {   
        // Check if key entered is valid
        for (int i = 0; i < strlen(argv[1]); i++) 
        {
            if (isalpha(argv[1][i]) != 0)
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        
        // Get string from user if key is valid
        string text = get_string("plaintext: ");
        int key = atoi(argv[1]) % 26;

        printf("ciphertext: ");
        for (int i = 0; i < strlen(text); i++)
        {
            // If char is between 'a' - 'z' do the following
            if (text[i] >= 'a' && text[i] <= 'z')
            {
                // If char + key is bigger than 'z', start counting at 'a'
                if ((text[i] + key) > 'z')
                {
                    int result = (text[i] + key) - 'z';
                    printf("%c", ('a' + result - 1));
                }
                else if ((text[i] + key) <= 'z')
                {
                    printf("%c", (text[i] + key));
                }
            }
            // If char is between 'A' - 'Z' do the following
            else if (text[i] >= 'A' && text[i] <= 'Z')
            {
                // If char + key is bigger than 'Z', start counting at 'A'

                if ((text[i] + key) > 'Z')
                {
                    int result = (text[i] + key) - 'Z';
                    printf("%c", ('A' + result - 1));
                }
                else if ((text[i] + key) <= 'Z')
                {
                    printf("%c", (text[i] + key));
                }
            }
            // Print all nonalphabetic chars
            else
            {
                printf("%c", text[i]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        return 1;
    }

}