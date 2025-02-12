#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

void sort(char letters[], char sorted[], unsigned int indexes[], unsigned int length)
{
    unsigned int searched_index = 0;
    unsigned int current_index = 0;
    unsigned int j = 0;

    while (j != length)
    {
        if (indexes[current_index] > length)
        {
            perror("Error: el valor asignado a una letra es distinto al que le corresponde.\n");
            exit(EXIT_FAILURE);
        }
        else if (searched_index == indexes[current_index])
        {
            sorted[searched_index] = letters[current_index];
            searched_index++;
            current_index = 0;
            j++;
        }
        else
        {
            current_index++;
            if (current_index >= length)
            {
                // Esto asegura que no excedamos el tamaño del arreglo
                current_index = 0;
            }
        }
    }
}

void dump(char arreglo[], unsigned int length)
{
    printf("\"");
    for (unsigned int j = 0u; j < length; j++)
    {
        printf("%c", arreglo[j]);
    }
    printf("\"");
    printf("\n\n");
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size)
{
    char letter;
    int number;
    unsigned int i = 0;

    FILE *file = fopen(path, "r");

    while (!feof(file))
    {
        fscanf(file, "%d -> *%c*\n", &number, &letter);

        indexes[i] = number;
        letters[i] = letter;

        i++;
    }

    fclose(file);

    if (i > max_size)
    {
        perror("El limite de elementos en el arreglo fue superado.\n");
        exit(EXIT_FAILURE);
    }

    return (i);
}