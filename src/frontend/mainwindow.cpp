#include "mainwindow.h"

//#include "../gifimage/qgifimage.h"

#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setWindowTitle("3D Viewer");

  timer = new QTimer(this);

  QLabel *labelMoveX = ui->lineMoveX;
  QLabel *labelMoveY = ui->lineMoveY;
  QLabel *labelMoveZ = ui->lineMoveZ;

  QLabel *labelRotateX = ui->lineRotateX;
  QLabel *labelRotateY = ui->lineRotateY;
  QLabel *labelRotateZ = ui->lineRotateZ;

  QLabel *labelScale = ui->lineScale;  //  значение

  connect(ui->MoveX, &QSlider::valueChanged, [labelMoveX](int value) {
    labelMoveX->setText(QString("%0").arg(value));
  });

  connect(ui->MoveY, &QSlider::valueChanged, [labelMoveY](int value) {
    labelMoveY->setText(QString("%0").arg(value));
  });

  connect(ui->MoveZ, &QSlider::valueChanged, [labelMoveZ](int value) {
    labelMoveZ->setText(QString("%0").arg(value));
  });

  connect(ui->RotateX, &QSlider::valueChanged, [labelRotateX](int value) {
    labelRotateX->setText(QString("%0").arg(value));
  });

  connect(ui->RotateY, &QSlider::valueChanged, [labelRotateY](int value) {
    labelRotateY->setText(QString("%0").arg(value));
  });

  connect(ui->RotateZ, &QSlider::valueChanged, [labelRotateZ](int value) {
    labelRotateZ->setText(QString("%0").arg(value));
  });

  connect(ui->Scale, &QSlider::valueChanged, [labelScale](int value) {
    labelScale->setText(QString("%0").arg(value));
  });

  connect(ui->Scale, SIGNAL(valueChanged(int)), this, SLOT(changeScale()));
  connect(ui->RotateX, SIGNAL(valueChanged(int)), this, SLOT(changeRotateX()));
  connect(ui->RotateY, SIGNAL(valueChanged(int)), this, SLOT(changeRotateY()));
  connect(ui->RotateZ, SIGNAL(valueChanged(int)), this, SLOT(changeRotateZ()));

  connect(ui->MoveX, SIGNAL(valueChanged(int)), this, SLOT(changeMoveX()));
  connect(ui->MoveY, SIGNAL(valueChanged(int)), this, SLOT(changeMoveY()));
  connect(ui->MoveZ, SIGNAL(valueChanged(int)), this, SLOT(changeMoveZ()));

  connect(ui->button_jpeg, SIGNAL(clicked()), this, SLOT(on_screenshotButton_clicked()));
  connect(ui->button_bmp, SIGNAL(clicked()), this, SLOT(on_screenshotButton_clicked()));

  connect(ui->button_gif, SIGNAL(clicked()), this, SLOT(gif_button_clicked()));

  connect(timer, SIGNAL(timeout()), this, SLOT(add_frame_to_gif_on_timeout()));



  //  connect(ui->color_edges,SIGNAL(clicked()),this,SLOT(setColorEdges()));
  //  connect(ui->color_verticies,SIGNAL(clicked()),this,SLOT(setColorVerticies()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_choose_OBJFile_clicked() {
  QString file = QFileDialog::getOpenFileName(this, "Choose File", "../../../../../src/models");
  if (!file.isEmpty()) {
    ui->label_9->setText(file);
    QByteArray file_bit = file.toLocal8Bit();
    char *fileName = file_bit.data();
    data_obj = (ObjData_t *)calloc(1, sizeof(ObjData_t));
    parse_file(data_obj, fileName);
    ui->edges->setText(QString::number(data_obj->index_array_size / 2));
    ui->verticies->setText(
        QString::number(data_obj->vertex_array.coords_number / 3));
    ui->openGLWidget->getModelData(data_obj);
    init();
    ui->openGLWidget->update();
  }
}

