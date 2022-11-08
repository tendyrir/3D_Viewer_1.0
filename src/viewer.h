#ifndef VIEWER_H
#define VIEWER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
# cube.obj
#

g cube

v  0.0  0.0  0.0 - координата первой вершины
v  0.0  0.0  1.0
v  0.0  1.0  0.0
v  0.0  1.0  1.0
v  1.0  0.0  0.0
v  1.0  0.0  1.0
v  1.0  1.0  0.0
v  1.0  1.0  1.0 - координата восьмой вершины

vn  0.0  0.0  1.0
vn  0.0  0.0 -1.0
vn  0.0  1.0  0.0
vn  0.0 -1.0  0.0
vn  1.0  0.0  0.0
vn -1.0  0.0  0.0

f  1  7  5 - первые 3 значения, соединяем в полигон точки 1, 7 и 5
f  1 3  7
f  1//6  4//5  3//6
f  1//6  2//6  4//6
f  3//3  8//3  7//3
f  3//3  4//3  8//3
f  5//5  7//5  8//5
f  5//5  8//5  6//5
f  1//4  5//4  6//4
f  1//4  6//4  2//4
f  2//1  6//1  8//1
f  2//1  8//1  4//1
*/

// v - (verticies) это кординаты вершины в формате x y z, тип данных double

// f - (faceit) это точки которые нужно соединить для получения полигона, нас
// интересуют только первые цифры из значения, значений может быть от 3 до
// бесконечности

typedef struct Matrix {  // структура данных для матрицы вершин
  double **matrix;
  int rows;
  int cols;
} matrix_t;

typedef struct facets {  // структура данных для массива полигонов
  int *vertexes;  // массив номеров вершин которые надо соединить [1, 7, 5]
  int numbers_of_vertexes_in_facets;  // количество вершин которые надо
                                      // соединить
} polygon_t;

typedef struct data {
  unsigned int total_vertexes;  // количество вершин (точек) после первого
                                // прочтения .obj файла
  unsigned int total_facets;  // количество полигонов после первого прочтения
  matrix_t matrix_3d;
  polygon_t *polygons;  // добавлякс как массив структур потому что 1 структура
                        // под одну строчку f
} data;

int parse_vertexes_from_file(FILE *fp);

#endif  // VIEWER_H