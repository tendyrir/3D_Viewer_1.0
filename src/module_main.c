#include "viewer.h"

int main(void) {
  int error = 0;
  data obj = {0};

  FILE* file_pointer = fopen("models/cube.obj", "r");

  if (file_pointer != NULL) {
    count_vertexes_and_polygons_number(file_pointer, &obj);

  } else {
    exit(EXIT_FAILURE);
  }

  printf("In current .obj file:\n");
  printf("vertexes: %d\n", obj.total_vertexes);
  printf("polygons: %d\n", obj.total_polygons);

  fclose(file_pointer);

  return error;
}
