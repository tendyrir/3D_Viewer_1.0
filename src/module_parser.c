#include "viewer.h"

/**
 * @brief Подсчет количества вершин и полигонов и запись в значений в структуру
 * data
 *
 * @param file_pointer - указатель на открытый файл
 * @param obj - указатель на структуру со счетчиками
 * @return int - код ошибки
 */
int count_vertexes_and_polygons_number(FILE* file_pointer, data* obj) {
  char line[64];
  int error = 0;

  while (fgets(line, sizeof(line), file_pointer) != NULL) {
    if (strstr(line, "v ") != NULL) {
      obj->total_vertexes++;
    } else if (strstr(line, "f ") != NULL) {
      obj->total_polygons++;
    } else {
      error = 1;
    }
  }
  return error;
}

/**
 * @brief
 *
 * @param file_pointer
 * @return int
 */
int parse_polygons(FILE* file_pointer, data* obj) {
  char line[100];

  while (fgets(line, sizeof(line), file_pointer) != NULL) {
    if (strstr(line, "f ")) {
      // отделить часть строки до первого пробела
      strtok(line, " ");
      // нужно сохранить строку

      char* vertexes_line = malloc(sizeof(char));
      char* token_pointer = NULL;

      while ((token_pointer = strtok(NULL, "/")) != NULL) {
        vertexes_line = strcat(vertexes_line, token_pointer);
        strtok(NULL, " ");
        // printf("%s", token_pointer);
      }
      printf("%s", vertexes_line);

      int digit_counter = 0;

      for (int i = 0; i < strlen(vertexes_line); i++) {
        if (isdigit(vertexes_line[i])) {
          digit_counter++;
        }
      }

      printf("   --> в этой строке %d числа", digit_counter);
      printf("\n");

      int* array[digit_counter];

      digit_counter = 0;
    }
  }
  return 0;
}

int vertexes_from_file_to_matrix_in_data(FILE* file_pointer, data* obj) {
  return 0;
}