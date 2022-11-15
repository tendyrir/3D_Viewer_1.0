#include "viewer.h"

int main (void) {

    FILE*     file_pointer  = NULL;
    ObjData_t data;
    char*     obj_file_name = "models/cube.obj";

    parse_file(file_pointer, &data, obj_file_name);
    print_vertex_array(data);
    
    return 0;
}


