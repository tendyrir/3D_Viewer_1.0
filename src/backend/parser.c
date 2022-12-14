#include "viewer.h"


int run_test(char* filename) {
    ObjData_t data = {0};
    if (check_file_exist(filename) == 1) {
        fprintf(stderr, "INVALID FILE NAME\n");
        return 1;
    } else {
        parse_file(&data, filename);
        free(data.vertex_array.coords_array);
        free(data.index_array);
    }
    return 0;
}


int parse_file(ObjData_t* data, char* obj_file_name) {
    FILE* fp;
    int error = 0;
    fp    = fopen(obj_file_name, "r");     /*  Открытие фай0ла */
    error = get_data_numbers(fp, data);    /*  Подсчет размеров массивов координат и индексов вершин */ 
    error = allocate_memory(data);         /*  Выделение память под массивы */
    error = get_data_arrays(fp, data);     /*  Заполнение массивов */
    center_model(data, 0.8);
    fclose(fp);
    return error;
}

int get_data_numbers(FILE* fp, ObjData_t* data) {
    data->index_array_size =  0;
    data->vertex_array.coords_number = 0;
    int     error            = 0;
    int     vertex_counter   = 0;
    int     total_indices    = 0;
    char*   line             = NULL;
    size_t  len              = 0;
    ssize_t read             = 0;
    /* считываем построчно открытый файл */
    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] == 'v' && line[1] == ' ') {
            vertex_counter++;
        }
        if (line[0] == 'f' && line[1] == ' ') {
            total_indices += count_cur_line(line);
        }
    }
    if (line != NULL) {
        free(line);
    }
    /* размер массива координат: количество v строк * 3 оси (x, y, z) */
    data->vertex_array.coords_number = vertex_counter * 3;
    /* размер массива индексов: количество индексов во всех f строках * 2 (для glDrawElemets) */
    data->index_array_size           = total_indices * 2;
    rewind(fp); /* <----------  перестановка указателя в начало файла */
    return error;
}

int allocate_memory(ObjData_t* data) {
    data->vertex_array.coords_array = calloc((size_t) data->vertex_array.coords_number, sizeof(double));
    data->index_array               = calloc((size_t) data->index_array_size, sizeof(int));
    if (!data->vertex_array.coords_array || !data->index_array) {
        printf("mem failure, exiting \n");
        exit(EXIT_FAILURE);
    }
    return 0;
}

int get_data_arrays(FILE* fp, ObjData_t* data) {
    int error = 0;
    char*   line = NULL;
    size_t  len = 0;
    ssize_t read = 0;
    int i = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] == 'v' && line[1] == ' ') {
            write_vertex_array_in_data(line, i, data);
            i += 3;    
        }
        if (line[0] == 'f' && line[1] == ' ') {
            char* line_copy = copy_current_line(line);
            write_index_array_in_data(line, line_copy, data);
            free(line_copy);
        }
    }
    if (line != NULL) {
        free(line);
    }
    return error;
}

int write_vertex_array_in_data(char* line, int i, ObjData_t* data) {
    double x = 0, y = 0, z = 0;
    char*  current_line = line + 2;
    sscanf(current_line, "%lf%lf%lf", &x, &y, &z);
    data->vertex_array.coords_array[i] = x;
    data->vertex_array.coords_array[i + 1] = y;
    data->vertex_array.coords_array[i + 2] = z;
    return 0;
}

char* copy_current_line(char* line) {
    size_t line_length = strlen(line);
    char* line_copy    = calloc(line_length, sizeof(int));

    if (!line_copy) {
        printf("mem failure, exiting \n");
        exit(EXIT_FAILURE);
    }

    if (strchr(line, '\n')) {
        memcpy(line_copy, line, line_length - 1);
    } else {
        memcpy(line_copy, line, line_length);
    }

    return line_copy;
}

