#include "scoredialog.h"

ScoreDialog::ScoreDialog(QWidget *parent):
    QDialog(parent)
{
    setWindowTitle("保存");
    //baseWidget = new QWidget(parent);
    label = new QLabel("请输入你的尊姓大名");
    lineEdit = new QLineEdit();
    QRegExp rx;
    rx.setPattern("[a-zA-Z0-9]{1,20}");
    lineEdit->setValidator(new QRegExpValidator(rx,lineEdit));
    confirmButton = new QPushButton("确认");
    vbox = new QVBoxLayout(this);
    vbox->addWidget(label);
    vbox->addWidget(lineEdit);
    vbox->addWidget(confirmButton);
    connect(confirmButton,&QPushButton::clicked,this,&ScoreDialog::confirm);
}

ScoreDialog::~ScoreDialog()
{

}

void ScoreDialog::confirm()
{
    emit(name(lineEdit->text()));
}
