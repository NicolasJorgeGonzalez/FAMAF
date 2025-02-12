#include <stdbool.h>
#include <limits.h>
#include <stdio.h>
#include "odd.h"

bool is_odd_sorted(int array[], unsigned int length)
{
    if (length < 2)
    {
        return true;
    }

    int min = array[1];

    for (unsigned int i = 1; i < length; i += 2)
    {
        if (array[i] < min)
        {
            return false;
        }
        min = array[i];
    }

    return true;
}