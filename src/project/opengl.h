#ifndef OPENGL_H
#define OPENGL_H

#include <QWidget>
#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLShaderProgram>
#include <QOpenGLTexture>

class openGL : public QOpenGLWidget, protected QOpenGLFunctions {
    Q_OBJECT
public:
    explicit openGL(QWidget *parent = nullptr);
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
    void initShaders();

private:
    QOpenGLShaderProgram m_program;
    QOpenGLTexture m_texture;
};

#endif // OPENGL_H
