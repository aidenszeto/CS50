#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

int main(void)
{
    // Counter for letters, sentences, and words
    float letters = 0;
    float sentences = 0;
    float words = 1;

    // Get input text and create variable for text length
    string text = get_string("Text: ");
    int length = strlen(text);

    // Count how many letters
    for (int i = 0; i < length; i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            letters++;
        }
    }

    // Count how many words
    for (int i = 0; i < length; i++)
    {
        if (text[i] == 32)
        {
            words++;
        }
    }

    // Count how many sentences
    for (int i = 0; i < length; i++)
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            sentences++;
        }
    }

    // Calculate and print grade level
    float L = letters * 100 / words;
    float S = sentences * 100 / words;
    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
       printf("Grade %i\n", index);
    }
}