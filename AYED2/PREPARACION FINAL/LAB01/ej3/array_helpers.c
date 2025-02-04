#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "array_helpers.h"

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath)
{
    int element;
    int lenght;
    FILE *file = fopen(filepath, "r");
    if (fscanf(file, "%d", &element) == 1)
    {
        lenght = element;
    }

    for (unsigned int i = 0; i < max_size; i++)
    {
        if (fscanf(file, "%d", &element) == 1)
        {
            array[i] = element;
        }
        else
        {
            break;
        }
    }
    fclose(file);
    return lenght;
}

void array_dump(int a[], unsigned int length)
{
    for (unsigned int i = 0; i < length; i++)
    {
        printf("%d\n", a[i]);
    }
}