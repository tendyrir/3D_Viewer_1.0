#ifndef VIEWER_H
#define VIEWER_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct VertexArray_t {
  double* coords_vertex;
  int coords_number;
  int scale;
 } VertexArray_t;

int v_lines_parser(FILE* fp, VertexArray_t* vertex_array, char* obj_file_name);

int get_number_of_vertexes(FILE* fp, VertexArray_t* vertex_array);
int get_coords_of_vertexes(FILE* fp, VertexArray_t* vertex_array);

void print_vertex_array(VertexArray_t* vertex_array);

#endif  // VIEWER_H