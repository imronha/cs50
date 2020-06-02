#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Get string from user
    string text = get_string("Text: ");
    // printf("%s\n", text);
    float letter_count = 0;
    float word_count = 1;
    float sentence_count = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letter_count ++;
        } 
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentence_count ++;
        } 
        else if (text[i] == ' ')
        {
            word_count ++;
        }
        
    }
    float l = 100 * (letter_count / word_count);
    float s = 100 * (sentence_count / word_count);
    int grade = round(0.0588 * l - 0.296 * s - 15.8);
    
    if (grade < 1)
    {
        printf("Before Grade 1\n");

    } 
    else if (grade > 16) 
    {
        printf("Grade 16+\n");
    } 
    else
    {
        printf("Grade %i\n", grade);
    }

    // printf("Grade %i\n", grade);
    // printf("%i letter(s)\n", letter_count);
    // printf("%i word(s)\n", word_count);
    // printf("%i sentence(s)\n", sentence_count);
}