#ifndef PHOTOSHOWER_H
#define PHOTOSHOWER_H
#include <QDialog>
#include "constants.h"
#include "picturepath.h"

class photoShower : public QDialog
{
    Q_OBJECT
public:
    photoShower(QWidget *parent,int pid);
signals:
    void opened();

};

#endif // PHOTOSHOWER_H
