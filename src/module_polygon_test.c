#include "viewer.h"

int main(void) {
  // Example input line: f 2/1/1 4/2/1 1/3/1\
  // Example output line: 2 4 1 \

  // int total_polygons = 1;
  // polygon_t all_polygons[total_polygons];  // -- массив структур polygon_t

  char* line = "f  1//2  7//2  5//2";

  int line_length = strlen(line);

  char* token_pointer = NULL;

  // get(line);

  printf("Length = %d\n", line_length);

  line = malloc(line_length * sizeof(char) + 1);

  strtok(line, " ");  // - отделить часть строки до первого пробела

  // нужно сохранить строку
  char* line_with_vertex_numbers;

  while ((token_pointer = strtok(NULL, "/")) != NULL) {
    printf("%s ", token_pointer);
    strtok(NULL, " ");
  }

  return 0;
}
