#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

#include <stdbool.h>
#include "player.h"

bool goes_before(player_t x, player_t y)
{
    return x->rank < y->rank;
}

bool array_is_sorted(player_t atp[], unsigned int length)
{
    for (unsigned int i = 0; i < length - 1; i++)
    {
        if (goes_before(atp[i + 1], atp[i])) // Verifica si el elemento siguiente es menor al actual
        {
            return false;
        }
    }
    return true;
}

void sort(player_t a[], unsigned int length)
{
    quick_sort_player(a, 0, length - 1);
}

void quick_sort_player(player_t array[], unsigned int lft, unsigned int rgt)
{
    if (lft < rgt)
    {
        unsigned int ppiv = partition(array, lft, rgt);
        quick_sort_player(array, lft, ppiv);
        quick_sort_player(array, ppiv + 1, rgt);
    }
}

unsigned int partition(player_t array[], unsigned int lft, unsigned int rgt)
{
    unsigned int ppiv = lft;
    unsigned int i = lft;
    unsigned int j = rgt;

    while (i < j)
    {
        while (goes_before(array[i], array[ppiv]))
        {
            i++;
        }
        while (goes_before(array[ppiv], array[j]))
        {
            j--;
        }

        if (i < j)
        {
            swap_player(array, i, j);
            i++;
            j--;
        }
    }

    swap_player(array, lft, j);
    return j;
}

void swap_player(player_t array[], unsigned int a, unsigned int b)
{
    player_t tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}
