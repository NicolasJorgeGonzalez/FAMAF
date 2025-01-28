#if !defined(WEATHER_UTILS)
#define WEATHER_UTILS

#include "../ej2/weather.h"
#include "../ej2/array_helpers.h"

int min_temp(WeatherTable array);

void max_temp_year(WeatherTable arreglo, int output[YEARS]);

void max_prec_month(WeatherTable arreglo, int output[YEARS]);

#endif // WEATHER_UTILS
