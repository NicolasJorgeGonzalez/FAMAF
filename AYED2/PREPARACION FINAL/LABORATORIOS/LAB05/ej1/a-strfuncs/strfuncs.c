#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "strfuncs.h"

size_t string_length(const char *str)
{
    const char *aux = str;
    size_t size = 0;

    while (*aux != '\0')
    {
        aux++;
        size++;
    }
    return size;
  /*return aux - str;  // Diferencia de punteros = longitud de la cadena*/
}

char *string_filter(const char *str, char c)
{
    const char *aux = str;
    size_t length = string_length(str);
    char *string_filter = malloc(sizeof(char)*(length + 1));
    int i = 0;

    while (*aux != '\0')
    {
        if (*aux != c)
        {
            string_filter[i] = *aux;
            i++;
        }
        aux++;
    }
    string_filter[i] = '\0';
    return string_filter;
}

bool string_is_symmetric(const char *str)
{
    const char *first = str;
    const char *last = str + string_length(str) - 1;
    bool result = true;

    while (first < last)
    {
        if (*first != *last)
        {
            return false;
        }
        first++;
        last--;
    }
    return result;
}