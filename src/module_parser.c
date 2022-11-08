#include "viewer.h"

int main(void) {
  FILE* file_pointer = fopen("models/cube.obj", "r");

  if (file_pointer == NULL) {
    fprintf(stderr, "ERROR: file_pointer is NULL, smth is wrong.");
    exit(EXIT_FAILURE);
  }

  // printf("Parsing %s\n",
  //  parse_vertexes_from_file(file_pointer) ? "succeeded" : "failed");

  char line[100];
  while (fgets(line, sizeof(line), file_pointer) != NULL) {
    printf("%s\n", parse_vertexes_from_file(file_pointer));
  }

  fclose(file_pointer);

  return 0;
}

int parse_vertexes_from_file(FILE* fp) {
  char line[100];

  double x = 0;
  double y = 0;
  double z = 0;

  while (fgets(line, sizeof(line), fp) != NULL) {
    char token[3] = "v ";

    if (strstr(line, token) != NULL) {
      const char delim[2] = " ";
      char* part_of_line;

      part_of_line = strtok(line, delim);

      while (part_of_line != NULL) {
        part_of_line = strtok(NULL, delim);
        printf("%s", part_of_line);
      }
      printf("%s", line);
    }
  }

  return 0;
}
