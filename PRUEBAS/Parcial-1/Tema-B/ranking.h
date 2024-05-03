#ifndef _RANKING_H
#define _RANKING_H

#define EXPECTED_RANKING_FILE_FORMAT " %d %d %d %s %s %f "

#define NO_PLAYERS 100
#define TYPES 2

#include <stdio.h>

typedef enum types
{
  road,
  track
} type_t;

typedef struct _ranking
{
  unsigned int pos;
  int pos_prev;
  int diff;
  char name[20];
  char team[20];
  float points;
} Ranking;

typedef Ranking RankingTable[NO_PLAYERS][TYPES];

Ranking ranking_from_file(FILE *file);

float total_track_points_per_team(RankingTable a, char team_name[]);

#endif
