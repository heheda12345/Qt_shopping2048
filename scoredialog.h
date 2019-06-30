#ifndef SCOREDIALOG_H
#define SCOREDIALOG_H

#include<QDialog>
#include<QObject>
#include<QLineEdit>
#include<QLabel>
#include<QPushButton>
#include<QCloseEvent>
#include<QRegExpValidator>
#include<QRegExp>
#include<QCoreApplication>
#include<QVBoxLayout>

class ScoreDialog : public QDialog
{
    Q_OBJECT
public:
    ScoreDialog(QWidget *parent);
    ~ScoreDialog();

private:
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *confirmButton;
    QCloseEvent *e;
    QVBoxLayout *vbox;
signals:
    void name(QString);

private slots:
    void confirm();

};

#endif // SCOREDIALOG_H
