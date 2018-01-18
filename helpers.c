/**
 * helpers.c
 *
 * CS50 AP
 * Sort Race
 *
 * Helper functions for the sort race
 */

#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

void printarray(int values[], int n);
/**
 * Returns true if str is a valid flag (-a, -b, -r, or -s), false otherwise.
 */
bool check_flag(char *str)
{
    // array with two numbers swapped
    if (strcmp(str, "-a") == 0)
    {
        return true;
    }

    // array totally backwards
    else if (strcmp(str, "-b") == 0)
    {
        return true;
    }

    // random array
    else if (strcmp(str, "-r") == 0)
    {
        return true;
    }

    // sorted array
    else if (strcmp(str, "-s") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * Sorts array of n values using bubble sort.
 */
void bubble(int values[], int n)
{
    for (int h = 0; h < n; h++)
    {
        int count = 0;
        for (int i = 0; i < n - 1; i++)
        {
            // assign next place value to another variable
            // assign current value to the next place
            // assign new variable value to the current place
            if (values[i + 1] < values[i])
            {
                int f = values[i + 1];
                values[i + 1] = values[i];
                values[i] = f;
                count++;
            }
        }
        // if array is already sorted, stop looping
        if (count == 0)
            {
                break;
            }
    }
    return;
}

/**
 * Sorts array of n values using selection sort.
 */
int min;

void selection(int values[], int n)
{
    // TODO
    for (int h = 0; h < (n - 1); h++)
    {
        min = h;
        for (int i = h + 1; i < n; i++)
        {
            // define minimum value
            if (values[i] < values[min])
            {
                min = i;
            }
        }
        // if set minimum is not the least, switch places with h
        // and set h to new min
        if (min != h)
        {
            int f = values[h];
            values[h] = values[min];
            values[min] = f;
        }
    }
    return;
}

/**
 * Sorts array of n values using insertion sort.
 */
void insertion(int values[], int n)
{
    // TODO
    for (int i = 1; i < n; i++)
    {
        int tosort = values[i];
        int j = i;

        // while values behind j greater than value of j
        // move j back one place
        while (j > 0 && values[j - 1] > tosort)
        {
            values[j] = values[j - 1];
            j = j - 1;
        }
        values[j] = tosort;
    }
    return;
}