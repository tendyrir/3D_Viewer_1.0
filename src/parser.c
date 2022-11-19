#include "viewer.h"

void print_vertex_array(ObjData_t data) {
    for (int j = 0; j < data.vertex_array.coords_number; j++) {
            printf("%lf ", data.vertex_array.coords_vertex[j]);
    }
}


int get_data_numbers(FILE* fp, ObjData_t* data) {
    int     error                 = 0;
    int     vertex_counter        = 0;
    int     polygons_counter      = 0;
    int     total_index_counter   = 0;
    int     polygon_index_counter = 0;
    char*   line                  = NULL;
    size_t  len                   = 0;
    ssize_t read                  = 0;

    /*     ssize_t getline(char **lineptr, size_t *n, FILE *stream); */
    while ((read = getline(&line, &len, fp)) != -1) {
        
        if (line[0] == 'v' && line[1] == ' ') {
            vertex_counter++;
        }

        if (line[0] == 'f' && line[1] == ' ') {
            polygons_counter++;

            // char *tokenPtr;
            // strtok(line, " "); // Read past the initial "f"
            // while ((tokenPtr = strtok(NULL, "/")) != NULL) {
            //     // printf("%s ", tokenPtr);
            //     strtok(NULL, " "); // Return value checking omitted, assume correct input
            //     // i++;
            //     total_index_counter++;
            //     polygon_index_counter++;

            // }
            // // putchar('\n');
            // polygon_index_counter = 0;

        }
    }

    if (line != NULL) {
        free(line);
    }

    data->vertex_number = vertex_counter * 3;
    data->polygons_number = polygons_counter;
    data->index_arr_size = total_index_counter * 2;

    printf("In current .obj file  :\n");
    printf("      vertex_counter  : %d\n", vertex_counter);
    printf("data->vertex_number   : %d <- под массив координат\n", data->vertex_number);
    printf("      polygons_counter: %d <- под массив структур\n", polygons_counter);
    printf("total_index_counter   : %d\n", total_index_counter);
    printf("data->index_arr_size  : %d <- под массив индексов\n", data->index_arr_size);

    // if (fp == NULL)
    //     exit(EXIT_FAILURE);

    return error;
}


int get_data_arrays(FILE* fp, ObjData_t* data) {
    int error = 0;

    char*   line = NULL;
    size_t  len = 0;
    ssize_t read = 0;

    int i = 0;
    int j = 0;
    double x = 0, y = 0, z = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] == 'v' && line[1] == ' ') {
            char*  current_line = line + 3;
            char*  coord_chars  = NULL;
            double coord_double = 0;
            sscanf(current_line, "%lf%lf%lf", &x, &y, &z);
            data->vertex_array.coords_vertex[i + 0] = x;
            data->vertex_array.coords_vertex[i + 1] = y;
            data->vertex_array.coords_vertex[i + 2] = z;
            i += 3;    
        }

        if (line[0] == 'f' && line[1] == ' ') {
            
            // 2 функции:

            //   1. для подсчета кол-ва вершин, которые необходимо соединить

            data->polygons_array[j].indices_number = get_number_of_polygon_indices(line, O);

            // data->polygons_array[j].polygon_indices = malloc(data->polygons_array[j].indices_number * sizeof(int));
            
            //   - потом выделяем память

            //   2. запись вершин в массив для которого мы только что выделили память

            error = get_array_of_polygon_indices(line, data, j);

            j++;

        }
    }

    if (line != NULL) {
        free(line);
    }

    return error;
}

int parse_file(FILE* fp, ObjData_t* data, char* obj_file_name) {

    int error = 0;

/*  . Первое открытие файла - узнаем количества координат всего, количество полигонов */
    fp = fopen(obj_file_name, "r");

    error = get_data_numbers(fp, data);

    fclose(fp);

/*  . Выделить память под массивы */
    data->vertex_array.coords_vertex = malloc(data->vertex_number * 3 * sizeof(double));
    data->polygons_array             = malloc(data->polygons_number * sizeof(Polygon_t));

    
/*  . Второе открытие файла - заполнение массивов */
    fp = fopen(obj_file_name, "r");
    error = get_data_arrays(fp, data);
    fclose(fp);

    return error;
}


int get_number_of_polygon_indices(char* line) {
    int number_of_polygon_indices = 0;
    char *tokenPtr;
    strtok(line, " "); // Read past the initial "f"
        while ((tokenPtr = strtok(NULL, "/")) != NULL) {
            // printf("%s ", tokenPtr);
            strtok(NULL, " "); // Return value checking omitted, assume correct input
            number_of_polygon_indices++;
            // total_index_counter++;
            // polygon_index_counter++;
        }
    // putchar('\n');
    // polygon_index_counter = 0;

    return number_of_polygon_indices;
}

int get_array_of_polygon_indices(char* line, ObjData_t* data, int j) {


    char *token_ptr;


    strtok(line, " "); // Read past the initial "f"
        while ((token_ptr = strtok(NULL, "/")) != NULL) {
            // printf("%s ", token_ptr);

            // long strtol(const char *start, char **end, int radix)
            
            int value = atoi(token_ptr);

            printf("%d ", value);
            // printf("aboba\n");

            strtok(NULL, " "); // Return value checking omitted, assume correct input
            // number_of_polygon_indices++;
            // total_index_counter++;
            // polygon_index_counter++;

        }

}