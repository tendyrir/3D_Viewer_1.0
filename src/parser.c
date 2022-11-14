#include "viewer.h"

void print_vertex_array(VertexArray_t* vertex_array) {
    for (int j = 0; j < vertex_array->coords_number; j++) {
            printf("%lf ", vertex_array->coords_vertex[j]);
    }
}


int get_number_of_vertexes_and_facets(FILE         * fp, 
                                      VertexArray_t* v_arr, 
                                      IndexArray_t * i_arr) {
    int     error              = 0;
    int     number_of_vertexes = 0;
    int     number_of_facets   = 0;
    char*   line               = NULL;
    size_t  len                = 0;
    ssize_t read               = 0;

    /*     ssize_t getline(char **lineptr, size_t *n, FILE *stream); */
    while ((read = getline(&line, &len, fp)) != -1) {
        
        if (line[0] == 'v' && line[1] == ' ') {
            number_of_vertexes++;
        }

        if (line[0] == 'f' && line[1] == ' ') {
            number_of_facets++;
        }


    }

    if (line != NULL) {
        free(line);
    }

    v_arr -> coords_number  = number_of_vertexes * 3;
    i_arr  -> indices_number = number_of_facets;

    printf("In current .obj file:\n");
    printf("vertexes: %d\n", number_of_vertexes);
    printf("polygons: %d\n", number_of_facets);

    // if (fp == NULL)
    //     exit(EXIT_FAILURE);

    return error;
}


int get_coords_of_vertexes(FILE* fp, VertexArray_t* v_arr) {
    int error = 0;
    int number_of_vertexes = 0;

    char* line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    int i = 0;
    double x = 0, y = 0, z = 0;

    /*     ssize_t getline(char **lineptr, size_t *n, FILE *stream); */
    while ((read = getline(&line, &len, fp)) != -1) {

        if (line[0] == 'v' && line[1] == ' ') {
            char*  current_line = line + 3;
            char*  coord_chars  = NULL;
            double coord_double = 0;
            // printf("строка:%s", current_line);
            sscanf(current_line, "%lf%lf%lf", &x, &y, &z);
            v_arr->coords_vertex[i + 0] = x; 
            v_arr->coords_vertex[i + 1] = y;
            v_arr->coords_vertex[i + 2] = z;
            // vertex_array->coords_vertex[i + 3] = vertex_array->scale;
            i += 3;    
        }

        if (line[0] == 'f' && line[1] == ' ') {
            
        }

    }
    if (line != NULL) {
        free(line);
    }
    return error;
}

int lines_parser(FILE* fp, VertexArray_t* v_arr, IndexArray_t* i_arr, char* obj_file_name) {

/*  1. Объявить структуру массива вершин, код ошибки, указатель на файл */
    int error = 0;

/*  2. Открыть файл, узнать и сохранить количество координат */
    fp = fopen(obj_file_name, "r");
    error = get_number_of_vertexes_and_facets(fp, v_arr, i_arr);
    fclose(fp);

/*  3. Выделить память под координаты (и масштаб) */
    v_arr->coords_vertex = malloc(v_arr->coords_number * sizeof(double));
    // vertex_array->scale = 1;
    
/*  6. Открыть файл еще раз для и считать данные координат вершин из файла в массив */
    fp = fopen(obj_file_name, "r");
    error = get_coords_of_vertexes(fp, v_arr);
    fclose(fp);

    return error;
}


