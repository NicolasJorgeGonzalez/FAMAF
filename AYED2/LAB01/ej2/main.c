#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

unsigned int array_from_stdin(int array[], unsigned int max_size)
{
    FILE *input = stdin;

    unsigned int length;

    printf("Ingrese la cantidad de elementos del array: ");
    fscanf(input, "%u", &length);

    if (length > max_size)
    {
        printf("La longitud del array excede el tamaño máximo permitido.\n");
        exit(EXIT_FAILURE);
    }

    for (unsigned int i = 0; i < length; i++)
    {
        unsigned int value;
        printf("Ingrese el elemento: ");
        fscanf(input, "%u", &value);
        array[i] = value;
    }

    return length;
}

void array_dump(int a[], unsigned int length)
{
    for (unsigned int i = 0; i < length; i++)
    {
        printf("%d ", a[i]);
    }
}

int main()
{
    int array[MAX_SIZE];

    unsigned int length = array_from_stdin(array, MAX_SIZE);

    array_dump(array, length);

    return EXIT_SUCCESS;
}
