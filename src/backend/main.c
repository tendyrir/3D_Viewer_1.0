#include "viewer.h"

int main(void) {
  ObjData_t data = {0};
  // matrix_t crd;

  // char* obj_file_name = "../models/upto100/cube.obj";
  // char* obj_file_name = "../models/upto1001/figure1.obj";
  // char*     obj_file_name = "models/icosahedron.obj";
  // char*     obj_file_name = "models/pyramid_2.obj";
  char*     obj_file_name = "../models/upto10000/gun.obj";

  if (check_file_exist(obj_file_name) == 1) {
    fprintf(stderr, "FILE ERROR\n");
    return 1;
  }

  parse_file(&data, obj_file_name);

  print_vertex_array(&data);
  free(data.vertex_array.coords_array);
  free(data.index_array);

  return 0;
}


