/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y)
{
    return x.rank <= y.rank;
}

bool array_is_sorted(player_t array[], unsigned int length)
{
    unsigned int i = 1u;
    while (i < length && goes_before(array[i - 1u], array[i]))
    {
        i++;
    }
    return (i == length);
}

void swap(player_t array[], unsigned int pos1, unsigned int pos2)
{
    player_t aux = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = aux;
}

static unsigned int partition(player_t array[], unsigned int lft, unsigned int rgt)
{
    int i, j, pivot;
    pivot = lft;
    i = lft + 1;
    j = rgt;

    while (i <= j)
    {
        if (goes_before(array[i], array[pivot]))
        {
            i = i + 1;
        }
        else if (goes_before(array[pivot], array[j]))
        {
            j = j - 1;
        }
        else if (goes_before(array[pivot], array[i]) && goes_before(array[j], array[pivot]))
        {
            swap(array, i, j);
            i = i + 1;
            j = j - 1;
        }
    }

    swap(array, pivot, j);
    pivot = j;

    return pivot;
}

static void quick_sort_rec(player_t array[], unsigned int lft, unsigned int rgt)
{
    unsigned int pivot;

    if (rgt > lft)
    {
        pivot = partition(array, lft, rgt);

        quick_sort_rec(array, lft, (pivot == 0u) ? 0u : pivot - 1);
        quick_sort_rec(array, pivot + 1, rgt);
    }
}

void sort(player_t a[], unsigned int length)
{
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}