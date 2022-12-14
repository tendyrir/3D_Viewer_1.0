#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * Тесты на количество вершин и индексов
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *  */


START_TEST(test_count_icosahedron) {
  char *obj_path = "models/icosahedron.obj";
  ObjData_t data = {0};

  parse_file(&data, obj_path);

  ck_assert_int_eq(data.vertex_array.coords_number, 36);
  ck_assert_int_eq(data.index_array_size, 120);

  free(data.vertex_array.coords_array);
  free(data.index_array);
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

