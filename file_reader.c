#include <stdio.h>
#include <stdlib.h>

#define MAX_STRING_LENGTH 35
#define MAX_LINE_LENGTH 150

char** read_lines_from_file(char*);

char** read_lines_from_file(char* file_name)
{
  FILE *file;
  char **lines;
  int i;
  file = fopen(file_name, "r");
  lines = malloc(sizeof(char*) * MAX_STRING_LENGTH);
  for(i = 0, lines[0] = lines[i] = malloc(sizeof(char) * MAX_LINE_LENGTH);
      fgets(lines[i], sizeof(char) * MAX_LINE_LENGTH, file) != NULL;
      i++, lines[i] = malloc(sizeof(char) * MAX_LINE_LENGTH));
  return lines;
}
