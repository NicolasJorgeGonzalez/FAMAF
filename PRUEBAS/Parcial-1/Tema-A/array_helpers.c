#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"
#include "character.h"

void array_dump(CharacterList array)
{
  for (alignment_t alignment = good; alignment < CHARACTER_ALIGNMENTS; ++alignment)
  {
    for (charttype_t charttype = physical; charttype < CHARACTER_TYPES; ++charttype)
    {
      Character character = array[charttype][alignment];

      char *str_alignment = (character.alignment == good) ? "Good" : "Evil";
      char *str_alive = (character.alive) ? "Yes" : "Nope";

      fprintf(stdout,
              "Character '%s': Life=%u/100, Strength=%u/10, Agility=%u/10, "
              "alignment='%s', Alive='%s'\n",
              NAMES[character.name], character.life, character.strength,
              character.agility, str_alignment, str_alive);
    }
  }
}

float array_alive_mean_life(CharacterList array)
{
  unsigned int players_alive = 0u;
  unsigned int total_life = 0u;
  float avarage_life;
  Character aux_character;

  for (alignment_t i = good; i < CHARACTER_ALIGNMENTS; i++)
  {
    for (charttype_t j = 0; j < CHARACTER_TYPES; j++)
    {
      aux_character = array[j][i];
      if (aux_character.alive)
      {
        total_life = total_life + aux_character.life;
        players_alive++;
      }
    }
  }
  if (players_alive != 0u)
  {
    avarage_life = total_life / players_alive;
  }
  else
  {
    avarage_life = 0;
  }
  return avarage_life;
}

unsigned int array_from_file(CharacterList array, const char *filepath)
{
  FILE *file = NULL;

  // check if file exists
  file = fopen(filepath, "r");
  if (file == NULL)
  {
    fprintf(stderr, "File does not exist.\n");
    exit(EXIT_FAILURE);
  }

  // read the file
  unsigned int readed = 0;
  while (!feof(file))
  {
    charttype_t charttype;
    alignment_t alignment;

    char s_charttype, s_alignment;
    int res = fscanf(file, " [%c %c] ", &s_charttype, &s_alignment);
    if (res != 2)
    {
      fprintf(stderr, "Error reading type and alignment.\n");
      exit(EXIT_FAILURE);
    }

    switch (s_charttype)
    {
    case 'a':
      charttype = agile;
      break;
    case 'p':
      charttype = physical;
      break;
    case 't':
      charttype = tank;
      break;
    case 'm':
      charttype = magic;
      break;
    default:
      fprintf(stderr, "Invalid charttype character.\n");
      exit(EXIT_FAILURE);
    }

    switch (s_alignment)
    {
    case 'g':
      alignment = good;
      break;
    case 'e':
      alignment = evil;
      break;
    default:
      fprintf(stderr, "Invalid charttype character.\n");
      exit(EXIT_FAILURE);
    }

    // Reads the name and obtains an name_t value
    name_t name = read_character_name(file);

    Character character = character_from_file_line(file, name, alignment);

    array[charttype][alignment] = character;
    ++readed;
  }

  // close the file
  fclose(file);

  return readed;
}
