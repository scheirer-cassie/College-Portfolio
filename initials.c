#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
// call all built-in functions

int main(void)
{
    // get name from user
    string name = get_string("");

    // check if first character is a letter
    if isalpha(name[0])
    {
        // if a letter, print uppercase letter
        printf("%c", toupper(name[0]));
    }
    // if first character is not a letter
    else
    {
        // do not print anything
        printf("");
    }
    // for each character of the string
    for (int i = 0; i < strlen(name); i++)
    {
        // check if any of the characters are spaces
        if (isspace(name[i]))
        {
            // check if the character after the space is a letter
            if (isalpha(name[i + 1]))
            {
                // if a letter, print the uppercase letter after the space
                printf("%c", toupper(name[i + 1]));
            }
        }
    }
    // new line (for aesthetic purposes)
    printf("\n");
}

// if character after string is a character and not a space, print the character