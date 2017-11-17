#include <stdio.h>
#include <cs50.h>
//calls all built-in functions


int main(int argc, string argv[])
{
    //if there are two inputs in the command line
    if (argc == 2)
    {
        //change celsius from a string to a float
        float celsius = atof(argv[1]);
        //calulate fahrenheit from celsius
        float fahrenheit = ((celsius * 9) / 5) + 32;
        printf("F: %0.1f\n", fahrenheit);
    }
    else
    {
        // if valid temperature not given, try again
        printf("Error: invalid input. Please enter a valid temperature.\n");
        return 1;
    }
}