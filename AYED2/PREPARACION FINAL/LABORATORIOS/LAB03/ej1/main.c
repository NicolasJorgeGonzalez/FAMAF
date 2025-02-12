#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

#define MAX_SIZE 1000

char *parse_filepath(int argc, char *argv[])
{
    char *result = NULL;

    if (argc < 2)
    {
        perror("No estas ingresando los parametros necesarios para iniciar.\n");
        exit(EXIT_FAILURE);
    }

    result = argv[1];
    return result;
}

int main(int argc, char *argv[])
{
    char *filepath = NULL;

    filepath = parse_filepath(argc, argv);

    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length = 0;

    length = data_from_file(filepath, indexes, letters, MAX_SIZE);

    sort(letters, sorted, indexes, length);
    dump(sorted, length);

    return EXIT_SUCCESS;
}