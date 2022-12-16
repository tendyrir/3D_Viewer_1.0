/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "opengl.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    openGL *openGLWidget;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_10;
    QGroupBox *groupBox_3;
    QSlider *Scale;
    QLabel *lineScale;
    QGroupBox *groupBox_2;
    QSlider *RotateZ;
    QSlider *RotateY;
    QLabel *label_8;
    QSlider *RotateX;
    QLabel *label_7;
    QLabel *label_6;
    QLabel *lineRotateZ;
    QLabel *lineRotateY;
    QLabel *lineRotateX;
    QGroupBox *groupBox;
    QSlider *MoveX;
    QSlider *MoveY;
    QSlider *MoveZ;
    QLabel *label_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *lineMoveY;
    QLabel *lineMoveX;
    QLabel *lineMoveZ;
    QGroupBox *groupBox_7;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *verticies;
    QLabel *edges;
    QGroupBox *groupBox_6;
    QRadioButton *vertex_circle;
    QRadioButton *vertex_square;
    QSlider *vertex_size;
    QLabel *label_12;
    QPushButton *color_verticies;
    QRadioButton *vertex_disable;
    QGroupBox *groupBox_5;
    QRadioButton *edge_solid;
    QRadioButton *edge_dashed;
    QSlider *edge_size;
    QLabel *label_11;
    QPushButton *color_edges;
    QGroupBox *groupBox_4;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *color_background;
    QLabel *label_9;
    QPushButton *button_jpeg;
    QPushButton *button_bmp;
    QPushButton *button_gif;
    QPushButton *choose_OBJFile;
    QStatusBar *statusbar;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1440, 1255);
        MainWindow->setMinimumSize(QSize(800, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        openGLWidget = new openGL(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(310, 100, 1100, 1101));
        openGLWidget->setMinimumSize(QSize(800, 600));
        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(10, 10, 1421, 1201));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1419, 1199));
        label_10 = new QLabel(scrollAreaWidgetContents);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 0, 71, 31));
        label_10->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     font: 700 13pt \"Arial\";\n"
"	color: white;\n"
" }"));
        groupBox_3 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 240, 281, 71));
        groupBox_3->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";"));
        Scale = new QSlider(groupBox_3);
        Scale->setObjectName(QString::fromUtf8("Scale"));
        Scale->setGeometry(QRect(30, 20, 201, 51));
        Scale->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: rgb(127, 187, 255);\n"
"border: 1px solid #777;\n"
"height: 20px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: #fff;\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #eee, stop:1 #ccc);\n"
"border: 1px solid #777;\n"
"width: 20px;\n"
"margin-top: -6px;\n"
"margin-bottom: -6px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #fff, stop:1 #ddd);\n"
"border: 1px solid #444;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"backgroun"
                        "d: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        Scale->setMinimum(1);
        Scale->setMaximum(100);
        Scale->setSingleStep(1);
        Scale->setPageStep(1);
        Scale->setValue(50);
        Scale->setOrientation(Qt::Horizontal);
        lineScale = new QLabel(groupBox_3);
        lineScale->setObjectName(QString::fromUtf8("lineScale"));
        lineScale->setGeometry(QRect(240, 30, 41, 31));
        lineScale->setStyleSheet(QString::fromUtf8("font: 14pt \".AppleSystemUIFont\";"));
        groupBox_2 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 310, 281, 151));
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";"));
        RotateZ = new QSlider(groupBox_2);
        RotateZ->setObjectName(QString::fromUtf8("RotateZ"));
        RotateZ->setGeometry(QRect(30, 100, 201, 41));
        RotateZ->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: rgb(127, 187, 255);\n"
"border: 1px solid #777;\n"
"height: 20px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: #fff;\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #eee, stop:1 #ccc);\n"
"border: 1px solid #777;\n"
"width: 20px;\n"
"margin-top: -6px;\n"
"margin-bottom: -6px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #fff, stop:1 #ddd);\n"
"border: 1px solid #444;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"backgroun"
                        "d: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        RotateZ->setMinimum(-360);
        RotateZ->setMaximum(360);
        RotateZ->setPageStep(1);
        RotateZ->setValue(0);
        RotateZ->setOrientation(Qt::Horizontal);
        RotateY = new QSlider(groupBox_2);
        RotateY->setObjectName(QString::fromUtf8("RotateY"));
        RotateY->setGeometry(QRect(30, 60, 201, 41));
        RotateY->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: rgb(127, 187, 255);\n"
