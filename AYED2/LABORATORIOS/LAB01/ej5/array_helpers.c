#include <stdio.h>
#include <stdlib.h>
#include "mybool.h"
#include "array_helpers.h"

unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath)
{
    FILE *file = fopen(filepath, "r");

    unsigned int length;
    fscanf(file, "%u", &length);

    if (length > max_size)
    {
        printf("La longitud del array excede el tamaño máximo permitido.\n");
        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < length; i++)
    {
        unsigned int value;
        fscanf(file, "%u", &value);
        array[i] = value;
    }

    fclose(file);

    return length;
}

mybool array_is_sorted(int a[], unsigned int length)
{
    mybool result = true;

    for (unsigned int i = 0; i < (length - 1); i++)
    {
        result = result && (a[i] <= a[i + 1]);
    }

    return result;
}

void array_dump(int a[], unsigned int length)
{
    for (unsigned int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
}