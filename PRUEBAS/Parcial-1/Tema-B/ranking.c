#include <stdlib.h>
#include "ranking.h"
#include <string.h>

static const int NUMBER_OF_RANKING_VARS = 6;

Ranking ranking_from_file(FILE *file)
{

  Ranking ranking;
  int a, b, c;
  char d[20], e[20];
  float f;

  int res = fscanf(file, EXPECTED_RANKING_FILE_FORMAT, &a, &b, &c, d, e, &f);
  if (res != NUMBER_OF_RANKING_VARS)
  {
    printf("Error with NUMBER_OF_RANKING_VARS");
    exit(EXIT_FAILURE);
  }

  ranking.pos = a;
  ranking.pos_prev = b;
  ranking.diff = c;
  strcpy(ranking.name, d);
  strcpy(ranking.team, e);
  ranking.points = f;

  return ranking;
}

float total_track_points_per_team(RankingTable a, char *team_name)
{
  float sum = 0;
  Ranking aux_biker;

  // printf("\nLegal\n");
  for (unsigned int ranking = 0u; ranking < NO_PLAYERS; ranking++)
  {
    // printf("\nIndice de ranking = %u\n", ranking);
    for (unsigned int type = road; type <= track; type++)
    {
      // printf("\nIndice de type = %u\n", ranking);
      aux_biker = a[ranking][type];
      if (strcmp(aux_biker.team, team_name) == 0)
      {
        printf("\nteam=%s\n", aux_biker.name);
        sum = aux_biker.points + sum;
      }
    }
  }
  return sum;
}
