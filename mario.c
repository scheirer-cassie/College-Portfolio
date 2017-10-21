#include <stdio.h>
#include <cs50.h>
#include <math.h> // call all modules

int main(void) // start c program
{
    int height = -2; // set initial height to value that's less than the amount of rows that work
    while (height <= -1 || height >= 24) // repeat this until height is greater than -1 or less than 24
    {
        height = get_int("Height:\n"); // get height from user if height <= 1 or >= 23
    }

    for (int row = height; row > 0; row--) // set number of rows to height; while number of rows is greater than 0, do this,
                                           // and subract 1 from rows every time
    {
        for (int spaces = 0; spaces < row - 1; spaces++) // set number of spaces to 0; while number of spaces is less than
                                                         // number of rows - 1, do this, and add 1 to spaces every time
        {
            printf(" ");    // print one space
        }
        for (int hashes = 0; hashes < (height + 2) - row; hashes++) // set number of hashes to 0; while number of hashes is
                                                                    // less than height plus 2 - number of rows, do this, and
                                                                    // add 1 to hashes every time
        {
            printf("#"); // print one hashtag
        }
        printf("\n"); // print one line
    }
}