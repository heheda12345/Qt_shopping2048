#include "welcomedialog.h"

welcomeDialog::welcomeDialog(QMainWindow *parent)
    :QMainWindow(parent)
{
    showWelcome();
    QTimer::singleShot(1000,this,&welcomeDialog::showMainWindow);
}

welcomeDialog::~welcomeDialog()
{

}

void welcomeDialog::showWelcome()
{
    this->setWindowIcon(QIcon(PC(gameBase,1)));
    this->setWindowTitle("小平大冒险");
    this->resize(500,500);
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(PC(gameBase,2)).scaled(this->size())));
    this->setPalette(palette);
}

void welcomeDialog::showMainWindow()
{
    this->resize(800,500);
    this->setMaximumSize(800,500);
    this->setWindowIcon(QIcon(PC(gameBase,1)));

    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(PC(gameBase,3)).scaled(this->size())));
    this->setPalette(palette);

    btn1=new QPushButton(this);
    btn1->setIconSize(QSize(54*8,10*5));
    btn1->setGeometry(QRect(23*8,46*5,54*8,10*5));
    btn1->setFlat(true);
    btn1->show();

    btn2=new QPushButton(this);
    btn2->setIconSize(QSize(54*8,10*5));
    btn2->setGeometry(QRect(23*8,60*5,54*8,10*5));
    btn2->setFlat(true);
    btn2->show();

    btn3=new QPushButton(this);
    btn3->setIconSize(QSize(54*8,10*5));
    btn3->setGeometry(QRect(23*8,72*5,54*8,10*5));
    btn3->setFlat(true);
    btn3->show();

    btn4=new QPushButton(this);
    btn4->setIconSize(QSize(54*8,10*5));
    btn4->setGeometry(QRect(23*8,87*5,54*8,10*5));
    btn4->setFlat(true);
    btn4->show();

    QObject::connect(btn1,&QPushButton::clicked,this,&welcomeDialog::clickBegin);
    QObject::connect(btn2,&QPushButton::clicked,this,&welcomeDialog::clickRank);
    QObject::connect(btn3,&QPushButton::clicked,this,&welcomeDialog::clickAuthor);
    QObject::connect(btn4,&QPushButton::clicked,this,&welcomeDialog::clickExit);
}

void welcomeDialog::go()
{
    qDebug()<<"clicked!";
}

void welcomeDialog::clickAuthor()
{
    ad = new authorDialog(this);
    ad->exec();
}

void welcomeDialog::clickExit()
{
   emit closed();
}

void welcomeDialog::clickBegin()
{
    gd = new GameController(this);
    gd->show();
}

void welcomeDialog::clickRank()
{
    rd = new rankDialog(this);
    rd->show();
}
