/**
 * helpers.c
 *
 * CS50 AP
 * Find
 *
 * Helper functions.
 */

#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // min is first value in array and max is last value in array
    int min = 0;
    int max = n;

    // split array in half and search the side that "value" is part of until value is found
    while (min <= max)
    {
        // midpoint of array is at the average of the end points
        int midpoint = (min + max) / 2;

        // if value is the midpoint, return true
        if (value == values[midpoint])
        {
            return true;
        }
        // if value is greater than the midpoint, reset the min to the point in front of the midpoint
        else if (value > values[midpoint])
        {
            min = midpoint + 1;
        }
        // if value is less than the midpoint, reset the max to the point behind the midpoint
        else if (value < values[midpoint])
        {
            max = midpoint - 1;
        }
    }
    return false;
}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // bubble sort

    // initialize array index to zero
    int count = 0;

    // for each index in array
    for (int i = 0; i < n - 1; i++)
    {
        if (values[i + 1] < values[i])
        {
            // assign next index value to another variable
            int f = values[i + 1];
            // assign current index value to the next index place
            values[i + 1] = values[i];
            // assign new variable value to the current index place
            values[i] = f;
            // move to next index
            count++;
        }
    }
        // if array is already sorted, stop looping
    if (count == 0)
        {
            break;
        }

    return;
}