void MainWindow::init() {
  ui->Scale->setValue(50);
  ui->RotateX->setValue(0);
  ui->RotateY->setValue(0);
  ui->RotateZ->setValue(0);
  ui->MoveX->setValue(0);
  ui->MoveY->setValue(0);
  ui->MoveZ->setValue(0);
}


void MainWindow::changeScale() {
  if (data_obj) {

      double newSliderValue = (double)ui->Scale->value();

    if (newSliderValue != 50) {

      s21_create_matrix(data_obj->vertex_array.coords_number / 3, 4, &ui->openGLWidget->data_matrix);
      conv_to_matr(data_obj, &ui->openGLWidget->data_matrix);

      model_move(&ui->openGLWidget->data_matrix, 'x', 0 - currentSliderValueMoveX);
      model_move(&ui->openGLWidget->data_matrix, 'y', 0 - currentSliderValueMoveY);
      model_move(&ui->openGLWidget->data_matrix, 'z', 0 - currentSliderValueMoveZ);

      model_scale(&ui->openGLWidget->data_matrix, newSliderValue / currentSliderValueScale);

      model_move(&ui->openGLWidget->data_matrix, 'x', currentSliderValueMoveX);
      model_move(&ui->openGLWidget->data_matrix, 'y', currentSliderValueMoveY);
      model_move(&ui->openGLWidget->data_matrix, 'z', currentSliderValueMoveZ);

      conv_from_matr(data_obj, &ui->openGLWidget->data_matrix);
      currentSliderValueScale = newSliderValue;

    }


    ui->openGLWidget->update();


  }

}

void MainWindow::changeRotateX() {
  if (data_obj) {

    double newSliderValue = (double)ui->RotateX->value() / 100;

    if (newSliderValue != 0) {

      s21_create_matrix(data_obj->vertex_array.coords_number / 3, 4, &ui->openGLWidget->data_matrix);
      conv_to_matr(data_obj, &ui->openGLWidget->data_matrix);

      model_move(&ui->openGLWidget->data_matrix, 'x', 0 - currentSliderValueMoveX);
      model_move(&ui->openGLWidget->data_matrix, 'y', 0 - currentSliderValueMoveY);
      model_move(&ui->openGLWidget->data_matrix, 'z', 0 - currentSliderValueMoveZ);


      model_rotate(&ui->openGLWidget->data_matrix, 'z', 0 - currentSliderValueRotateZ);
      model_rotate(&ui->openGLWidget->data_matrix, 'y', 0 - currentSliderValueRotateY);

      model_rotate(&ui->openGLWidget->data_matrix, 'x', newSliderValue - currentSliderValueRotateX);
      model_rotate(&ui->openGLWidget->data_matrix, 'y', currentSliderValueRotateY);
      model_rotate(&ui->openGLWidget->data_matrix, 'z', currentSliderValueRotateZ);

      model_move(&ui->openGLWidget->data_matrix, 'x', currentSliderValueMoveX);
      model_move(&ui->openGLWidget->data_matrix, 'y', currentSliderValueMoveY);
      model_move(&ui->openGLWidget->data_matrix, 'z', currentSliderValueMoveZ);

      conv_from_matr(data_obj, &ui->openGLWidget->data_matrix);
      currentSliderValueRotateX = newSliderValue;
    }

    ui->openGLWidget->update();
  }

}

