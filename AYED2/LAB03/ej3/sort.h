#ifndef _SORT_H
#define _SORT_H
#include <stdbool.h>
#include "player.h"

bool goes_before(player_t x, player_t y);

/**
 * @brief    Checks if the array 'a' is in ascending order according
 *           to the goes_before function
 *
 * @param[in]  atp     The Player array
 * @param[in]  length  Length of player array
 *
 * @return True if array is sorted in ascendirng order according to goes_before function, false otherwise
 */
bool array_is_sorted(player_t atp[], unsigned int length);

void sort(player_t a[], unsigned int length);

void quick_sort_player(player_t array[], unsigned int lft, unsigned int rgt);

unsigned int partition(player_t array[], unsigned int lft, unsigned int rgt);

void swap_player(player_t array[], unsigned int a, unsigned int b);

#endif
