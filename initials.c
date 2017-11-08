#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
// call all built-in functions

int main(void)
{
    // get name from user
    string name = get_string("\n");

    // print uppercase first character of string
    printf("%c", toupper(name[0]));

    // for each character of the string
    for (int i = 0; i < strlen(name); i++)
    {
        // check if any of the characters are spaces
        if (isspace(name[i]))
        {
            // if a space, print the uppercase character after the space
            printf("%c", toupper(name[i + 1]));
        }
    }
    // new line (for aesthetic purposes)
    printf("\n");
}