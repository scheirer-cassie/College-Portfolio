#include <stdio.h>
#include <cs50.h>
#include <math.h>
// calls all built-in functions

int main(void)
// starts c program
{
    long long isbn_number = get_long_long("ISBN:\n");
    // retrieve isbn number from user

    int multiply = 10;
    // defining number that will multiply by the first digit of the isbn number
    long long total = 0;
    // defining the sum of all isbn digit computations
    int xth_digit;
    // defining the digits place

    while (isbn_number >= 1)
    // while there are 1 or greater digit places of the isbn number
    {
        xth_digit = isbn_number % 10;
        // find last digit of isbn number
        isbn_number = isbn_number / 10;
        // divide isbn number by 10
        total = total + (xth_digit * multiply);
        // multiply this digit by [1-9] and add this to the total sum of the isbn number
        multiply--;
        // subract one from multiply

    }

    if (isbn_number < 1)
    // if isbn_number has been divided more than 10 times
    {
        if (total % 11 == 0)
        // if the total of the isbn number is divisible by 11
        {
            printf("YES\n");
            // print yes
        }
        else
        // if not divisible by 11
        {
            printf("NO\n");
            // print no
        }
    }
    else
    // if number hasn't yet been divided more than 10 times
    {
        printf("Whoops\n");
        // print whoops
    }
}