int write_index_array_in_data(char* line, char* line_copy, ObjData_t* data) {
    int error = 0;
    char* token_ptr;
    int i = 0;
    int value = 0;
    int first_value = 0;
    int current_line_index_counter = count_cur_line(line_copy);
    strtok(line, " ");
    int flag = 0;
    char* part = " ";
    if (strchr(line, '/')) {
          flag = 1;
          part = "/";
    }
    while ((token_ptr = strtok(NULL, part)) != NULL) {
        if (flag) {
             strtok(NULL, " ");
        }
        value = atoi(token_ptr) - 1; // - перевод из текущего токена в число
        if (i == 0) {
            first_value = value;     // - сохраняем первое значение в отдельную переменную
            write_value(data, first_value);
        }
        if (i > 0 && i < current_line_index_counter) {  
            write_value(data, value);
            write_value(data, value);
        }
        i++;
        if (i == current_line_index_counter) {
            write_value(data, first_value);
        }   
    }
    // printf("счетчик: %d", data->index_array_counter);
    // printf("\n");
    return error;
}

int write_value(ObjData_t* data, int value) {
    data->index_array[data->index_array_counter] = value;
    // printf("очередной_1 индекс: %d\n", data->index_array[data->index_array_counter]);
    data->index_array_counter++;                    
    // data->index_array[data->index_array_counter] = value;
    // // printf("очередной_2 индекс: %d\n", data->index_array[data->index_array_counter]);
    // data->index_array_counter++;    
    return 0;       
}

int count_cur_line(char* line_copy) {
    char* token_ptr;
    int current_line_index_counter_1 = 0;
    strtok(line_copy, " ");
    if (strchr(line_copy, '/')) {
        while ((token_ptr = strtok(NULL, "/")) != NULL) {
            current_line_index_counter_1++;
            strtok(NULL, " ");
        }
    } else {
        while ((token_ptr = strtok(NULL, " ")) != NULL) {
            current_line_index_counter_1++;
        }
    }
    return current_line_index_counter_1;
}



void print_vertex_array(ObjData_t* data) {
    printf("data->vertex_array.coords_number : %d <- под координаты\n", data->vertex_array.coords_number);
    printf("data->index_array_size           : %d <- под индексы\n", data->index_array_size);
    printf("\n");
    int j = 0;
    while (j < data->vertex_array.coords_number) {
        printf("%10lf ", data->vertex_array.coords_array[j]);
        printf("%10lf ", data->vertex_array.coords_array[j + 1]);
        printf("%10lf ", data->vertex_array.coords_array[j + 2]);
        printf("\n");
        j += 3;
    }
    printf("\n");
    for (int i = 0; i < data->index_array_counter; i++) {
            // printf("%d ", data->index_array[i]);
    }
    printf("\n счетчик в конце равен: %d \n", data->index_array_counter);
}






void center_model(ObjData_t *data, double value) {
    
    move_model_to_center(data);

    double scale_value = resize_model_on_screen(data, value);

    matrix_t coords;
    s21_create_matrix(data->vertex_array.coords_number / 3, 3, &coords);

    conv_to_matr(data, &coords);

    model_scale(&coords, scale_value);

    conv_from_matr(data, &coords);

    s21_remove_matrix(&coords);
  
}


double resize_model_on_screen(ObjData_t* data, double value) {
    /* 1. Подогнать размер под экран */

    double max_x = find_max_coord(data, 0); // x
    double max_y = find_max_coord(data, 1); // y
    double max_z = find_max_coord(data, 2); // z

    double min_x = find_min_coord(data, 0); // x
    double min_y = find_min_coord(data, 1); // y
    double min_z = find_min_coord(data, 2); // z


    double diff_x = max_x - min_x;
    double diff_y = max_y - min_y;
    double diff_z = max_z - min_z;

    double diff_max    = maximum_difference(diff_x, diff_y, diff_z);
    double scale_value = (value - (value * (-1))) / diff_max;

    return scale_value;
}

double maximum_difference(double diff_x, double diff_y, double diff_z) {
    double max;
    if (diff_x > diff_y) max = diff_x;
    else max = diff_y;
    if (diff_z > max) max = diff_z;
    return max;
}


