#include <stdio.h>
#include <stdlib.h>
#include "../ej2/weather.h"
#include "../ej2/array_helpers.h"
#include "weather_utils.h"

int min_temp(WeatherTable array)
{
    int result = array[0][0][0]._min_temp;

    for (unsigned int i = 0; i < YEARS; i++)
    {
        for (unsigned int j = 0; j < MONTHS; j++)
        {
            for (unsigned int k = 0; k < DAYS; k++)
            {
                if (result > array[i][j][k]._min_temp)
                {
                    result = array[i][j][k]._min_temp;
                }
            }
        }
    }

    return result;
}

void max_temp_year(WeatherTable arreglo, int output[YEARS])
{
    int result = arreglo[0][0][0]._max_temp;

    for (unsigned int i = 0; i < YEARS; i++)
    {
        for (unsigned int j = 0; j < MONTHS; j++)
        {
            for (unsigned int k = 0; k < DAYS; k++)
            {
                if (result < arreglo[i][j][k]._max_temp)
                {
                    result = arreglo[i][j][k]._max_temp;
                }
            }
        }
        output[i] = result;
    }
}

void max_prec_month(WeatherTable arreglo, int output[YEARS])
{
    for (unsigned int i = 0; i < YEARS; i++)
    {
        unsigned int result = 0;
        unsigned int month = 0;

        for (unsigned int j = 0; j < MONTHS; j++)
        {
            for (unsigned int k = 0; k < DAYS; k++)
            {
                if (result < arreglo[i][j][k]._rainfall)
                {
                    result = arreglo[i][j][k]._rainfall;
                    month = j;
                }
            }
        }
        output[i] = month;
    }
}
