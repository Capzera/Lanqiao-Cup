#ifndef QWDLGMANUAL_H
#define QWDLGMANUAL_H

#include <QDialog>
#include <QCheckBox>
#include <QPushButton>
#include <QRadioButton>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>

class QWDlgManual : public QDialog {
    Q_OBJECT

public:
    QWDlgManual(QWidget *parent = 0);
    ~QWDlgManual();
public slots:
    void on_chkBoxUnder(bool checked);
    void on_chkBoxItalic(bool checked);
    void on_chkBoxBold(bool checked);
    void on_BtnCancel();
    void setTextColor();
private:
    QCheckBox *chkBoxBold, *chkBoxItalic, *chkBoxUnder;
    QPushButton *btnClose, *btnOK, *btnCancel;
    QRadioButton *rBtnBlack, *rBtnBlue, *rBtnRed;
    QPlainTextEdit *txtEdit;
    void init();
};

#endif // QWDLGMANUAL_H
