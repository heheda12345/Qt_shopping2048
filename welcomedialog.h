#ifndef WELCOMEDIALOG_H
#define WELCOMEDIALOG_H
#include <QDialog>
#include <QTimer>
#include <QPushButton>
#include <QDebug>
#include<QCloseEvent>
#include<QCoreApplication>
#include "constants.h"
#include "picturepath.h"
#include "authordialog.h"
#include "gamecontroller.h"
#include "rankdialog.h"
#include <QMainWindow>

class welcomeDialog : public QMainWindow
{
    Q_OBJECT
public:
    welcomeDialog(QMainWindow *parent=0);
    ~welcomeDialog();
    void showWelcome();

private:
    QPushButton *btn1,*btn2,*btn3,*btn4;
    authorDialog *ad;
    QCloseEvent *e;
    GameController *gd;
    rankDialog *rd;

signals:
    void closed();

private slots:
    void showMainWindow();
    void go();
    void clickAuthor();
    void clickExit();
    void clickBegin();
    void clickRank();
};

#endif // WELCOMEDIALOG_H
