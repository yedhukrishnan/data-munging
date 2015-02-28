#include<stdio.h>

#include "file_reader.c"
#include "data_parser.c"

int main()
{
  int i, temperature_spread, day;
  char **lines = read_lines_from_file("weather.dat");
  struct weather *weather_data = get_weather_data(lines);

  temperature_spread = weather_data[0].max_temperature - weather_data[0].min_temperature;
  day = weather_data[0].day;
  for(i = 1; i <= MAX_DAY_COUNT; i++)
    if(temperature_spread > (weather_data[i].max_temperature - weather_data[i].min_temperature))
      {
        temperature_spread = weather_data[i].max_temperature - weather_data[i].min_temperature;
        day = weather_data[i].day;
      }

  printf("Day with minimum temperature spread: %d\n", day);

  return 0;
}
