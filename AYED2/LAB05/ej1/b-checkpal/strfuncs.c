#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "strfuncs.h"

size_t string_length(const char *str)
{
    size_t index = 0u;

    while (str[index] != '\0')
    {
        index++;
    }

    return index;
}

char *string_filter(const char *str, char c)
{
    char *new_str = NULL;
    unsigned int index1 = 0u;
    unsigned int index2 = 0u;
    size_t str_length = string_length(str);

    new_str = malloc(sizeof(char) * (str_length + 1));

    while (str[index1] != '\0')
    {
        if (str[index1] != c)
        {
            new_str[index2] = str[index1];
            index2++;
        }
        index1++;
    }

    new_str[index2] = '\0';

    return new_str;
}

bool string_is_symmetric(const char *str)
{
    size_t str_length = string_length(str);
    unsigned int index = 0u;
    bool result = true;

    if (str_length == 0)
    {
        return result; // Una cadena vacía es simétrica
    }

    while (result && (index <= str_length))
    {
        result = result && (str[index] == str[str_length - 1]);
        index++;
        str_length--;
    }

    return result;
}
