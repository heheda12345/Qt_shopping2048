#include "helpdialog.h"

Helpdialog::Helpdialog(QWidget *parent):
            QDialog(parent),
            text("慧文老爹，我将永远孝敬您")
{
    setWindowTitle("请完成下面的任务");
    //baseWidget = new QWidget(parent);
    label = new QLabel("请输入\""+text+"\"");//father
    lineEdit = new QLineEdit();

    confirmButton = new QPushButton("确认");
    cancelButton = new QPushButton("取消");
    btnBox = new QDialogButtonBox(Qt::Horizontal);
    btnBox->addButton(confirmButton, QDialogButtonBox::ActionRole);
    btnBox->addButton(cancelButton, QDialogButtonBox::ActionRole);

    vbox = new QVBoxLayout(this);
    vbox->addWidget(label);
    vbox->addWidget(lineEdit);
    vbox->addWidget(btnBox);

    connect(confirmButton,&QPushButton::clicked,this,&Helpdialog::confirm);

    e=new QCloseEvent();
    text_right = 0;
}

Helpdialog::~Helpdialog()
{
    delete baseWidget;
    delete label;
    delete lineEdit;
    delete confirmButton;
    delete cancelButton;
    delete btnBox;
    delete vbox;
    delete e;
}

void Helpdialog::closeEvent(QCloseEvent *event)
{
    if (textRight())
    {
        //qDebug()<<"text right!";
        QMessageBox::information(this,"Hmmm……","年轻人要自力更生，艰苦奋斗啊！");
        QDialog::closeEvent(event);
    }
    else
    {
        QMessageBox::information(this,"Hmmm....","小朋友你不是需要帮助吗？");
        event->ignore();
    }
    //event->accept(); 允许关闭
}

void Helpdialog::confirm()
{
    if (lineEdit->text() == text)
    {
        text_right = 1;
        QCoreApplication::sendEvent(this,e);
    }
    else
        QMessageBox::information(this,"Hmmm……","好好说话！");

}
