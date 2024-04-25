#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 1000

static void dump(char a[], unsigned int length)
{
    printf("\"");
    for (unsigned int j = 0u; j < length; j++)
    {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

void print_help(char *program_name)
{
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Sort an array given in a file in disk.\n"
           "\n"
           "The input file must have the following format:\n"
           " * The first line must contain only a positive integer,"
           " which is the length of the array.\n"
           " * The second line must contain the members of the array"
           " separated by one or more spaces. Each member must be an integer."
           "\n\n"
           "In other words, the file format is:\n"
           "<amount of array elements>\n"
           "<array elem 1> <array elem 2> ... <array elem N>\n\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[])
{
    char *result = NULL;

    if (argc < 2)
    {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return result;
}

unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size)
{
    FILE *file = fopen(path, "r");

    unsigned int i = 0;

    if (file == NULL)
    {
        fprintf(stderr, "El archivo \"%s\" no existe.\n", path);
        return EXIT_FAILURE;
    }

    while (!feof(file))
    {
        int num;
        char letter;

        fscanf(file, "%d -> *%c*\n", &num, &letter);

        if (i > max_size)
        {
            printf("%i is not a valid index, as exceeds the maximum size of %i elements.\n", i, MAX_SIZE);
            exit(EXIT_FAILURE);
        }

        indexes[i] = num;
        letters[i] = letter;

        i++;
    }

    fclose(file);

    return i;
}

int main(int argc, char *argv[])
{
    char *file = NULL;
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length = 0;

    file = parse_filepath(argc, argv);

    length = data_from_file(file, indexes, letters, MAX_SIZE);

    for (unsigned int i = 0u; i < length; i++)
    {
        sorted[indexes[i]] = letters[i];
    }

    dump(sorted, length);

    return EXIT_SUCCESS;
}
