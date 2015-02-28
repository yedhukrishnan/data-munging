#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "weather.c"

#define MAX_DAY_COUNT 30

struct weather* get_weather_data(char** line)
{
  struct weather *weather_data;
  int i = 0, counter = 0;

  weather_data = malloc(sizeof(struct weather) * MAX_DAY_COUNT);
  
  for(i = 0; i < 33; i++)
    {
      char *day, *max_temp, *min_temp;
      day = strtok(line[i], " *");
      if(isdigit(day[0]))
        {
          max_temp = (char*) strtok(NULL, " *");
          min_temp = (char*) strtok(NULL, " *");
          weather_data[counter].day = atoi(day);
          weather_data[counter].max_temperature = atoi(max_temp);
          weather_data[counter].min_temperature = atoi(min_temp);
          counter++;
        }
    }

  return weather_data;
}
