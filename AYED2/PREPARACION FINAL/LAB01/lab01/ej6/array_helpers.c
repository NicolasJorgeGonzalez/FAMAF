#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

bool array_is_sorted(int a[], unsigned int length)
{
    bool is_sorted = true;

    for (unsigned int i = 1; i < length; i++)
    {
        if (a[i - 1] > a[i])
        {
            is_sorted = false;
            return is_sorted;
        }
    }
    return is_sorted;
}

void array_swap(int a[], unsigned int i, unsigned int j)
{
    int aux = a[i];

    a[i] = a[j];
    a[j] = aux;
}