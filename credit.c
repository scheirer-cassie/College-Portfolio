#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    // get card number from user
    long long number = 0;
    while (number <= 0)
    {
        number = get_long_long("Number:");
    }

    // set original values of variables
    int total = 0;
    int count = 0;
    long long og_number = number;

    // calculate card number algorithm
    // increase counter by 1 each loop
    while (number > 0)
    {
        int digit = number % 10;
        number = number / 10;
        if (count % 2 == 0)
        {
            total = total + digit;
        }
        else
        {
            total = total + ((digit * 2) % 10) + ((digit * 2) / 10);
        }
        count++;
    }

    // if the total is divisible by 10
    if (total % 10 == 0)
    {
        // if the card number is 15 digits and starts with 34 or 37, print AMEX
        // force the pow function (normally a float function) into a long long
        if ((og_number / (long long) pow(10, 13)) == 34 || (og_number / (long long) pow(10, 13)) == 37)
        {
            printf("AMEX\n");
        }
        // if the card number is 16 digits and starts with 51-55, print MASTERCARD
        else if ((og_number / (long long) pow(10, 14)) >= 51 && (og_number / (long long) pow(10, 14)) <= 55)
        {
            printf("MASTERCARD\n");
        }
        // if the card number is 16 or 13 digits and starts with 4, print VISA
        else if (((og_number / (long long) pow(10, 15)) == 4) || (og_number / (long long) pow(10, 12)) == 4)
        {
            printf("VISA\n");
        }
        // otherwise, number is invalid
        else
        {
            printf("INVALID\n");
        }
    }
    // if the total is not divisible by 10
    else
    {
        printf("INVALID\n");
    }
}
