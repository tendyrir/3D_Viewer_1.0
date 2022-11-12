#include "opengl.h"

openGL::openGL(QWidget *parent)
    : QOpenGLWidget(parent) {

}

void openGL::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // черный цвет
    glEnable(GL_DEPTH_TEST); // включение буффера глубины
    glEnable(GL_CULL_FACE); // отключает задние грани
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    initShaders();
}
void openGL::resizeGL(int width, int height) {
    glViewport(0, 0, width, height);
}
void openGL::paintGL() {
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    qglClearColor(Qt::darkCyan);
//    qglColor(Qt::red);
//    glBegin(GL_LINE_LOOP);
//        update();

}

void openGL::initShaders() {
//    m_program.addShaderFromSourceFile(QOpenGLShader::Vertex, "vshader")
}
