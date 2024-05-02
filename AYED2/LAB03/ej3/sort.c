#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool array_is_sorted(player_t atp[], unsigned int length)
{
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i]))
    {
        i++;
    }
    return (i == length);
}

bool goes_before(player_t x, player_t y)
{
    if (x.rank > y.rank)
    {
        return false;
    }

    return true;
}

void sort(player_t a[], unsigned int length)
{
    quick_sort_player(a, 1, length);
}

void quick_sort_player(player_t array[], unsigned int lft, unsigned int rgt)
{
    unsigned int ppiv;

    while (lft <= rgt)
    {
        ppiv = partition(array, lft, rgt);
        quick_sort_player(array, lft, ppiv - 1);
        quick_sort_player(array, ppiv + 1, rgt);
    }
}

unsigned int partition(player_t array[], unsigned int lft, unsigned int rgt)
{
    unsigned int ppiv = lft;
    unsigned int i = lft + 1;
    unsigned int j = rgt;

    while (i <= j)
    {
        if (goes_before(array[i], array[ppiv]))
        {
            i++;
        }

        if (goes_before(array[ppiv], array[j]))
        {
            j--;
        }

        else if (goes_before(array[j], array[ppiv]) && goes_before(array[ppiv], array[i]))
        {
            swap_player(array, i, j);
            i++;
            j--;
        }
    }

    swap_player(array, ppiv, j);
    return j;
}

void swap_player(player_t array[], unsigned int a, unsigned int b)
{
    player_t tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}