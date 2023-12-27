#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "openglcore.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>
#include "chartview.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);



    connect(ui->xSlider, &QSlider::valueChanged, ui->widgetOgl, &OpenGlCore::xRotate);
    connect(ui->ySlider, &QSlider::valueChanged, ui->widgetOgl, &OpenGlCore::yRotate);
    connect(ui->zSlider, &QSlider::valueChanged, ui->widgetOgl, &OpenGlCore::zRotate);

}

MainWindow::~MainWindow()
{
    delete ui;
}
