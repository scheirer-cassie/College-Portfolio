#include <stdio.h>
#include <cs50.h>
#include <math.h>
// call all built-in functions

// declare main function
int main(int argc, string argv[])
{
    // run if there are 3 arguments in command line
    if (argc == 4)
    {
        // set first number to variable a and second to variable b
        float a = atof(argv[1]);
        float b = atof(argv[3]);

        // declare total variable
        float total = 0;

        // declare actions for different operations
        switch (argv[2][0])
        {
            // additiom
            case '+':
                total = (a + b);
                printf("%f\n", total);
                return 0;
                break;
            // subtraction
            case '-':
                total = (a - b);
                printf("%f\n", total);
                return 0;
                break;
            // multiplication
            case 'x':
                total = (a * b);
                printf("%f\n", total);
                return 0;
                break;
            // division
            case '/':
                total = (a / b);
                printf("%f\n", total);
                return 0;
                break;
            // modulo
            case '%':
                total = (int) (a / b);
                total = (a - (b * total));
                printf("%f\n", total);
                return 0;
                break;
            // else
            default:
                printf("Error: please print a valid operation.\n");
                return 1;
        }
    }
    else
    {
        // if not correct number of arguments, try again
        printf("Error: too many/too few arguments. Try again.");
        return 1;
    }
}