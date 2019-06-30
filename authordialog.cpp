
#include "authordialog.h"

authorDialog::authorDialog(QWidget *parent):
    QDialog(parent)
{
    this->resize(700,500);

    btn=new QPushButton(this);
    btn->setIconSize(QSize(800,500));
    btn->setGeometry(QRect(-50,0,800,500));
    btn->setFlat(true);
    btn->setIcon(QIcon(PC(gameBase,4)));
    btn->show();

    connect(btn,&QPushButton::clicked,this,&authorDialog::ret);
}

authorDialog::~authorDialog()
{
    delete btn;
    delete e;
}

void authorDialog::ret()
{
    e=new QCloseEvent();
    QCoreApplication::sendEvent(this,e);
}
