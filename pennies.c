#include <stdio.h>
#include <cs50.h>
#include <math.h>   // calls all modules

int main(void)  // starts function
{
    float days = 0;     // sets initial value of days to 0 so while loop can start
    while (days > 31 || days < 28)  // until there is a valid number of days, run this loop
    {
        days = get_float("Days in month: \n");  // retrieve input (number of days) from user
    }
    long long pennies = 0; // sets intial value of pennies to 0 so while loop can start
    while (pennies < 1) // until there is a valid number of pennies, run this loop
    {
        pennies = get_long_long("Pennies on the first day: \n");  // retrieve input (number of pennies on first day) from user
    }


    double money = (pennies * pow(2, days)-pennies)/100;    // make calculation and change pennies to dollars
    printf("$%.2f\n", money);   // print dollars with two decimal places
}