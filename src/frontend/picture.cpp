#include "mainwindow.h"

#include "../gifimage/qgifimage.h"
#include "./ui_mainwindow.h"

/** tendyrir screenshot hard coding skills **/

void MainWindow::on_screenshotButton_clicked() {
    QPushButton *btn = (QPushButton *)sender();
    QString butVal = btn->text();
    QString filename;

    if (QString::compare(butVal, "bmp", Qt::CaseInsensitive) == 0) {
        filename = QFileDialog::getSaveFileName(this, tr("Save screenshot bmp"), pathProject, tr("BMP files (*.bmp)"));
    } else if (QString::compare(butVal, "jpeg", Qt::CaseInsensitive) == 0) {
        filename = QFileDialog::getSaveFileName(this, tr("Save screenshot jpeg"), pathProject, tr("JPEG files (*.jpeg)"));
    }

    QImage screenshot = ui->openGLWidget->grabFramebuffer();
    screenshot.save(filename, nullptr, 80);
}




void MainWindow::gif_button_clicked() {

/* таймер равен 100 милисекундам, что равно 1/10 секунды
 * нужно для 10-ти кадров в секунду
*/
    timer->start(100);
    add_frame_to_gif_on_timeout();
    frames_count = 0;
}

void MainWindow::add_frame_to_gif_on_timeout() {
    if (frames_count <= 50) {
        gif.push_back(ui->openGLWidget->grab().toImage()); // push_back() - вставка в конец вектора
        frames_count++;
    } else {
        save_gif_file();
        timer->stop();
    }
}

void MainWindow::save_gif_file() {
    QString filename = QFileDialog::getSaveFileName(this, tr("Save gif"), pathProject, tr("GIF files (*.gif)"));
    if (!filename.isNull()) {
    QGifImage gif_file(QSize(1100, 1100));
        gif_file.setDefaultDelay(100);
        for (QVector<QImage>::Iterator frames = gif.begin(); frames != gif.end(); frames++) {
            gif_file.addFrame(*frames);
        }
        gif_file.save(filename);
    }

    gif.clear();
    frames_count = 0;
}









//void MainWindow::start_timer() {
//    timer = new QTimer(this);
//    connect(timer, SIGNAL(timeout()), this, SLOT(change_time()));
//    timer->start(1000);
//}

//void MainWindow::change_time(QGifImage gif) {
//    add_frame_signal_count++;
//    QTime time = QTime::currentTime();
//    std::string count = std::to_string(add_frame_signal_count);
//    QString time_text = time_text.fromStdString(count);
//    ui->time_label->setText(time_text);
//     QString filename = QFileDialog::getSaveFileName(this, tr("Save File"), pathProject, tr("(*.gif)"));
//    if(add_frame_signal_count <= 50){
//        timer->start();
//        QImage screenshot = ui->openGLWidget->grabFramebuffer();
//        gif.addFrame(screenshot);
//    }else{
//        timer->stop();
//    }
//    gif.save(filename);
//}

//void MainWindow::start_timer() {
//}




