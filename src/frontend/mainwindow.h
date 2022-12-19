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
#include <QSettings>

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
    QString pathProject = QDir::homePath();
    ~MainWindow();
    ObjData_t* data_obj = NULL;
    double currentSliderValueScale = 50;
    double currentSliderValueRotateX = 0;
    double currentSliderValueRotateY = 0;
    double currentSliderValueRotateZ = 0;
    double currentSliderValueMoveX = 0;
    double currentSliderValueMoveY = 0;
    double currentSliderValueMoveZ = 0;
    QColor *edges_color = new QColor(0, 0, 0, 255);
    QColor *back_color = new QColor(214, 214, 214, 255);
    QColor *vertex_color = new QColor(0, 0, 255, 255);
    bool vertex_square = false;
    bool vertex_circle = false;
    bool vertex_disable = false;
    QSettings *settings;

private slots:
    void on_gifButton_clicked();
    void on_screenshotButton_clicked();
    void on_choose_OBJFile_clicked();
    void changeScale();
    void changeRotateX();
    void changeRotateY();
    void changeRotateZ();
    void changeMoveX();
    void changeMoveY();
    void changeMoveZ();

    void on_color_edges_clicked();
    void on_color_verticies_clicked();
    void on_color_background_clicked();
    void edge_size_valueChanged();
    void vertex_size_valueChanged();

    void on_radioButton_toggled(bool checked);
    void on_edge_dashed_toggled(bool checked);
    void on_vertex_circle_toggled(bool checked);
    void on_vertex_square_toggled(bool checked);

    void on_vertex_disable_toggled(bool checked);
    void check_frame_vertex();

    void save_settings();
    void on_load_settings_clicked();

private:
    void init ();
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
