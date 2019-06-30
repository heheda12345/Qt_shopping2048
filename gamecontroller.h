#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include<QWidget>
#include<QObject>
#include<cstring>
#include<string>
#include<QPainter>
#include<QKeyEvent>
#include<QDebug>
#include<QPushButton>
#include<winnerdialog.h>
#include<QDialog>
#include<QPalette>
#include<QCloseEvent>
#include<QMessageBox>
#include<QLineEdit>
#include<vector>
#include<fstream>
#include"constants.h"
#include"picturepath.h"
#include"helpdialog.h"
#include"choosedialog.h"
#include"scoredialog.h"
#include"mover.h"
#include"usermessage.h"
#include<iostream>
#include<rankdialog.h>

class GameController : public QDialog
{
    Q_OBJECT
public:
    explicit GameController(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    //void show();
    ~GameController();

private:
    Mover *mover;
    QPushButton *btn_up,*btn_down,*btn_left,*btn_right;
    QPushButton *btn_help,*btn_return,*btn_c,*btn_z,*btn_l;
    winnerDialog *wd;
    Helpdialog *hd;
    ChooseDialog *cd;
    QCloseEvent *e;
    ScoreDialog *sd;
    void checkWin();
    bool win,gdie;
    void scoreStore();
protected:
//    bool eventFilter(QObject *obj, QEvent *event);
    void keyPressEvent(QKeyEvent *e);
    void closeEvent(QCloseEvent *e);
signals:
    void die();
    void signal_left();
    void signal_right();
    void signal_up();
    void signal_down();

private slots:
    void goUp();
    void goDown();
    void goLeft();
    void goRight();
    void newround();
    void showHelp();
    void showL();
    void showZ();
    void showC();
    void goReturn();
    void saveName(QString name);
};

#endif // GAMECONTROLLER_H