void MainWindow::changeRotateY() {
  if (data_obj) {

    double newSliderValue = (double)ui->RotateY->value() / 100;

    if (newSliderValue != 0) {

      s21_create_matrix(data_obj->vertex_array.coords_number / 3, 4, &ui->openGLWidget->data_matrix);
      conv_to_matr(data_obj, &ui->openGLWidget->data_matrix);

      model_move(&ui->openGLWidget->data_matrix, 'x', 0 - currentSliderValueMoveX);
      model_move(&ui->openGLWidget->data_matrix, 'y', 0 - currentSliderValueMoveY);
      model_move(&ui->openGLWidget->data_matrix, 'z', 0 - currentSliderValueMoveZ);


      model_rotate(&ui->openGLWidget->data_matrix, 'z', 0 - currentSliderValueRotateZ);
      model_rotate(&ui->openGLWidget->data_matrix, 'x', 0 - currentSliderValueRotateX);

      model_rotate(&ui->openGLWidget->data_matrix, 'x', currentSliderValueRotateX);
      model_rotate(&ui->openGLWidget->data_matrix, 'y', newSliderValue - currentSliderValueRotateY);
      model_rotate(&ui->openGLWidget->data_matrix, 'z', currentSliderValueRotateZ);


      model_move(&ui->openGLWidget->data_matrix, 'x', currentSliderValueMoveX);
      model_move(&ui->openGLWidget->data_matrix, 'y', currentSliderValueMoveY);
      model_move(&ui->openGLWidget->data_matrix, 'z', currentSliderValueMoveZ);

      conv_from_matr(data_obj, &ui->openGLWidget->data_matrix);
      currentSliderValueRotateY = newSliderValue;
    }

    ui->openGLWidget->update();

  }
}

void MainWindow::changeRotateZ() {
  if (data_obj) {

    double newSliderValue = (double)ui->RotateZ->value() / 100;

    if (newSliderValue != 0) {

      s21_create_matrix(data_obj->vertex_array.coords_number / 3, 4, &ui->openGLWidget->data_matrix);
      conv_to_matr(data_obj, &ui->openGLWidget->data_matrix);

      model_move(&ui->openGLWidget->data_matrix, 'x', 0 - currentSliderValueMoveX);
      model_move(&ui->openGLWidget->data_matrix, 'y', 0 - currentSliderValueMoveY);
      model_move(&ui->openGLWidget->data_matrix, 'z', 0 - currentSliderValueMoveZ);


      model_rotate(&ui->openGLWidget->data_matrix, 'y', 0 - currentSliderValueRotateY);
      model_rotate(&ui->openGLWidget->data_matrix, 'x', 0 - currentSliderValueRotateX);


      model_rotate(&ui->openGLWidget->data_matrix, 'x', currentSliderValueRotateX);
      model_rotate(&ui->openGLWidget->data_matrix, 'y', currentSliderValueRotateY);
      model_rotate(&ui->openGLWidget->data_matrix, 'z', newSliderValue - currentSliderValueRotateZ);


      model_move(&ui->openGLWidget->data_matrix, 'x', currentSliderValueMoveX);
      model_move(&ui->openGLWidget->data_matrix, 'y', currentSliderValueMoveY);
      model_move(&ui->openGLWidget->data_matrix, 'z', currentSliderValueMoveZ);

      conv_from_matr(data_obj, &ui->openGLWidget->data_matrix);
      currentSliderValueRotateZ = newSliderValue;

    }

    ui->openGLWidget->update();

  }

}

void MainWindow::changeMoveX() {
  if (data_obj) {
    double newSliderValue = (double)ui->MoveX->value() / 100;
    if (newSliderValue != 0) {
      s21_create_matrix(data_obj->vertex_array.coords_number / 3, 4,
                        &ui->openGLWidget->data_matrix);
      conv_to_matr(data_obj, &ui->openGLWidget->data_matrix);
      model_move(&ui->openGLWidget->data_matrix, 'x',
                 newSliderValue - currentSliderValueMoveX);
      conv_from_matr(data_obj, &ui->openGLWidget->data_matrix);
      currentSliderValueMoveX = newSliderValue;
    }
    ui->openGLWidget->update();
  }
}

void MainWindow::changeMoveY() {
  if (data_obj) {
    double newSliderValue = (double)ui->MoveY->value() / 100;
    if (newSliderValue != 0) {
      s21_create_matrix(data_obj->vertex_array.coords_number / 3, 4,
                        &ui->openGLWidget->data_matrix);
      conv_to_matr(data_obj, &ui->openGLWidget->data_matrix);
      model_move(&ui->openGLWidget->data_matrix, 'y',
                 newSliderValue - currentSliderValueMoveY);
      conv_from_matr(data_obj, &ui->openGLWidget->data_matrix);
      currentSliderValueMoveY = newSliderValue;
    }
    ui->openGLWidget->update();
  }
}

