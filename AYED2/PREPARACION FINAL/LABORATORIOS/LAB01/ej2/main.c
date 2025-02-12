#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Maximum allowed length of the array */
#define MAX_SIZE 100000

unsigned int array_from_stdin(int array[])
{
    unsigned int lenght;

    printf("Ingrese la cantidad de elementos que tendra el arreglo: ");
    scanf("%u", &lenght);

    if (lenght > MAX_SIZE)
    {
        perror("Supero el numero maximo de numeros posibles.");
        return EXIT_FAILURE;
    }

    for (unsigned int i = 0; i < lenght; i++)
    {
        printf("Ingrese el numero °%d: ", i + 1);
        scanf("%d", &array[i]);
    }

    return lenght;
}

void array_dump(int a[], unsigned int length)
{
    for (unsigned int i = 0; i < length; i++)
    {
        printf("El numero °%d es: %d\n", i + 1, a[i]);
    }
}

int main()
{
    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];

    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_stdin(array);

    /*dumping the array*/
    array_dump(array, length);

    return EXIT_SUCCESS;
}
