/**
 * pennies.c
 *
 * CS50 AP
 * Old Friends
 *
 * Calculates how many pennies a user would get if their change
 * doubles each day using command line information
 */

#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

// defined constants
#define MAX_DAYS 31
#define MIN_DAYS 28

// main function
int main(int argc, string argv[])
{
    // give a number of days and pennies
    // if there are three inputs in the command line
    if (argc == 3)
    {
        // change first string to interger and assign it as
        // the number of days
        int days = atoi(argv[1]);

        // if the first input, days, is between 28 and 31
        if (days >= MIN_DAYS && days <= MAX_DAYS)
        {
            // change the second string to integer and assign
            // it as the number of pennies
            int pennies = atoi(argv[2]);
            if (pennies > 0)
            {
                long long total = pennies;

                // for each day until (days) days, double the number of pennies
                for (int i = 1; i < days; i++)
                {
                    total += pennies * pow(2, i);
                }

                // print total pennies
                printf("$%.2f\n", ((double) total) / 100);
            }
            else
            {
                // if number of pennies is 0, try again
                printf("Error: incorrect input. Please enter a number of pennies greater than 0.\n");
                return 1;
            }
        }
        else
        {
            // if number of days is not >= 28 and <= 31, try again
            printf("Error: incorrect input. Please enter a valid number of days.\n");
            return 1;
        }
    }
    else
    {
        printf("Error: too many/too few arguments. Try again.\n");
        return 1;
    }
}