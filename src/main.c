#include "viewer.h"

int main (void) {

    FILE* file_pointer = NULL;

    VertexArray_t vertex_array = {0};
    IndexArray_t index_array   = {0};

    char* obj_file_name = "models/cube.obj";

    lines_parser(file_pointer, &vertex_array, &index_array, obj_file_name);
    
    print_vertex_array(&vertex_array);

    return 0;
}


