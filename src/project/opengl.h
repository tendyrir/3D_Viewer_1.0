#define GL_SILENCE_DEPRECATION
#ifndef OPENGL_H
#define OPENGL_H

#include <QWidget>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer> // create obj buffers


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
    void mousePressEvent(QMouseEvent *mo) override;
    void mouseMoveEvent(QMouseEvent*) override;

private:
    float xRot, zRot, yRot;
    QPoint mPos;
    void draw(ObjData_t* data_obj);
    void setupProjection(int w = 0, int h = 0);
    QOpenGLVertexArrayObject vertexArrays; // хранилище индексов VBO
    QOpenGLBuffer vertexBuffer;
    QOpenGLBuffer elementBuffer;
    QMatrix4x4 rotateMatrix;
    QMatrix4x4 moveMatrix;
    QMatrix4x4 scaleMatrix;
};

#endif // OPENGL_H
