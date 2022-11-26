#include <src/s21_matrix.h>

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

int scale_matrix(matrix_t *move, matrix_t *result) {
    result->matrix[0][0] = move->matrix[0][0];
    result->matrix[1][1] = move->matrix[0][1];
    result->matrix[2][2] = move->matrix[0][2];
    result->matrix[3][3] = 1;
    return 0;
}

/* Следующие две функции предназначены для вытаскивания координаты из списка или,
наоборот, вставки координаты */

void crd_stlr(matrix_t *crd_main, matrix_t *crd, int row) {
    for (int i = 0; i < 4; i++)
        crd->matrix[0][i] = crd_main->matrix[row][i];
}

void crd_ret(matrix_t *crd_main, matrix_t *crd, int row) {
    for (int i = 0; i < 4; i++)
        crd_main->matrix[row][i] = crd->matrix[0][i];
}

/* Данная функция производит само афинное преобразование, пробегаясь по
каждой точке в матрице координат */

void crd_metamorph(matrix_t *crd_main, matrix_t *athena) {
    matrix_t crd;

    s21_create_matrix(1, 4, &crd);

    for (int i = 0; i < crd_main->rows; i++) {
        crd_stlr(crd_main, &crd, i);
        s21_mult_matrix(&crd, athena, &crd);
        crd_ret(crd_main, &crd, i);
    }

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
        scale_matrix(move, &athena);
    }

    crd_metamorph(crd_main, &athena);
    s21_remove_matrix(&athena);
}

void conv_to_matr(coor_type *coors, matrix_t *crd_main) {
    s21_create_matrix(coors->elements / 3, 4, crd_main);

    for (int i = 0; i < coor_type->elements; i++) {
        crd_main->matrix[i / 3][i % 3] = coors->line[i];
        if (i % 3 == 2)
            crd_main->matrix[i / 3][3] = 0.0;
    }
}

void conv_from_matr(coor_type *coors, matrix_t *crd_main) {
    for (int i = 0; i < coor_type->elements; i++) {
        coors->line[i] = crd_main->matrix[i / 3][i % 3];
    }
}
