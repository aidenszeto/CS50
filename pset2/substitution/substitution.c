#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    char temp;

    // Check validity of key
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    if (strlen(argv[1]) < 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if ((argv[1][i] < 65) || (argv[1][i] > 90 && argv[1][i] < 97) || (argv[1][i] > 122))
        {
            printf("Key must only contain alphabetic characters.");
            return 1;
        }
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        temp = argv[1][i];
        for (int j = i + 1; j < strlen(argv[1]); j++)
        {
            if (argv[1][j] == temp)
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    // Prompt for user input string
    string input = get_string("plaintext: ");

    // Create lower-case and upper-case version of key
    char lower[strlen(argv[1])];
    char upper[strlen(argv[1])];
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (argv[1][i] >= 65 && argv[1][i] <= 90)
        {
            lower[i] = argv[1][i] + 32;
        }
        else
        {
            lower[i] = argv[1][i];
        }
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (argv[1][i] >= 97 && argv[1][i] <= 122)
        {
            upper[i] = argv[1][i] - 32;
        }
        else
        {
            upper[i] = argv[1][i];
        }
    }

    // Convert plaintext to ciphertext
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] >= 'A' && input[i] <= 'Z')
        {
            input[i] = upper[input[i] - 65];
        }
        if (input[i] >= 'a' && input[i] <= 'z')
        {
            input[i] = lower[input[i] - 97];
        }
    }

    printf("ciphertext: %s\n", input);
}