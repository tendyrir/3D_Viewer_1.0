#define GL_SILENCE_DEPRECATION
#ifndef OPENGL_H
#define OPENGL_H

#include <QWidget>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>


extern "C" {
#include "viewer.h"
}

class openGL : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT
public:
    openGL(QWidget *parent = nullptr);
    ObjData_t data_obj;

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

private:
    float xRot, zRot, yRot;
    QPoint mPos;
    QTimer tmr;
    void drawCube(ObjData_t* data_obj);
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
};

#endif // OPENGL_H
