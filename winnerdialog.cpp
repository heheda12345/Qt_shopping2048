#include "winnerdialog.h"

winnerDialog::winnerDialog(QWidget *parent):
            QDialog(parent)
{
    setWindowTitle("现在是奖励时间");
    //baseWidget = new QWidget(parent);
    vbox = new QVBoxLayout(this);
    label = new QLabel(QString("请选择你想要的奖励"));
    vbox->addWidget(label);
    for (int i=0; i<8; i++)
    {
        rb[i] = new QRadioButton(name[i],this);
        vbox->addWidget(rb[i]);
    }
    confirmButton = new QPushButton("确认");
    vbox->addWidget(confirmButton);
    connect(confirmButton,&QPushButton::clicked,this,&winnerDialog::confirm);
    //e=new QCloseEvent();
}

winnerDialog::~winnerDialog()
{
    //QCloseEvent *e;
    delete label;
    delete confirmButton;
}

void winnerDialog::confirm()
{
    int choose=-1;
    for (int i=0; i<8; i++)
        if (rb[i]->isChecked())
            choose=i;
    if (choose==-1)
    {
        QMessageBox::information(this,"!","你竟然不愿意要我们的奖励TAT");
        return;
    }
    ps = new photoShower(this,choose);
    //connect(ps,&photoShower::opened,this,&winnerDialog::goReturn);
    ps->exec();
    goReturn();
}

void winnerDialog::goReturn()
{
    e = new QCloseEvent();
    QCoreApplication::sendEvent(this,e);
}

