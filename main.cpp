#include "mainwindow.h"
#include "welcomedialog.h"
#include <QApplication>
#include <QObject>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setQuitOnLastWindowClosed(true);

    welcomeDialog *dia = new welcomeDialog();
    QObject::connect(dia,&welcomeDialog::closed,&a,&QApplication::quit);

    dia->show();

    return a.exec();
}
