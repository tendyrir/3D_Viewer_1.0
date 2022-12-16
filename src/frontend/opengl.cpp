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
    glClearColor(color_back->red()/255.f, color_back->green()/255.f, color_back->blue()/255.f, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   if (data_obj_openGL != NULL) {
       double* vertices = this->data_obj_openGL->vertex_array.coords_array;
       int*    indices  = this->data_obj_openGL->index_array;
       draw(vertices, indices);
   }
}

void openGL::draw(double* vertices, int* indices) {
  glColor3f(color_vertex->red()/255.f, color_vertex->green()/255.f, color_vertex->blue()/255.f);
  glPointSize(point_size);

  glEnableClientState(GL_VERTEX_ARRAY);

  glVertexPointer(3, GL_DOUBLE, 0, vertices);

    glEnable(GL_POINT_SMOOTH);
        glDrawArrays(GL_POINTS, 0, this->data_obj_openGL->vertex_array.coords_number / 3);
    glDisable(GL_POINT_SMOOTH);

  glColor3f(color_edge->red()/255.f, color_edge->green()/255.f, color_edge->blue()/255.f);
  glLineWidth(line_size);

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

