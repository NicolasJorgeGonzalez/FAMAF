#include <stdbool.h>
#include <stdio.h>
#include "pivot.h"

bool is_pivot(int array[], unsigned int length, unsigned int piv)
{
    for (unsigned int i = 0; i < length; i++)
    {
        if ((i <= piv) && (array[i] > array[piv]))
        {
            return false;
        }
        else if ((i > piv) && (array[i] <= array[piv]))
        {
            return false;
        }
    }

    return true;
}