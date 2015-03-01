#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "file_reader.c"

struct team
{
  char name[10];
  int for_goal_count;
  int against_goal_count;
};

int main()
{
  char **lines = read_lines_from_file("football.dat");
  char football_data[10][10];
  int i, j, counter = 0;
  struct team teams[20];
  for(i = 0; lines[i] != NULL; i++)
    {
      char *data;
      for(j = 0, data = (char*) strtok(lines[i], " .-"); data != NULL; j++, data = (char*) strtok(NULL, " .-"))
        strcpy(football_data[j], data);
      if(isdigit(football_data[0][0]))
        {
          strcpy(teams[counter].name, football_data[1]);
          teams[counter].for_goal_count = atoi(football_data[6]);
          teams[counter].against_goal_count = atoi(football_data[7]);
        }
    }
  return 0;
}
