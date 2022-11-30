#include "opengl.h"

openGL::openGL(QWidget *parent) : QOpenGLWidget(parent) {
//    setDefault();
}

//void openGL::setDefault() {
//    // Проекция: 0 - центральная, 1 - параллельная
//    projectionMode = 0;
//    // Цвет фона
//    backgroundColor.setRgb(0, 0, 0);
//    // Цвет линии
//    edgesColor.setRgb(0, 127, 51);
//    // Толщина линии
//    edgesSize = 1;
//    // Тип линии: 0 - сплошная, 1 - пунктирная
//    edgesMode = 0;
//    // Цвет точки
//    verticiesColor.setRgb(0, 214, 120);
//    // Размер точки
//    verticiesSize = 1;
//    // Тип точки: 0 - нет точек, 1 - круг, 2 - квадрат
//    verticiesMode = 0;
//}

void openGL::initializeGL() {
   initializeOpenGLFunctions(); // for ubuntu
   glEnable(GL_DEPTH_TEST);
// glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // черный цвет
// glOrtho(minX, maxX, minY, maxY, -100000, 10000);
//   rotateMatrix.setToIdentity();
//   moveMatrix.setToIdentity();
//   scaleMatrix.setToIdentity();
}

void openGL::resizeGL(int width, int height) {
    glViewport(0, 0, width, height);

}

void openGL::paintGL() {

//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    gluPerspective (130, 1, 50, 0);
//    glFrustum(-1,1,-1,1,0.1,3);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glMatrixMode(GL_MODELVIEW);
//    glLoadIdentity();
//    glTranslatef(0, 0, -2.1);
//    glRotatef(xRot, 1, 0, 0);
//    glRotatef(yRot, 0, 1, 0);

    draw(&data_obj);
}

void openGL::draw(ObjData_t* data_obj) {

    /*the vertex; array is enabled for writing and used during rendering when glDrawArrays, or glDrawElements is called*/
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_DOUBLE, 0, data_obj->vertex_array.coords_array);
    glDrawElements(GL_LINES, data_obj->index_array_size, GL_UNSIGNED_INT, data_obj->index_array);
    glDisableClientState(GL_VERTEX_ARRAY);

}

void openGL::mousePressEvent(QMouseEvent *mo) {
    mPos = mo->pos();
}

void openGL::mouseMoveEvent(QMouseEvent *mo) {
    xRot = 1 / M_PI * (mo->pos().y() - mPos.y());
    yRot = 1 / M_PI * (mo->pos().x() - mPos.x());
    update();
}

//void openGL::setupProjection(int w, int h) {
//  if (w < 1 || h < 1) {
//    w = width();
//    h = height();
//  }
//}

void openGL::setScale(int value) {
  if (value != scaleVal) {
    scaleVal = value;
    update();
  }
}
