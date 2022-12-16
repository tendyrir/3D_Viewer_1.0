#include "mainwindow.h"

#include "../gifimage/qgifimage.h"
#include "./ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  this->setWindowTitle("3D Viewer");

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
  connect(ui->button_gif, SIGNAL(clicked()), this, SLOT(on_gifButton_clicked()));

  connect(ui->edge_size, SIGNAL(valueChanged(int)), this, SLOT(edge_size_valueChanged()));
  connect(ui->vertex_size, SIGNAL(valueChanged(int)), this, SLOT(vertex_size_valueChanged()));
}

MainWindow::~MainWindow() { delete ui; }

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
  ui->openGLWidget->line_size = 1;
}

void MainWindow::changeScale() {
  if (data_obj) {
    double newSliderValue = (double)ui->Scale->value();
    if (newSliderValue != 50) {
      s21_create_matrix(data_obj->vertex_array.coords_number / 3, 4,
                        &ui->openGLWidget->data_matrix);
      conv_to_matr(data_obj, &ui->openGLWidget->data_matrix);
      model_scale(&ui->openGLWidget->data_matrix,
                  newSliderValue / currentSliderValueScale);
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
      s21_create_matrix(data_obj->vertex_array.coords_number / 3, 4,
                        &ui->openGLWidget->data_matrix);
      conv_to_matr(data_obj, &ui->openGLWidget->data_matrix);
      model_rotate(&ui->openGLWidget->data_matrix, 'x',
                   newSliderValue - currentSliderValueRotateX);
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
      s21_create_matrix(data_obj->vertex_array.coords_number / 3, 4,
                        &ui->openGLWidget->data_matrix);
      conv_to_matr(data_obj, &ui->openGLWidget->data_matrix);
      model_rotate(&ui->openGLWidget->data_matrix, 'y',
                   newSliderValue - currentSliderValueRotateY);
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
      s21_create_matrix(data_obj->vertex_array.coords_number / 3, 4,
                        &ui->openGLWidget->data_matrix);
      conv_to_matr(data_obj, &ui->openGLWidget->data_matrix);
      model_rotate(&ui->openGLWidget->data_matrix, 'z',
                   newSliderValue - currentSliderValueRotateZ);
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
        vertex_mood = 1; // circle
    }
    check_frame_vertex();
}

void MainWindow::on_vertex_square_toggled(bool checked) {
    if (checked) {
        vertex_mood = 2; // square
    }
    check_frame_vertex();
}

void MainWindow::on_vertex_disable_toggled(bool checked) {
    if (checked) {
        vertex_mood = 0; // disable
    }
    check_frame_vertex();
}

void MainWindow::check_frame_vertex() {
    if (vertex_mood == 0) {
        ui->openGLWidget->vertex_mood = 0;
    } else if (vertex_mood == 1) {
        ui->openGLWidget->vertex_mood = 1;
    } else {
        ui->openGLWidget->vertex_mood = 2;
    }
    ui->openGLWidget->update();
}