"border: 1px solid #777;\n"
"height: 20px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: #fff;\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #eee, stop:1 #ccc);\n"
"border: 1px solid #777;\n"
"width: 20px;\n"
"margin-top: -6px;\n"
"margin-bottom: -6px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #fff, stop:1 #ddd);\n"
"border: 1px solid #444;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"backgroun"
                        "d: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        RotateY->setMinimum(-360);
        RotateY->setMaximum(360);
        RotateY->setPageStep(1);
        RotateY->setValue(0);
        RotateY->setOrientation(Qt::Horizontal);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 110, 16, 21));
        label_8->setStyleSheet(QString::fromUtf8("font: 14pt \".AppleSystemUIFont\";"));
        RotateX = new QSlider(groupBox_2);
        RotateX->setObjectName(QString::fromUtf8("RotateX"));
        RotateX->setGeometry(QRect(30, 20, 201, 41));
        RotateX->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: rgb(127, 187, 255);\n"
"border: 1px solid #777;\n"
"height: 20px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: #fff;\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #eee, stop:1 #ccc);\n"
"border: 1px solid #777;\n"
"width: 20px;\n"
"margin-top: -6px;\n"
"margin-bottom: -6px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #fff, stop:1 #ddd);\n"
"border: 1px solid #444;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"backgroun"
                        "d: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        RotateX->setMinimum(-360);
        RotateX->setMaximum(360);
        RotateX->setPageStep(1);
        RotateX->setValue(0);
        RotateX->setSliderPosition(0);
        RotateX->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 70, 16, 21));
        label_7->setStyleSheet(QString::fromUtf8("font: 14pt \".AppleSystemUIFont\";"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 30, 16, 16));
        label_6->setStyleSheet(QString::fromUtf8("font: 14pt \".AppleSystemUIFont\";"));
        lineRotateZ = new QLabel(groupBox_2);
        lineRotateZ->setObjectName(QString::fromUtf8("lineRotateZ"));
        lineRotateZ->setGeometry(QRect(240, 100, 31, 31));
        lineRotateZ->setStyleSheet(QString::fromUtf8("font: 14pt \".AppleSystemUIFont\";"));
        lineRotateY = new QLabel(groupBox_2);
        lineRotateY->setObjectName(QString::fromUtf8("lineRotateY"));
        lineRotateY->setGeometry(QRect(240, 60, 31, 31));
        lineRotateY->setStyleSheet(QString::fromUtf8("font: 14pt \".AppleSystemUIFont\";"));
        lineRotateX = new QLabel(groupBox_2);
        lineRotateX->setObjectName(QString::fromUtf8("lineRotateX"));
        lineRotateX->setGeometry(QRect(240, 20, 31, 31));
        lineRotateX->setStyleSheet(QString::fromUtf8("font: 14pt \".AppleSystemUIFont\";"));
        groupBox = new QGroupBox(scrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 460, 281, 151));
        groupBox->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";"));
        MoveX = new QSlider(groupBox);
        MoveX->setObjectName(QString::fromUtf8("MoveX"));
        MoveX->setGeometry(QRect(30, 20, 201, 41));
        MoveX->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: rgb(127, 187, 255);\n"
"border: 1px solid #777;\n"
"height: 20px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: #fff;\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #eee, stop:1 #ccc);\n"
"border: 1px solid #777;\n"
"width: 20px;\n"
"margin-top: -6px;\n"
"margin-bottom: -6px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #fff, stop:1 #ddd);\n"
"border: 1px solid #444;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"backgroun"
                        "d: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        MoveX->setMinimum(-180);
        MoveX->setMaximum(180);
        MoveX->setPageStep(1);
        MoveX->setValue(0);
        MoveX->setOrientation(Qt::Horizontal);
        MoveY = new QSlider(groupBox);
        MoveY->setObjectName(QString::fromUtf8("MoveY"));
        MoveY->setGeometry(QRect(30, 60, 201, 41));
        MoveY->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: rgb(127, 187, 255);\n"
"border: 1px solid #777;\n"
"height: 20px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: #fff;\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #eee, stop:1 #ccc);\n"
"border: 1px solid #777;\n"
"width: 20px;\n"
"margin-top: -6px;\n"
"margin-bottom: -6px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #fff, stop:1 #ddd);\n"
"border: 1px solid #444;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"backgroun"
                        "d: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        MoveY->setMinimum(-180);
        MoveY->setMaximum(180);
        MoveY->setPageStep(1);
        MoveY->setValue(0);
        MoveY->setOrientation(Qt::Horizontal);
        MoveZ = new QSlider(groupBox);
        MoveZ->setObjectName(QString::fromUtf8("MoveZ"));
        MoveZ->setGeometry(QRect(30, 100, 201, 41));
        MoveZ->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: rgb(127, 187, 255);\n"
