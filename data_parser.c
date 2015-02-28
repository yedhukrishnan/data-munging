#include <stdio.h>
//#include <string.h>
//#include <ctype.h>
//#include <stdlib.h>

//#include "weather.c"

int main()
{
  FILE *weather_data_file;
  char line[31][200];
  //struct weather weather_data[31];
  int i = 0, j;
  
  weather_data_file = fopen("weather.dat", "r");
  for(i = 0; fgets(line[i], sizeof(line[i]), weather_data_file) != NULL; i++);
  for(i = 0; i < 31; i++)
    puts(line[i]);
  fclose(weather_data_file);
  /*
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
  
  */
  puts("lol");
  return 0;
}


/*
int main()
{
  puts("something wrong");
  read_lines_from_file();
  puts("lol2");
  return 0;
}
*/
