#include <stdio.h>
#include <cs50.h>
// call built-in functions

// define main function
int main(int argc, string argv[])
{
    // if there are two arguments in the command line
    if (argc == 2)
    {
        // print "Hello, (argument 1)
        printf("Hello, %s!\n", argv[1]);
    }
    else
    {
        // if argument 1 not given, try again
        printf("Error: Print './hello <firstname>'\n");
        return 1;
    }
}