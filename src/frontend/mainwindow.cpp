#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("3D Viewer");

    QLabel *labelMoveX = ui->lineMoveX;
    QLabel *labelMoveY = ui->lineMoveY;
    QLabel *labelMoveZ = ui->lineMoveZ;

    QLabel *labelRotateX = ui->lineRotateX;
    QLabel *labelRotateY = ui->lineRotateY;
    QLabel *labelRotateZ = ui->lineRotateZ;

    QLabel *labelScale = ui->lineScale;


    connect(ui->MoveX, &QSlider::valueChanged, [labelMoveX](int value) {
      labelMoveX->setText( QString("%0").arg(value));
    });

    connect(ui->MoveY, &QSlider::valueChanged, [labelMoveY](int value) {
      labelMoveY->setText( QString("%0").arg(value));
    });

    connect(ui->MoveZ, &QSlider::valueChanged, [labelMoveZ](int value) {
      labelMoveZ->setText( QString("%0").arg(value));
    });

    connect(ui->RotateX, &QSlider::valueChanged, [labelRotateX](int value) {
      labelRotateX->setText( QString("%0").arg(value));
    });

    connect(ui->RotateY, &QSlider::valueChanged, [labelRotateY](int value) {
      labelRotateY->setText( QString("%0").arg(value));
    });

    connect(ui->RotateZ, &QSlider::valueChanged, [labelRotateZ](int value) {
      labelRotateZ->setText( QString("%0").arg(value));
    });

    connect(ui->Scale, &QSlider::valueChanged, [labelScale](int value) {
      labelScale->setText( QString("%0").arg(value));
    });
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_choose_OBJFile_clicked() {
    ui->openGLWidget->data_obj = {0};
    QString file = QFileDialog::getOpenFileName(this, "Choose File");
    if(file.isEmpty())
        return ;
    ui->label_9->setText(file);
    QByteArray file_bit = file.toLocal8Bit();
    char*     obj_file_name = file_bit.data();
    parse_file(&ui->openGLWidget->data_obj, obj_file_name);
    print_vertex_array(&ui->openGLWidget->data_obj);
    ui->edges->setText(QString::number(ui->openGLWidget->data_obj.index_array_size / 2));
    ui->verticies->setText(QString::number(ui->openGLWidget->data_obj.vertex_array.coords_number / 3));
    ui->openGLWidget->update();
}

void MainWindow::init () {
    ui->MoveX->setRange(-50, 50);
    ui->MoveX->setSingleStep(1);

    ui->MoveY->setRange(-50, 50);
    ui->MoveY->setSingleStep(1);

    ui->MoveZ->setRange(-50, 50);
    ui->MoveZ->setSingleStep(1);
}



