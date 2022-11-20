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

typedef struct Polygon_t {
   int* polygon_indices;
   int indices_number;
} Polygon_t;

typedef struct ObjData_t { // для куба
   int vertex_number;      // количество координат -> 24
   int polygons_number;    // количество полигонов -> 12
   
   
   int index_arr_size;     // массив индексов      -> 72
   int* index_array;
   VertexArray_t vertex_array;
   Polygon_t* polygons_array;

} ObjData_t;

int parse_file(FILE* fp, ObjData_t* data, char* obj_file_name);

int get_data_numbers(FILE* fp, ObjData_t* data);
int get_data_arrays(FILE* fp, ObjData_t* data);

void get_number_of_polygon_indices(char* line, ObjData_t* data, int f_line_counter); // возвращает указатель
int get_array_of_polygon_indices(char* line, ObjData_t* data, int f_line_counter);

void print_vertex_array(ObjData_t* data);

#endif  // VIEWER_H