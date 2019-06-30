#ifndef AUTHORDIALOG_H
#define AUTHORDIALOG_H
#include<QObject>
#include<QDialog>
#include<QWidget>
#include<QCloseEvent>
#include<QPushButton>
#include<QPalette>
#include<QCoreApplication>
#include<constants.h>
#include<picturepath.h>

class authorDialog : public QDialog
{
    Q_OBJECT
public:
    authorDialog(QWidget *parent=0);
    ~authorDialog();

private:
    QPushButton *btn;
    QCloseEvent *e;

private slots:
    void ret();

};

#endif // AUTHORDIALOG_H
