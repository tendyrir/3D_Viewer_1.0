#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "./test.h"

#define CORRECT_PATH 0
#define INVALID_PATH 1

START_TEST(test_correct_path) {
  char *filename = "./models/upto100/cube.obj";
  ck_assert_int_eq(run_test(filename), CORRECT_PATH);
} END_TEST

START_TEST(test_invalid_path) {
  char *filename = "aboba abobovna";
  ck_assert_int_eq(run_test(filename), INVALID_PATH);
} END_TEST

Suite *suite_open_file(void) {
  Suite *s;
  TCase *tc_core;
  s = suite_create("file_path_check");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_correct_path);
  tcase_add_test(tc_core, test_invalid_path);
  suite_add_tcase(s, tc_core);
  return s;
}

