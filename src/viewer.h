#ifndef VIEWER_H
#define VIEWER_H

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Vertex_t {
  double* coords_array;
  int coords_number;        //->  количество координат -> 24
} Vertex_t;

typedef struct Polygon_t {
   int* polygon_indices;
   int indices_number;
} Polygon_t;

typedef struct ObjData_t {  // для куба
   int  index_array_size;
   int  index_array_counter;
   int* index_array;
   
   // int  polygons_number;    // количество полигонов -> 6
   Polygon_t* polygons_array;

   Vertex_t vertex_array;   //->
} ObjData_t;

int parse_file(FILE* fp, ObjData_t* data, char* obj_file_name);

int get_data_numbers(FILE* fp, ObjData_t* data);
int get_data_arrays(FILE* fp, ObjData_t* data);

// void get_number_of_polygon_indices(char* line, ObjData_t* data, int f_line_counter); // возвращает указатель
// int get_array_of_polygon_indices(char* line, ObjData_t* data, int f_line_counter);

int write_index_array_in_data(char* line, char* line_copy, ObjData_t* data);

void print_vertex_array(ObjData_t* data);

#endif  // VIEWER_H