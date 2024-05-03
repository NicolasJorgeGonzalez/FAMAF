#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

void print_help(char *program_name)
{
  /* Print the usage help of this program. */
  printf("Usage: %s <input file path>\n\n"
         "Load character data from a given file in disk.\n"
         "\n"
         "The input file must exist in disk and every line in it must have the "
         "following format:\n\n"
         "[<char> <char>] <char[5]> life: <uint>, strength: <uint>, agility: <uint>\n\n"

         "where each value represent: \n\n"
         "[<a | p | t | m> <g | e>] <Name> life: <[0-100]>, strength: <[0-10]>,"
         "agility: <[0-10]>\n\n"
         "Those elements must be copied into an array 'a'.\n"
         "\n\n",
         program_name);
}

char *parse_filepath(int argc, char *argv[])
{
  /* Parse the filepath given by command line argument. */
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

  /* parse the filepath given in command line arguments */
  filepath = parse_filepath(argc, argv);

  /* create an array to store all the game characters */
  CharacterList array;

  /* parse the file to fill the array */
  array_from_file(array, filepath);

  /* show the data on the screen */
  array_dump(array);

  /* calculate the mean life of all alive characters */
  printf("La vida media de los caracteres es:%f\n", array_alive_mean_life(array));

  return (EXIT_SUCCESS);
}
