#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QWidget>
#include <QMessageBox>
#include <QToolBar>
#include <QImage>
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
    QString pathProject = QDir::homePath();

private slots:
    void on_screenshotButton_clicked();  //tendyrir
    void on_choose_OBJFile_clicked();
    void changeScale();

private:
    void init ();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
