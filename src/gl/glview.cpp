#include "glview.h"
#include "./ui_glview.h"

glView::glView(QWidget *parent)
    : QOpenGLWidget(parent)
    , ui(new Ui::glView)
{
    ui->setupUi(this);
}

glView::~glView()
{
    delete ui;
}

void glView::on_choose_OBJFile_clicked() {
    QString filename = QFileDialog::getOpenFileName(this, "Choose File");
    if(filename.isEmpty())
        return;
    ui->label_9->setText(filename);
}
