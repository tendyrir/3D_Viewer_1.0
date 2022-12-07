#include "viewer.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int error = OK;

  if (result == NULL || rows <= 0 || columns <= 0) {
    error = ERR_1;

  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(result->rows, sizeof(double *));
    if (result->matrix == NULL) {
      error = ERR_1;
    } else {
      for (int i = 0; i < result->rows; i++) {
        result->matrix[i] = calloc(result->columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          error = ERR_1;
        }
      }
    }
  }
  return error;
}

 int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
   int error = OK;
   if ((A == NULL || A->matrix == NULL || A->columns <= 0 || A->rows <= 0) ||
       (B == NULL || B->matrix == NULL || B->columns <= 0 || B->rows <= 0)) {
     error = ERR_1;
   } else if (!((A->columns == B->rows) || (B->columns == A->rows))) {
     error = ERR_2;
   } else {

//     s21_create_matrix(A->rows, B->columns, result);
     for (int i = 0; i < result->rows; i++) {
       for (int j = 0; j < result->columns; j++) {
         for (int k = 0; k < B->rows; k++) {
           result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
         }
       }

     }
   }
   return error;
 }

void s21_remove_matrix(matrix_t *A) {
  if (A != NULL && A->matrix != NULL && A->columns > 0 && A->rows > 0) {
    for (int i = 0; i < A->rows; i++) {
      free(A->matrix[i]);
      A->matrix[i] = NULL;
    }
    free(A->matrix);
    A->matrix = NULL;
    A->columns = 0;
    A->rows = 0;
  }
}

/* Матрицы поворота относительно осей x, y и z соответственно */

int rotate_x(double alpha, matrix_t *result) {
  s21_create_matrix(4, 4, result);
  result->matrix[0][0] = 1;
  result->matrix[1][1] = cos(alpha);
  result->matrix[1][2] = -sin(alpha);
  result->matrix[2][1] = sin(alpha);
  result->matrix[2][2] = cos(alpha);
  result->matrix[3][3] = 1;
  return 0;
}

int rotate_y(double alpha, matrix_t *result) {
  s21_create_matrix(4, 4, result);
  result->matrix[0][0] = cos(alpha);
  result->matrix[0][2] = sin(alpha);
  result->matrix[1][1] = 1;
  result->matrix[2][0] = -sin(alpha);
  result->matrix[2][2] = cos(alpha);
  result->matrix[3][3] = 1;
  return 0;
}

int rotate_z(double alpha, matrix_t *result) {
  s21_create_matrix(4, 4, result);
  result->matrix[0][0] = cos(alpha);
  result->matrix[0][1] = -sin(alpha);
  result->matrix[1][0] = sin(alpha);
  result->matrix[1][1] = cos(alpha);
  result->matrix[2][2] = 1;
  result->matrix[3][3] = 1;
  return 0;
}

/* Функция создания матрицы вращения по 3-м осям */

int rotation(matrix_t *move, matrix_t *result) {
  matrix_t x_rot;
  matrix_t y_rot;
  matrix_t z_rot;
  matrix_t buffer;

  s21_create_matrix(4, 4, &buffer);

  rotate_x(move->matrix[0][0], &x_rot);
  rotate_y(move->matrix[0][1], &y_rot);
  rotate_z(move->matrix[0][2], &z_rot);

  s21_mult_matrix(&x_rot, &y_rot, &buffer);
  s21_mult_matrix(&buffer, &z_rot, result);

  s21_remove_matrix(&x_rot);
  s21_remove_matrix(&y_rot);
  s21_remove_matrix(&z_rot);
  s21_remove_matrix(&buffer);
  return 0;
}

/* Матрица смещения точки по 3-м координатам */

int move_matrix(matrix_t *move, matrix_t *result) {
  result->matrix[0][0] = 1;
  result->matrix[0][3] = move->matrix[0][0];
  result->matrix[1][1] = 1;
  result->matrix[1][3] = move->matrix[0][1];
  result->matrix[2][2] = 1;
  result->matrix[2][3] = move->matrix[0][2];
  result->matrix[3][3] = 1;
  return 0;
}

/* Матрица масштабирования */
// записываем в атену athena
int scale_matrix(matrix_t *move, matrix_t *result) {
  result->matrix[0][0] = move->matrix[0][0];
  result->matrix[1][1] = move->matrix[0][1];
  result->matrix[2][2] = move->matrix[0][2];
  result->matrix[3][3] = 1;
  return 0;
}

/* Следующие две функции предназначены для вытаскивания координаты из списка
или, наоборот, вставки координаты */

void crd_stlr(matrix_t *crd_main, matrix_t *crd, int row) {
  for (int i = 0; i < 4; i++) crd->matrix[0][i] = crd_main->matrix[row][i];
}

