#include <malloc/malloc.h>

#include "viewer.h"

int main(void) {
  int error = 0;
  data obj = {
      .total_vertexes = 0,
      .total_polygons = 0,
      .matrix_3d = {.matrix = NULL, .rows = 0, .cols = 3},
      .polygons = NULL,
  };

  FILE* file_pointer;

  //---------- узнаем количество вершин и полигонов ------------------
  file_pointer = fopen("models/cube.obj", "r");

  if (file_pointer != NULL) {
    printf("start of file\n");
    error = count_vertexes_and_polygons_number(file_pointer, &obj);
  } else {
    printf("error file not found\n");
    exit(EXIT_FAILURE);
  }
  printf("In current .obj file:\n");
  printf("vertexes: %d\n", obj.total_vertexes);
  printf("polygons: %d\n", obj.total_polygons);

  fclose(file_pointer);
  printf("end of file reached and file closed\n\n");

  //--- выделяем память под считанное количество структур полигонов ---

  // unsigned int size = 0;

  // obj.polygons = calloc(1, sizeof(polygon_t));
  // size = malloc_size(obj.polygons);
  // printf("размер памяти под полигоны до: %d \n", size);

  // printf("выделяем память под %d полигонов\n", obj.total_polygons);
  // obj.polygons = calloc(obj.total_polygons, sizeof(polygon_t));

  // size = malloc_size(obj.polygons);
  // printf("разме памяти под полигоны после: %d \n\n", size);

  //--------------- парсим полигоны ----------------------------------

  // file_pointer = fopen("models/cube.obj", "r");

  // if (file_pointer != NULL) {
  //   printf("------------------ start of file\n");

  //   error = parse_polygons(file_pointer, &obj);

  //   } else {
  //   printf("error file not found\n");
  //   exit(EXIT_FAILURE);
  // }

  // fclose(file_pointer);
  // printf("------------------ end of file reached and file closed\n");

  return error;
}
