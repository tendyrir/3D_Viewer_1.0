#include "viewer.h"

int parse_file(FILE* fp, ObjData_t* data, char* obj_file_name) {

    int error = 0;

/*  . Первое открытие файла - узнаем количества координат всего, количество полигонов */
    fp    = fopen(obj_file_name, "r");
    error = get_data_numbers(fp, data);
    fclose(fp);

/*  . Выделить память под массивы */
    data->vertex_array.coords_array = malloc(data->vertex_array.coords_number * sizeof(double));
    data->index_array = malloc(data->index_array_size * sizeof(int));
    // data->polygons_array = malloc(data->polygons_number * sizeof(Polygon_t));


    
/*  . Второе открытие файла - заполнение массивов */
    fp    = fopen(obj_file_name, "r");
    error = get_data_arrays(fp, data);
    fclose(fp);

    return error;
}












void print_vertex_array(ObjData_t* data) {
    
    for (int j = 0; j < data->vertex_array.coords_number; j++) {
            printf("%lf ", data->vertex_array.coords_array[j]);
    }


    for (int j = 0; j < data->index_array_counter; j++) {
            printf("%d ", data->index_array[j]);
    }


}

int get_data_numbers(FILE* fp, ObjData_t* data) {

    int     error            = 0;
    int     vertex_counter   = 0;
    // int     polygons_counter = 0;
    int     total_indices    = 0;
    char*   line             = NULL;
    size_t  len              = 0;
    ssize_t read             = 0;
    char *token_ptr = NULL;

    while ((read = getline(&line, &len, fp)) != -1) {
        
        if (line[0] == 'v' && line[1] == ' ') {
            vertex_counter++;
        }
        if (line[0] == 'f' && line[1] == ' ') {
            // polygons_counter++;
            // количество не полигонов а всех индексов всех полигонов

            strtok(line, " ");
            while ((token_ptr = strtok(NULL, "/")) != NULL) {
                total_indices++;
                strtok(NULL, " ");
            }

        }
    }

    if (line != NULL) {
        free(line);
    }

    data->vertex_array.coords_number = vertex_counter * 3;
    // data->polygons_number            = 0;

    data->index_array_size           = total_indices * 2;

    printf("data->vertex_array.coords_number : %d <- под 1 массив Сержуне\n", data->vertex_array.coords_number);
    // printf("data->polygons_number            : %d <- под массив структур\n",  data->polygons_number); 
    printf("data->index_array_size           : %d <- под 2 массив Сержуне\n", data->index_array_size);
    printf("\n");

    return error;
}










int get_data_arrays(FILE* fp, ObjData_t* data) {
    int error = 0;

    char*   line = NULL;
    size_t  len = 0;
    ssize_t read = 0;

    int i = 0;
    // int f_line_counter = 0;
    double x = 0, y = 0, z = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] == 'v' && line[1] == ' ') {
            char*  current_line = line + 3;
            char*  coord_chars  = NULL;
            double coord_double = 0;
            sscanf(current_line, "%lf%lf%lf", &x, &y, &z);

            data->vertex_array.coords_array[i] = x;
            data->vertex_array.coords_array[i + 1] = y;
            data->vertex_array.coords_array[i + 2] = z;
            i += 3;    
        }

        if (line[0] == 'f' && line[1] == ' ') {
            
            int   line_length = strlen(line);
            char* line_copy   = malloc(line_length * sizeof(int));

            memcpy(line_copy, line, line_length);
            // sprintf(line_copy, "%s", line);

            // printf("%s", line_copy);
            

            // 2 функции:
            //   1. для подсчета кол-ва вершин, которые необходимо соединить
            // get_number_of_polygon_indices(line_copy, data, f_line_counter);
            // free(line_copy);
            
            //   - потом выделяем память
            // data->polygons_array[f_line_counter].polygon_indices = malloc(data->polygons_array[f_line_counter].indices_number * sizeof(int));

            //   2. запись вершин в массив для которого мы только что выделили память
            // error = get_array_of_polygon_indices(line, data, f_line_counter);

            // f_line_counter++;


            error = write_index_array_in_data(line, line_copy, data);

            





        }
    }



    // for (int i = 0; i < data->polygons_number; i++) {
    //     printf("polygon_#_%d: indices: %d \n", i, data->polygons_array[i].indices_number);
    //     for (int j = 0; j < data->polygons_array[i].indices_number; j++) {
    //         printf("%d ", data->polygons_array[i].polygon_indices[j]);
    //     }
    //     printf("\n");
    // }

    if (line != NULL) {
        free(line);
    }

    return error;
}


// void get_number_of_polygon_indices(char* line, ObjData_t* data, int f_line_counter) {
//     int number_of_polygon_indices = 0;
//     char* tokenPtr;

//     strtok(line, " ");
//         while ((tokenPtr = strtok(NULL, "/")) != NULL) {
//             strtok(NULL, " ");
//             number_of_polygon_indices++;
//         }
//     data->polygons_array[f_line_counter].indices_number = number_of_polygon_indices;
// }

// int get_array_of_polygon_indices(char* line, ObjData_t* data, int j) {
//     char *token_ptr;
//     int i = 0;
//     int value = 0;

//     strtok(line, " ");
//         while ((token_ptr = strtok(NULL, "/")) != NULL) {
//             value = atoi(token_ptr);
//             data->polygons_array[j].polygon_indices[i] = value;
//             i++;
//             strtok(NULL, " ");
//         }
// }

int write_index_array_in_data(char* line, char* line_copy, ObjData_t* data) {
    // printf("%s", line);

    // data->index_array_counter = 0;

    char* token_ptr;
    int counter = 0;
    int value = 0;

        strtok(line_copy, " ");
        while ((token_ptr = strtok(NULL, "/")) != NULL) {
            strtok(NULL, " ");
            counter++;
        }

        strtok(line, " ");


        while ((token_ptr = strtok(NULL, "/")) != NULL) {


            strtok(NULL, " ");
            value = atoi(token_ptr);



            if (data->index_array_counter = 0) {
            data->index_array[data->index_array_counter] = value - 1;
            data->index_array_counter++;




        }


    // printf("%d ", counter);

}