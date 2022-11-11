#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("3D Viewer");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_choose_OBJFile_clicked() {
    QString filename = QFileDialog::getOpenFileName(this, "Choose File");
    if(filename.isEmpty())
        return;
    ui->label_9->setText(filename);
//    ui->statusbar->showMessage("You choose file: " + filename);
}


// double* arrau = {0, 0, 0};
