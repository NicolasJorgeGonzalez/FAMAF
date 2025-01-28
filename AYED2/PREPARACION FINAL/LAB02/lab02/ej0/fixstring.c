#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s)
{
    unsigned int length = 0;
    for (unsigned int i = 0; i < FIXSTRING_MAX; i++)
    {
        if (s[i] == '\0')
        {
            break;
        }
        length++;
    }
    return length;
}

bool fstring_eq(fixstring s1, fixstring s2)
{
    bool are_eq = true;
    unsigned int s1_length = fstring_length(s1);
    unsigned int s2_length = fstring_length(s2);
    unsigned int max_length = s1_length;
    if (s2_length != s1_length)
    {
        are_eq = false;
        return are_eq;
    }
    for (unsigned int i = 0; i < max_length; i++)
    {
        if (s1[i] != s2[i])
        {
            are_eq = false;
            return are_eq;
        }
    }
    return are_eq;
}

bool fstring_less_eq(fixstring s1, fixstring s2)
{
    bool are_less_eq = true;
    unsigned int s1_length = fstring_length(s1);
    unsigned int s2_length = fstring_length(s2);
    if (s2_length > s1_length)
    {
        are_less_eq = true;
        return are_less_eq;
    }
    for (unsigned int i = 0; i < s1_length; i++)
    {
        if (s1[i] > s2[i])
        {
            are_less_eq = false;
            return are_less_eq;
        }
    }
    return are_less_eq;
}
