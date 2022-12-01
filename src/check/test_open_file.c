#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты ошибки открытия файла
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

START_TEST(test) {
  char *obj_path = "models/icosahedron.obj";
  ObjData_t data = {0};
  // s21_parser_result code_check = S21_PARSER_ERROR_FILE;
  // test_parser_fail(obj_path, &data, code_check);
  parse_file(&data, obj_path);



  free(data.vertex_array.coords_array);
  free(data.index_array);

}

// START_TEST(test_parser_fail2) {
//   char *obj_path = "_objfiles/lkjhygtfrds.obj";
//   s21_obj_data data;
//   s21_parser_result code_check = S21_PARSER_ERROR_FILE;
//   test_parser_fail(obj_path, &data, code_check);
// }



Suite *suite_open_file(void) {

  Suite *s;
  TCase *tc_core;

  s = suite_create("parse_file");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test);
  // tcase_add_test(tc_core, test_parser_fail2);

  suite_add_tcase(s, tc_core);

  return s;
}

