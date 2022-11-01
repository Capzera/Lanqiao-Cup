#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) : QDialog(parent), ui(new Ui::Dialog) {
    ui->setupUi(this);
    connect(ui->rBtnBlack, SIGNAL(clicked(bool)), this, SLOT(setTextColor()));
    connect(ui->rBtnBlue, SIGNAL(clicked(bool)), this, SLOT(setTextColor()));
    connect(ui->rBtnRed, SIGNAL(clicked(bool)), this, SLOT(setTextColor()));
}

Dialog::~Dialog() {
    delete ui;
}

void Dialog::on_chkBoxUnder_clicked(bool checked) {
    QFont font = ui->txtEdit->font();
    font.setUnderline(checked);
    ui->txtEdit->setFont(font);
}

void Dialog::on_chkBoxItalic_clicked(bool checked) {
    QFont font = ui->txtEdit->font();
    font.setItalic(checked);
    ui->txtEdit->setFont(font);
}


void Dialog::on_chkBoxBold_clicked(bool checked) {
    QFont font = ui->txtEdit->font();
    font.setBold(checked);
    ui->txtEdit->setFont(font);
}

void Dialog::setTextColor(){
    QPalette palette = ui->txtEdit->palette();
    if (ui->rBtnBlack->isChecked())
        palette.setColor(QPalette::Text, Qt::black);
    else if (ui->rBtnBlue->isChecked())
        palette.setColor(QPalette::Text, Qt::blue);
    else if (ui->rBtnRed->isChecked())
        palette.setColor(QPalette::Text, Qt::red);
    else palette.setColor(QPalette::Text, Qt::black);
    ui->txtEdit->setPalette(palette);
}
