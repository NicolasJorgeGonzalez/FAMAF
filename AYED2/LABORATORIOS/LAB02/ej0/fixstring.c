#include <stdbool.h>
#include <assert.h>

#include "fixstring.h"

unsigned int fstring_length(fixstring s) { 
    unsigned int length = 0;

    for (unsigned int i = 0; i < FIXSTRING_MAX; i++)
    {
        if (s[i] != '\0')
        {
            length ++;
        }
        else
        {
            break;
        }
    }
    
    return length;
}

bool fstring_eq(fixstring s1, fixstring s2) {
    bool resultado = s1 == s2;
    return resultado;
}

bool fstring_less_eq(fixstring s1, fixstring s2) {
    bool resultado = s1 <= s2;
    return resultado;
}

