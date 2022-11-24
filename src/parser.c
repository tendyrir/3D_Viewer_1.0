#include "viewer.h"

int parse_file(ObjData_t* data, char* obj_file_name) {
    FILE* fp;
    int error = 0;
/*  Открытие фай0ла                                       */
    fp    = fopen(obj_file_name, "r");
/*  Подсчет размеров массивов координат и индексов вершин */
    error = get_data_numbers(fp, data);
/*  Выделение память под массивы                          */
    error = allocate_memory(data);
/*  Заполнение массивов                                   */
    error = get_data_arrays(fp, data);
    fclose(fp);
    return error;
}





























int get_data_numbers(FILE* fp, ObjData_t* data) {

    int     error            = 0;
    int     vertex_counter   = 0;
    int     total_indices    = 0;
    char*   line             = NULL;
    size_t  len              = 0;
    ssize_t read             = 0;
    char*   token_ptr        = NULL;
    int i = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
        
        if (line[0] == 'v' && line[1] == ' ') {
            vertex_counter++;
        }
        
        if (line[0] == 'f' && line[1] == ' ') {
            strtok(line, " ");
            if (strchr(line, '/')) {
                while ((token_ptr = strtok(NULL, "/")) != NULL) {
                    total_indices++;
                    i++;
                    strtok(NULL, " ");
                    // printf("%d - %s ",  total_indices, token_ptr);
                }
            } else {
                while ((token_ptr = strtok(NULL, " ")) != NULL) {
                    total_indices++;
                    i++;
                    // printf("%d -%s\n",  total_indices, token_ptr);
                }
            }
        }
    }

    // printf("\n");

    if (line != NULL) {
        free(line);
    }

    data->vertex_array.coords_number = vertex_counter * 3;
    data->index_array_size           = total_indices * 2;

    printf("data->vertex_array.coords_number : %d <- под координаты\n", data->vertex_array.coords_number);
    printf("data->index_array_size           : %d <- под индексы\n", data->index_array_size);
    printf("\n");

    rewind(fp);
    
    return error;
}











































int get_data_arrays(FILE* fp, ObjData_t* data) {
    int error = 0;

    char*   line = NULL;
    size_t  len = 0;
    ssize_t read = 0;

    int i = 0;

    double x = 0, y = 0, z = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] == 'v' && line[1] == ' ') {
            char*  current_line = line + 2;
            printf("%s", current_line);
            sscanf(current_line, "%lf%lf%lf", &x, &y, &z);
            data->vertex_array.coords_array[i] = x;
            data->vertex_array.coords_array[i + 1] = y;
            data->vertex_array.coords_array[i + 2] = z;
            i += 3;    
        }

        if (line[0] == 'f' && line[1] == ' ') {
            
            int   line_length = strlen(line);
            char* line_copy   = calloc(line_length, sizeof(int));


            if (strchr(line, '\n')) {
                memcpy(line_copy, line, line_length - 1);
            } else {
                memcpy(line_copy, line, line_length);
            }

            write_index_array_in_data(line, line_copy, data);

            free(line_copy);
        }
    }

    if (line != NULL) {
        free(line);
    }

    return error;
}






















































int write_index_array_in_data(char* line, char* line_copy, ObjData_t* data) {

    char* token_ptr;
    int error = 0;
    int current_line_index_counter = 0;

    int i = 0;
    int value = 0;
    int first_value = 0;

    current_line_index_counter = count_cur_line(line_copy);

    strtok(line, " ");
    if (strchr(line, '/')) {
        while ((token_ptr = strtok(NULL, "/")) != NULL) {    // этот вайл крутится столько раз сколько индексов
            strtok(NULL, " ");

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
        
    } else {
        while ((token_ptr = strtok(NULL, " ")) != NULL) {    // этот вайл крутится столько раз сколько индексов

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
    }

    printf("счетчик: %d", data->index_array_counter);
    printf("\n");

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











































int allocate_memory_for_vertex_array(ObjData_t* data) {

    data->vertex_array.coords_array = calloc(data->vertex_array.coords_number, sizeof(double));

    return 0;
}

int allocate_memory_for_index_array(ObjData_t* data) {

    data->index_array = calloc(data->index_array_size, sizeof(int));

    return 0;
}

int allocate_memory(ObjData_t* data) {

    allocate_memory_for_vertex_array(data);

    allocate_memory_for_index_array(data);

    return 0;
}













































void print_vertex_array(ObjData_t* data) {
    
    // for (int j = 0; j < data->vertex_array.coords_number; j++) {
    //         printf("%lf ", data->vertex_array.coords_array[j]);
    // }

    int j = 0;
    while (j < data->vertex_array.coords_number) {
        printf("%10lf ", data->vertex_array.coords_array[j]);
        printf("%10lf ", data->vertex_array.coords_array[j + 1]);
        printf("%10lf ", data->vertex_array.coords_array[j + 2]);
        printf("\n");
        j += 3;
    }

    printf("\n");

    for (int j = 0; j < data->index_array_counter; j++) {
            printf("%d ", data->index_array[j]);
    }
    printf("\n счетчик в конце равен: %d \n", data->index_array_counter);
}
