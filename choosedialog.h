#ifndef CHOOSEDIALOG_H
#define CHOOSEDIALOG_H

#include<QDialog>
#include<QPainter>
#include<QPushButton>
#include<QMessageBox>
#include<QCloseEvent>
#include"constants.h"

class ChooseDialog : public QDialog
{
    Q_OBJECT

public:
    ChooseDialog(QWidget *parent = 0);
    ~ChooseDialog();
    bool exit_press() { return exit_pressed;}

protected:
    void paintEvent(QPaintEvent *);
    void closeEvent(QCloseEvent *event);

private:
    QPushButton *Z,*L,*E;
    bool exit_pressed;
    QCloseEvent *e;

private slots:
    void L_newmessage();
    void Z_newmessage();
    void E_pressing() { exit_pressed=1; }

};

#endif // CHOOSEDIALOG_H