void move_model_to_center(ObjData_t *data) {
    /* 2. Поставить модельку в центр */

    double max_x = find_max_coord(data, 0); // x
    double max_y = find_max_coord(data, 1); // y
    double max_z = find_max_coord(data, 2); // z

    double min_x = find_min_coord(data, 0); // x
    double min_y = find_min_coord(data, 1); // y
    double min_z = find_min_coord(data, 2); // z

    printf("max x = %lf min x = %lf max y = %lf min y = %lf max z = %lf min z = %lf\n", max_x, min_x, max_y, min_y, max_z, min_z);

    double diff_x = (min_x + (max_x - min_x) / 2);
    double diff_y = (min_y + (max_y - min_y) / 2);
    double diff_z = (min_z + (max_z - min_z) / 2);

    int j = 0;

    while(j < data->vertex_array.coords_number) {

        data->vertex_array.coords_array[j] -= diff_x;
        j++;
        data->vertex_array.coords_array[j] -= diff_y;
        j++;
        data->vertex_array.coords_array[j] -= diff_z;
        j++;
    }

}


double find_max_coord(ObjData_t *data, int axis) {
    
    double max_coord     = data->vertex_array.coords_array[axis];
    int    coord_counter = axis;

    while (coord_counter < data->vertex_array.coords_number) {

        // printf("найдена координата больше 1 %d\n", more_than_one);
        // printf("максимальная координата: %d\n", max_coord);

        if (data->vertex_array.coords_array[coord_counter] > max_coord) {
            max_coord = data->vertex_array.coords_array[coord_counter];
        }

        coord_counter += 3;
    }

    return max_coord;
}

double find_min_coord(ObjData_t *data, int axis) {
    
    double min_coord     = data->vertex_array.coords_array[axis];
    int    coord_counter = axis;

    while (coord_counter < data->vertex_array.coords_number) {

        // printf("найдена координата больше 1 %d\n", more_than_one);
        // printf("максимальная координата: %d\n", max_coord);

        if (data->vertex_array.coords_array[coord_counter] < min_coord) {
            min_coord = data->vertex_array.coords_array[coord_counter];
        }

        coord_counter += 3;
    }

    return min_coord;
}

    // printf("max_coord: %d", max_coord);


    // double max_x = data->vertex_array.coords_array[0];
    // double min_x = data->vertex_array.coords_array[0];

    // double max_y = data->vertex_array.coords_array[1];
    // double min_y = data->vertex_array.coords_array[1];

    // double max_z = data->vertex_array.coords_array[2];
    // double min_z = data->vertex_array.coords_array[2];

    // int i = 0;

    // while (i < data->vertex_array.coords_number) {

    //     if (data->vertex_array.coords_array[i] > max_x) {
    //         max_x = data->vertex_array.coords_array[i];
    //     }

    //     if (data->vertex_array.coords_array[i] < min_x) {
    //         min_x = data->vertex_array.coords_array[i];
    //     }
    //     i++;

    //     if (data->vertex_array.coords_array[i] > max_y) {
    //         max_y = data->vertex_array.coords_array[i];
    //     }
    //     if (data->vertex_array.coords_array[i] < min_y) {
    //         min_y = data->vertex_array.coords_array[i];
    //     }
    //     i++;

    //     if (data->vertex_array.coords_array[i] > max_z) {
    //         max_z = data->vertex_array.coords_array[i];
    //     }
    //     if (data->vertex_array.coords_array[i] < min_z) {
    //         min_z = data->vertex_array.coords_array[i];
    //     }
    //     i++;
        

    // }





// int check_coords_more_one(ObjData_t *data) {
//     int check_if_coords_have_more_one = 0;
//     for (int i = 0; i < data->vertex_array.coords_number; i++) {
//         if (data->vertex_array.coords_array[i] > 1.0) {
//             check_if_coords_have_more_one = 1;
//         }
//     }
//     return check_if_coords_have_more_one;
// } 


int check_file_exist(char* filename) {
    if (access(filename, F_OK) != 0) {
        return 1;
    }
    return 0;
}