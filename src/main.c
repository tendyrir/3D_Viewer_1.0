#include "viewer.h"

int main (void) {

    FILE*     file_pointer  = NULL;
    ObjData_t data = {0};
    // char*     obj_file_name = "models/dodecahedron.obj";    // 20 v 60 crd 36 f 108 ind
    // char*     obj_file_name = "models/icosahedron.obj";    //
    char*     obj_file_name = "models/pyramid_2.obj";    


    parse_file(file_pointer, &data, obj_file_name);

    printf("\n");
    print_vertex_array(&data);


    // char* file_full_path = "models/cube.obj";         // 8 v 24 crd 12 f 72 ind

    // parse_file(&data, file_full_path);





    
    return 0;
}


