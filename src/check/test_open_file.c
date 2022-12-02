#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты ошибки открытия файла
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

START_TEST(test_open_valid_cube) {
  char *obj_path = "models/icosahedron.obj";
  ObjData_t data = {0};

  parse_file(&data, obj_path);

  free(data.vertex_array.coords_array);
  free(data.index_array);

}

START_TEST(test_2) {
  char *obj_path = "models/icosahedron.obj";
  ObjData_t data = {0};

  parse_file(&data, obj_path);
  
  free(data.vertex_array.coords_array);
  free(data.index_array);

}



Suite *suite_open_file(void) {

  Suite *s;
  TCase *tc_core;

  s = suite_create("parse_file");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_1);
  tcase_add_test(tc_core, test_2);


  suite_add_tcase(s, tc_core);

  return s;
}

