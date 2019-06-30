#ifndef WINNERDIALOG_H
#define WINNERDIALOG_H

#include <QObject>
#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPalette>
#include <QIntValidator>
#include <QRadioButton>
#include <QMessageBox>
#include <constants.h>
#include "photoshower.h"
#include <QCloseEvent>
#include <QCoreApplication>

class winnerDialog : public QDialog
{
    Q_OBJECT
public:
    winnerDialog(QWidget *parent=0);
    ~winnerDialog();

protected:
     //void closeEvent(QCloseEvent *event);

private:
    //QCloseEvent *e;
    QLabel *label;
    QPushButton *confirmButton;
    QRadioButton *rb[8];
    QVBoxLayout *vbox;
    void goReturn();
    QCloseEvent *e;
    photoShower *ps;
private slots:
    void confirm();

};

#endif // WINNERDIALOG_H
