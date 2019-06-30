#include "choosedialog.h"
#include <QDebug>

ChooseDialog::ChooseDialog(QWidget *parent) :
                QDialog(parent)
{
    resize(16*MUL,4*MUL);
    setWindowTitle("你面临一个抉择");
    exit_pressed=0;

    L=new QPushButton(this);
    L->setText("慧文爹爹更牛");
    L->setIconSize(QSize(4*MUL,1*MUL));
    L->setGeometry(QRect(3*MUL,2*MUL+MUL/2,4*MUL,1*MUL));
    L->setFlat(true);

    Z=new QPushButton(this);
    Z->setText("张晨叔叔更牛");
    Z->setIconSize(QSize(4*MUL,1*MUL));
    Z->setGeometry(QRect(9*MUL,2*MUL+MUL/2,4*MUL,1*MUL));
    Z->setFlat(true);

    E=new QPushButton(this);
    E->setGeometry(QRect(0,0,MUL,MUL));
    E->setFlat(true);

    connect(L,&QPushButton::clicked,this,&ChooseDialog::L_newmessage);
    connect(Z,&QPushButton::clicked,this,&ChooseDialog::Z_newmessage);
    connect(E,&QPushButton::clicked,this,&ChooseDialog::E_pressing);

    e=new QCloseEvent();
}

ChooseDialog::~ChooseDialog()
{
    delete Z;
    delete L;
    delete E;
    delete e;
}

void ChooseDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawText(4*MUL,1*MUL,"慧文和晨神谁更牛？");
}

void ChooseDialog::L_newmessage()
{
    QMessageBox::information(this, tr("Hmmm..."), tr("放肆！！！ ————zc\n再给你一次机会"));
}

void ChooseDialog::Z_newmessage()
{
    QMessageBox::information(this, tr("Hmmm..."), tr("猖狂！！！ ————lhw\n再给你一次机会"));
}

void ChooseDialog::closeEvent(QCloseEvent *event)
{
    qDebug() << "Enter close Event!";
    if (!exit_press())
    {
        QMessageBox::information(this,"Hmmm....","年轻人连选择的勇气都没有吗？");
        event->ignore();
    }
    //event->accept(); 允许关闭
}
