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
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
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
    QPushButton *choose_OBJFile;
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
    QLabel *label_9;
    QGroupBox *groupBox_3;
    QSlider *Scale;
    QLabel *lineScale;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *verticies;
    QLabel *edges;
    QMenuBar *menubar;
    QMenu *menuSuchka;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(2120, 1269);
        MainWindow->setMinimumSize(QSize(800, 600));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        openGLWidget = new openGL(centralwidget);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(310, 100, 1791, 1101));
        openGLWidget->setMinimumSize(QSize(800, 600));
        choose_OBJFile = new QPushButton(centralwidget);
        choose_OBJFile->setObjectName(QString::fromUtf8("choose_OBJFile"));
        choose_OBJFile->setGeometry(QRect(10, 20, 281, 51));
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
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 80, 281, 151));
        groupBox->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";"));
        MoveX = new QSlider(groupBox);
        MoveX->setObjectName(QString::fromUtf8("MoveX"));
        MoveX->setGeometry(QRect(20, 20, 211, 41));
        MoveX->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(x1: 0, y1: 0,    x2: 0, y2: 1,\n"
"    stop: 0 #76q, stop: 1 #bbf);\n"
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
"background"
                        ": #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        MoveX->setMinimum(-50);
        MoveX->setMaximum(50);
        MoveX->setValue(0);
        MoveX->setOrientation(Qt::Horizontal);
        MoveY = new QSlider(groupBox);
        MoveY->setObjectName(QString::fromUtf8("MoveY"));
        MoveY->setGeometry(QRect(20, 60, 211, 41));
        MoveY->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(x1: 0, y1: 0,    x2: 0, y2: 1,\n"
"    stop: 0 #76q, stop: 1 #bbf);\n"
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
"background"
                        ": #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        MoveY->setMinimum(-50);
        MoveY->setMaximum(50);
        MoveY->setValue(0);
        MoveY->setOrientation(Qt::Horizontal);
        MoveZ = new QSlider(groupBox);
        MoveZ->setObjectName(QString::fromUtf8("MoveZ"));
        MoveZ->setGeometry(QRect(20, 100, 211, 41));
        MoveZ->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(x1: 0, y1: 0,    x2: 0, y2: 1,\n"
"    stop: 0 #76q, stop: 1 #bbf);\n"
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
"background"
                        ": #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        MoveZ->setMinimum(-50);
        MoveZ->setMaximum(50);
        MoveZ->setValue(0);
        MoveZ->setOrientation(Qt::Horizontal);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(0, 110, 58, 16));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 70, 58, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(0, 30, 58, 16));
        lineMoveY = new QLabel(groupBox);
        lineMoveY->setObjectName(QString::fromUtf8("lineMoveY"));
        lineMoveY->setGeometry(QRect(240, 60, 41, 31));
        lineMoveX = new QLabel(groupBox);
        lineMoveX->setObjectName(QString::fromUtf8("lineMoveX"));
        lineMoveX->setGeometry(QRect(240, 20, 41, 31));
        lineMoveZ = new QLabel(groupBox);
        lineMoveZ->setObjectName(QString::fromUtf8("lineMoveZ"));
        lineMoveZ->setGeometry(QRect(240, 100, 41, 31));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 230, 281, 141));
        groupBox_2->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";"));
        RotateZ = new QSlider(groupBox_2);
        RotateZ->setObjectName(QString::fromUtf8("RotateZ"));
        RotateZ->setGeometry(QRect(20, 100, 211, 41));
        RotateZ->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(x1: 0, y1: 0,    x2: 0, y2: 1,\n"
"    stop: 0 #76q, stop: 1 #bbf);\n"
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
"background"
                        ": #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        RotateZ->setMinimum(-180);
        RotateZ->setMaximum(180);
        RotateZ->setValue(0);
        RotateZ->setOrientation(Qt::Horizontal);
        RotateY = new QSlider(groupBox_2);
        RotateY->setObjectName(QString::fromUtf8("RotateY"));
        RotateY->setGeometry(QRect(20, 60, 211, 41));
        RotateY->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(x1: 0, y1: 0,    x2: 0, y2: 1,\n"
"    stop: 0 #76q, stop: 1 #bbf);\n"
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
"background"
                        ": #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        RotateY->setMinimum(-180);
        RotateY->setMaximum(180);
        RotateY->setValue(0);
        RotateY->setOrientation(Qt::Horizontal);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(0, 110, 58, 16));
        label_8->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";"));
        RotateX = new QSlider(groupBox_2);
        RotateX->setObjectName(QString::fromUtf8("RotateX"));
        RotateX->setGeometry(QRect(20, 20, 211, 41));
        RotateX->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(x1: 0, y1: 0,    x2: 0, y2: 1,\n"
"    stop: 0 #76q, stop: 1 #bbf);\n"
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
"background"
                        ": #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        RotateX->setMinimum(-180);
        RotateX->setMaximum(180);
        RotateX->setValue(0);
        RotateX->setOrientation(Qt::Horizontal);
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(0, 70, 58, 16));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 30, 58, 16));
        lineRotateZ = new QLabel(groupBox_2);
        lineRotateZ->setObjectName(QString::fromUtf8("lineRotateZ"));
        lineRotateZ->setGeometry(QRect(240, 100, 41, 31));
        lineRotateY = new QLabel(groupBox_2);
        lineRotateY->setObjectName(QString::fromUtf8("lineRotateY"));
        lineRotateY->setGeometry(QRect(240, 60, 41, 31));
        lineRotateX = new QLabel(groupBox_2);
        lineRotateX->setObjectName(QString::fromUtf8("lineRotateX"));
        lineRotateX->setGeometry(QRect(240, 20, 41, 31));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(310, 0, 911, 31));
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(0, 360, 291, 71));
        groupBox_3->setStyleSheet(QString::fromUtf8("font: 18pt \".AppleSystemUIFont\";"));
        Scale = new QSlider(groupBox_3);
        Scale->setObjectName(QString::fromUtf8("Scale"));
        Scale->setGeometry(QRect(20, 20, 221, 61));
        Scale->setStyleSheet(QString::fromUtf8("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"background: qlineargradient(x1: 0, y1: 0,    x2: 0, y2: 1,\n"
"    stop: 0 #76q, stop: 1 #bbf);\n"
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
"background"
                        ": #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        Scale->setMinimum(1);
        Scale->setMaximum(300);
        Scale->setValue(30);
        Scale->setOrientation(Qt::Horizontal);
        lineScale = new QLabel(groupBox_3);
        lineScale->setObjectName(QString::fromUtf8("lineScale"));
        lineScale->setGeometry(QRect(250, 30, 41, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(310, 30, 71, 31));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(310, 60, 71, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(1580, 40, 161, 41));
        pushButton->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Arial\";\n"
"color: white;\n"
"background-color:rgb(127, 187, 255);\n"
"border: 1px solid rgb(191, 210, 255);\n"
"border-radius: 5px;"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(1760, 40, 151, 41));
        pushButton_2->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Arial\";\n"
"color: white;\n"
"background-color:rgb(127, 187, 255);\n"
"border: 1px solid rgb(191, 210, 255);\n"
"border-radius: 5px;"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(1930, 40, 171, 41));
        pushButton_3->setStyleSheet(QString::fromUtf8("font: 700 13pt \"Arial\";\n"
"color: white;\n"
"background-color:rgb(127, 187, 255);\n"
"border: 1px solid rgb(191, 210, 255);\n"
"border-radius: 5px;"));
        verticies = new QLabel(centralwidget);
        verticies->setObjectName(QString::fromUtf8("verticies"));
        verticies->setGeometry(QRect(390, 30, 61, 31));
        edges = new QLabel(centralwidget);
        edges->setObjectName(QString::fromUtf8("edges"));
        edges->setGeometry(QRect(390, 60, 61, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 2120, 22));
        menuSuchka = new QMenu(menubar);
        menuSuchka->setObjectName(QString::fromUtf8("menuSuchka"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuSuchka->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        choose_OBJFile->setText(QCoreApplication::translate("MainWindow", "OBJ File", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Move", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        lineMoveY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineMoveX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineMoveZ->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Rotate", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Z", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Y", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "X", nullptr));
        lineRotateZ->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineRotateY->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lineRotateX->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_9->setText(QString());
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "Scale", nullptr));
        lineScale->setText(QCoreApplication::translate("MainWindow", "30", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Verticies:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Edges:", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "JPG", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "BMP", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "GIF", nullptr));
        verticies->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        edges->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        menuSuchka->setTitle(QCoreApplication::translate("MainWindow", "Suchka", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