void crd_ret(matrix_t *crd_main, matrix_t *crd, int row) {
  for (int i = 0; i < 4; i++) crd_main->matrix[row][i] = crd->matrix[0][i];
}

/* Данная функция производит само афинное преобразование, пробегаясь по
каждой точке в матрице координат */

void crd_metamorph(matrix_t *crd_main, matrix_t *athena) {
  matrix_t crd;

  s21_create_matrix(1, 4, &crd);

  for (int i = 0; i < crd_main->rows; i++) {
    crd_stlr(crd_main, &crd, i);

    s21_mult_matrix(&crd, athena, &crd);

//        for (int k = 0; k < crd.rows; k++){
//            for (int j = 0; j < crd.columns; j++){
//                printf("%lf\n", crd.matrix[k][j]);
//            }
//        }

//    printf("\nmult returns: %d\n", aboba);

     crd_ret(crd_main, &crd, i);
  }
  //
  s21_remove_matrix(&crd);
}

/* Данная функция - объединение всего, что написано сверху.
crd_main - матрица координат, move - матрица 1x3, в которой указаны
координаты смещения. type - тип преобразования:
0 - вращение по осям
1 - смещение
2 - масштабирование */

void core_algorithm(matrix_t *crd_main, matrix_t *move, int type) {
  matrix_t athena;

  s21_create_matrix(4, 4, &athena);

  if (type == 0) {
    rotation(move, &athena);
  } else if (type == 1) {
    move_matrix(move, &athena);
  } else if (type == 2) {
    scale_matrix(move, &athena);  // атена изменилась
  }

  crd_metamorph(crd_main, &athena);
  s21_remove_matrix(&athena);
}

void conv_to_matr(ObjData_t *data,
                  matrix_t *crd_main) {  // перевод из массива в матрицу

  for (int i = 0; i < data->vertex_array.coords_number; i++) {
    crd_main->matrix[i / 3][i % 3] = data->vertex_array.coords_array[i];
    if (i % 3 == 2) crd_main->matrix[i / 3][3] = 0.0;
  }
}

//void conv_from_matr_to_array_copy(ObjData_t* data, double *coords_array_copy, matrix_t *crd_main) {  // перевод из матрицы в массив
//  for (int i = 0; i < data->vertex_array.coords_number; i++) {
//    coords_array_copy[i] = crd_main->matrix[i / 3][i % 3];
//  }
//}


void conv_from_matr(ObjData_t* data, matrix_t *crd_main) { // перевод из матрицы в массив
    for (int i = 0; i < data->vertex_array.coords_number; i++) {
        data->vertex_array.coords_array[i] = crd_main->matrix[i / 3][i % 3];
    }
}

void model_scale(matrix_t*  vertexes, double scale) {
    if (scale != 0) {
        for (int i = 1; i < vertexes->rows; i++) {
            for (int j = 0; j < 3; j++) {
                vertexes->matrix[i][j] *= scale;
            }
        }
    }
}

void model_rotate(matrix_t *vertexes, char coord, double angle) {
    if (coord == 'x') {
        for (int i = 1; i < vertexes->rows; i++) {
            double temp_y = vertexes->matrix[i][1];
            double temp_z = vertexes->matrix[i][2];
            vertexes->matrix[i][1] = cos(angle) * temp_y - sin(angle) * temp_z;
            vertexes->matrix[i][2] = sin(angle) * temp_y + cos(angle) * temp_z;
        }
    } else if (coord == 'y') {
        for (int i = 1; i < vertexes->rows; i++) {
            double temp_x = vertexes->matrix[i][0];
            double temp_z = vertexes->matrix[i][2];
            vertexes->matrix[i][0] = cos(angle) * temp_x - sin(angle) * temp_z;
            vertexes->matrix[i][2] = sin(angle) * temp_x + cos(angle) * temp_z;
        }
    } else if (coord == 'z') {
        for (int i = 1; i < vertexes->rows; i++) {
            double temp_x = vertexes->matrix[i][0];
            double temp_y = vertexes->matrix[i][1];
            vertexes->matrix[i][0] = cos(angle) * temp_x - sin(angle) * temp_y;
            vertexes->matrix[i][1] = sin(angle) * temp_x + cos(angle) * temp_y;
        }
    }
}

void model_move(matrix_t *vertexes, char coord, double value) {
    int index;
    if (coord == 'x') {
        index = 0;
    } else if (coord == 'y') {
        index = 1;
    } else if (coord == 'z') {
        index = 2;
    }
    for (int i = 1; i < vertexes->rows; i++) {
        vertexes->matrix[i][index] += value;
    }
}


