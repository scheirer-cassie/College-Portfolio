#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
// built-in functions

// intital declaration of variables and functions
int shift(int k, char crtr);
string plaintext;
int i;
int n;

int main(int argc, string argv[])
{
    // if there are two arguments in the command line:
    if (argc == 2)
    {
        // second argument is the key
        int key = atoi(argv[1]);

        // get word to cipher from user
        plaintext = get_string("plaintext: ");

        char crtr;
        printf("ciphertext: ");

        // for each character in that word
        for (i = 0, n = strlen(plaintext); i < n; i++)
        {
            // checks if character is part of the alphabet:
            //if yes,
            if (isalpha(plaintext[i]))
            {
                // execute shift
                crtr = shift(key, plaintext[i]);
            }
            else
            {
                // if no, return that original character
                printf("%c", plaintext[i]);
            }
            // print characters of ciphered word
            printf("%c", crtr);
        }
        printf("\n");
    }
    // error if no or too many inputs
    else
    {
        printf("Error: enter one key number\n");
        return 1;
    }
}

// define shift function: shift the characters of original word key # of times
int shift(int key, char crtr)
{
    // for all uppercase characters
    if (isupper(plaintext[i]))
    {
        crtr = (((plaintext[i] + key) - 65) % 26) + 65;
        return crtr;
    }
    // for all lowercase characters
    else if (islower(plaintext[i]))
    {
        crtr = (((plaintext[i] + key) - 97) % 26) + 97;
        return crtr;
    }
    // end function
    else
    {
        printf("Error: no characters\n");
        return 1;
    }
}