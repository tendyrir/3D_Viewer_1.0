#ifndef VIEWER_H
#define VIEWER_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 typedef struct VertexArray_t {
  double* coords_vertex;
  int coords_number;
 } VertexArray_t;

 typedef struct IndexArray_t {
    int* indices;
    int indices_number;
 } IndexArray_t;


int lines_parser(FILE* fp, VertexArray_t* v_arr, IndexArray_t* i_arr, char* obj_file_name);

int get_number_of_vertexes_and_facets(FILE* fp, VertexArray_t* v_arr, IndexArray_t* i_arr);

int get_coords_of_vertexes(FILE* fp, VertexArray_t* v_arr);

void print_vertex_array(VertexArray_t* v_arr);

#endif  // VIEWER_H