"border: 1px solid #777;\n"
"height: 20px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: #fff;\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #eee, stop:1 #ccc);\n"
"border: 1px solid #777;\n"
"width: 20px;\n"
"margin-top: -6px;\n"
"margin-bottom: -6px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #fff, stop:1 #ddd);\n"
"border: 1px solid #444;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"backgroun"
                        "d: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        MoveZ->setMinimum(-180);
        MoveZ->setMaximum(180);
        MoveZ->setPageStep(1);
        MoveZ->setValue(0);
        MoveZ->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 110, 16, 16));
        label_3->setStyleSheet(QString::fromUtf8("font: 14pt \".AppleSystemUIFont\";"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 70, 16, 16));
        label->setStyleSheet(QString::fromUtf8("font: 14pt \".AppleSystemUIFont\";"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 16, 16));
        label_2->setStyleSheet(QString::fromUtf8("font: 14pt \".AppleSystemUIFont\";"));
        lineMoveY = new QLabel(groupBox);
        lineMoveY->setObjectName(QString::fromUtf8("lineMoveY"));
        lineMoveY->setGeometry(QRect(240, 60, 31, 31));
        lineMoveY->setStyleSheet(QString::fromUtf8("font: 14pt \".AppleSystemUIFont\";"));
        lineMoveX = new QLabel(groupBox);
        lineMoveX->setObjectName(QString::fromUtf8("lineMoveX"));
        lineMoveX->setGeometry(QRect(240, 20, 31, 31));
        lineMoveX->setStyleSheet(QString::fromUtf8("font: 14pt \".AppleSystemUIFont\";"));
        lineMoveZ = new QLabel(groupBox);
        lineMoveZ->setObjectName(QString::fromUtf8("lineMoveZ"));
        lineMoveZ->setGeometry(QRect(240, 100, 31, 31));
        lineMoveZ->setStyleSheet(QString::fromUtf8("font: 14pt \".AppleSystemUIFont\";"));
        groupBox_7 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_7->setObjectName(QString::fromUtf8("groupBox_7"));
        groupBox_7->setGeometry(QRect(10, 30, 281, 71));
        groupBox_7->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";"));
        label_4 = new QLabel(groupBox_7);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 0, 71, 31));
        label_4->setStyleSheet(QString::fromUtf8("font: 16pt;"));
        label_5 = new QLabel(groupBox_7);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 30, 71, 31));
        label_5->setStyleSheet(QString::fromUtf8("font: 16pt;"));
        verticies = new QLabel(groupBox_7);
        verticies->setObjectName(QString::fromUtf8("verticies"));
        verticies->setGeometry(QRect(90, 0, 181, 31));
        verticies->setStyleSheet(QString::fromUtf8("font: 16pt;"));
        edges = new QLabel(groupBox_7);
        edges->setObjectName(QString::fromUtf8("edges"));
        edges->setGeometry(QRect(90, 30, 181, 31));
        edges->setStyleSheet(QString::fromUtf8("font: 16pt;"));
        groupBox_6 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        groupBox_6->setGeometry(QRect(10, 790, 281, 191));
        groupBox_6->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";"));
        vertex_circle = new QRadioButton(groupBox_6);
        vertex_circle->setObjectName(QString::fromUtf8("vertex_circle"));
        vertex_circle->setGeometry(QRect(20, 40, 101, 21));
        vertex_circle->setStyleSheet(QString::fromUtf8("font: 16pt \".AppleSystemUIFont\";"));
        vertex_square = new QRadioButton(groupBox_6);
        vertex_square->setObjectName(QString::fromUtf8("vertex_square"));
        vertex_square->setGeometry(QRect(190, 40, 99, 20));
        vertex_square->setStyleSheet(QString::fromUtf8("font: 16pt \".AppleSystemUIFont\";"));
        vertex_size = new QSlider(groupBox_6);
        vertex_size->setObjectName(QString::fromUtf8("vertex_size"));
        vertex_size->setGeometry(QRect(60, 70, 191, 61));
        vertex_size->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: rgb(127, 187, 255);\n"
"border: 1px solid #777;\n"
"height: 20px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: #fff;\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #eee, stop:1 #ccc);\n"
"border: 1px solid #777;\n"
"width: 20px;\n"
"margin-top: -6px;\n"
"margin-bottom: -6px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #fff, stop:1 #ddd);\n"
"border: 1px solid #444;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"backgroun"
                        "d: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        vertex_size->setMinimum(1);
        vertex_size->setMaximum(50);
        vertex_size->setPageStep(1);
        vertex_size->setValue(1);
        vertex_size->setOrientation(Qt::Horizontal);
        label_12 = new QLabel(groupBox_6);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 90, 51, 21));
        label_12->setStyleSheet(QString::fromUtf8("font: 16pt \".AppleSystemUIFont\";"));
        color_verticies = new QPushButton(groupBox_6);
        color_verticies->setObjectName(QString::fromUtf8("color_verticies"));
        color_verticies->setGeometry(QRect(10, 130, 261, 41));
        color_verticies->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     font: 700 13pt \"Arial\";\n"
