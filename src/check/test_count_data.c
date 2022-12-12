#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на количество вершин и индексов
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */

// START_TEST(test) {
//   char *obj_path = "models/icosahedron.obj";
//   ObjData_t data = {0};
//   // s21_parser_result code_check = S21_PARSER_ERROR_FILE;
//   // test_parser_fail(obj_path, &data, code_check);
//   parse_file(&data, obj_path);
//   free(data.vertex_array.coords_array);
//   free(data.index_array);

// }


START_TEST(test_count_icosahedron) {
  char *obj_path = "models/icosahedron.obj";
  ObjData_t data = {0};

//   test_parser(obj_path, &data, S21_FALSE);
  parse_file(&data, obj_path);

  ck_assert_int_eq(data.vertex_array.coords_number, 36);
  ck_assert_int_eq(data.index_array_size, 120);

  free(data.vertex_array.coords_array);
  free(data.index_array);

//   ck_assert_float_eq_tol(data.max_coord, 167.101471, TEST_PRECISION);

//   s21_destroy_obj_data(&data);
}


Suite *suite_count_data(void) {

  Suite *s;
  TCase *tc_core;

  s = suite_create("count_data");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_count_icosahedron);

  suite_add_tcase(s, tc_core);

  return s;
}

