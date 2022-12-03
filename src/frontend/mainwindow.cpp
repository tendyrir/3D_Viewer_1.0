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

    QLabel *labelScale = ui->lineScale; //  значение


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

    connect(ui->Scale, SIGNAL(valueChanged(int)), this, SLOT(changeScale()));

    connect(ui->RotateX, SIGNAL(valueChanged(int)), this, SLOT(changeRotateX()));
}

MainWindow::~MainWindow() {
    delete ui;


}

void MainWindow::on_choose_OBJFile_clicked() {
    QString file = QFileDialog::getOpenFileName(this, "Choose File", "../../../../../src/models");
    if(!file.isEmpty()) {
        ui->label_9->setText(file);
        QByteArray file_bit = file.toLocal8Bit();
        char*     fileName = file_bit.data();
        ui->openGLWidget->data_obj  = (ObjData_t*)calloc(1, sizeof(ObjData_t)); // free ?
        parse_file(ui->openGLWidget->data_obj, fileName);
        ui->edges->setText(QString::number(ui->openGLWidget->data_obj->index_array_size / 2));
        ui->verticies->setText(QString::number(ui->openGLWidget->data_obj->vertex_array.coords_number / 3));
        ui->openGLWidget->update();
    }
}

void MainWindow::init () {
    ui->MoveX->setRange(-50, 50); // устнавливаем диапазон значений
    ui->MoveX->setSingleStep(1);
    ui->MoveX->setValue(0); // задаем стартовое значение
    ui->MoveX->setTickInterval(2); // задаем шаг для рисования рисок

    ui->MoveY->setRange(-50, 50);
    ui->MoveY->setSingleStep(1);

    ui->MoveZ->setRange(-50, 50);
    ui->MoveZ->setSingleStep(1);
}

void MainWindow::changeScale() {

    float sliderValue = ui->Scale->value()/100.0;

//    printf("%f\n", sliderValue);

    s21_create_matrix(1, 3, &ui->openGLWidget->move_matrix);
    s21_create_matrix(ui->openGLWidget->data_obj->vertex_array.coords_number / 3, 4, &ui->openGLWidget->data_matrix);

    ui->openGLWidget->move_matrix.matrix[0][0] = sliderValue;
    ui->openGLWidget->move_matrix.matrix[0][1] = sliderValue;
    ui->openGLWidget->move_matrix.matrix[0][2] = sliderValue;

    conv_to_matr(ui->openGLWidget->data_obj, &ui->openGLWidget->data_matrix);

//    for (int i = 0; i < ui->openGLWidget->data_matrix.rows; i++){
//        for (int j = 0; j < ui->openGLWidget->data_matrix.columns; j++){
//            printf("%lf\n", ui->openGLWidget->data_matrix.matrix[i][j]);

//        }
//    }

    matrix_t athena;

    s21_create_matrix(4, 4, &athena);

//    scale_matrix(&ui->openGLWidget->move_matrix, &athena);



//    for (int i = 0; i < ui->openGLWidget->data_matrix.rows; i++){
//        for (int j = 0; j < ui->openGLWidget->data_matrix.columns; j++){
//            printf("%lf\n", ui->openGLWidget->data_matrix.matrix[i][j]);
//        }
//    }

    matrix_t crd;

    s21_create_matrix(1, 4, &crd);

    for(int i = 0; i < ui->openGLWidget->data_matrix.rows; i++) {
        crd_stlr(&ui->openGLWidget->data_matrix, &crd, i);

        for (int k = 0; k < crd.rows; k++){
            for (int j = 0; j < crd.columns; j++){
                printf("%lf\n", crd.matrix[k][j]);
            }
        }
        printf("\n");

    }

    conv_from_matr(ui->openGLWidget->data_obj, &ui->openGLWidget->data_matrix);

    ui->openGLWidget->update();
}



 void MainWindow::changeRotateX() {

    s21_create_matrix(1, 3, &ui->openGLWidget->move_matrix);

    s21_create_matrix(ui->openGLWidget->data_obj->vertex_array.coords_number / 3, 4, &ui->openGLWidget->data_matrix);

    ui->openGLWidget->move_matrix.matrix[0][0] = ui->RotateX->value()/100.0;
    ui->openGLWidget->move_matrix.matrix[0][1] = ui->RotateY->value()/100.0;
    ui->openGLWidget->move_matrix.matrix[0][2] = ui->RotateZ->value()/100.0;

    conv_to_matr(ui->openGLWidget->data_obj, &ui->openGLWidget->data_matrix);

    matrix_t athena;

    s21_create_matrix(4, 4, &athena);

    rotation(&ui->openGLWidget->move_matrix, &athena);

//    for (int k = 0; k < athena.rows; k++){
//        for (int j = 0; j < athena.columns; j++){
//            printf("%lf\n", athena.matrix[k][j]);
//        }
//    }
//    printf("\n");

    crd_metamorph(&ui->openGLWidget->data_matrix, &athena);

    for (int k = 0; k < ui->openGLWidget->data_matrix.rows; k++){
        for (int j = 0; j < ui->openGLWidget->data_matrix.columns; j++){
            printf("%lf\n", ui->openGLWidget->data_matrix.matrix[k][j]);
        }
        printf("\n");
    }
    s21_remove_matrix(&athena);
}

