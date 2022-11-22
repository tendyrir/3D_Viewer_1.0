#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("3D Viewer");
    openGLWidget = new openGL;
}

MainWindow::~MainWindow() {
    delete ui;
}

QString MainWindow::on_choose_OBJFile_clicked() {
   QString filename = QFileDialog::getOpenFileName(this, "Choose File");
    if(filename.isEmpty())
        return NULL;
    ui->label_9->setText(filename);
    return filename;
}


//void setFilename(QString filename_set) {
//    filename = filename_set;
//}

//std::string getFilename() {
//    return MainWindow::filename;
//}

//void setFilename(QString filename_set) {
//    filename = filename_set;
//}