void MainWindow::changeMoveZ() {
  if (data_obj) {
    double newSliderValue = (double)ui->MoveZ->value() / 100;
    if (newSliderValue != 0) {
      s21_create_matrix(data_obj->vertex_array.coords_number / 3, 4,
                        &ui->openGLWidget->data_matrix);
      conv_to_matr(data_obj, &ui->openGLWidget->data_matrix);
      model_move(&ui->openGLWidget->data_matrix, 'z',
                 newSliderValue - currentSliderValueMoveZ);
      conv_from_matr(data_obj, &ui->openGLWidget->data_matrix);
      currentSliderValueMoveZ = newSliderValue;
    }
    ui->openGLWidget->update();
  }
}

// void MainWindow::setColorVerticies() {
//     QColor color = QColorDialog::getColor();
//         if (color.isValid()) {
//             *vertex_color = color;
//             ui->openGLWidget->color_vertex = vertex_color;
//             ui->openGLWidget->update();
//         }
// }

void MainWindow::on_color_edges_clicked() {
  QColor color = QColorDialog::getColor();
  if (color.isValid()) {
    *edges_color = color;
    ui->openGLWidget->color_edge = edges_color;
    ui->openGLWidget->update();
  }
}

void MainWindow::on_color_verticies_clicked() {
  QColor color = QColorDialog::getColor();
  if (color.isValid()) {
    *vertex_color = color;
    ui->openGLWidget->color_vertex = vertex_color;
    ui->openGLWidget->update();
  }
}
























/** tendyrir screenshot hard coding skills **/

void MainWindow::on_screenshotButton_clicked() {
    QPushButton *btn = (QPushButton *)sender();
    QString butVal = btn->text();
    QString filename;
    if (QString::compare(butVal, "bmp") == 0) {
        filename = QFileDialog::getSaveFileName(this, tr("Save screenshot bmp"), pathProject, tr("BMP files (*.bmp)"));
    } else if (QString::compare(butVal, "jpeg") == 0) {
        filename = QFileDialog::getSaveFileName(this, tr("Save screenshot jpeg"), pathProject, tr("JPEG files (*.jpeg)"));
    }
    QImage screenshot = ui->openGLWidget->grabFramebuffer();
    screenshot.save(filename, nullptr, 80);
}


void MainWindow::gif_button_clicked() {
    timer->start(100); // 100 милисекунд = 1/10 секунды * 50 = 50 кадров за 5 секунд
    ui->button_gif->setDisabled(true); // <--- отключаем кнопку на время записи
    add_frame_to_gif_on_timeout();
    frames_count = 0;
}

void MainWindow::add_frame_to_gif_on_timeout() {
    if (frames_count <= 50) {
//        gif.push_back(ui->openGLWidget->grab().toImage()); // push_back() - вставка в конец вектора
        gif.push_back(ui->openGLWidget->grabFramebuffer());
        frames_count++;
    } else {
        save_gif_file();
        timer->stop();
    }
}

void MainWindow::save_gif_file() {
    QString filename = QFileDialog::getSaveFileName(this, tr("Save gif"), pathProject, tr("GIF files (*.gif)"));
    if (!filename.isNull()) {

//    QGifImage gif_file(QSize(ui->openGLWidget->width() * 2, ui->openGLWidget->height() * 2));
        QGifImage gif_file(QSize(ui->openGLWidget->width() * 2, ui->openGLWidget->height() * 2));


        gif_file.setDefaultDelay(100); //выставляем задержку
        for (QVector<QImage>::Iterator frames = gif.begin(); frames != gif.end(); frames++) {
            gif_file.addFrame(*frames);
        }
        gif_file.save(filename);
    }
    gif.clear();
    frames_count = 0;
    ui->button_gif->setEnabled(true); // <--- в конце включаем кнопку
}



