#include "mainwindow.h"

#include "../gifimage/qgifimage.h"
#include "./ui_mainwindow.h"

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

void MainWindow::on_gifButton_clicked()
{
  QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), pathProject, tr("(*.gif)"));

  if (!filename.isEmpty()) {

    QGifImage gif(ui->openGLWidget->grab().size());
    gif.setDefaultDelay(100);

    for (int i = 0; i < 50; i++) {

      ui->Scale->setValue(50+i);
      changeScale();

      ui->RotateX->setValue(i);
      changeRotateX();

      QImage screenshot = ui->openGLWidget->grabFramebuffer();
      gif.addFrame(screenshot);
    }

    gif.save(filename);
  }

}