"	color: white;\n"
"	background-color:rgb(127, 187, 255);\n"
"	border: 1px solid rgb(191, 210, 255);\n"
"	border-radius: 5px;\n"
" }\n"
"\n"
" QPushButton:hover {\n"
"     background-color: blue;\n"
" }"));
        vertex_disable = new QRadioButton(groupBox_6);
        vertex_disable->setObjectName(QString::fromUtf8("vertex_disable"));
        vertex_disable->setGeometry(QRect(100, 40, 99, 20));
        vertex_disable->setStyleSheet(QString::fromUtf8("font: 16pt \".AppleSystemUIFont\";"));
        vertex_disable->setChecked(true);
        groupBox_5 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 610, 281, 181));
        groupBox_5->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";"));
        edge_solid = new QRadioButton(groupBox_5);
        edge_solid->setObjectName(QString::fromUtf8("edge_solid"));
        edge_solid->setGeometry(QRect(20, 40, 101, 21));
        edge_solid->setStyleSheet(QString::fromUtf8("font: 16pt \".AppleSystemUIFont\";"));
        edge_solid->setChecked(true);
        edge_dashed = new QRadioButton(groupBox_5);
        edge_dashed->setObjectName(QString::fromUtf8("edge_dashed"));
        edge_dashed->setGeometry(QRect(180, 40, 99, 20));
        edge_dashed->setStyleSheet(QString::fromUtf8("font: 16pt \".AppleSystemUIFont\";"));
        edge_size = new QSlider(groupBox_5);
        edge_size->setObjectName(QString::fromUtf8("edge_size"));
        edge_size->setGeometry(QRect(60, 60, 191, 61));
        edge_size->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: rgb(127, 187, 255);\n"
"border: 1px solid #777;\n"
"height: 20px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: #fff;\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #eee, stop:1 #ccc);\n"
"border: 1px solid #777;\n"
"width: 20px;\n"
"margin-top: -6px;\n"
"margin-bottom: -6px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"    stop:0 #fff, stop:1 #ddd);\n"
"border: 1px solid #444;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"backgroun"
                        "d: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        edge_size->setMinimum(1);
        edge_size->setMaximum(50);
        edge_size->setPageStep(1);
        edge_size->setValue(1);
        edge_size->setOrientation(Qt::Horizontal);
        label_11 = new QLabel(groupBox_5);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, 80, 51, 21));
        label_11->setStyleSheet(QString::fromUtf8("font: 16pt \".AppleSystemUIFont\";"));
        color_edges = new QPushButton(groupBox_5);
        color_edges->setObjectName(QString::fromUtf8("color_edges"));
        color_edges->setGeometry(QRect(10, 120, 261, 41));
        color_edges->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     font: 700 13pt \"Arial\";\n"
"	color: white;\n"
"	background-color:rgb(127, 187, 255);\n"
"	border: 1px solid rgb(191, 210, 255);\n"
"	border-radius: 5px;\n"
" }\n"
"\n"
" QPushButton:hover {\n"
"     background-color: blue;\n"
" }"));
        groupBox_4 = new QGroupBox(scrollAreaWidgetContents);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(10, 100, 281, 141));
        groupBox_4->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";"));
        radioButton = new QRadioButton(groupBox_4);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(20, 40, 99, 20));
        radioButton->setTabletTracking(false);
        radioButton->setStyleSheet(QString::fromUtf8("font: 16pt \".AppleSystemUIFont\";"));
        radioButton->setChecked(false);
        radioButton_2 = new QRadioButton(groupBox_4);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(160, 40, 99, 20));
        radioButton_2->setStyleSheet(QString::fromUtf8("font: 16pt \".AppleSystemUIFont\";"));
        radioButton_2->setChecked(true);
        radioButton_2->setAutoRepeat(false);
        color_background = new QPushButton(groupBox_4);
        color_background->setObjectName(QString::fromUtf8("color_background"));
        color_background->setGeometry(QRect(10, 80, 261, 41));
        color_background->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     font: 700 13pt \"Arial\";\n"
