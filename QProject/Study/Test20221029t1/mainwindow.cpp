#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setFixedSize(640, 480);
    QPushButton* bt1 = new QPushButton(this);
    bt1->setText("陈启航爱秦婧");
    bt1->setFlat(false);
    bt1->setGeometry(270, 190, 100, 100);
}

MainWindow::~MainWindow()
{
    delete ui;
}
