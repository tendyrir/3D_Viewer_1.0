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