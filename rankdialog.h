#ifndef RANKDIALOG_H
#define RANKDIALOG_H

#include <QDialog>
#include<usermessage.h>
#include <vector>
#include <QScrollArea>
#include <QGridLayout>
#include <QLabel>
#include <QPalette>
#include <QFont>
#include <QFile>
#include <QDebug>
#include <QPushButton>
#include <QCoreApplication>
#include <QCloseEvent>
#include "constants.h"
#include "picturepath.h"

using std::vector;

class rankDialog : public QDialog
{
    Q_OBJECT
public:
    rankDialog(QWidget *parent = 0);
    rankDialog(QWidget *parent, UserMessage &vec);
    ~rankDialog();

private:
    QGridLayout *grid;
    vector<QLabel*> lab1,lab2;
    QLabel *head1,*head2,*e1,*e2,*e3,*e4,*e5;
    QPushButton *btn_return;
    QCloseEvent *e;
    void print();
    void goReturn();
    void add(UserMessage mes);

signals:

public slots:
};

#endif // RANKDIALOG_H
