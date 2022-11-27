#include "opengl.h"

openGL::openGL(QWidget *parent) : QOpenGLWidget(parent) {
    setGeometry(400, 200, 800, 600);
}

void openGL::initializeGL() {
    initializeOpenGLFunctions(); // for ubuntu
//    glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // черный цвет
    glEnable(GL_DEPTH_TEST);  // включение буффера глубины для Z
//    glOrtho(minX, maxX, minY, maxY, -100000, 10000);

}
void openGL::resizeGL(int width, int height) {
    glViewport(0, 0, width, height);
}

void openGL::paintGL() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-1,1,-1,1,1,3);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0, 0, -2.1);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);
    drawCube(&data_obj);
}

void openGL::drawCube(ObjData_t* data_obj) {
    glVertexPointer(3, GL_DOUBLE, 0, data_obj->vertex_array.coords_array);
    glEnableClientState(GL_VERTEX_ARRAY); // включить состояние OpenGL
    glEnable(GL_POINT_SMOOTH);
    glPointSize(2);
    glDisable(GL_POINT_SMOOTH);
    glDrawElements(GL_LINES, data_obj->index_array_size, GL_UNSIGNED_INT, data_obj->index_array);
    glDrawArrays(GL_POINTS, 0, data_obj->vertex_array.coords_number / 3);
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