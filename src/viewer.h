#ifndef VIEWER_H
#define VIEWER_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct matrix {
  double** matrix;
  int rows;
  int cols;
} matrix_t;

int create_matrix(int rows, int cols, matrix_t *result);
char* create_lexem(char* infix_input_str);

int filling_tmp_double_array_for_current_line(char* current_line, 
        char* axis_coord_char_array, double axis_coord_double, double* tmp_array_for_current_line);


#endif  // VIEWER_H