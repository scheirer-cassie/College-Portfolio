#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float money = get_float("How much change do you have? Exclude the dollar symbol.\n");
    money = round(money * 100);
    int coins = 0;

    while (money >= 25)
    {
        money = money - 25;
        coins += 1;
    }
    while (money >= 10)
    {
        money = money - 10;
        coins += 1;
    }
    while (money >= 5)
    {
        money = money - 5;
        coins += 1;
    }
    while (money >= 1)
    {
        money = money - 1;
        coins += 1;
    }

    printf("You get %d coins.\n", coins);
}