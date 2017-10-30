#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // set initial height to value that's less than the amount of rows that work
    int height = -2;
    // repeat this until height is greater than -1 or less than 24
    while (height <= -1 || height >= 24)
    {
        // get height from user if height <= 1 or >= 23
        height = get_int("Height:\n");
    }

    // set number of rows to height; while number of rows is greater than 0, do this,
    // and subract 1 from rows every time
    for (int row = height; row > 0; row--)
    {
        // set number of spaces to 0; while number of spaces is less than
        // number of rows - 1, do this, and add 1 to spaces every time
        for (int spaces = 0; spaces < row - 1; spaces++)
        {
            // print one space
            printf(" ");
        }
        // set number of hashes to 0; while number of hashes is
        // less than height plus 2 - number of rows, do this, and
        // add 1 to hashes every time
        for (int hashes = 0; hashes < (height + 2) - row; hashes++)
        {
            // print one hashtag
            printf("#");
        }
        // print one line
        printf("\n");
    }
}