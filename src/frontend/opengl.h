#define GL_SILENCE_DEPRECATION
#ifndef OPENGL_H
#define OPENGL_H

#include <QWidget>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLBuffer> // create obj buffers
#include "mainwindow.h"


class openGL : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT
public:
    openGL(QWidget *parent = nullptr);
    void getModelData(ObjData_t* model);
    void drawEdges(int* indices);
    void drawVerticies(double* vertices);
    matrix_t data_matrix;
    matrix_t move_matrix;
    ObjData_t* data_obj_openGL = NULL;
    QColor *color_edge = new QColor(214, 214, 214, 255);
    QColor *color_back = new QColor(0, 0, 0, 255);
    QColor *color_vertex = new QColor(0, 0, 255, 255);
    int line_size = 1;
    int point_size = 1;
    bool central_perspective = false;
    int edge_mood = 0; // 0 - solid, 1 - dashed
    int vertex_circle = 0;
    int vertex_square = 0;
    int vertex_disable = 1;

protected:
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void mousePressEvent(QMouseEvent *mo) override;
    void mouseMoveEvent(QMouseEvent *mo) override;

private:
    float xRot, zRot, yRot;
    QPoint mPos;
    void draw(double* vertices, int* indices);
};

#endif // OPENGL_H
