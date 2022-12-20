#include "test.h"

START_TEST(test_scale) {
    matrix_t test_mat;
    matrix_t scaled;
    double scale = 2;
    int wrong = 0;

    s21_create_matrix(3, 3, &test_mat);
    s21_create_matrix(3, 3, &scaled);

    test_mat.matrix[0][0] = 1;
    test_mat.matrix[0][1] = 2;
    test_mat.matrix[0][2] = 3;
    test_mat.matrix[1][0] = 4;
    test_mat.matrix[1][1] = 5;
    test_mat.matrix[1][2] = 6;
    test_mat.matrix[2][0] = 7;
    test_mat.matrix[2][1] = 8;
    test_mat.matrix[2][2] = 9;

    scaled.matrix[0][0] = 2;
    scaled.matrix[0][1] = 4;
    scaled.matrix[0][2] = 6;
    scaled.matrix[1][0] = 8;
    scaled.matrix[1][1] = 10;
    scaled.matrix[1][2] = 12;
    scaled.matrix[2][0] = 14;
    scaled.matrix[2][1] = 16;
    scaled.matrix[2][2] = 18;

    model_scale(&test_mat, scale);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (test_mat.matrix[i][j] != scaled.matrix[i][j])
                wrong = 1;

    s21_remove_matrix(&test_mat);
    s21_remove_matrix(&scaled);       

    ck_assert_int_eq(wrong, 0);
} END_TEST

START_TEST(test_rotate_x) {
    matrix_t test_mat;
    matrix_t rotated;
    int wrong = 0;

    s21_create_matrix(3, 3, &test_mat);
    s21_create_matrix(3, 3, &rotated);

    test_mat.matrix[0][0] = 1;
    test_mat.matrix[0][1] = 2;
    test_mat.matrix[0][2] = 3;
    test_mat.matrix[1][0] = 4;
    test_mat.matrix[1][1] = 5;
    test_mat.matrix[1][2] = 6;
    test_mat.matrix[2][0] = 7;
    test_mat.matrix[2][1] = 8;
    test_mat.matrix[2][2] = 9;

    rotated.matrix[0][0] = 1;
    rotated.matrix[0][1] = -1.50207;
    rotated.matrix[0][2] = 3.27777;
    rotated.matrix[1][0] = 4;
    rotated.matrix[1][1] = -2.47881;
    rotated.matrix[1][2] = 7.40645;
    rotated.matrix[2][0] = 7;
    rotated.matrix[2][1] = -3.45556;
    rotated.matrix[2][2] = 11.5351;

    model_rotate(&test_mat, 'x', 45);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            ck_assert_float_eq_tol(test_mat.matrix[i][j], rotated.matrix[i][j], 1e-3);

    s21_remove_matrix(&test_mat);
    s21_remove_matrix(&rotated);       

    ck_assert_int_eq(wrong, 0);
} END_TEST

START_TEST(test_rotate_y) {
    matrix_t test_mat;
    matrix_t rotated;
    int wrong = 0;

    s21_create_matrix(3, 3, &test_mat);
    s21_create_matrix(3, 3, &rotated);

    test_mat.matrix[0][0] = 1;
    test_mat.matrix[0][1] = 2;
    test_mat.matrix[0][2] = 3;
    test_mat.matrix[1][0] = 4;
    test_mat.matrix[1][1] = 5;
    test_mat.matrix[1][2] = 6;
    test_mat.matrix[2][0] = 7;
    test_mat.matrix[2][1] = 8;
    test_mat.matrix[2][2] = 9;

    rotated.matrix[0][0] = -2.02739;
    rotated.matrix[0][1] = 2;
    rotated.matrix[0][2] = 2.42687;
    rotated.matrix[1][0] = -3.00413;
    rotated.matrix[1][1] = 5;
    rotated.matrix[1][2] = 6.55555;
    rotated.matrix[2][0] = -3.98088;
    rotated.matrix[2][1] = 8;
    rotated.matrix[2][2] = 10.6842;

    model_rotate(&test_mat, 'y', 45);


    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            ck_assert_float_eq_tol(test_mat.matrix[i][j], rotated.matrix[i][j], 1e-3);

    s21_remove_matrix(&test_mat);
    s21_remove_matrix(&rotated);       

    ck_assert_int_eq(wrong, 0);
} END_TEST

START_TEST(test_rotate_z) {
    matrix_t test_mat;
    matrix_t rotated;
    int wrong = 0;

    s21_create_matrix(3, 3, &test_mat);
    s21_create_matrix(3, 3, &rotated);

    test_mat.matrix[0][0] = 1;
    test_mat.matrix[0][1] = 2;
    test_mat.matrix[0][2] = 3;
    test_mat.matrix[1][0] = 4;
    test_mat.matrix[1][1] = 5;
    test_mat.matrix[1][2] = 6;
    test_mat.matrix[2][0] = 7;
    test_mat.matrix[2][1] = 8;
    test_mat.matrix[2][2] = 9;

    rotated.matrix[0][0] = -1.17649;
    rotated.matrix[0][1] = 1.90155;
    rotated.matrix[0][2] = 3;
    rotated.matrix[1][0] = -2.15323;
    rotated.matrix[1][1] = 6.03022;
    rotated.matrix[1][2] = 6;
    rotated.matrix[2][0] = -3.12997;
    rotated.matrix[2][1] = 10.1589;
    rotated.matrix[2][2] = 9;

    model_rotate(&test_mat, 'z', 45);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            ck_assert_float_eq_tol(test_mat.matrix[i][j], rotated.matrix[i][j], 1e-3);

    s21_remove_matrix(&test_mat);
    s21_remove_matrix(&rotated);       

    ck_assert_int_eq(wrong, 0);
} END_TEST

