#ifndef HELPDIALOG_H
#define HELPDIALOG_H

#include<QWidget>
#include<QDialog>
#include<QLabel>
#include<QLineEdit>
#include<QPushButton>
#include<QDialogButtonBox>
#include<QVBoxLayout>
#include<QMessageBox>
#include<QCloseEvent>
#include<QCoreApplication>
#include<QDebug>

class Helpdialog: public QDialog
{
    Q_OBJECT
public:
    Helpdialog(QWidget *parent=0);
    ~Helpdialog();
    bool textRight() { return text_right;}

protected:
     void closeEvent(QCloseEvent *event);

private:
    const QString text;
    QWidget* baseWidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *confirmButton, *cancelButton;
    QDialogButtonBox *btnBox;
    QVBoxLayout *vbox;
    QCloseEvent *e;
    bool text_right;
private slots:
    void confirm();
    //void cancel();

};

#endif // HELPDIALOG_H
