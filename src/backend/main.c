#include "viewer.h"

int main(void) {
  ObjData_t data = {0};
  matrix_t crd;
  s21_create_matrix(8, 3, &crd);

  // char* obj_file_name = "../models/upto100/cube.obj";
  char* obj_file_name = "../models/upto100/figure1.obj";
  // char*     obj_file_name = "models/icosahedron.obj";
  // char*     obj_file_name = "models/pyramid_2.obj";
  // char*     obj_file_name = "models/gun.obj";

  parse_file(&data, obj_file_name);

  print_vertex_array(&data);

  conv_to_matr(&data, &crd);

  model_rotate(&crd, 'x', 1);

  conv_from_matr(&data, &crd);


  // printf("\n");
  print_vertex_array(&data);

  free(data.vertex_array.coords_array);
  free(data.index_array);

  return 0;
}