"	color: white;\n"
"	background-color:rgb(127, 187, 255);\n"
"	border: 1px solid rgb(191, 210, 255);\n"
"	border-radius: 5px;\n"
" }\n"
"\n"
" QPushButton:hover {\n"
"     background-color: blue;\n"
" }"));
        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(300, 0, 1411, 31));
        label_9->setStyleSheet(QString::fromUtf8(""));
        button_jpeg = new QPushButton(scrollAreaWidgetContents);
        button_jpeg->setObjectName(QString::fromUtf8("button_jpeg"));
        button_jpeg->setGeometry(QRect(470, 30, 81, 41));
        button_jpeg->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     font: 700 13pt \"Arial\";\n"
"	color: white;\n"
"	background-color:rgb(127, 187, 255);\n"
"	border: 1px solid rgb(191, 210, 255);\n"
"	border-radius: 5px;\n"
" }\n"
"\n"
" QPushButton:hover {\n"
"     background-color: blue;\n"
" }"));
        button_bmp = new QPushButton(scrollAreaWidgetContents);
        button_bmp->setObjectName(QString::fromUtf8("button_bmp"));
        button_bmp->setGeometry(QRect(560, 30, 81, 41));
        button_bmp->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     font: 700 13pt \"Arial\";\n"
"	color: white;\n"
"	background-color:rgb(127, 187, 255);\n"
"	border: 1px solid rgb(191, 210, 255);\n"
"	border-radius: 5px;\n"
" }\n"
"\n"
" QPushButton:hover {\n"
"     background-color: blue;\n"
" }"));
        button_gif = new QPushButton(scrollAreaWidgetContents);
        button_gif->setObjectName(QString::fromUtf8("button_gif"));
        button_gif->setGeometry(QRect(650, 30, 81, 41));
        button_gif->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     font: 700 13pt \"Arial\";\n"
"	color: white;\n"
"	background-color:rgb(127, 187, 255);\n"
"	border: 1px solid rgb(191, 210, 255);\n"
"	border-radius: 5px;\n"
" }\n"
"\n"
" QPushButton:hover {\n"
"     background-color: blue;\n"
" }"));
        choose_OBJFile = new QPushButton(scrollAreaWidgetContents);
        choose_OBJFile->setObjectName(QString::fromUtf8("choose_OBJFile"));
        choose_OBJFile->setGeometry(QRect(310, 30, 151, 41));
        choose_OBJFile->setStyleSheet(QString::fromUtf8(" QPushButton {\n"
"     font: 700 13pt \"Arial\";\n"
"	color: white;\n"
"	background-color:rgb(127, 187, 255);\n"
"	border: 1px solid rgb(191, 210, 255);\n"
"	border-radius: 5px;\n"
" }\n"
"\n"
" QPushButton:hover {\n"
"     background-color: blue;\n"
" }"));
        scrollArea->setWidget(scrollAreaWidgetContents);
        MainWindow->setCentralWidget(centralwidget);
        scrollArea->raise();
        openGLWidget->raise();
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1440, 22));
        MainWindow->setMenuBar(menubar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Path file:", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        lineScale->setText(QCoreApplication::translate("MainWindow", "50", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        lineRotateZ->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineRotateY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineRotateX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Move", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        lineMoveY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineMoveX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineMoveZ->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        groupBox_7->setTitle(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "Verticies:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Edges:", nullptr));
        verticies->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        edges->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        groupBox_6->setTitle(QCoreApplication::translate("MainWindow", "Verticies", nullptr));
        vertex_circle->setText(QCoreApplication::translate("MainWindow", "Circle", nullptr));
        vertex_square->setText(QCoreApplication::translate("MainWindow", "Square", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Size:", nullptr));
        color_verticies->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        vertex_disable->setText(QCoreApplication::translate("MainWindow", "Disable", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Edges", nullptr));
        edge_solid->setText(QCoreApplication::translate("MainWindow", "Solid", nullptr));
        edge_dashed->setText(QCoreApplication::translate("MainWindow", "Dashed", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Size:", nullptr));
        color_edges->setText(QCoreApplication::translate("MainWindow", "Color", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Projection", nullptr));
        radioButton->setText(QCoreApplication::translate("MainWindow", "Central", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Parallel", nullptr));
        color_background->setText(QCoreApplication::translate("MainWindow", "Background color", nullptr));
        label_9->setText(QString());
        button_jpeg->setText(QCoreApplication::translate("MainWindow", "jpeg", nullptr));
        button_bmp->setText(QCoreApplication::translate("MainWindow", "bmp", nullptr));
        button_gif->setText(QCoreApplication::translate("MainWindow", "gif", nullptr));
        choose_OBJFile->setText(QCoreApplication::translate("MainWindow", "OBJ File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
