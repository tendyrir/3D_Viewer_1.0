#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "viewer.h"

int main(void) {
  int number_of_vertex = 0;   /* количество рядов матрицы */
  int number_of_cols = 4;     /* количество столбцов*/
  FILE* file_pointer;   /* указатель на файл        */
  char* line = NULL;    /* указатель на строку      */
  
  size_t len = 0;
  ssize_t read;

// 1. прочитать файл и вернуть количество вершин
  
  file_pointer = fopen("models/cube.obj", "r");
  if (file_pointer == NULL)
    exit(EXIT_FAILURE);
  printf("FIRST reading of file:\n");
  /* ssize_t getline(char **lineptr, size_t *n, FILE *stream); */
  while ((read = getline(&line, &len, file_pointer)) != -1) {
    /* это печатает длинну полученной строки 
    printf("Retrieved line of length %zu :\n", read); */

    if (line[0] == 'v' && line[1] == ' ') {
      number_of_vertex++;
      printf("%s", line);
    }
  }

  if (line != NULL) {
    free(line);
  }

  printf("In current .obj file:\n");
  printf("vertexes: %d\n", number_of_vertex);

// 2. выделить память под матрицу 4 колонки на 'количество_вершин' строк

  matrix_t vertex_matrix; 
  // = {.matrix = 0,
                            // .rows = number_of_vertex, 
                            // .cols = number_of_cols};
  create_matrix(number_of_vertex, number_of_cols, &vertex_matrix);

// 3. открыть файл для чтения еще раз
  
  file_pointer = fopen("models/cube.obj", "r");
  if (file_pointer == NULL)
    exit(EXIT_FAILURE);

// 4. считать строчку

  printf("SECOND reading of file:\n");

    int x = 0;
    // while (x != vertex_matrix.rows) {

      while ((read = getline(&line, &len, file_pointer)) != -1) {
    /* это печатает длинну полученной строки 
    printf("Retrieved line of length %zu :\n", read); */


// 5. есили текущая строк - строка с кординатами вершин
      

        if (line[0] == 'v' && line[1] == ' ') {


          double double_array_current_line[4] = {0, 0, 0, 0};
          char*  current_line = line + 3;
          char*  coord_chars  = NULL;
          double coord_double = 0;

          printf("текущая ст: %s", line);
          printf("для лексем: %s", current_line);

          filling_tmp_double_array_for_current_line(current_line, coord_chars, coord_double, double_array_current_line);

          vertex_matrix.matrix[x] = double_array_current_line;


          printf("double_array_current_line: ");

          for (int i = 0; i < 3; i++) {
            printf("%lf ", double_array_current_line[i]);
          }
          printf("\n");

        }

      // }



    }
      

  for (int k = 0; k < vertex_matrix.rows; k++) {
      for (int j = 0; j < vertex_matrix.cols; j++) {
        printf("%lf ", vertex_matrix.matrix[k][j]);
      }
    printf("\n");
  }

  if (line != NULL) {
    free(line);
  }




  return EXIT_SUCCESS;
}










int create_matrix(int rows, int cols, matrix_t *vertex_matrix) {
    int error = 0;
    if (vertex_matrix == NULL || rows <= 0 || cols <= 0) {
        error = 1;
    } else {
        vertex_matrix->rows = rows;
        vertex_matrix->cols = cols;
        vertex_matrix->matrix = calloc(vertex_matrix->rows, sizeof(double*));
        if (vertex_matrix->matrix == NULL) {
            error = 1;
        } else  {
            for (int i = 0; i < vertex_matrix->rows; i++) {
                vertex_matrix->matrix[i] = calloc(vertex_matrix->cols, sizeof(double));
                if (vertex_matrix->matrix[i] == NULL) {
                    error = 1;
                }
            }
        }
    }
    return error;
}

char* create_lexem(char* infix_input_str) {
  char* delimeters = " ";
  int next_lexem_start_index = strcspn(infix_input_str, delimeters);
  char* lexem = calloc(64, sizeof(char));
  if (!next_lexem_start_index) {
    lexem[next_lexem_start_index] = infix_input_str[next_lexem_start_index];
  } else {
    for (int i = 0; i < next_lexem_start_index; i++) {
      lexem[i] = infix_input_str[i];
    }
  }
  return lexem;
}

int filling_tmp_double_array_for_current_line(char* current_line, char* axis_coord_char_array, 
                                              double axis_coord_double, double* tmp_array_for_current_line) {

  int k = 0;
// . цикл для записи во временный массив

      while (k < 3) {
        for (int n = strlen(current_line); n >= 0; n--) {

          if (strlen(current_line) == 0)
            break;
          axis_coord_char_array = create_lexem(current_line);
          current_line += strlen(axis_coord_char_array) + 2;

// . п  ереводим массив чаров в дабл

          /* int sscanf(const char *str, const char *format, ...); */
          sscanf(axis_coord_char_array, "%lf", &axis_coord_double);
          // printf("текущая координата: %lf\n", axis_coord_double);

          tmp_array_for_current_line[k] = axis_coord_double;

          printf("элт тмп массива: %lf \n", tmp_array_for_current_line[k]);

          k++;
          
          // printf("%lf \n", axis_coord_double);

          free(axis_coord_char_array);
        }


      }


      tmp_array_for_current_line[k] = 1.111111;


  return 0;
}