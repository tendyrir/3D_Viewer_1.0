#include "opengl.h"

openGL::openGL(QWidget *parent) : QOpenGLWidget(parent) {
}

void openGL::initializeGL() {
  initializeOpenGLFunctions();  // for ubuntu
  glEnable(GL_DEPTH_TEST);
}

void openGL::resizeGL(int width, int height) {
  glViewport(0, 0, width, height);
}

void openGL::paintGL() {
   if (data_obj_openGL != NULL) {
       double* vertices = this->data_obj_openGL->vertex_array.coords_array;
       int*    indices  = this->data_obj_openGL->index_array;
       draw(vertices, indices);
   }
}

void openGL::draw(double* vertices, int* indices) {
  /*the vertex; array is enabled for writing and used during rendering when
   * glDrawArrays, or glDrawElements is called*/
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_DOUBLE, 0, vertices);


  glDrawElements(GL_LINES, this->data_obj_openGL->index_array_size, GL_UNSIGNED_INT, indices);
  glDisableClientState(GL_VERTEX_ARRAY);
}

void openGL::mousePressEvent(QMouseEvent *mo) { mPos = mo->pos(); }

void openGL::mouseMoveEvent(QMouseEvent *mo) {
  xRot = 1 / M_PI * (mo->pos().y() - mPos.y());
  yRot = 1 / M_PI * (mo->pos().x() - mPos.x());
  update();
}

void openGL::getModelData(ObjData_t* model) {
  if (model)
    this->data_obj_openGL = model;
  else
    this->data_obj_openGL = NULL;
}

