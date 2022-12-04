#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QWidget>
#include <QMessageBox>
#include <QToolBar>
#include "opengl.h"
#include <QtWidgets>
#include <QColorDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    float sliderValue;

private slots:
    void on_choose_OBJFile_clicked();
    void changeRotateX();
    double* changeScale();

private:
    void init ();
    Ui::MainWindow *ui;
//    float sliderValuePast;
//    double* coords_array_copy;

};
#endif // MAINWINDOW_H
