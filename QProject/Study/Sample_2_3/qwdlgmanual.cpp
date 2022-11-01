#include "qwdlgmanual.h"

QWDlgManual::QWDlgManual(QWidget *parent) : QDialog(parent){
    init();
    setWindowTitle("Font Designer V2.0 By:机长大大");
    setFixedSize(440, 320);
}

QWDlgManual::~QWDlgManual() {

}

void QWDlgManual::init() {
    chkBoxBold = new QCheckBox(tr("粗体"));
    chkBoxItalic = new QCheckBox(tr("斜体"));
    chkBoxUnder = new QCheckBox(tr("下划线"));
    QHBoxLayout *HL1 = new QHBoxLayout;
    HL1->addWidget(chkBoxBold);
    HL1->addWidget(chkBoxItalic);
    HL1->addWidget(chkBoxUnder);

    rBtnBlack = new QRadioButton(tr("黑色"));
    rBtnRed = new QRadioButton(tr("红色"));
    rBtnBlue = new QRadioButton(tr("蓝色"));
    rBtnBlack->setChecked(true);
    QHBoxLayout *HL2 = new QHBoxLayout;
    HL2->addWidget(rBtnBlack);
    HL2->addWidget(rBtnRed);
    HL2->addWidget(rBtnBlue);

    btnOK = new QPushButton(tr("确 定"));
    btnCancel = new QPushButton(tr("清 除"));
    btnClose = new QPushButton(tr("退 出"));
    QHBoxLayout *HL3 = new QHBoxLayout;
    HL3->addWidget(btnOK);
    HL3->addWidget(btnCancel);
    HL3->addStretch();
    HL3->addWidget(btnClose);

    txtEdit = new QPlainTextEdit;
    txtEdit->setPlainText("请在此处输入文字");
    QFont font = txtEdit->font();
    font.setPointSize(20);
    txtEdit->setFont(font);

    QVBoxLayout *VL = new QVBoxLayout;
    VL->addLayout(HL1);
    VL->addLayout(HL2);
    VL->addWidget(txtEdit);
    VL->addLayout(HL3);
    setLayout(VL);

    connect(chkBoxBold, SIGNAL(toggled(bool)), this, SLOT(on_chkBoxBold(bool)));
    connect(chkBoxItalic, SIGNAL(toggled(bool)), this, SLOT(on_chkBoxItalic(bool)));
    connect(chkBoxUnder, SIGNAL(toggled(bool)), this, SLOT(on_chkBoxUnder(bool)));
    connect(rBtnBlack, SIGNAL(toggled(bool)), this, SLOT(setTextColor()));
    connect(rBtnBlue, SIGNAL(toggled(bool)), this, SLOT(setTextColor()));
    connect(rBtnRed, SIGNAL(toggled(bool)), this, SLOT(setTextColor()));
    connect(btnOK, SIGNAL(clicked(bool)), this, SLOT(accept()));
    connect(btnCancel, SIGNAL(clicked(bool)), this, SLOT(on_BtnCancel()));
    connect(btnClose, SIGNAL(clicked(bool)), this, SLOT(close()));
}

void QWDlgManual::on_chkBoxBold(bool checked) {
    QFont font = txtEdit->font();
    font.setBold(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::on_chkBoxItalic(bool checked) {
    QFont font = txtEdit->font();
    font.setItalic(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::on_chkBoxUnder(bool checked) {
    QFont font = txtEdit->font();
    font.setUnderline(checked);
    txtEdit->setFont(font);
}

void QWDlgManual::on_BtnCancel() {
    rBtnBlack->setChecked(true);
    rBtnBlue->setChecked(false);
    rBtnRed->setChecked(false);
    chkBoxBold->setChecked(false);
    chkBoxItalic->setChecked(false);
    chkBoxUnder->setChecked(false);
}

void QWDlgManual::setTextColor() {
    QPalette palette = txtEdit->palette();
    if (rBtnBlue->isChecked())
        palette.setColor(QPalette::Text, Qt::blue);
    else if (rBtnRed->isChecked())
        palette.setColor(QPalette::Text, Qt::red);
    else palette.setColor(QPalette::Text, Qt::black);
    txtEdit->setPalette(palette);
}
