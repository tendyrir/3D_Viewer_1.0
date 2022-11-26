#include "opengl.h"

openGL::openGL(QWidget *parent) : QOpenGLWidget(parent) {}

void openGL::initializeGL() {
   initializeOpenGLFunctions(); // for ubuntu
// шейдеры будут

// glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // черный цвет
// glOrtho(minX, maxX, minY, maxY, -100000, 10000);
   rotateMatrix.setToIdentity();
   moveMatrix.setToIdentity();
   scaleMatrix.setToIdentity();
}

void openGL::resizeGL(int width, int height) {
//    glViewport(0, 0, width, height);
    setupProjection(width, height);
}

void openGL::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST); // включение буффера глубины для Z
    if (vertexArrays.isCreated()) {
      rotateMatrix.setToIdentity();
      moveMatrix.setToIdentity();
      scaleMatrix.setToIdentity();
      setupProjection();
    }
    draw(&data_obj);

//    glDrawElements(GL_LINES, data_obj.index_array_size, GL_UNSIGNED_INT, 0);
}

//void openGL::paintGL() {
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glEnable(GL_DEPTH_TEST); // включение буффера глубины для Z
//    glMatrixMode(GL_MODELVIEW);
//    glMatrixMode(GL_PROJECTION);
//    glLoadIdentity();
//    glFrustum(-1,1,-1,1,1,3);
////    glEnable(GL_DEPTH_TEST);
//    glLoadIdentity();

//    glTranslatef(0, 0, -2.1);
//    glRotatef(xRot, 1, 0, 0);
//    glRotatef(yRot, 0, 1, 0);
//    draw(&data_obj);
//}

void openGL::draw(ObjData_t* data_obj) {
    if (vertexArrays.isCreated()) {
        vertexArrays.destroy();
      }
      if (vertexBuffer.isCreated()) {
        vertexBuffer.destroy();
      }
      if (elementBuffer.isCreated()) {
        elementBuffer.destroy();
      }
    vertexArrays.create();
    vertexArrays.bind();
    QOpenGLBuffer vertexBuffer(QOpenGLBuffer::VertexBuffer); // создание объекта буффера координат вершин, определяет тип объекта буфера OpenGL
    vertexBuffer.create(); // Создает буферный объект на сервере OpenGL
    vertexBuffer.bind(); // Привязывает буфер, связанный с этим объектом
    vertexBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    vertexBuffer.allocate(data_obj->vertex_array.coords_array,
                    data_obj->vertex_array.coords_number * sizeof(GLfloat));
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,3 * sizeof(GLfloat), nullptr);
    glEnableVertexAttribArray(0);


    QOpenGLBuffer elementBuffer(QOpenGLBuffer::IndexBuffer);
    elementBuffer.create();
    elementBuffer.bind();
    elementBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    elementBuffer.allocate(data_obj->index_array,
                    data_obj->index_array_size * sizeof(GLuint));
//    glDrawElements(GL_LINES, data_obj->index_array_size, GL_UNSIGNED_INT, data_obj->index_array);
    vertexArrays.release();

//    glEnableClientState(GL_VERTEX_ARRAY); // включить состояние OpenGL
//    glVertexPointer(3, GL_DOUBLE, 0, data_obj->vertex_array.coords_array);
//    glEnable(GL_POINT_SMOOTH);
//    glPointSize(2);
//    glDisable(GL_POINT_SMOOTH);
//    glDrawElements(GL_LINES, data_obj->index_array_size, GL_UNSIGNED_INT, data_obj->index_array);
//    glDrawArrays(GL_POINTS, 0, data_obj->vertex_array.coords_number / 3);
//    glDisableClientState(GL_VERTEX_ARRAY); //выключить состояние OpenGL
}

void openGL::mousePressEvent(QMouseEvent *mo) {
    mPos = mo->pos();
}

void openGL::mouseMoveEvent(QMouseEvent *mo) {
    xRot = 1 / M_PI * (mo->pos().y() - mPos.y());
    yRot = 1 / M_PI * (mo->pos().x() - mPos.x());
    update();
}

void openGL::setupProjection(int w, int h) {
  if (w < 1 || h < 1) {
    w = width();
    h = height();
  }
}
