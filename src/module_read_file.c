#include "viewer.h"

int main(void) {
  /*    FILE* fopen(const char* filename, const char* mode);
   *    “r” – Searches file. If the file is opened successfully fopen( ) loads
   * it into memory and sets up a pointer which points to the first character in
   *    it. If the file cannot be opened fopen( ) returns NULL.
   * */

  FILE* file_pointer;
  file_pointer = fopen("models/cube.obj", "r");  // - to open a file

  if (!file_pointer) {
    printf("Error_1: File failed to open\n");
  } else {
    printf("File successfully open\n");

    char line[100];
    int vertice_counter;
    int facets_counter;

    while (fgets(line, 100, file_pointer) != NULL) {
      // TODO: count lines for vertexes and faces in file
      printf("%s\n", line);
    }

    printf("\n");
  }
  fclose(file_pointer);  // - to close a file

  printf("Data successfully read from file\n");
  printf("The file is now closed.");
}
