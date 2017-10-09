#include <stdio.h>
#include <cs50.h>   // calls all modules

int main(void) // sets up this function
{
    float temperature_c = get_float("C: \n");   // retrieves temp in C from user
    float temperature_f = ((temperature_c * 9) / 5) + 32;   // converts temp from C to F
    printf("F: %0.1f\n", temperature_f);   // prints temp in F
}