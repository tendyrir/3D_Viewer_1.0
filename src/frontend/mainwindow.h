#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QWidget>
#include <QMessageBox>
#include <QToolBar>
#include <QtWidgets>
#include <QColorDialog>
#include <math.h>

extern "C" {
#include "../backend/viewer.h"
}

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    ObjData_t* data_obj = NULL;
    double currentSliderValueScale = 50;
    double currentSliderValueRotateX = 0;
    double currentSliderValueRotateY = 0;
    double currentSliderValueRotateZ = 0;
    double currentSliderValueMoveX = 0;
    double currentSliderValueMoveY = 0;
    double currentSliderValueMoveZ = 0;

private slots:
    void on_choose_OBJFile_clicked();
    void changeScale();
    void changeRotateX();

private:
    void init ();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
