#include "viewer.h"

int main (void) {

    ObjData_t data = {0};

    char*     obj_file_name = "models/dodecahedron.obj";
    // char*     obj_file_name = "models/icosahedron.obj";
    // char*     obj_file_name = "models/pyramid_2.obj";
    // char*     obj_file_name = "models/gun.obj";

    parse_file(&data, obj_file_name);
    
    printf("\n");
    print_vertex_array(&data);

    free(data.vertex_array.coords_array);
    free(data.index_array);

    return 0;
}


