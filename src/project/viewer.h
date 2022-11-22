#ifndef VIEWER_H
#define VIEWER_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define OK 0
#define ERR_1 1
#define ERR_2 2


typedef struct Vertex_t {
  double* coords_array;
  int coords_number;
} Vertex_t;

// typedef struct Polygon_t {
//    int* polygon_indices;
//    int indices_number;
// } Polygon_t;

typedef struct ObjData_t {
   Vertex_t vertex_array;
   // Polygon_t* polygons_array;

   int  index_array_size;
   int  index_array_counter;
   int* index_array; // массив индексов
} ObjData_t;

typedef struct matrix_t {
  double** matrix;
  int columns;
  int rows;
} matrix_t;


int  parse_file(FILE* fp, ObjData_t* data, char* obj_file_name);
int  get_data_numbers(FILE* fp, ObjData_t* data);
int  get_data_arrays(FILE* fp, ObjData_t* data);
int  write_index_array_in_data(char* line, char* line_copy, ObjData_t* data);
void print_vertex_array(ObjData_t* data);

int  rotate_x(double alpha, matrix_t *result);
int  rotate_y(double alpha, matrix_t *result);
int  rotate_z(double alpha, matrix_t *result);
int  rotation(matrix_t *move, matrix_t *result);
int  move_matrix(matrix_t *move, matrix_t *result);
int  scale_matrix(matrix_t *move, matrix_t *result);
void crd_stlr(matrix_t *crd_main, matrix_t *crd, int row);
void crd_ret(matrix_t *crd_main, matrix_t *crd, int row);
void crd_metamorph(matrix_t *crd_main, matrix_t *athena);
void core_algorithm(matrix_t *crd_main, matrix_t *move, int type);


int  s21_create_matrix(int rows, int columns, matrix_t *result);
int  s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
void s21_remove_matrix(matrix_t *A);

#endif  // VIEWER_H
