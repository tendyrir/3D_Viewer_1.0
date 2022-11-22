#include "opengl.h"

openGL::openGL(QWidget *parent) : QOpenGLWidget(parent) {
    setGeometry(400, 200, 800, 600);
//    window = new MainWindow;
    FILE*     file_pointer  = NULL;
//    std::string file = MainWindow::filename;
//    QString file =  window->on_choose_OBJFile_clicked();
//    //  QString file =  "/Users/sandslas/Documents/3D_Viewer_1.0/src/project/models/_octahedron.obj";
//    QByteArray file_bit = file.toLocal8Bit();
//    char*     obj_file_name = file_bit.data();
//    parse_file(file_pointer, &data_obj, obj_file_name);


}

void openGL::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);  // черный цвет
    glEnable(GL_DEPTH_TEST);  // включение буффера глубины
}
void openGL::resizeGL(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //    glOrtho(-1,1,-1,1,1,2);
    glFrustum(-1, 1, -1, 1, 1, 3);
}

void openGL::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0, 0, -2);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);
    drawCube(&data_obj);
}

void openGL::drawCube(ObjData_t* data_obj) {
    glVertexPointer(3, GL_DOUBLE, 0, data_obj->vertex_array.coords_array);
    glEnableClientState(GL_VERTEX_ARRAY); // включить состояние OpenGL
//    glDrawArrays(GL_QUADS, 0, 24);
    glDrawElements(GL_LINES, data_obj->index_array_size, GL_UNSIGNED_INT, data_obj->index_array);
    glDisableClientState(GL_VERTEX_ARRAY); //выключить состояние OpenGL
}

void openGL::mousePressEvent(QMouseEvent *mo) {
    mPos = mo->pos();
}

void openGL::mouseMoveEvent(QMouseEvent *mo) {
    xRot = 1 / M_PI * (mo->pos().y() - mPos.y());
    yRot = 1 / M_PI * (mo->pos().x() - mPos.x());
    update();
}


