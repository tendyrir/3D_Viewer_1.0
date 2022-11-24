#include "viewer.h"

int main (void) {

    FILE*     file_pointer  = NULL;
    ObjData_t data = {0};
    // char*     obj_file_name = "models/cube.obj";         // 8 v 24 crd 12 f 72 ind
    char*     obj_file_name = "models/dodecahedron.obj";    // 20 v 60 crd 36 f 108 ind

    parse_file(file_pointer, &data, obj_file_name);

    printf("\n");
    print_vertex_array(&data);
    
    return 0;
}


