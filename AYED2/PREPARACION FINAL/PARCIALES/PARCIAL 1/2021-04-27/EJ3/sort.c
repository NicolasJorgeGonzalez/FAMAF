/*
  @file sort.c
  @brief sort functions implementation
*/
#include <stdbool.h>
#include "helpers.h"
#include "sort.h"
#include "song.h"

bool goes_before(song_t s1, song_t s2)
{
    return s1.seconds <= s2.seconds;
}

bool array_is_sorted(song_t playlist[], unsigned int length)
{
    unsigned int i = 0u;
    bool sorted = true;
    while (i + 1 < length && sorted)
    {
        sorted = goes_before(playlist[i], playlist[i + 1]);
        i = i + 1;
    }
    return sorted;
}

bool array_is_odd_sorted(song_t playlist[], unsigned int length)
{
    if (length < 2)
    {
        return true;
    }

    song_t min = playlist[1];

    for (unsigned int i = 1; i < length; i += 2)
    {
        if (!goes_before(min, playlist[i]))
        {
            return false;
        }
        min = playlist[i];
    }

    return true;
}
