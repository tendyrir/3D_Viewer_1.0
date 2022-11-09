#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->choose_OBJFile, SIGNAL(clicked()), this, SLOT(on_choose_OBJFile_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;

}



void MainWindow::on_choose_OBJFile_clicked() {
    QString fileContent;

    QString filename= QFileDialog::getOpenFileName(this, "Choose File");


   if(filename.isEmpty())
       return;

   QFile file(filename);

   if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
       return;

   QTextStream in(&file);

   fileContent= in.readAll();

   file.close();

   ui->textEdit->clear();
   ui->textEdit->setPlainText(fileContent);
}

