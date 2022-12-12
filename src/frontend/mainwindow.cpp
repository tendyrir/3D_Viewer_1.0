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

//    connect(ui->Scale, &QSlider::valueChanged, ui->openGLWidget,
//            &openGL::setScale);

    connect(ui->screenshot_bmp, SIGNAL(clicked()), (this), SLOT(on_screenshotButton_clicked()));
    connect(ui->screenshot_jpeg, SIGNAL(clicked()), (this), SLOT(on_screenshotButton_clicked()));


}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_choose_OBJFile_clicked() {
//    ui->openGLWidget->data_obj = {0};

    QString file = QFileDialog::getOpenFileName(this, tr("Choose File"), "/Users/tendyrir/Desktop/3D_Viewer_1.0/src/models");

    if(file.isEmpty())
        return;

    ui->label_9->setText(file);

    QByteArray file_bit = file.toLocal8Bit();
    char*     obj_file_name = file_bit.data();
    parse_file(&ui->openGLWidget->data_obj, obj_file_name);
//    print_vertex_array(&ui->openGLWidget->data_obj);
    ui->edges->setText(QString::number(ui->openGLWidget->data_obj.index_array_size / 2));
    ui->verticies->setText(QString::number(ui->openGLWidget->data_obj.vertex_array.coords_number / 3));
    ui->openGLWidget->update();
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
    printf("%f\n", sliderValue);
    s21_create_matrix(1, 3, &ui->openGLWidget->move_matrix);
    s21_create_matrix(ui->openGLWidget->data_obj.vertex_array.coords_number / 3, 4, &ui->openGLWidget->data_matrix);
    ui->openGLWidget->move_matrix.matrix[0][0] = sliderValue;
    ui->openGLWidget->move_matrix.matrix[0][1] = sliderValue;
    ui->openGLWidget->move_matrix.matrix[0][2] = sliderValue;
    conv_to_matr(&ui->openGLWidget->data_obj, &ui->openGLWidget->data_matrix);
    core_algorithm(&ui->openGLWidget->data_matrix, &ui->openGLWidget->move_matrix, 2);
    conv_from_matr(&ui->openGLWidget->data_obj, &ui->openGLWidget->data_matrix);
    ui->openGLWidget->update();
}

/** tendyrir screenshot hard coding skills **/

void MainWindow::on_screenshotButton_clicked()
{
    QPushButton *btn = (QPushButton *)sender();
    QString butVal = btn->text();
    QString filename;

    if (QString::compare(butVal, "bmp", Qt::CaseInsensitive) == 0) {
        filename = QFileDialog::getSaveFileName(this, tr("Save File"), pathProject, tr("BMP files (*.bmp)"));
    } else if (QString::compare(butVal, "jpeg", Qt::CaseInsensitive) == 0) {
        filename = QFileDialog::getSaveFileName(this, tr("Save File"), pathProject, tr("JPEG files (*.jpeg)"));
    }

    QImage screenshot = ui->openGLWidget->grabFramebuffer();
    screenshot.save(filename, nullptr, 80);

}

//QPushButton *btn = (QPushButton *)sender();
//QString butVal = btn->text();

//QDir *pathDir = new QDir();
//pathDir->mkdir(pathProject);
//pathDir->mkdir(pathProject + "/screenshots");

//QDateTime dateTime = dateTime.currentDateTime();
//QString currentDateTime = dateTime.toString("yyyy_MM_dd_HHmmss_zzz");

//if (QString::compare(butVal, "bmp", Qt::CaseInsensitive) == 0) {
//  ui->btn_screen_bmp->setEnabled(false);
//  ui->OGLwidget->grab().save(pathProject + "screenshots/" + currentDateTime +
//                             ".bmp");
//  ui->btn_screen_bmp->setEnabled(true);
//} else if (QString::compare(butVal, "jpg", Qt::CaseInsensitive) == 0) {
//  ui->btn_screen_jpg->setEnabled(false);
//  ui->OGLwidget->grab().save(pathProject + "screenshots/" + currentDateTime +
//                             ".jpg");
//  ui->btn_screen_jpg->setEnabled(true);
//} else if (QString::compare(butVal, "gif", Qt::CaseInsensitive) == 0) {
//  ui->btn_screen_gif->setEnabled(false);
//  pathDir->mkdir(pathProject + "/screenshots/gif_obj/");
//  startTime = 0, tmpTime = 1000 / GifFps;
//  timer = new QTimer(this);
//  connect(timer, SIGNAL(timeout()), this, SLOT(oneGif()));
//  timer->start(1000 / GifFps);
//}

