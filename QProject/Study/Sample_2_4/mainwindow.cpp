#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actBold_triggered(bool checked)
{
    QTextCharFormat fmt = ui->txtEdit->currentCharFormat();
    fmt.setFontWeight(checked ? QFont::Bold : QFont::Normal);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}
void MainWindow::on_actItalic_triggered(bool checked)
{
    QTextCharFormat fmt = ui->txtEdit->currentCharFormat();
    fmt.setFontItalic(checked);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}

void MainWindow::on_actUnder_triggered(bool checked)
{
    QTextCharFormat fmt = ui->txtEdit->currentCharFormat();
    fmt.setFontUnderline(checked);
    ui->txtEdit->mergeCurrentCharFormat(fmt);
}
