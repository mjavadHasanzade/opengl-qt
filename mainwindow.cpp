#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "openglcore.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


//    connect(ui->xSlider, &QSlider::valueChanged, &OpenGlCore, &OpenGlCore::xRotate);


}

MainWindow::~MainWindow()
{
    delete ui;
}

