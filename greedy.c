#include <stdio.h>
#include <cs50.h>
#include <math.h>   // calls all modules

int main(void)  // starts function
{
    float money = get_float("How much change do you have? Exclude the dollar symbol.\n");   // asks user for amount of change
    money = round(money * 100);     // converts change in dollars to change in cents
    int coins = 0;      // starts coin count at 0

    while (money >= 25)     // while the total change is greater than or equal to 25
    {
        money = money - 25;     // subtract 25 from total change
        coins += 1;     // add a coin to coins
    }
    while (money >= 10)     // while the total change is greater than or equal to 10
    {
        money = money - 10;     // subtract 10 from total change
        coins += 1;     // add a coin to coins
    }
    while (money >= 5)      // while the total change is greater than or equal to 5
    {
        money = money - 5;      // subtract 5 from total change
        coins += 1;     // add a coin to coins
    }
    while (money >= 1)      // while the total change is greater than or equal to 1
    {
        money = money - 1;      // subtract 1 from total change
        coins += 1;     // add a coin to coins
    }

    printf("You get %d coins.\n", coins);       // print number of coins after all the change is subtracted
}