#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 35
#define MAX_LINE_LENGTH 150

char** read_lines_from_file(char*);

char** read_lines_from_file(char* file_name)
{
  FILE *file;
  char **line;
  int i;
  file = fopen(file_name, "r");
  line = malloc(sizeof(char*) * MAX_STRING_LENGTH);
  for(i = 0; i < 33; i++)
    {
      line[i] = malloc(sizeof(char) * MAX_LINE_LENGTH);
      fgets(line[i], sizeof(char) * MAX_LINE_LENGTH, file);
    }
  return line;
}
