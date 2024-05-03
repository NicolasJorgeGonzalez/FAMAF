#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

void print_help(char *program_name)
{
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Load store data from a given file in disk.\n"
           "\n"
           "The input file must exist in disk and every line in it must have the following format:\n\n"
           ".---(price data)----. .--(amount data)--. .---(store data)----.\n"
           "<sh> <mb> <cs> <mo> <sh> <mb> <cs> <mo> #<store_id>-<store_number># \n\n"
           "The value of <store_id> must be a unsigned int type and the remaining values of the line must be unsigned integers.\n"
           "\n\n",
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

    return (result);
}

int main(int argc, char *argv[])
{
    char *filepath = NULL;

    filepath = parse_filepath(argc, argv);

    RankingTable array;

    array_from_file(array, filepath);

    array_dump(array);

    char *team_name = "...";
    char team[20];

    printf("\nElija un team: ");
    scanf("%s", team);
    team_name = team;

    float sum_points_team = total_track_points_per_team(array, team_name);
    printf("\nTotal Maximo de %.20s es: %f \n", team_name, sum_points_team);
    return (EXIT_SUCCESS);
}
