#include "mainwindow.h"

//#include "../gifimage/qgifimage.h"

#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setWindowTitle("3D Viewer");

  timer = new QTimer(this);

  settings = new QSettings("Setting", "3DViewer", this);
  
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

  connect(ui->edge_size, SIGNAL(valueChanged(int)), this, SLOT(edge_size_valueChanged()));
  connect(ui->vertex_size, SIGNAL(valueChanged(int)), this, SLOT(vertex_size_valueChanged()));
}

MainWindow::~MainWindow() {
    save_settings();
    delete ui;
}

void MainWindow::on_choose_OBJFile_clicked() {
  QString file = QFileDialog::getOpenFileName(this, "Choose File", "../../../../../src/models");
  if (!file.isEmpty()) {
    init();
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
  changeScale();
  ui->RotateX->setValue(0);
  changeRotateX();
  ui->RotateY->setValue(0);
  changeRotateY();
  ui->RotateZ->setValue(0);
  changeRotateZ();
  ui->MoveX->setValue(0);
  changeMoveX();
  ui->MoveY->setValue(0);
  changeMoveY();
  ui->MoveZ->setValue(0);
  changeMoveZ();
  ui->edge_size->setValue(1);
  ui->vertex_size->setValue(1);
  ui->edge_solid->setChecked(1);
  ui->edge_dashed->setChecked(0);
  ui->radioButton_2->setChecked(1);
  ui->radioButton->setChecked(0);
  ui->vertex_circle->setChecked(0);
  ui->vertex_square->setChecked(0);
  ui->vertex_disable->setChecked(0);
  *back_color = QColor(0, 0, 0, 255);
  ui->openGLWidget->color_back = back_color;
  *edges_color = QColor(214, 214, 214, 255);
  ui->openGLWidget->color_edge = edges_color;
  *vertex_color = QColor(0, 0, 255, 255);
  ui->openGLWidget->color_vertex = vertex_color;
}


void MainWindow::changeScale() {
  if (data_obj) {
    double newSliderValue = (double)ui->Scale->value();
//    if (newSliderValue != 50) {
      s21_create_matrix(data_obj->vertex_array.coords_number / 3, 4,
                        &ui->openGLWidget->data_matrix);
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
//    }
    ui->openGLWidget->update();


  }

}

void MainWindow::changeRotateX() {
  if (data_obj) {

    double newSliderValue = (double)ui->RotateX->value() / 100;
//    if (newSliderValue != 0) {
      s21_create_matrix(data_obj->vertex_array.coords_number / 3, 4,
                        &ui->openGLWidget->data_matrix);
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
//    }
    ui->openGLWidget->update();
  }

}

void MainWindow::changeRotateY() {
  if (data_obj) {

    double newSliderValue = (double)ui->RotateY->value() / 100;
//    if (newSliderValue != 0) {
      s21_create_matrix(data_obj->vertex_array.coords_number / 3, 4,
                        &ui->openGLWidget->data_matrix);
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
//    }
    ui->openGLWidget->update();

  }
}

void MainWindow::changeRotateZ() {
  if (data_obj) {

    double newSliderValue = (double)ui->RotateZ->value() / 100;
//    if (newSliderValue != 0) {
      s21_create_matrix(data_obj->vertex_array.coords_number / 3, 4,
                        &ui->openGLWidget->data_matrix);
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
//    }
    ui->openGLWidget->update();

  }

}

void MainWindow::changeMoveX() {
  if (data_obj) {
    double newSliderValue = (double)ui->MoveX->value() / 100;
//    if (newSliderValue != 0) {
      s21_create_matrix(data_obj->vertex_array.coords_number / 3, 4,
                        &ui->openGLWidget->data_matrix);
      conv_to_matr(data_obj, &ui->openGLWidget->data_matrix);
      model_move(&ui->openGLWidget->data_matrix, 'x',
                 newSliderValue - currentSliderValueMoveX);
      conv_from_matr(data_obj, &ui->openGLWidget->data_matrix);
      currentSliderValueMoveX = newSliderValue;
//    }
    ui->openGLWidget->update();
  }
}

void MainWindow::changeMoveY() {
  if (data_obj) {
    double newSliderValue = (double)ui->MoveY->value() / 100;
//    if (newSliderValue != 0) {
      s21_create_matrix(data_obj->vertex_array.coords_number / 3, 4,
                        &ui->openGLWidget->data_matrix);
      conv_to_matr(data_obj, &ui->openGLWidget->data_matrix);
      model_move(&ui->openGLWidget->data_matrix, 'y',
                 newSliderValue - currentSliderValueMoveY);
      conv_from_matr(data_obj, &ui->openGLWidget->data_matrix);
      currentSliderValueMoveY = newSliderValue;
//    }
    ui->openGLWidget->update();
  }
}

void MainWindow::changeMoveZ() {
  if (data_obj) {
    double newSliderValue = (double)ui->MoveZ->value() / 100;
//    if (newSliderValue != 0) {
      s21_create_matrix(data_obj->vertex_array.coords_number / 3, 4,
                        &ui->openGLWidget->data_matrix);
      conv_to_matr(data_obj, &ui->openGLWidget->data_matrix);
      model_move(&ui->openGLWidget->data_matrix, 'z',
                 newSliderValue - currentSliderValueMoveZ);
      conv_from_matr(data_obj, &ui->openGLWidget->data_matrix);
      currentSliderValueMoveZ = newSliderValue;
//    }
    ui->openGLWidget->update();
  }
}

void MainWindow::on_color_background_clicked() {
    QColor color = QColorDialog::getColor();
    if (color.isValid()) {
      *back_color = color;
      ui->openGLWidget->color_back = back_color;
      ui->openGLWidget->update();
    }
}

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

void MainWindow::edge_size_valueChanged() {
    ui->openGLWidget->line_size = ui->edge_size->value();
    ui->openGLWidget->update();
}

void MainWindow::vertex_size_valueChanged() {
    ui->openGLWidget->point_size = ui->vertex_size->value();
    ui->openGLWidget->update();
}

void MainWindow::on_radioButton_toggled(bool checked) {
    if (checked) {
        ui->openGLWidget->central_perspective = true;
    } else {
        ui->openGLWidget->central_perspective = false;
    }
    ui->openGLWidget->update();
}

void MainWindow::on_edge_dashed_toggled(bool checked) {
    if (checked) {
        ui->openGLWidget->edge_mood = 1; // dashed
    } else {
        ui->openGLWidget->edge_mood = 0; // solid
    }
    ui->openGLWidget->update();
}

void MainWindow::on_vertex_circle_toggled(bool checked) {
    if (checked) {
        ui->openGLWidget->vertex_circle = 1;
        ui->openGLWidget->vertex_square = 0;
        ui->openGLWidget->vertex_disable = 0;
    }
    ui->openGLWidget->update();
}

void MainWindow::on_vertex_square_toggled(bool checked) {
    if (checked) {
        ui->openGLWidget->vertex_square = 1;
        ui->openGLWidget->vertex_circle = 0;
        ui->openGLWidget->vertex_disable = 0;
    }
    ui->openGLWidget->update();
}

void MainWindow::on_vertex_disable_toggled(bool checked) {
    if (checked) {
        ui->openGLWidget->vertex_disable = 1;
        ui->openGLWidget->vertex_circle = 0;
        ui->openGLWidget->vertex_square = 0;
    }
    ui->openGLWidget->update();
}

void MainWindow::save_settings() {
    settings->setValue("color_background", *ui->openGLWidget->color_back);
    settings->setValue("color_edges", *ui->openGLWidget->color_edge);
    settings->setValue("color_vertex", *ui->openGLWidget->color_vertex);

    settings->setValue("vertex_circle", ui->openGLWidget->vertex_circle);
    settings->setValue("vertex_square", ui->openGLWidget->vertex_square);
    settings->setValue("vertex_size", ui->openGLWidget->point_size);

    settings->setValue("edge_size", ui->openGLWidget->line_size);
    settings->setValue("edge_dashed", ui->openGLWidget->edge_mood);

    settings->setValue("radioButton", ui->openGLWidget->central_perspective);
}

void MainWindow::on_load_settings_clicked() {
    ui->openGLWidget->central_perspective = settings->value("radioButton").toBool();
    if(ui->openGLWidget->central_perspective) ui->radioButton->setChecked(1);
    else ui->radioButton_2->setChecked(1);

    *back_color = settings->value("color_background").toByteArray().constData();
    ui->openGLWidget->color_back = back_color;
    *edges_color = settings->value("color_edges").toByteArray().constData();
    ui->openGLWidget->color_edge = edges_color;
    *vertex_color = settings->value("color_vertex").toByteArray().constData();
    ui->openGLWidget->color_vertex = vertex_color;

    if(settings->value("vertex_circle").toBool()) {
        ui->openGLWidget->vertex_circle = 1;
        ui->vertex_circle->setChecked(1);
    } else if (settings->value("vertex_square").toBool()) {
        ui->openGLWidget->vertex_square = 1;
        ui->vertex_square->setChecked(1);
    } else if (settings->value("vertex_disable").toBool()) {
        ui->openGLWidget->vertex_disable = 1;
        ui->vertex_disable->setChecked(1);
    }

    ui->openGLWidget->point_size = settings->value("vertex_size").toDouble();
    ui->vertex_size->setValue(ui->openGLWidget->point_size);

    ui->openGLWidget->line_size = settings->value("edge_size").toDouble();
    ui->edge_size->setValue(ui->openGLWidget->line_size);

    ui->openGLWidget->edge_mood = settings->value("edge_dashed").toBool();
    if(ui->openGLWidget->edge_mood) ui->edge_dashed->setChecked(1);
    else ui->edge_solid->setChecked(1);

    ui->openGLWidget->update();
}

void MainWindow::on_reset_settings_clicked()
{
    init();
    ui->openGLWidget->update();
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



