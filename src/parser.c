#include "viewer.h"

int get_number_of_vertexes(FILE* fp, VertexArray_t* vertex_array) {
    int error = 0;
    int number_of_vertexes = 0;

    char* line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    /*     ssize_t getline(char **lineptr, size_t *n, FILE *stream); */
    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] == 'v' && line[1] == ' ') {
            number_of_vertexes++;
        }
    }

    if (line != NULL) {
        free(line);
    }
    vertex_array->coords_number = number_of_vertexes * 4;
    // printf("In current .obj file:\n");
    // printf("vertexes: %d\n", number_of_vertexes);

    // if (fp == NULL)
    //     exit(EXIT_FAILURE);

    return error;
}


int get_coords_of_vertexes(FILE* fp, VertexArray_t* vertex_array) {
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
            vertex_array->coords_vertex[i + 0] = x; 
            vertex_array->coords_vertex[i + 1] = y;
            vertex_array->coords_vertex[i + 2] = z;
            vertex_array->coords_vertex[i + 3] = vertex_array->scale;
            i += 4;    
        }
    }
    if (line != NULL) {
        free(line);
    }
    return error;
}

int v_lines_parser(FILE* fp, VertexArray_t* vertex_array, char* obj_file_name) {

/*  1. Объявить структуру массива вершин, код ошибки, указатель на файл */
    int error = 0;

/*  2. Открыть файл, узнать и сохранить количество координат */
    fp = fopen(obj_file_name, "r");
    error = get_number_of_vertexes(fp, &vertex_array);
    fclose(fp);

/*  3. Выделить память под координаты (и масштаб) */
    vertex_array->coords_vertex = malloc(vertex_array->coords_number * sizeof(double));
    vertex_array->scale = 1;
    
/*  6. Открыть файл еще раз для и считать данные координат вершин из файла в массив */
    fp = fopen(obj_file_name, "r");
    error = get_coords_of_vertexes(fp, &vertex_array);
    fclose(fp);

    return error;
}