#include "opengl.h"

openGL::openGL(QWidget *parent) : QOpenGLWidget(parent) {
}

void openGL::initializeGL() {
  initializeOpenGLFunctions();  // for ubuntu
  glEnable(GL_DEPTH_TEST); //включаем буфер глубины для отображения Z-координаты
}

void openGL::resizeGL(int width, int height) {
  glViewport(0, 0, width, height);
}

void openGL::paintGL() {
    glClearColor(color_back->red()/255.f, color_back->green()/255.f, color_back->blue()/255.f, 1); // цвет фона
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // очищение буффера
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (!central_perspective) {
        glOrtho(-1, 1,-1, 1,  -2, 100);
    } else {
        glFrustum(-0.1, 0.1, -0.1, 0.1, 0.8, 100);
        glTranslatef(0, 0, -7);
    }
    glMatrixMode(GL_MODELVIEW);
   if (data_obj_openGL != NULL) {
       double* vertices = this->data_obj_openGL->vertex_array.coords_array;
       int*    indices  = this->data_obj_openGL->index_array;
       draw(vertices, indices);
   }
}

void openGL::draw(double* vertices, int* indices) {
    glEnableClientState(GL_VERTEX_ARRAY);
    drawVerticies(vertices);
    drawEdges(indices);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void openGL::drawEdges(int* indices) {
    glColor3f(color_edge->red()/255.f, color_edge->green()/255.f, color_edge->blue()/255.f);
    glLineWidth(line_size);
    if(edge_mood) {
        glEnable(GL_LINE_STIPPLE);
        glLineStipple(1, 0xFF);
    } else {
        glDisable(GL_LINE_STIPPLE);
    }
    glDrawElements(GL_LINES, this->data_obj_openGL->index_array_size, GL_UNSIGNED_INT, indices);
    glDisableClientState(GL_VERTEX_ARRAY);
}

void openGL::drawVerticies(double* vertices) {
    glColor3f(color_vertex->red()/255.f, color_vertex->green()/255.f, color_vertex->blue()/255.f);
    glPointSize(point_size);
    glVertexPointer(3, GL_DOUBLE, 0, vertices);
    if(vertex_mood) {
        if(vertex_mood == 1) {
            glEnable(GL_POINT_SMOOTH);
        } else if (vertex_mood == 2) {
            glDisable(GL_POINT_SMOOTH);
        }
        glDrawArrays(GL_POINTS, 0, this->data_obj_openGL->vertex_array.coords_number / 3);
    }
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

