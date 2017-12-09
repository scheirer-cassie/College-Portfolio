#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
// built-in functions

// intital declaration of function
int shift(int key, char crtr);

int main(int argc, string argv[])
{
    // error if there are two arguments in the command line:
    if (argc != 2)
    {
        printf("Error: enter only one key word\n");
        return 1;
    }

    // error if the key has non-alphabetical characters
    for (int x = 0, y = strlen(argv[1]); x < y; x++)
    {
        if (!isalpha(argv[1][x]))
        {
            printf("Error: enter only alphabetical characters\n");
            return 1;
        }
    }

    // second argument is the key
    string key = argv[1];

    // get word to cipher from user
    string plaintext = get_string("plaintext: ");

    char crtr;
    printf("ciphertext: ");

    // for each character in that word
    for (int i = 0, j = 0, n = strlen(plaintext); i < n; i++)
    {
        // checks if character is part of the alphabet:
        // if yes,
        if (isalpha(plaintext[i]))
        {
            // keep going through key word until end of word, then repeat
            j = j % strlen(key);

            // for uppercase keys, shift
            if (isupper(key[j]))
            {
                crtr = shift((key[j] - 65), plaintext[i]);
                j++;
            }

            // for lowercase keys, shift
            else if (islower(key[j]))
            {
                crtr = shift((key[j] - 97), plaintext[i]);
                j++;
            }

        }
        else
        {
            // if no, return that original character
            crtr = plaintext[i];
        }
        // print characters of ciphered word
        printf("%c", crtr);
    }
    printf("\n");
}

// define shift function: shift the characters of original word key[char] # of times
int shift(int key, char crtr)
{
    // for all uppercase characters
    if (isupper(crtr))
    {
        // specific math found on CS50 Stack Exchange
        crtr = (((crtr + key) - 65) % 26) + 65;
        return crtr;
    }
    // for all lowercase characters
    else if (islower(crtr))
    {
        // specific math found on CS50 Stack Exchange
        crtr = (((crtr + key) - 97) % 26) + 97;
        return crtr;
    }
    // end function
    else
    {
        printf("Error: no characters\n");
        return 1;
    }
}