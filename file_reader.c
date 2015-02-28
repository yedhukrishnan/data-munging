#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#include "weather.c"

int parse_file()
{
  FILE *weather_data_file;
  char line[100];
  struct weather weather_data[31];
  int i = 0, j;

  weather_data_file = fopen("weather.dat", "r");
  while(fgets(line, sizeof(line), weather_data_file) != NULL)
    {
      char *value[3];
      value[0] = strtok(line, " *");
      if(isdigit(value[0][0]))
        {
          for(j = 1; j <= 2; j++)
            value[j] = strtok(NULL, " *");
          weather_data[i].day = atoi(value[0]);
          weather_data[i].max_temperature = atoi(value[1]);
          weather_data[i].min_temperature = atoi(value[2]);
        }
    }
  fclose(weather_data_file);

  return 0;
}

int main()
{
  parse_file();
  return 0;
}
