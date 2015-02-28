#include<stdio.h>

#include "file_reader.c"
#include "data_parser.c"

int main()
{
  int i;
  char **lines = read_lines_from_file("weather.dat");
  struct weather *weather_data = get_weather_data(lines);
  
  for(i = 0; i < MAX_DAY_COUNT; i++)
    {
      printf("%d\n", weather_data[i].day);
    }

  return 0;
}