START_TEST(test_move_x) {
    matrix_t test_mat;
    matrix_t moved;
    int wrong = 0;

    s21_create_matrix(3, 3, &test_mat);
    s21_create_matrix(3, 3, &moved);

    test_mat.matrix[0][0] = 1;
    test_mat.matrix[0][1] = 2;
    test_mat.matrix[0][2] = 3;
    test_mat.matrix[1][0] = 4;
    test_mat.matrix[1][1] = 5;
    test_mat.matrix[1][2] = 6;
    test_mat.matrix[2][0] = 7;
    test_mat.matrix[2][1] = 8;
    test_mat.matrix[2][2] = 9;

    moved.matrix[0][0] = 2;
    moved.matrix[0][1] = 2;
    moved.matrix[0][2] = 3;
    moved.matrix[1][0] = 5;
    moved.matrix[1][1] = 5;
    moved.matrix[1][2] = 6;
    moved.matrix[2][0] = 8;
    moved.matrix[2][1] = 8;
    moved.matrix[2][2] = 9;

    model_move(&test_mat, 'x', 1);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (test_mat.matrix[i][j] != moved.matrix[i][j])
                wrong = 1;

    s21_remove_matrix(&test_mat);
    s21_remove_matrix(&moved);       

    ck_assert_int_eq(wrong, 0);
} END_TEST

START_TEST(test_move_y) {
    matrix_t test_mat;
    matrix_t moved;
    int wrong = 0;

    s21_create_matrix(3, 3, &test_mat);
    s21_create_matrix(3, 3, &moved);

    test_mat.matrix[0][0] = 1;
    test_mat.matrix[0][1] = 2;
    test_mat.matrix[0][2] = 3;
    test_mat.matrix[1][0] = 4;
    test_mat.matrix[1][1] = 5;
    test_mat.matrix[1][2] = 6;
    test_mat.matrix[2][0] = 7;
    test_mat.matrix[2][1] = 8;
    test_mat.matrix[2][2] = 9;

    moved.matrix[0][0] = 1;
    moved.matrix[0][1] = 3;
    moved.matrix[0][2] = 3;
    moved.matrix[1][0] = 4;
    moved.matrix[1][1] = 6;
    moved.matrix[1][2] = 6;
    moved.matrix[2][0] = 7;
    moved.matrix[2][1] = 9;
    moved.matrix[2][2] = 9;

    model_move(&test_mat, 'y', 1);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (test_mat.matrix[i][j] != moved.matrix[i][j])
                wrong = 1;

    s21_remove_matrix(&test_mat);
    s21_remove_matrix(&moved);       

    ck_assert_int_eq(wrong, 0);
} END_TEST

START_TEST(test_move_z) {
    matrix_t test_mat;
    matrix_t moved;
    int wrong = 0;

    s21_create_matrix(3, 3, &test_mat);
    s21_create_matrix(3, 3, &moved);

    test_mat.matrix[0][0] = 1;
    test_mat.matrix[0][1] = 2;
    test_mat.matrix[0][2] = 3;
    test_mat.matrix[1][0] = 4;
    test_mat.matrix[1][1] = 5;
    test_mat.matrix[1][2] = 6;
    test_mat.matrix[2][0] = 7;
    test_mat.matrix[2][1] = 8;
    test_mat.matrix[2][2] = 9;

    moved.matrix[0][0] = 1;
    moved.matrix[0][1] = 2;
    moved.matrix[0][2] = 4;
    moved.matrix[1][0] = 4;
    moved.matrix[1][1] = 5;
    moved.matrix[1][2] = 7;
    moved.matrix[2][0] = 7;
    moved.matrix[2][1] = 8;
    moved.matrix[2][2] = 10;

    model_move(&test_mat, 'z', 1);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (test_mat.matrix[i][j] != moved.matrix[i][j])
                wrong = 1;

    s21_remove_matrix(&test_mat);
    s21_remove_matrix(&moved);       

    ck_assert_int_eq(wrong, 0);
} END_TEST


Suite *suite_athena(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("athena");
  tc_core = tcase_create("Core");

//   tcase_add_test(tc_core, test_conv_from);
//   tcase_add_test(tc_core, test_conv_to);
  tcase_add_test(tc_core, test_scale);
  tcase_add_test(tc_core, test_rotate_x);
  tcase_add_test(tc_core, test_rotate_y);
  tcase_add_test(tc_core, test_rotate_z);
  tcase_add_test(tc_core, test_move_x);
  tcase_add_test(tc_core, test_move_y);
  tcase_add_test(tc_core, test_move_z);
  suite_add_tcase(s, tc_core);
  return s;
}