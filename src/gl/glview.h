#ifndef GLVIEW_H
#define GLVIEW_H

#include <QtWidgets/QWidget>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QWidget>
#include <QMessageBox>
#include <QToolBar>
#include <QtOpenGL>
#include <QOpenGLWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class glView; }
QT_END_NAMESPACE

class glView : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    glView(QWidget *parent = nullptr);
    ~glView();

private slots:
    void on_choose_OBJFile_clicked();

private:
    Ui::glView *ui;
};
#endif // GLVIEW_H
