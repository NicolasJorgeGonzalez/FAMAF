/*
  @file array_helpers.c
  @brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"

/**
 * @brief returns true when reach last line in weather file
 * @param[in] year Year array position (start in 0 ends with YEARS - 1)
 * @param[in] month Month of the year (december is last month 11u)
 * @param[in] day Day of the month. We assume all month have 28 days.
 * @return True when is the last line of the file, False otherwise
 */
static bool is_last_line(unsigned int year, unsigned int month, unsigned int day)
{
    return year == YEARS - 1u && month == december && day == DAYS - 1u;
}

void array_dump(WeatherTable a)
{
    for (unsigned int year = 0u; year < YEARS; ++year)
    {
        for (month_t month = january; month <= december; ++month)
        {
            for (unsigned int day = 0u; day < DAYS; ++day)
            {
                fprintf(stdout, "%u %u %u ", year + FST_YEAR, month + 1, day + 1);
                weather_to_file(stdout, a[year][month][day]);
                if (!is_last_line(year, month, day))
                {
                    fprintf(stdout, "\n");
                }
            }
        }
    }
}

void array_from_file(WeatherTable array, const char *filepath)
{
    FILE *file = NULL;

    file = fopen(filepath, "r");
    if (file == NULL)
    {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }

    unsigned int k_year = 0u;
    unsigned int k_month = 0u;
    unsigned int k_day = 0u;
    while (!feof(file))
    {
        int res = fscanf(file, " %u %u %u ", &k_year, &k_month, &k_day);

        if (res != 3)
        {
            fprintf(stderr, "Invalid array.\n");
            exit(EXIT_FAILURE);
        }

        if (k_year < FST_YEAR || k_year > LST_YEAR)
        {
            fprintf(stderr, "\"%i\" is an invalid year, must be in between 1980 and 2016\n", k_year);
            exit(EXIT_FAILURE);
        }

        if (k_month > MONTHS)
        {
            fprintf(stderr, "\"%i\" is an invalid month, must be in between 1 and 12\n", k_month);
            exit(EXIT_FAILURE);
        }

        if (k_day < FST_DAY || k_day > LST_DAY)
        {
            fprintf(stderr, "\"%i\" is an invalid day, must be in between 1 and 28\n", k_day);
            exit(EXIT_FAILURE);
        }

        Weather weather = weather_from_file(file);
        unsigned int year_index = -(FST_YEAR - k_year);
        unsigned int month_index = k_month - 1;
        unsigned int day_index = k_day - FST_DAY;

        array[year_index][month_index][day_index] = weather;
    }

    fclose(file);
}