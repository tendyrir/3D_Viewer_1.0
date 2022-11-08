#include "viewer.h"

int main(void) {
  char line[17] = "v  1.0  -1.0  0.0";
  const char delim[3] = "v ";
  char *token;

  double x = 0;
  double y = 0;
  double z = 0;

  printf("input line: |%s|\n", line);

  token = strtok(line, delim);

  while (token != NULL) {
    printf("%s\n", token);
    token = strtok(NULL, delim);
  }

  return 0;
}