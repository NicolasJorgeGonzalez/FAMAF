#ifndef _STRFUNCS_H
#define _STRFUNCS_H

#include <stdbool.h>

/**
 * @brief Calcula la longitud de la cadena apuntada por str
 **/
size_t string_length(const char *str);

/**
 * @brief Devuelve una nueva cadena en memoria dinámica que se obtiene tomando los caracteres de str que son distintos del caracter c
 **/
char *string_filter(const char *str, char c);

/**
 * @brief  Indica si la cadena apuntada por str es simétrica
 **/
char *string_filter(const char *str, char c);

#endif
