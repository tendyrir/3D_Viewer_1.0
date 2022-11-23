#include "viewer.h"

int parse_file(ObjData_t* data, char* obj_file_name) {

    int error = 0;

/*  . Первое открытие файла - узнаем количества координат всего, количество полигонов */
    FILE* fp    = fopen(obj_file_name, "r");
    error = get_data_numbers(fp, data);
    fclose(fp);

/*  . Выделить память под массивы */
    data->vertex_array.coords_array = malloc(data->vertex_array.coords_number * sizeof(double));
    data->index_array               = malloc(data->index_array_size * sizeof(int));

/*  . Второе открытие файла - заполнение массивов */
    fp    = fopen(obj_file_name, "r");
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
    char *token_ptr = NULL;

    while ((read = getline(&line, &len, fp)) != -1) {
        
        if (line[0] == 'v' && line[1] == ' ') {
            vertex_counter++;
        }
        if (line[0] == 'f' && line[1] == ' ') {
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
    data->index_array_size           = total_indices * 2;

    printf("data->vertex_array.coords_number : %d <- под 1 массив Сержуне\n", data->vertex_array.coords_number);
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

    double x = 0, y = 0, z = 0;

    while ((read = getline(&line, &len, fp)) != -1) {
        if (line[0] == 'v' && line[1] == ' ') {
            char*  current_line = line + 3;
            sscanf(current_line, "%lf%lf%lf", &x, &y, &z);
            data->vertex_array.coords_array[i] = x;
            data->vertex_array.coords_array[i + 1] = y;
            data->vertex_array.coords_array[i + 2] = z;
            i += 3;    
        }

        if (line[0] == 'f' && line[1] == ' ') {
            
            int   line_length = strlen(line);
            char* line_copy   = malloc(line_length * sizeof(int));

            memcpy(line_copy, line, line_length - 1);

            error = write_index_array_in_data(line, line_copy, data);
        }
    }

    if (line != NULL) {
        free(line);
    }

    return error;
}


int write_index_array_in_data(char* line, char* line_copy, ObjData_t* data) {
    // printf("%s", line);

    char* token_ptr;
    int error = 0;
    int current_line_index_counter_1 = 0;
    int value = 0;

        strtok(line_copy, " ");
        while ((token_ptr = strtok(NULL, "/")) != NULL) {
            strtok(NULL, " ");
            // printf("|%s |", token_ptr);
            current_line_index_counter_1++;  // - считаем количество индексов в текущей строчке
        }
        // printf("            индексов: %d\n", current_line_index_counter_1);

        int i = 0;
        int spe_val = 0;

        strtok(line, " ");
        while ((token_ptr = strtok(NULL, "/")) != NULL) {    // этот вайл крутится столько раз сколько индексов
            
            strtok(NULL, " ");
            value = atoi(token_ptr) - 1; // - перевод из текущего токена в число

            if (i == 0) {
                spe_val = value;     // - сохраняем первое значение в отдельную переменную
                data->index_array[data->index_array_counter] = spe_val;
                // printf("     первый индекс: %d\n", data->index_array[data->index_array_counter]);
                data->index_array_counter++;
            }
            if (i > 0 && i < current_line_index_counter_1) {
                data->index_array[data->index_array_counter] = value;
                // printf("очередной_1 индекс: %d\n", data->index_array[data->index_array_counter]);
                data->index_array_counter++;                    
                data->index_array[data->index_array_counter] = value;
                // printf("очередной_2 индекс: %d\n", data->index_array[data->index_array_counter]);
                data->index_array_counter++;                    
            }

            i++;

            if (i == current_line_index_counter_1) {
                data->index_array[data->index_array_counter] = spe_val;
                // printf("     первый индекс: %d\n", data->index_array[data->index_array_counter]);
                data->index_array_counter++;
            }
        }   
        // printf("             счетчик: %d", data->index_array_counter);
        // printf("\n");
    return error;
}


void print_vertex_array(ObjData_t* data) {
    
    for (int j = 0; j < data->vertex_array.coords_number; j++) {
            printf("%lf ", data->vertex_array.coords_array[j]);
    }
        printf("\n");
    for (int j = 0; j < data->index_array_counter; j++) {
            printf("%d ", data->index_array[j]);
    }
    printf("\n счетчик в конце равен: %d \n", data->index_array_counter);
}

