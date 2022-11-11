#ifndef OPENGL_H
#define OPENGL_H

#include <QWidget>
#include <QtOpenGL>
#include <QOpenGLWidget>

class openGL : public QOpenGLWidget
{
    Q_OBJECT
public:
    explicit openGL(QWidget *parent = nullptr);
//    void initialiseGL();
//    void realizeGL(int w, int h);
//    void paintGL();

signals:

};

#endif // OPENGL_H
