#include "opengl.h"

openGL::openGL(QWidget *parent)
    : QOpenGLWidget(parent) {
    setGeometry(400, 200, 800,600);
}

void openGL::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f); // черный цвет
    glEnable(GL_DEPTH_TEST); // включение буффера глубины
//    glEnable(GL_CULL_FACE); // отключает задние грани
//    glEnable(GL_LIGHT0);
//    glEnable(GL_LIGHTING);
//    glEnable(GL_COLOR_MATERIAL);
}
void openGL::resizeGL(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(-1,1,-1,1,1,2);
    glFrustum(-1,1,-1,1,1,3);
}


void openGL::paintGL() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0,0,-2);
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);
    drawCube(1);
}

void openGL::drawCube(float a) {
    float ver_cub[] = {

         a, a, a,

         a, a, -a,

         a, -a, a,

         a, -a, -a,

         -a, a, a,

         -a, a, -a,

         -a, -a, a,

         -a, -a, -a

    };
    unsigned int indexes_array[] = {
        0, 1, 1, 2, 2, 0,
        2, 3, 3, 1, 1, 2,
        2, 4, 4, 0, 0, 2,
        0, 5, 5, 4, 4, 0,
        0, 5, 5, 1, 1, 0,
        4, 6, 6, 2, 2, 4,
        4, 5, 5, 6, 6, 4,
        6, 5, 5, 7, 7, 6,
        7, 5, 5, 3, 3, 7,
        3, 5, 5, 1, 1, 3,
        6, 2, 2, 7, 7, 6,
        2, 7, 7, 3, 3, 2
    };



    float color[] = {
        0, 0, 0,

        0, 0, 1,

        0, 1, 0,

        0, 1, 1,

        1, 0, 0,

        1, 0, 1,

        1, 1, 0,

        1, 1, 1
    };

    glVertexPointer(3, GL_FLOAT, 0, &ver_cub);
    glEnableClientState(GL_VERTEX_ARRAY); // включить состояние OpenGL

    glColorPointer(3, GL_FLOAT, 0, &color);
    glEnableClientState(GL_COLOR_ARRAY);

//    glDrawArrays(GL_QUADS, 0, 24);
    glDrawElements(GL_LINES, 72, GL_UNSIGNED_INT, &indexes_array);
    glDisableClientState(GL_COLOR_ARRAY);
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



